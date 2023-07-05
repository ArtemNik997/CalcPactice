#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "FindSent.h"

using namespace std;

ifstream fileIn;
ofstream fileOut;

string ReadText()
{
	string Text = "";
	fileIn.open("text.txt");

	if (!fileIn.is_open()) { _ASSERTE(false);  return "Error"; }

	string line;
	while (getline(fileIn, line))	Text += line + "\n";
	fileIn.close();

	return Text;
}

char signs[] = { '.', '!', '?' };

bool CompStr(char cur)
{
	for (int i = 0; i < sizeof(signs) / sizeof(signs[0]); i++)
	{
		if (cur == signs[i])
			return true;
	}
	return false;
}

void FindWriteAnswer(string Text, int length) {
	if (length <= 0 || Text == "") { _ASSERT(false); return; }
	fileOut.open("answer.txt");
	int start = 0;
	int end = 0;
	bool sentNotExist = true;

	for (unsigned int i = 0; i < Text.length(); i++)
	{
		if (CompStr(Text[i]))
		{
			end = i;
			if (end - start + 1 == length)
			{
				for (int j = start; j <= end; j++)
				{
					cout << Text[j];
					if (fileOut.is_open())
					{
						fileOut << Text[j];
					}
				}
				cout << endl;
				fileOut << endl;
				sentNotExist = false;
				fileOut << endl;
			}
			if (end < Text.length() - 1 && (Text[end + 1] == ' ' || Text[end + 1] == '\n'))
			{
				start = end + 1;
				while (start < Text.length() && (Text[start] == ' ' || Text[start] == '\n'))
				{
					start++;
				}
			}
		}
	}
	if (sentNotExist)
	{
		cout << "There are no such sentences in the text";
		fileOut << "There are no such sentences in the text";
	}
	fileOut.close();
}
