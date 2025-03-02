#include<iostream>
#include<fstream>
using namespace std;
//int main()
//{
//	int count = 0;
//	//streampos start, end;
//	char s, flag = 'y';
//	while (tolower(flag) == 'y')
//	{
//		ifstream infile("file.txt");
//		if (!infile)
//		{
//			cout << "file cannot be opened!" << endl;
//			return 0;
//		}
//		cout << "请输入要统计的字符:" << endl;
//		cin >> s;
//		while (!infile.eof())
//		{
//			if (s == infile.get())
//				count = count + 1;
//		}
//		cout << "文件有" << count << "个字符!" << endl;
//		cout << "是否继续统计字符(是-y，否-n)?";
//		cin >> flag;
//		count = 0;
//		infile.close();
//	}
//}

int main()
{
	int count = 0;
	//streampos start, end;
	char s, flag = 'y';
	while (tolower(flag) == 'y')
	{
		ifstream infile("file.txt");
		if (!infile)
		{
			cout << "file cannot be opened!" << endl;
			return 0;
		}
		cout << "请输入要统计的字符:" << endl;
		cin >> s;
		while (!infile.eof())
		{
			if (s == infile.get())
				count = count + 1;
		}
		cout << "文件有" << count << "个字符!" << endl;
		//重新定位文件读指针至文件开始位置，并读取文件内容输出到屏幕
		infile.clear();
		infile.seekg(0, ios::beg);
		while (!infile.eof())
		{
			char txt[255];
			infile.getline(txt, sizeof(txt));
			cout << txt << endl;
		}
		cout << "是否继续统计字符(是-y，否-n)?";
		cin >> flag;
		count = 0;
		infile.close();
	}
}

