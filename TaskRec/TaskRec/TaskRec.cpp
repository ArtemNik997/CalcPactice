// Task ¹5
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "CheckFunc.h"

using namespace std;

int main()
{
	int num = 0;
	int sum = 0;
	int recCount = 0;
	double recTime = 0.0;
	
	cout << "Write the number: ";
	cin >> num;
	while (true)
	{
		if (num > 0)
		{
			break;
		}
		cout << "Wrong input! Try again: ";
		cin >> num;
	}
	
	cout << "Is it dividable by 3?\n";

	cout << "Recursion:\n";
	cout << " Answer:";
	if (!(RecCheckCount(num, sum, recCount, recTime) % 3)) cout << " Yes";
	else cout << " No";
	cout << endl << " Num of actions of recursion: " << recCount;
	cout << endl << " Time of recursion: " << recTime;

	cout << "\nCycle:\n";
	cout << " Answer:";
	if (!(CycleCheckCount(num, sum, recCount, recTime) % 3)) cout << " Yes";
	else cout << " No";
	cout << endl << " Num of cycles: " << recCount;
	cout << endl << " Time of cycle: " << recTime;
	
	_getch();
  return 0;
}

