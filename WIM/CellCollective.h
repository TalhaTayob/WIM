#pragma once
#include "Imports.h"

class CellCollective
{
private:
	Cell* cell = new Cell;
	vector<Dist*> distList;
public:
	CellCollective(int CellID, string CellName, int Easting, int Northing, double Longi, double Lat);
	void addDist(Dist* dist);
	Cell* getCell();
	void setCell(Cell* Cell);
	void printCell();
	void printCellDistances();
};
