#include "stdafx.h"
#include <ctime> 
#include <iostream>
#include <time.h> 
#include "CheckFunc.h"

using namespace std;

int GetDigitRec(int num, int sum, int &counter)
{

	if (num <= 0 || sum < 0) { _ASSERTE(false); return 0; } 

	int tmp = 0;
	
	tmp = num % 10;
	num -= tmp;
	num /= 10;
	sum += tmp;
	if (num <= 9) 
	{
		sum += num;
		counter++;
	}

	if (num > 9)
		sum = GetDigitRec(num, sum, counter);

	counter++;
	return sum;
}

int RecCheckCount(int num, int sum, int &counter, double &cTime) 
{
	time_t start, end;

	time(&start);

	sum = GetDigitRec(num, sum, counter);

	time(&end);
	cTime = difftime(end, start);
	return sum;
}

// - - - - - - - - - - - - - - - - - - - - - 

int GetDigitCycle(int num, int sum, int &counter)
{
	int tmp = 0;

	while (num != 0)
	{
		tmp = num % 10;
		num /= 10;
		sum += tmp;
		counter++;
	}

	return sum;
}

int CycleCheckCount(int num, int sum, int &counter, double &cTime)
{
	time_t start, end;

	time(&start);

	sum = GetDigitCycle(num, sum, counter);

	time(&end);
	cTime = difftime(end, start);
	return sum;
}