// Task 
// Point's Location
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include "Polugon.h"

using namespace std;

int main()
{
	int n = 0;
	SPoint curPoint;
	CPolygon poly;

	poly.ReadFile();
	cout << "The polygon's vertices:\n";
	poly.ShowWriteInfo();

	cout << "\nInput the point coords:\n x = ";
	cin >> curPoint.x;
	cout << " y = ";
	cin >> curPoint.y;
	poly.LocationInfo(curPoint);

	_getch();
  return 0;
}

