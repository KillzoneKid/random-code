/*
	Copies notepad viad binary stream to desktop and launches the copy
*/


#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

bool Execute(LPCTSTR Process)
{
    STARTUPINFO sInfo = {};
    sInfo.cb = sizeof(sInfo);
    PROCESS_INFORMATION pInfo = {};

    return CreateProcess(Process, NULL, NULL, NULL, FALSE, CREATE_DEFAULT_ERROR_MODE, NULL, NULL, &sInfo, &pInfo);
}

int main()
{
    std::wstring src_name(L"C:\\Windows\\system32\\notepad.exe");
    std::wstring dst_name(L"C:\\Users\\KK\\Desktop\\mynotepad.exe");

    std::ifstream src(src_name, std::ios::binary);
    std::ofstream dst(dst_name, std::ios::binary);

    dst << src.rdbuf();

    src.close();
    dst.close();

    if (!Execute(dst_name.c_str()))
        std::cout << "ERROR: " << GetLastError() << std::endl;

    return 0;
}
