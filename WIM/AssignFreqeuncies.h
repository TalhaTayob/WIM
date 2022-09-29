#pragma once
#include "Imports.h"
class AssignFreqeuncies
{
public:
	AssignFreqeuncies(vector<Dist*> allDistList, double averageDist, double longestDist, double shortestDist);
private:
	int findBaseFreq(int fg);
};

