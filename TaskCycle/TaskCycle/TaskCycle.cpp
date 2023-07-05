// Task ¹5
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <fstream>
#include <conio.h>
#include "ThreeNums.h"

using namespace std;

int main()
{
	srand(rand());
	int amount = 0;

	cout << "Insert an amunt of numbers (>= 3): ";
	cin >> amount;
	while (amount < 3)
	{
		cout << "Error! Insert an amunt of numbers (>= 3): ";
		cin >> amount;
	}

	int *arr_Numbers = new int[amount];
	GenerateArray(arr_Numbers, amount);

	ShowArrayInfo(arr_Numbers, amount);
	WriteArrayInfo(arr_Numbers, amount);

	CNumbs maxThree;

	cout << endl;
	cout << "Max three nums anf result:\n";
	maxThree.BiggestNum(arr_Numbers, amount);
	maxThree.ShowInfo();
	
	maxThree.WriteInfo();

	delete[] arr_Numbers;
	_getch();
  return 0;
}