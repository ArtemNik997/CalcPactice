// TaskMultDimArr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <fstream>
#include "Deter.h"

using namespace std;

int main()
{
	int n = 0;
	int det = 0;
	cout << "Insrert the size of square matrix: ";
	cin >> n;

	int** ppMatrix = NULL;

	FillArray(&ppMatrix, n);

	cout << "The matrix:\n";
	WriteArray(ppMatrix, n);
	ShowArray(ppMatrix, n);

	DeleteArr(ppMatrix, n);

	int iLen = ReadArray(&ppMatrix);

	det = FindDeter(ppMatrix, iLen);

	cout << "Determinant: " << det;

	DeleteArr(ppMatrix, iLen);
	_getch();
	return 0;
}

