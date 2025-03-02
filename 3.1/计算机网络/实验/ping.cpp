#define WINSOCK DEPRECATED NO WARNINGS
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib,"ws2_32.lib")
using namespace std;

//IP报头
typedef struct
{
	unsigned char hdr_len : 4;         //4位头部长度
	unsigned char version : 4;         //4位版本号
	unsigned char tos;               //8位服务类型
	unsigned short total_len;        //16位总长度
	unsigned short identifier;       //16位标识符
	unsigned short frag_and_flags;   //3位标志加13位片偏移
	unsigned char ttl;               //8位生存时间
	unsigned char protocol;          //8位上层协议号
	unsigned short checksum;         //16位效验和
	unsigned long sourceIP;          //32位源IP地址
	unsigned long destIP;            //32位目的IP地址
}IP_HEADER;

//ICMP报头
typedef struct
{
	BYTE type;     //8位类型字段
	BYTE code;     //8位代码字段
	USHORT cksum;  //16位效验和
	USHORT id;     //16位标识符
	USHORT seq;    //16位序列号
}ICMP_HEADER;


//报文解码结构
typedef struct
{
	USHORT usSeqNo;          //序列号
	DWORD dwRoundTripTime;   //返回时间
	in_addr dwIPaddr;        //返回报文的IP地址
}DECODE_RESULT;

//计算网际效验和函数
USHORT checksum(USHORT* pBuf, int iSize)
{
	unsigned long cksum = 0;
	while (iSize > 1)
	{
		cksum += *pBuf++;
		iSize -= sizeof(USHORT);
	}
	if (iSize)
	{
		cksum += *(USHORT*)pBuf;
	}
	cksum = (cksum >> 16) + (cksum & 0xffff);
	cksum += (cksum >> 16);
	return(USHORT)(~cksum);
}

//对数据包进行解码
BOOL DecodeIcmpResponse(char* pBuf, int iPacketSize, DECODE_RESULT& DecodeResult, BYTE ICMP_ECHO_REPLY, BYTE ICMP_TIMEOUT)
{
	//检查数据报大小的合法性
	IP_HEADER* pIpHdr = (IP_HEADER*)pBuf;
	int iIpHdrLen = pIpHdr->hdr_len * 4;
	if (iPacketSize < (int)(iIpHdrLen + sizeof(ICMP_HEADER)))
		return FALSE;
	//根据ICMP报文类型提取ID字段和序列号字段
	ICMP_HEADER* pIcmpHdr = (ICMP_HEADER*)(pBuf + iIpHdrLen);
	USHORT usID, usSquNo;
	if (pIcmpHdr->type == ICMP_ECHO_REPLY)    //ICMP回显应答报文
	{
		usID = pIcmpHdr->id;   //报文ID
		usSquNo = pIcmpHdr->seq;  //报文序列号
	}
	else if (pIcmpHdr->type == ICMP_TIMEOUT)   //ICMP超时差错报文
	{
		char* pInnerIpHdr = pBuf + iIpHdrLen + sizeof(ICMP_HEADER);  //载荷中的IP头
		int iInnerIPHdrLen = ((IP_HEADER*)pInnerIpHdr)->hdr_len * 4; //载荷中的IP头长
		ICMP_HEADER* pInnerIcmpHdr = (ICMP_HEADER*)(pInnerIpHdr + iInnerIPHdrLen);//载荷中的ICMP头
		usID = pInnerIcmpHdr->id;  //报文ID
		usSquNo = pInnerIcmpHdr->seq;  //序列号
	}
	else {
		return false;
	}
	//检查ID和序列号以确定收到期待数据报
	if (usID != (USHORT)GetCurrentProcessId() || usSquNo != DecodeResult.usSeqNo)
	{
		return false;
	}
	//记录IP地址并计算往返时间
	DecodeResult.dwIPaddr.s_addr = pIpHdr->sourceIP;
	DecodeResult.dwRoundTripTime = GetTickCount() - DecodeResult.dwRoundTripTime;

	//处理正确收到的ICMP数据报
	if (pIcmpHdr->type == ICMP_ECHO_REPLY || pIcmpHdr->type == ICMP_TIMEOUT)
	{
		return true;
	}
	else {
		return false;
	}
	return true;
}
int ping(const char* IpAddress) {
	//得到IP地址
	u_long ulDestIP = inet_addr(IpAddress);
	//转换不成功时按域名解析
	if (ulDestIP == INADDR_NONE)
	{
		hostent* pHostent = gethostbyname(IpAddress);
		if (pHostent)
		{
			ulDestIP = (*(in_addr*)pHostent->h_addr).s_addr;
		}
		else
		{
			cout << "输入的IP地址或域名无效" << endl;
			WSACleanup();
			return 0;
		}
	}

	cout << "正在 Ping " << IpAddress << "具有 32 字节的数据：" << endl << endl;

	//填充目的端socket地址
	sockaddr_in destSockAddr;
	ZeroMemory(&destSockAddr, sizeof(sockaddr_in));
	destSockAddr.sin_family = AF_INET;//AF_INET（IPv4）、
	destSockAddr.sin_addr.s_addr = ulDestIP;

	/*　指明socket的类型，Windows Sockets 2常见类型如下：

	SOCK_STREAM（流套接字，使用TCP协议）、

	SOCK_DGRAM（数据报套接字，使用UDP协议）、

	SOCK_RAW（原始套接字）、

	SOCK_RDM（提供可靠的消息数据报文，reliable message datagram）、

	SOCK_SEQPACKET（Provides a pseudo-stream packet based on datagrams，在UDP的基础上提供了伪流数据包）。

	protocol

	指明数据传输协议，该参数取决于af和type参数的类型。protocol参数在Winsock2.h and Wsrm.h定义。通常使用如下3中协议：

	IPPROTO_TCP（TCP协议，使用条件，af是AF_INET or AF_INET6、type是SOCK_STREAM ）

	IPPROTO_UDP（UDP协议，使用条件，af是AF_INET or AF_INET6、type是SOCK_DGRAM）

	IPPROTO_RM（PGM（Pragmatic General Multicast，实际通用组播协议）协议，使用条件，af是AF_INET 、type是SOCK_RDM*/
	//ICMP协议在实际传输中数据包：20字节IP首部 + 8字节ICMP首部+ 1472字节<数据大小>38字节    

	//创建原始套接字
	SOCKET sockRaw = WSASocket(AF_INET, SOCK_RAW, IPPROTO_ICMP, NULL, 0, WSA_FLAG_OVERLAPPED);
	//超时时间
	int iTimeout = 3000;
	//接收超时
	setsockopt(sockRaw, SOL_SOCKET, SO_RCVTIMEO, (char*)&iTimeout, sizeof(iTimeout));
	//发送超时
	setsockopt(sockRaw, SOL_SOCKET, SO_SNDTIMEO, (char*)&iTimeout, sizeof(iTimeout));


	//构造ICMP回显请求消息，并以TTL递增的顺序发送报文
	//ICMP类型字段
	const BYTE ICMP_ECHO_REQUEST = 8;   //请求回显
	const BYTE ICMP_ECHO_REPLY = 0;     //回显应答
	const BYTE ICMP_TIMEOUT = 11;       //传输超时

	//其他常量定义
	const int DEF_ICMP_DATA_SIZE = 32;    //ICMP报文默认数据字段长度
	const int MAX_ICMP_PACKET_SIZE = 1024; //ICMP报文最大长度（包括报头）
	const DWORD DEF_ICMP_TIMEOUT = 3000;   //回显应答超时时间
	const int DEF_MAX_HOP = 4;            //最大跳站数(循环次数)

	//填充ICMP报文中每次发送时不变的字段
	char IcmpSendBuf[sizeof(ICMP_HEADER) + DEF_ICMP_DATA_SIZE]; //发送缓冲区
	memset(IcmpSendBuf, 0, sizeof(IcmpSendBuf));     //初始化发送缓冲区
	char IcmpRecvBuf[MAX_ICMP_PACKET_SIZE];        //接收缓冲区
	memset(IcmpRecvBuf, 0, sizeof(IcmpRecvBuf));     //初始化接收缓冲区

	ICMP_HEADER* pIcmpHeader = (ICMP_HEADER*)IcmpSendBuf;
	pIcmpHeader->type = ICMP_ECHO_REQUEST;             //类型为请求回显
	pIcmpHeader->code = 0;                             //代码字段为0
	pIcmpHeader->id = (USHORT)GetCurrentProcessId();   //ID字段为当前进程号
	memset(IcmpSendBuf + sizeof(ICMP_HEADER), 'E', DEF_ICMP_DATA_SIZE);   //数据字段
	USHORT usSeqNo = 0;                //ICMP报文序列号
	int iTTL = 64;                      //TTL初始值为1
	int r = 0, o = 0;
	BOOL bReachDestHost = FALSE;       //循环退出标志
	int iMaxHot = DEF_MAX_HOP;         //循环的最大次数
	DECODE_RESULT DecodeResult;      //传递给报文解码函数的结构化参数

	while (!bReachDestHost && iMaxHot--)
	{
		//设置IP报头的TTL字段
		setsockopt(sockRaw, IPPROTO_IP, IP_TTL, (char*)&iTTL, sizeof(iTTL));

		//填充ICMP报文中每次发送变化的字段
		((ICMP_HEADER*)IcmpSendBuf)->cksum = 0;                 //效验和先置为0
		((ICMP_HEADER*)IcmpSendBuf)->seq = htons(usSeqNo++);    //填充序列号
		((ICMP_HEADER*)IcmpSendBuf)->cksum = checksum((USHORT*)IcmpSendBuf, sizeof(ICMP_HEADER) + DEF_ICMP_DATA_SIZE);  //计算效验和

		//记录序列号和当前时间
		DecodeResult.usSeqNo = ((ICMP_HEADER*)IcmpSendBuf)->seq;    //当前序号
		DecodeResult.dwRoundTripTime = GetTickCount();              //当前时间
		//发送TCP回显请求信息
		sendto(sockRaw, IcmpSendBuf, sizeof(IcmpSendBuf), 0, (sockaddr*)&destSockAddr, sizeof(destSockAddr));
		//接收ICMP差错报文并进行解析处理
		sockaddr_in from;              //对端socket地址
		int iFromLen = sizeof(from);     //地址结构大小
		int iReadDataLen;              //接收数据长度
		while (1)
		{
			//接收数据
			iReadDataLen = recvfrom(sockRaw, IcmpRecvBuf, MAX_ICMP_PACKET_SIZE, 0, (sockaddr*)&from, &iFromLen);
			if (iReadDataLen != SOCKET_ERROR)//有数据达到
			{
				//对数据包进行解码
				if (DecodeIcmpResponse(IcmpRecvBuf, iReadDataLen, DecodeResult, ICMP_ECHO_REPLY, ICMP_TIMEOUT))
				{
					//到达目的地，退出循环
					if (DecodeResult.dwIPaddr.s_addr == destSockAddr.sin_addr.s_addr) {
						//输出IP地址
						if (DecodeResult.dwRoundTripTime)
							cout << "来自 " << inet_ntoa(DecodeResult.dwIPaddr) << " 的回复：字节32 时间=" << DecodeResult.dwRoundTripTime << "ms TTL:" << iTTL << endl;
						else
							cout << "来自 " << inet_ntoa(DecodeResult.dwIPaddr) << " 的回复：字节32 时间< 1ms TTL:" << iTTL << endl;
						r++;
						break;
					}

				}
			}
			else if (WSAGetLastError() == WSAETIMEDOUT) //接收超时，输出星号
			{
				cout << "请求超时。" << endl;
				o++;
				break;
			}
			else {
				break;
			}
		}
	}
	cout << endl;
	cout << IpAddress << " 的 Ping 统计信息：" << endl;
	cout << '\t' << "数据包：已发送=4，已接收=" << r << "，丢失=" << o << endl;
}


int main()
{
	//初始化Windows sockets网络环境
	/*指向WSADATA结构体的指针，lpWSAData返回了系统对Windows Sockets 的描述。*/
	WSADATA wsa;

	/*
	标识了用户调用的Winsock的版本号。高字节指明辅版本编号，低字节指明主版本编号。
	通常使用MAKEWORD来生成一个版本号。
	当前Winsock sockets的版本号为2.2，用到的dll是 Ws2_32.dll。
	*/
	WSAStartup(MAKEWORD(2, 2), &wsa);//WSAStartup 函数用于初始化供进程调用的Winsock相关的dll。
	char IpAddress[255];
	cout << "请输入一个IP地址或域名：";
	cin >> IpAddress;
	ping(IpAddress);
	return 0;

}

