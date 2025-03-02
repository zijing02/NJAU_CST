/******************************************************
 *  graphics.h
 *
 *	在 VC 下模拟 Borland BGI 绘图库，实现简单的绘图
 *
 *	2009-11-23 by yw80@msn.com
 *	http://hi.baidu.com/yangw80
 ******************************************************/

#pragma once

#ifndef WINVER                          // Specifies that the minimum required platform is Windows Vista.
#define WINVER 0x0400           // Change this to the appropriate value to target other versions of Windows.
#endif

#ifndef _WIN32_WINNT            // Specifies that the minimum required platform is Windows Vista.
#define _WIN32_WINNT 0x0400     // Change this to the appropriate value to target other versions of Windows.
#endif

#ifndef _WIN32_WINDOWS          // Specifies that the minimum required platform is Windows 98.
#define _WIN32_WINDOWS 0x0410 // Change this to the appropriate value to target Windows Me or later.
#endif

#if defined(_UNICODE) && (_MSC_VER > 1200)
	#pragma comment(lib,"graphics9u.lib")
#elif !defined(_UNICODE) && (_MSC_VER > 1200)
	#pragma comment(lib,"graphics9.lib")
#elif defined(_UNICODE)
	#pragma comment(lib,"graphics6u.lib")
#elif !defined(_UNICODE)
	#pragma comment(lib,"graphics6.lib")
#endif

#if _MSC_VER > 1200
	#ifdef _DEBUG
		#pragma comment(linker, "/NODEFAULTLIB:libcmtd.lib")
	#else
		#pragma comment(linker, "/NODEFAULTLIB:libcmt.lib")
	#endif
#else
	#ifdef _DEBUG
		#pragma comment(linker, "/NODEFAULTLIB:libc.lib")
	#endif
#endif



#include "windows.h"
#include "tchar.h"

#define PI 3.1415926535

// 为了兼容 Borland C++ 3.1 而做的无意义定义
#define DETECT 0
#define VGA	0
#define VGAHI 0

// 绘图环境初始化参数
#define SHOWCONSOLE		1		// 进入图形模式时，保留控制台的显示

// 颜色
#define	BLACK			0
#define	BLUE			0xA80000
#define	GREEN			0x00A800
#define	CYAN			0xA8A800
#define	RED				0x0000A8
#define	MAGENTA			0xA800A8
#define	BROWN			0x0054A8
#define	LIGHTGRAY		0xA8A8A8
#define	DARKGRAY		0x545454
#define	LIGHTBLUE		0xFC5454
#define	LIGHTGREEN		0x54FC54
#define	LIGHTCYAN		0xFCFC54
#define	LIGHTRED		0x5454FC
#define	LIGHTMAGENTA	0xFC54FC
#define	YELLOW			0x54FCFC
#define	WHITE			0xFCFCFC

// 填充模式
#define	NULL_FILL			1		// 不填充
#define	SOLID_FILL			2		// 用指定颜色完全填充
#define	BDIAGONAL_FILL		3		// /// 填充 (普通一组)
#define	CROSS_FILL			4		// +++ 填充
#define	DIAGCROSS_FILL		5		// xxx 填充
#define	DOT_FILL			6		// ... 填充
#define	FDIAGONAL_FILL		7		// \\\ 填充
#define	HORIZONTAL_FILL		8		// --- 填充
#define	VERTICAL_FILL		9		// ||| 填充
#define	BDIAGONAL2_FILL		10		// /// 填充 (密集一组)
#define	CROSS2_FILL			11		// +++ 填充
#define	DIAGCROSS2_FILL		12		// xxx 填充
#define	DOT2_FILL			13		// ... 填充
#define	FDIAGONAL2_FILL		14		// \\\ 填充
#define	HORIZONTAL2_FILL	15		// --- 填充
#define	VERTICAL2_FILL		16		// ||| 填充
#define	BDIAGONAL3_FILL		17		// /// 填充 (粗线一组)
#define	CROSS3_FILL			18		// +++ 填充
#define	DIAGCROSS3_FILL		19		// xxx 填充
#define	DOT3_FILL			20		// ... 填充
#define	FDIAGONAL3_FILL		21		// \\\ 填充
#define	HORIZONTAL3_FILL	22		// --- 填充
#define	VERTICAL3_FILL		23		// ||| 填充
#define	INTERLEAVE_FILL		24		// xxx 填充 (十分密)
#define	PATTERN_FILL		25		// 用指定图案填充



// 绘图模式相关函数

void initgraph(int Width, int Height, int Flag = NULL);	// 初始化图形环境
void initgraph(int* gdriver, int* gmode, char* path);	// 兼容 Borland C++ 3.1 的重载，默认 640x480@24bit
void closegraph();										// 关闭图形环境



// 绘图环境设置

void cleardevice();					// 清屏

COLORREF getcolor();				// 获取当前绘图前景色
void setcolor(COLORREF color);		// 设置当前绘图前景色
COLORREF getbkcolor();				// 获取当前绘图背景色
void setbkcolor(COLORREF color);	// 设置当前绘图背景色
void setbkmode(int iBkMode);		// 设置背景混合模式

void getviewport(int *pleft, int *ptop, int *pright, int *pbottom, bool *pclip = NULL);	// 获取视图信息
void setviewport(int left, int top, int right, int bottom, bool clip = true);			// 设置视图
void clearviewport();															// 清空视图

void getlinestyle(int *plinestyle, WORD *pupattern = NULL, int *pthickness = NULL);	// 获取当前线形
void setlinestyle(int linestyle, WORD upattern = NULL, int thickness = 1);			// 设置当前线形
void getfillstyle(COLORREF *pcolor, int *ppattern = NULL, char *pupattern = NULL);			// 获取填充类型
void setfillstyle(COLORREF color, int pattern = SOLID_FILL, const char *pupattern = NULL);	// 设置填充类型

void getaspectratio(float *pxasp, float *pyasp);		// 获取当前缩放因子
void setaspectratio(float xasp = 1, float yasp = 1);	// 设置当前缩放因子

void setwritemode(int mode);				// 设置绘图位操作模式

void graphdefaults();						// 重置所有绘图设置为默认值



// 绘图函数

COLORREF getpixel(int x, int y);				// 获取点的颜色
void putpixel(int x, int y, COLORREF color);	// 画点

void moveto(int x, int y);						// 移动当前点(绝对坐标)
void moverel(int dx, int dy);					// 移动当前点(相对坐标)

void line(int x1, int y1, int x2, int y2);		// 画线
void linerel(int dx, int dy);					// 画线(至相对坐标)
void lineto(int x, int y);						// 画线(至绝对坐标)

void rectangle(int left, int top, int right, int bottom);	// 画矩形

void getarccoords(int *px, int *py, int *pxstart, int *pystart, int *pxend, int *pyend);	// 获取圆弧坐标信息
void arc(int x, int y, int stangle, int endangle, int radius);					// 画圆弧
void circle(int x, int y, int radius);											// 画圆
void pieslice(int x, int y, int stangle, int endangle, int radius);				// 画填充圆扇形
void ellipse(int x, int y, int stangle, int endangle, int xradius, int yradius);// 画椭圆弧线
void fillellipse(int x, int y, int xradius, int yradius);						// 画填充椭圆
void sector(int x, int y, int stangle, int endangle, int xradius, int yradius);	// 画填充椭圆扇形

void bar(int left, int top, int right, int bottom);								// 画无边框填充矩形
void bar3d(int left, int top, int right, int bottom, int depth, bool topflag);	// 画有边框三维填充矩形

void drawpoly(int numpoints, const int *polypoints);	// 画多边形
void fillpoly(int numpoints, const int *polypoints);	// 画填充的多边形
void floodfill(int x, int y, int border);				// 填充区域



// 文字相关函数

void outtext(LPCTSTR textstring);					// 在当前位置输出文字
void outtextxy(int x, int y, LPCTSTR textstring);	// 在指定位置输出文字
int textwidth(LPCTSTR textstring);					// 获取字符串占用的像素宽
int textheight(LPCTSTR textstring);					// 获取字符串占用的像素高

// 设置当前字体样式
//		nHeight: 字符的平均高度，默认为 16；
//		nWidth: 字符的平均宽度，默认为 0，表示自适应；
//		lpszFace: 字体名称，默认为“System”；
//		nEscapement: 字符串的书写角度，单位 0.1 度，默认为 0；
//		nOrientation: 每个字符的书写角度，单位 0.1 度，默认为 0；
//		fnWeight: 字符的笔画粗细。常用的是 400，0 表示默认粗细，默认为 0；
//		fdwItalic: 是否斜体，true / false，默认为 false；
//		fdwUnderline: 是否下划线，true / false，默认为 false；
//		fdwStrikeOut: 是否删除线，true / false，默认为 false。
void setfont(int nHeight = 16, int nWidth = 0, LPCTSTR lpszFace = NULL, int nEscapement = 0, int nOrientation = 0, int fnWeight = 0, bool fdwItalic = 0, bool fdwUnderline= 0, bool fdwStrikeOut = 0);
void setfont(const LOGFONT *font);	// 设置当前字体样式
void getfont(LOGFONT *font);		// 获取当前字体样式



// 图像处理函数

// 定义图像对象
class IMAGE
{
private:
	HBITMAP m_hBmp;
	HDC m_hDC;
	int m_width, m_height;
	SIZE LoadImageFromFile(LPCTSTR pFile, HDC dc, int nDstWidth = 0, int nDstHeight = 0);
public:
	IMAGE();
	IMAGE(IMAGE &img);				// 拷贝构造函数
	IMAGE& operator = (IMAGE &img);	// 赋值运算符重载函数
	~IMAGE();
	void getimage(int srcX, int srcY, int srcWidth, int srcHeight);
	void getimage(LPCTSTR pImgFile, int zoomWidth = 0, int zoomHeight = 0);
	void getimage(const IMAGE *pSrcImg, int srcX, int srcY, int srcWidth, int srcHeight);
	void putimage(int dstX, int dstY, DWORD dwRop = SRCCOPY) const;
	void putimage(int dstX, int dstY, int dstWidth, int dstHeight, int srcX, int srcY, DWORD dwRop = SRCCOPY) const;
	void putimage(IMAGE *pDstImg, int dstX, int dstY, DWORD dwRop = SRCCOPY) const;
	void putimage(IMAGE *pDstImg, int dstX, int dstY, int dstWidth, int dstHeight, int srcX, int srcY, DWORD dwRop = SRCCOPY) const;
};

void getimage(IMAGE *pDstImg, int srcX, int srcY, int srcWidth, int srcHeight);				// 从屏幕获取图像
void getimage(IMAGE *pDstImg, LPCTSTR pImgFile, int zoomWidth = 0, int zoomHeight = 0);		// 从图片文件(bmp/jpg/gif/emf/wmf)获取图像
void getimage(IMAGE *pDstImg, const IMAGE *pSrcImg, int srcX, int srcY, int srcWidth, int srcHeight);	// 从另一个 IMAGE 对象中获取图像
void putimage(int dstX, int dstY, const IMAGE *pSrcImg, DWORD dwRop = SRCCOPY);							// 绘制图像到屏幕
void putimage(int dstX, int dstY, int dstWidth, int dstHeight, const IMAGE *pSrcImg, int srcX, int srcY, DWORD dwRop = SRCCOPY);	// 绘制图像到屏幕(指定宽高)
void putimage(IMAGE *pDstImg, int dstX, int dstY, const IMAGE *pSrcImg, DWORD dwRop = SRCCOPY);			// 绘制图像到另一图像中
void putimage(IMAGE *pDstImg, int dstX, int dstY, int dstWidth, int dstHeight, const IMAGE *pSrcImg, int srcX, int srcY, DWORD dwRop = SRCCOPY);	// 绘制图像到另一图像中(指定宽高)



// 其它函数

int	getmaxx();		// 获取最大 x 坐标
int	getmaxy();		// 获取最大 y 坐标
int	getx();			// 获取当前 x 坐标
int	gety();			// 获取当前 y 坐标

void BeginBatchDraw();	// 开始批量绘制
void FlushBatchDraw();	// 执行未完成的绘制任务
void FlushBatchDraw(int left, int top, int right, int bottom);	// 执行指定区域内未完成的绘制任务
void EndBatchDraw();	// 结束批量绘制，并执行未完成的绘制任务
void EndBatchDraw(int left, int top, int right, int bottom);	// 结束批量绘制，并执行指定区域内未完成的绘制任务

int GetGraphicsVer();			// 获取当前版本
LPCTSTR GetGraphicsAuthor();



// 鼠标消息
// 支持如下消息：
//		WM_MOUSEMOVE		鼠标移动
//		WM_MOUSEWHEEL		鼠标滚轮拨动
//		WM_LBUTTONDOWN		左键按下
//		WM_LBUTTONUP		左键弹起
//		WM_LBUTTONDBLCLK	左键双击
//		WM_MBUTTONDOWN		中键按下
//		WM_MBUTTONUP		中键弹起
//		WM_MBUTTONDBLCLK	中键双击
//		WM_RBUTTONDOWN		右键按下
//		WM_RBUTTONUP		右键弹起
//		WM_RBUTTONDBLCLK	右键双击
struct MOUSEMSG
{
	UINT uMsg;			// 当前鼠标消息
	bool mkCtrl;		// Ctrl 键是否按下
	bool mkShift;		// Shift 键是否按下
	bool mkLButton;		// 鼠标左键是否按下
	bool mkMButton;		// 鼠标中键是否按下
	bool mkRButton;		// 鼠标右键是否按下
	int x;				// 当前鼠标 x 坐标
	int y;				// 当前鼠标 y 坐标
	int wheel;			// 鼠标滚轮滚动值(120的倍数)
};

bool MouseHit();				// 检查是否存在鼠标消息
MOUSEMSG GetMouseMsg();			// 获取一个鼠标消息。如果没有，就等待
void FlushMouseMsgBuffer();		// 清空鼠标消息缓冲区
