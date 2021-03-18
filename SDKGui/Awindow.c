#include<windows.h>

//消息函数
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);

//窗口主函数
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,PSTR szCmdLine,int iCmdShow)
{
    static TCHAR *szAppName=TEXT("myWindow");   //应用名称
    HWND hwnd;  //存放句柄
    MSG msg;    //消息机制
    WNDCLASS wndclass;   //win窗口类

    //设置WNDCLASS窗口类 wndclass
    wndclass.style=CS_VREDRAW|CS_HREDRAW;                       //指定窗口风格
    wndclass.lpfnWndProc=WndProc;                               //指定窗口过程（必须为回调函数）
    wndclass.cbClsExtra=0;                                      //预留额外空间，一般为0
    wndclass.cbWndExtra=0;                                      //预留额外空间，一般为0
    wndclass.hInstance=hInstance;                               //应用程序的实例句柄
    wndclass.hIcon=LoadIcon(NULL,IDI_APPLICATION);              //为所有基于该窗口类的窗口设置一个图标
    wndclass.hCursor=LoadCursor(NULL,IDC_ARROW);                //为所有基于该窗口类的窗口设置一个鼠标指针
    wndclass.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH); //指定窗口背景颜色
    wndclass.lpszMenuName=NULL;                                 //指定窗口菜单
    wndclass.lpszClassName=szAppName;                           //指定窗口类名

    if(!RegisterClass(&wndclass))   //注册窗口类，输入参数为目前窗口类的名称
    {
        MessageBox(NULL,TEXT("该程序应该运行在WIN NT上"),szAppName,MB_ICONERROR|MB_OK);
        return 0;
    }

    //创建窗口
    hwnd=CreateWindow(szAppName,    //窗口类名称
        TEXT("Yurzi"),              //窗口标题
        WS_OVERLAPPEDWINDOW,        //窗口风格
        CW_USEDEFAULT,              //初始x坐标
        CW_USEDEFAULT,              //初始y坐标
        CW_USEDEFAULT,              //初始x方向尺寸
        CW_USEDEFAULT,              //初始y方向尺寸
        NULL,                       //父窗口句柄
        NULL,                       //窗口菜单句柄
        hInstance,                  //程序实例句柄
        NULL);                      //创建参数

    //显示窗口
    ShowWindow(hwnd,iCmdShow);
    //更新窗口  参数句柄
    UpdateWindow(hwnd);

    //消息循环
    while (GetMessage(&msg,NULL,0,0))   //得到消息
    {
        TranslateMessage(&msg);     //翻译消息
        DispatchMessage(&msg);      //指派消息
    }

    return msg.wParam;
    
}

LRESULT CALLBACK WndProc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;
    RECT rect;

    switch(message)
    {
        case WM_PAINT:
            hdc=BeginPaint(hwnd,&ps);
            GetClientRect(hwnd,&rect);
            DrawText(hdc,TEXT("Hello World"),-1,&rect,
                DT_CENTER|DT_SINGLELINE|DT_VCENTER);
            EndPaint(hwnd,&ps);
            return 0;
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }

    return DefWindowProc(hwnd,message,wParam,lParam);
}