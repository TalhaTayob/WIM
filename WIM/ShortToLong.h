#pragma once
#include "Imports.h"
#include "CellCollective.h"
class ShortToLong
{
public:
	ShortToLong(vector<CellCollective*> CellList, vector<Dist*> allDistList);
	vector<Dist*> getOrderedDistList();
	void printList();
	static bool compareDist(const Dist* left, const Dist* right);
private:
	vector<CellCollective*> cellList;
	vector<Dist*> allDistList;
	void orderShortToLong();
};
