#include <windows.h>
#include <locale.h>

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPreInstance,PSTR szCmdLine,int iCmdShow)
{
    TCHAR *szContent=TEXT("�������");
    TCHAR *szCaption=TEXT("���Ǳ���");
    MessageBox(NULL,szContent,szCaption,MB_OKCANCEL|MB_ICONWARNING);
    return 0;
}