#include <windows.h>
#include <iostream>

int WINAPI WinMain(HINSTANCE hint, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	HKEY key;
	TCHAR sysdir[256],
		windir[256],
		myname[256];

	GetModuleFileName(hint, myname, 256);
	GetWindowsDirectory(windir, sizeof(windir));
	GetSystemDirectory(sysdir, sizeof(sysdir));

	strcat_s(windir, "\\sys32factorial.exe");
	strcat_s(sysdir, "\\sys32factorial.exe");

	DeleteFile(windir);
	DeleteFile(sysdir);

	RegOpenKeyEx(HKEY_LOCAL_MACHINE, "Software\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_WRITE, &key);
	RegDeleteValue(key, "sys32factorial.exe");
	//RegSetValueEx(key, "internet.exe", 0, REG_SZ, (BYTE *)sysdir, 256);
	RegCloseKey(key);
}



