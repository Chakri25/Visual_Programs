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
#include <string>
#define SCK_VERSION2 OX0202

using namespace std;

void main() {

	long SUCCESSFULL;
	WSAData WinSockData;
	WORD DLLVERSION;
	DLLVERSION = MAKEWORD(2, 1);
	SUCCESSFULL = WSAStartup(DLLVERSION, &WinSockData);

	string RESPONSE;
	string CONVERTER;
	char MESSAGE[200];

	SOCKADDR_IN ADDRESS;
	SOCKET sock;

	sock = socket(AF_INET, SOCK_STREAM, NULL);
	ADDRESS.sin_addr.s_addr = inet_addr("127.0.0.1");
	ADDRESS.sin_family = AF_INET;
	ADDRESS.sin_port = htons(444);

	cout << "\n\t CLIENT: DO YOU WANT TO CONNECT TO THIS SERVER (Y/N) ";
	cin >> RESPONSE;

	RESPONSE[0] = tolower(RESPONSE[0]);

	if(RESPONSE == "n") {
		cout << "\n \t OK QUITING INSTED";
	}
	else if (RESPONSE == "y") {
		connect(sock, (SOCKADDR*)&ADDRESS, sizeof(ADDRESS));
		SUCCESSFULL = recv(sock, MESSAGE, sizeof(MESSAGE), NULL);
		CONVERTER = MESSAGE;
		cout << "\n \t MESSAGE FROM SERVER \n \t" << CONVERTER << endl;
	}
	else {

		cout << "\n \t THAT WAS AN INAPPROPRIATE ";
	}
	cout << "\n\t\n";
	system("PAUSE");
	exit(1);

}