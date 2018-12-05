#pragma once

#ifndef MAP_H
#define MAP_H

#include <map>
#include <vector>
#include <set>
#include <utility>
#include <string>
#include <tuple>
//#define che
#define debug(...) fprintf(stderr,__VA_ARGS__)

using std::vector;

enum Type_node { Place, Point, Restaurant, WC, Parking_lot, Smarket };

typedef std::pair<int, int> Coordinate;
const int N= 100;const double INF=1e9, RADIUS= 10;
struct Node
{
	Coordinate coordinate;
	Type_node type;
	//-1 == footwalk
	// 1 == roadway
	std::set<std::tuple<Coordinate,int> > neighbors;
	std::string name;
	std::string info;
};

class Map
{
public:
	//This function is prepared for Weixing Feng
	Map();
	~Map() = default;

	std::vector<Coordinate> shortest_particular(Coordinate from, Coordinate to, int op) ;

	//return the shortest path by driving
//	std::vector<Coordinate> shortest_Navigation_Car(Coordinate from, Coordinate to) ;
	//return the shortest path by walking
//	std::vector<Coordinate> shortest_Navigation_Walk(Coordinate from, Coordinate to) ;

	std::vector<Node> getPlace() const;
	std::vector<Node> getWC() const;
	std::vector<Node> getParking_lot() const;
	std::vector<Node> getSmarket() const;
	std::vector<Node> getRestaurant() const;

	std::string Info(Coordinate) ;

	Coordinate MatchSite(Coordinate) ;
    std::vector<Coordinate> shortest_Navigation_Car(
        const std::vector<Coordinate> &KeySite);
    std::vector<Coordinate> shortest_Navigation_Walk(
        	const std::vector<Coordinate> &KeySite);
private:
	std::map<Coordinate, Node> adj_Matrix;
    void BuildGraph(int n,int op);
    int Label_Common();
    int Label_Key(const std::vector<Coordinate> &KeySite);
    std::vector<Coordinate> shortest_particular(const vector<Coordinate> &KeySite ,int op);

	void Walk_Along_Shortest(int n,int from, int to, std::vector<int> &);
	double distance(Coordinate , Coordinate);
};

#endif // !MAP_H

