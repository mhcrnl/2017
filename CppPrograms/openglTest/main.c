#include <windows.h>
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{

	MessageBox(NULL, "\tHello World!", "My first windows app", NULL);
	return 0;
}
