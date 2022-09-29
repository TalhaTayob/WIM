#include "ScoreSolution.h"

ScoreSolution::ScoreSolution(double LongestDistance, double ShortestDistance) {
	score = 0;
	shortestDistance = ShortestDistance;
	longestDistance = LongestDistance;

}

void ScoreSolution::calculateScore(vector<Dist*> allDistList) {
	for (auto i : allDistList) {
		score = score + getIndividualScore(abs(i->left->freq - i->right->freq), i->dist);
	}
}

double ScoreSolution::getScore() {
	return score;
}

double ScoreSolution::getIndividualScore(int fg, double dist) {
	double indiScore = 0;

	switch (fg) {
	case 0:
		indiScore = (100 / (longestDistance - shortestDistance)) * dist - 50;
		break;
	case 1:
		indiScore = (66.67 / (longestDistance - shortestDistance)) * dist - 33.33;
		break;
	case 2:
		indiScore = (33.33 / (longestDistance - shortestDistance)) * dist - 16.67;
		break;
	case 3:
		indiScore = (-33.33 / (longestDistance - shortestDistance)) * dist + 16.67;
		break;
	case 4:
		indiScore = (-66.67 / (longestDistance - shortestDistance)) * dist + 33.33;
		break;
	case 5:
		indiScore = (-100 / (longestDistance - shortestDistance)) * dist + 50;
		break;
	}

	return indiScore;
}