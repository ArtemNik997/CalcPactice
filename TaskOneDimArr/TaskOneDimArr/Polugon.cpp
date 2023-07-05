#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "Polugon.h"

using namespace std;


CPolygon::CPolygon() { m_iNum = 0; m_aVerts = nullptr; }

CPolygon::~CPolygon() { delete[] m_aVerts; }

void CPolygon::ReadFile()
{
	inFile.open("data.txt");

	inFile >> m_iNum;

	m_aVerts = new SPoint[m_iNum];

	if (!inFile.is_open()) {
		_ASSERT(false);
		return;
	}

	for (int i = 0; i < m_iNum; i++)
	{
		inFile >> m_aVerts[i].x;
		inFile >> m_aVerts[i].y;
	}

	inFile.close();

}

void CPolygon::ShowWriteInfo() {
	for (int i = 0; i < m_iNum; i++)
	{
		cout << "Point " << i + 1 << "\n (" << m_aVerts[i].x 
			<< ", " << m_aVerts[i].y << ")\n";
	}
}

void CPolygon::LocationInfo(SPoint pnt)
{
	int d = 0;
	int outCount = 0;
	for (int i = 0; i < m_iNum; i++)
	{
		if (pnt.x == m_aVerts[i].x && pnt.y == m_aVerts[i].y)
		{
			cout << "Point is one of the vertices";
			return;
		}
		else
		{
			d = (pnt.x - m_aVerts[i].x)*(m_aVerts[i].y - m_aVerts[(i + 1) % m_iNum].y) -
				(pnt.y - m_aVerts[i].y)*(m_aVerts[i].x - m_aVerts[(i + 1) % m_iNum].x);
			if (d < 0)
			{
				cout << "Polygon is out of polygon";
				return;
			}
		}
	}
	cout << "Point is inside of the polygon";
}


