#pragma once

#define giNumbsLen  3
class CNumbs
{
public:
	int m_aiMax[giNumbsLen];
	int m_iRes;

	void FindResult();
	void ShowInfo();
	void WriteInfo();

public:
	CNumbs();

	void BiggestNum(int *arr_Num, int amount);
};

void GenerateArray(int *arr_Num, int amount);
void WriteArrayInfo(int *arr_Num, int amount);
void ShowArrayInfo(int *arr_Num, int amount);
