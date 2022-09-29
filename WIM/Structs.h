#pragma once

using namespace std;

struct Cell {
	int easting, northing, cellID;
	double longi, lat;
	string cellName;
	int freq;
};

struct Dist {
	int distID;
	Cell* left;
	Cell* right;
	double dist;
};