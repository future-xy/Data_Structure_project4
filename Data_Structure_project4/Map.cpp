#include "Map.h"

using std::string;
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
namespace _Fc_Temp_Array_{
    Coordinate Located_Common[N];
    map<Coordinate,int> Index_Common;
    int Index_Key[N], Located_Key[N];
    bool Car_Access[N];
    double Edge_dis[N][N], Short_dis[N][N];
    double f[(1<<22)+3][20];

    int dcmp(double a){
        if ( fabs(a) < 1e-9) return 0;
        return a < 0 ? -1 : 1;
    }
} using namespace _Fc_Temp_Array_;

Map::Map(){//Build the Map from filename;
}
std::vector<Node> Map::getPlace()const{
	std::vector<Node> tot;
	for (auto item:adj_Matrix)
		if (item.second.type == Place) tot.push_back(item.second);
	return tot;
}
std::vector<Node> Map::getWC()const{
	std::vector<Node> tot;
	for (auto item:adj_Matrix)
		if (item.second.type == WC) tot.push_back(item.second);
	return tot;
}
std::vector<Node> Map::getParking_lot()const{
	std::vector<Node> tot;
	for (auto item:adj_Matrix)
		if (item.second.type == Parking_lot) tot.push_back(item.second);
	return tot;
}
std::vector<Node> Map::getSmarket()const{
	std::vector<Node> tot;
	for (auto item:adj_Matrix)
		if (item.second.type == Smarket) tot.push_back(item.second);
	return tot;
}
std::vector<Node> Map::getRestaurant()const{
	std::vector<Node> tot;
	for (auto item:adj_Matrix)
		if (item.second.type == Restaurant) tot.push_back(item.second);
	return tot;
}
std::string Map::Info(Coordinate pos) {
	if ( adj_Matrix.count(pos)) return adj_Matrix[pos].info;
		else return "";

Map::Map()
{
	//Build the Map from filename;
}
//#endif // !MAP_H
