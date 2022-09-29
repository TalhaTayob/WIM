#pragma once
#include "Imports.h"

class ScoreSolution
{
public:
	ScoreSolution(double LongestDistance, double ShortestDistance);
	void calculateScore(vector<Dist*> allDistList);
	double getScore();
	double getIndividualScore(int fg, double dist);
private:
	double score;
	double longestDistance, shortestDistance;
};