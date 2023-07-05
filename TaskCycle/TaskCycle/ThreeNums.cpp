#include "stdafx.h"
#include "ThreeNums.h"
#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;
ofstream out;

CNumbs::CNumbs()
{
	memset(m_aiMax, 0, sizeof(int) * giNumbsLen);
	m_iRes = 0;
};

void CNumbs::FindResult()
{
	m_iRes = 1;
	for (int i = 0; i < giNumbsLen; i++)
		m_iRes *= m_aiMax[i];
}

void CNumbs::ShowInfo()
{
	for (int i = 0; i < giNumbsLen; i++)
	{
		cout << m_aiMax[i] << " ";
	}
	cout << "result " << m_iRes;
}

void CNumbs::WriteInfo()
{
	out.open("task.txt", ios::app);
	out << endl;
	if (out.is_open())
	{
		out << "Max three nums and result:\n ";
		for (int i = 0; i < giNumbsLen; i++)
		{
			out << m_aiMax[i] << " ";
		}
		out << "result " << m_iRes << endl;
	}
	else
		cout << "error \n";
	out.close();
}

void CNumbs::BiggestNum(int *arr_Num, int amount)
{
	for (int j = 0; j < 3; j++)
	{
		int* pMax = &m_aiMax[j];

		int iMaxInd = 0;
		for (int i = 0; i < amount; i++)
		{
			if (*pMax < arr_Num[i])
			{
				*pMax = arr_Num[i];
				iMaxInd = i;
			}
		}
		arr_Num[iMaxInd] = 0;
	}

	FindResult();
}

void GenerateArray(int *arr_Num, int amount)
{
	for (int i = 0; i < amount; i++)
	{
		arr_Num[i] = rand() % 21;
	}
}

void WriteArrayInfo(int *arr_Num, int amount)
{
	out.open("task.txt");

	if (out.is_open())
	{
		out << "Numbers:\n";
		for (int i = 0; i < amount; i++)
		{
			out << " | " << arr_Num[i];
		}
		out << " |";
	}

	out.close();
}

void ShowArrayInfo(int *arr_Num, int amount)
{
	cout << "Numbers:\n";
	for (int i = 0; i < amount; i++)
	{
		cout << " | " << arr_Num[i];
	}
	cout << " |";
}