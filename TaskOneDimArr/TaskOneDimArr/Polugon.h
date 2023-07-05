#pragma once

#include <fstream>

using namespace std;

typedef struct _SPoint
{
	int x;
	int y;

	_SPoint() { x = y = 0; }
} SPoint;


class CPolygon
{
public:
	int m_iNum;
	SPoint* m_aVerts;
	ifstream inFile;

	CPolygon();
	~CPolygon();

	void ReadFile();

	void ShowWriteInfo();

	void LocationInfo(SPoint pnt);
};

