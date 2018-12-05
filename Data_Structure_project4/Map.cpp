#include "Map.h"

#include<fstream>
#include<sstream>

using std::map;
using std::set;
using std::pair;
using std::vector;
using std::tuple;
using std::ifstream;
using std::ios;
using std::string;
using std::stringstream;

const string filename = "Map.csv";

Map::Map()
{
	//Build the Map from filename;
	ifstream inFile(filename, ios::in);
	string information;
	getline(inFile, information);
	while (getline(inFile, information))
	{
		Node node;
		string temp;
		stringstream ss(information);
		getline(ss, temp, ',');
		const char *cstr = temp.c_str();
		int first, second;
		sscanf_s(cstr, "%d %d", &first, &second);
		Coordinate point(first, second);
		node.coordinate = point;

		getline(ss, temp, ',');
		node.name = temp;

		getline(ss, temp, ',');
		//int choice;
		if (temp == "Place") {
			//choice = 0;
			node.type = Place;
		}
		else if (temp == "Restaurant") {
			//choice = 1;
			node.type = Restaurant;
		}
		else if (temp == "WC") {
			//choice = 2;
			node.type = WC;
		}
		else if (temp == "Parking_lot") {
			//choice = 3;
			node.type = Parking_lot;
		}
		else if (temp == "Smarket") {
			//choice = 4;
			node.type = Smarket;
		}
		else {
			//choice = 5;
			node.type = Point;
		}

		getline(ss, temp, ',');
		node.info = temp;

		while (getline(ss, temp, ',')) {
			const char *_cstr = temp.c_str();
			int a, b, c;
			sscanf_s(_cstr, "%d %d %d", &a, &b, &c);
			Coordinate p(a, b);
			tuple <Coordinate, int> pt(p, c);
			node.neighbors.insert(pt);
		}

		adj_Matrix[point] = node;
	}
}
