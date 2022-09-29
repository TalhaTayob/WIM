#include "RandomizeFreqs.h"

RandomizeFreqs::RandomizeFreqs(vector<CellCollective*> CellList) {
	cellList = CellList;
	//srand(time(NULL));
	for (auto i : cellList) {
		int randN = rand()%6+110;
		i->getCell()->freq = randN;
		//cout << randN << endl;
	}
}