#include "CellCollective.h"

CellCollective::CellCollective(int CellID, string CellName, int Easting, int Northing, double Longi, double Lat) {
	cell->easting = Easting;
	cell->northing = Northing;
	cell->longi = Longi;
	cell->lat = Lat;
	cell->cellID = CellID;
	cell->cellName = CellName;
	cell->freq = 0;
}

void CellCollective::addDist(Dist* dist) {
	distList.push_back(dist);
}

Cell* CellCollective::getCell() {
	return cell;
}

void CellCollective::setCell(Cell* Cell) {
	cell = Cell;
}

void CellCollective::printCell() {
	cout << "Name: " << cell->cellName << ", cellID: " << cell->cellID << ", Easting: " << cell->easting << ", Northing: " << cell->northing
		<< ", Longitude: " << cell->longi << ", Latitude: " << cell->lat << ", Freq: " << cell->freq << endl;
}

void CellCollective::printCellDistances() {
	cout << "Cell Name: " << cell->cellName << endl;
	for (auto i : distList) {
		cout << "Distance ID: " << i->distID << ", Left Cell Name: " << i->left->cellName << ", Right Cell Name: " << 
			i->right->cellName << ", Distance: " << i->dist << endl << endl;
	}
}