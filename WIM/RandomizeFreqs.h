#pragma once
#include "Imports.h"
#include "CellCollective.h"
class RandomizeFreqs
{
public:
	RandomizeFreqs(vector<CellCollective*> CellList);
private:
	vector<CellCollective*> cellList;
	vector<Dist*> allDistList;
};

