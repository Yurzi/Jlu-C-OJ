#include <windows.h>
#include <locale.h>

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,PSTR szCmdLine,int iCmdShow)
{
    TCHAR *szContent=TEXT("�������");
    static TCHAR *szCaption=TEXT("���Ǳ���");
    MessageBox(NULL,szContent,szCaption,MB_OKCANCEL|MB_ICONWARNING);
    return 0;
}