#pragma once
#include "Imports.h"
#include "CellCollective.h"

class CellList
{
public:
	CellList(string fileName);
	void findDistances();
	vector<CellCollective*> getCellList();
	vector<Dist*> getAllDistList();
	double getAverageDist();
	double getLongestDist();
	double getShortestDist();

	void printList();
	void printDistances(vector<Dist*> cells);
private:
	void readFromFile(const string fileName);
	//bool is_number(const string& s);

	double averageDist, longestDist, shortestDist;
	vector<CellCollective*> cellList;
	vector<Dist*> allDistList;
};
