#include "Imports.h"
#include "CellList.h"


CellList::CellList(string fileName) {

	readFromFile(fileName);

}

void CellList::readFromFile(const string fileName) {
	ifstream inFile(fileName);

	string line;
	while (getline(inFile, line))
	{

		int value = 0, cellID = 0;

		istringstream ss(line);
		string token, cellName;
		int northing = 0, easting = 0;
		double lat = 0, longi = 0;
		bool firstLine = false;
		while (getline(ss, token, ',')) {
			firstLine = false;
			switch (value) {
			case 0:
				cellName = token;
				value++;
				break;
			case 1:
				easting = stoi(token);
				value++;
				break;
			case 2:
				northing = stoi(token);
				value++;
				break;
			case 3:
				longi = stof(token);
				value++;
				break;
			case 4:
				lat = stof(token);
				break;
			default:
				cout << "what did you do wrong?" << endl;
			}

		}
		cellList.push_back(new CellCollective(cellID, cellName, easting, northing, longi, lat));
	}

	inFile.close();

}

void CellList::findDistances() {
	int arrSize = static_cast<int>(cellList.size());
	int distID = 0;
	double totalDist = 0;
	shortestDist = numeric_limits<double>::max();
	longestDist = numeric_limits<double>::min();
	for (int i = 0; i < arrSize - 1; i++) {
		for (int j = i + 1; j < arrSize; j++) {
			Dist* dist = new Dist();
			dist->distID = distID;
			dist->left = cellList.at(i)->getCell();
			dist->right = cellList.at(j)->getCell();
			dist->dist = static_cast<double>(sqrt(pow(cellList.at(i)->getCell()->easting - cellList.at(j)->getCell()->easting, 2) + 
				pow(cellList.at(i)->getCell()->northing - cellList.at(j)->getCell()->northing, 2)));
			cellList.at(i)->addDist(dist);
			cellList.at(j)->addDist(dist);
			allDistList.push_back(dist);
			totalDist += dist->dist;
			if (dist->dist > longestDist) {
				longestDist = dist->dist;
			}
			else if (dist->dist < shortestDist) {
				shortestDist = dist->dist;
			}
			distID++;
		}
	}
	averageDist = totalDist / distID;
}

double CellList::getAverageDist() {
	return averageDist;
}

double CellList::getLongestDist() {
	return longestDist;
}

double CellList::getShortestDist() {
	return shortestDist;
}

void CellList::printList() {
	for (auto i : cellList) {
		i->printCell();
	}
}

void CellList::printDistances(vector<Dist*> cells) {
	for (auto i : cells) {
		cout << "Distance ID: " << i->distID << ", Left Cell Name: " << i->left->cellName << ", Right Cell Name: " 
			<< i->right->cellName << ", Distance: " << i->dist << ", Left Freq:" << i->left->freq << ", Right Freq:" 
			<< i->right->freq << endl;
	}
}

vector<CellCollective*> CellList::getCellList() {
	return cellList;
}

vector<Dist*> CellList::getAllDistList() {
	return allDistList;
}