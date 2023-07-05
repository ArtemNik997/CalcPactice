// TaskStr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h>
#include "FindSent.h"

using namespace std;

int main()
{
	unsigned int length = 0;
	string text = ReadText();

	cout << "Insert the number of symbols in sentence (letters, signs? including '.'): \n";
	cin >> length;

	cout << "Text: \n" << text << "\n\n" << "Answer:\n";
	FindWriteAnswer(text, length);

	_getch();
	return 0;
}

