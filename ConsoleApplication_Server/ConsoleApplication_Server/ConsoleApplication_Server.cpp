// ConsoleApplication_Server.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#pragma comment(lib, "ws2_32.lib")

//std console header files
#include <sdkddkver.h>
#include <conio.h>
#include <stdio.h>

//socket header files
#include <WinSock2.h>
#include <Windows.h>
#include <iostream>

using namespace std;

int main()
{
	//main locals
	long SUCCESSFUL;
	WSAData WinSockData;
	WORD DLLVERSION;

	DLLVERSION = MAKEWORD(2, 1);
	SUCCESSFUL = WSAStartup(DLLVERSION, &WinSockData);

	SOCKADDR_IN ADDRESS;
	int AddressSize = sizeof(ADDRESS);

	SOCKET Sock_LISTEN;
	SOCKET Sock_CONNECTION;

	Sock_CONNECTION = socket(AF_INET, SOCK_STREAM, NULL);
	ADDRESS.sin_addr.s_addr = inet_addr("127.0.0.1");
	ADDRESS.sin_family = AF_INET;
	ADDRESS.sin_port = htons(444);

	Sock_LISTEN = socket(AF_INET, SOCK_STREAM, NULL);
	bind(Sock_LISTEN, (SOCKADDR*)&ADDRESS, sizeof(ADDRESS));
	listen(Sock_LISTEN, SOMAXCONN);

	for (;;) {

		cout << "\n\t server:waiting for incomming connection ....";
		if (Sock_CONNECTION = accept(Sock_LISTEN, (SOCKADDR*)&ADDRESS, &AddressSize)) {

			cout << "\n \t A CONNECTION WAS FOUND" << endl;
			SUCCESSFUL = send(Sock_CONNECTION, "Welcome! you have connected to Banana server", 46, NULL);

		}
	}

    return 0;
}

