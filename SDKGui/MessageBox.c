#include <windows.h>
#include <locale.h>

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPreInstance,PSTR szCmdLine,int iCmdShow)
{
    TCHAR *szContent=TEXT("你好世界");
    TCHAR *szCaption=TEXT("这是标题");
    MessageBox(NULL,szContent,szCaption,MB_OKCANCEL|MB_ICONWARNING);
    return 0;
}