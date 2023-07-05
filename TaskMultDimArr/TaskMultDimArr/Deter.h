#pragma once

#include <iostream>

using namespace std;

void FillArray(int*** arr, int length);

void ShowArray(int** arr, int length);

void WriteArray(int** arr, int length);

int ReadArray(int*** arr);

void DeleteArr(int** arr, int length);

int FindDeter(int** arr, int length);