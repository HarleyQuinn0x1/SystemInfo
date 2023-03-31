#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <lmcons.h>

using namespace std;

int main() {

	//Get System Info
	SYSTEM_INFO sysInfo;
	SYSTEMTIME sysTime;
	GetSystemInfo(&sysInfo);
	GetLocalTime(&sysTime);

	//Get Username
	char username[UNLEN + 1];
	DWORD username_lenght = UNLEN + 1;
	GetUserNameA(username, &username_lenght);
	
	//Get Computer Name
	char computer_name[UNCLEN + 1];
	DWORD computer_name_lenght = UNCLEN + 1;
	GetComputerNameA(computer_name, &computer_name_lenght);
	
	//Get Memory Information
	MEMORYSTATUSEX mem;
	mem.dwLength = sizeof(mem);
	GlobalMemoryStatusEx(&mem);


	cout << "--SYSTEM INFORMATION--" << endl;
	cout << "System Local Time: " << sysTime.wHour << ":" << sysTime.wMinute << endl;
	cout << "Number of Processors: " << sysInfo.dwNumberOfProcessors << endl;
	cout << "Processor Type: " << sysInfo.dwProcessorType << endl;
	cout << "Username: " << username << endl;
	cout << "Computer Name: " << computer_name << endl;
	cout << "Total Memory [Megabyte]: " << mem.ullTotalPhys / 1024 / 1024 << endl;
	cout << "Avaible Memory [Megabyte]: " << mem.ullAvailPhys / 1024 / 1024 << endl;

	return 0;
}
