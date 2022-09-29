#include "AssignFreqeuncies.h"

AssignFreqeuncies::AssignFreqeuncies(vector<Dist*> allDistList, double averageDist, double longestDist, double shortestDist) {

	int freq1, freq2;

	for (auto i : allDistList) {

		int fg = round((-5.0 / (longestDist - shortestDist)) * (i->dist- shortestDist)) + 5;


		if (i->left->freq == 0 && i->right->freq == 0) {
			int freq1 = findBaseFreq(fg);
			i->left->freq = freq1;
			i->right->freq = freq1+fg;
		}
		else if (i->left->freq == 0 && i->right->freq != 0) {
			if (i->right->freq >= 113) {
				i->left->freq = i->right->freq - fg;
			}
			else {
				i->left->freq = i->right->freq + fg;
			}
		}
		else if (i->left->freq != 0 && i->right->freq == 0) {
			if (i->left->freq >= 113) {
				i->right->freq = i->left->freq - fg;
			}
			else {
				i->right->freq = i->left->freq + fg;
			}
		}
	}
}

int AssignFreqeuncies::findBaseFreq(int fg) {
	int freq1 = 0;
	switch (fg) {
	case 0:
		freq1 = 113;
		break;
	case 1:
		freq1 = 111;
		break;
	case 2:
		freq1 = 110;
		break;
	case 3:
		freq1 = 111;
		break;
	case 4:
		freq1 = 111;
		break;
	case 5:
		freq1 = 110;
		break;
	default:
		cout << "ERROR" << endl;
	}
	return freq1;
}
