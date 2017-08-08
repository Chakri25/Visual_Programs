// TemplateFunctions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

template <class genericDT>
genericDT addFun(genericDT a, genericDT b) {
	return(a + b);
}

int main()
{
	int a = 10, b = 20, c;
	double x = 10.23, y = 30.43, z;
	c = addFun(a, b);
	z = addFun(x, y);
	cout << "adding integers " << c << endl;
	cout << "adding doubles " << z << endl;
	system("pause");
    return 0;
}

