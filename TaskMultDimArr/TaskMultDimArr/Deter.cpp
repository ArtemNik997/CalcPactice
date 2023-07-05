#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include "Deter.h"

using namespace std;

ifstream inFile;
ofstream outFile;

// - - - - - - - - - - - - - - - - - - - - - -
void FillArray(int*** arr, int length)
{
	*arr = new int*[length];

	for (int i = 0; i < length; i++)
	{
		(*arr)[i] = new int[length];
		for (int j = 0; j < length; j++)
		{
			(*arr)[i][j] = rand() % 10;
		}
	}
}

int ReadArray(int*** arr)
{
	inFile.open("data.bin", ios::binary);
	int iLen = 0;

	if (inFile.is_open())
	{
		inFile >> iLen;
		(*arr) = new int*[iLen];
		for (int i = 0; i < iLen; i++)
		{
			(*arr)[i] = new int[iLen];
			for (int j = 0; j < iLen; j++)
				inFile >> (*arr)[i][j];
		}
	}

	inFile.close();
	return iLen;
}

// - - - - - - - - - - - - - - - - - - - - - -

void ShowArray(int** arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			cout << " " << arr[i][j];
		}
		cout << endl;
	}
	outFile.close();
}

void WriteArray(int** arr, int length)
{
	outFile.open("data.bin", ios::binary);
	if (outFile.is_open())
	{
		outFile << length << "\n";

		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < length; j++)
				outFile << " " << arr[i][j];
			outFile << endl;
		}
	}
	else { _ASSERT(false); return; }

	outFile.close();
}

// - - - - - - - - - - - - - - - - - - - - - -

void DeleteArr(int** arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

// - - - - - - - - - - - - - - - - - - - - - -

int FindDeter(int** arr, int length)
{
	int det = 0.0;

	if (length == 2)
	{
		return arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0];
	}

	for (int col = 0; col < length; col++) {
		int** submatrix = new int*[length - 1];
		for (int i = 0; i < length - 1; i++) {
			submatrix[i] = new int[length - 1];
		}

		for (int i = 1; i < length; i++) {
			int k = 0;
			for (int j = 0; j < length; j++) {
				if (j != col) {
					submatrix[i - 1][k] = arr[i][j];
					k++;
				}
			}
		}

		int subdet = FindDeter(submatrix, length - 1);

		if (col % 2 == 0) {
			det += arr[0][col] * subdet;
		}
		else {
			det -= arr[0][col] * subdet;
		}

		DeleteArr(submatrix, length - 1);
	}

	return det;
}