#include "ShortToLong.h"

ShortToLong::ShortToLong(vector<CellCollective*> CellList, vector<Dist*> AllDistList) {
	cellList = CellList;
	allDistList = AllDistList;
	orderShortToLong();
}

void ShortToLong::orderShortToLong() {
	sort(allDistList.begin(), allDistList.end(), compareDist);
}

vector<Dist*> ShortToLong::getOrderedDistList() {
	return allDistList;
}

void ShortToLong::printList() {
	for (auto i : allDistList) {
		cout << "Distance ID: " << i->distID << ", Left Cell Name: " << i->left->cellName << ", Right Cell Name: "
			<< i->right->cellName << ", Distance: " << i->dist << endl << endl;
	}
}

inline bool ShortToLong::compareDist(const Dist* left, const Dist* right) { return (left->dist < right->dist); }