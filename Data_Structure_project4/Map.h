#pragma once

#ifndef MAP_H
#define MAP_H

#include <map>
#include <vector>
#include <set>
#include <utility>
#include <string>
#include <tuple>

enum Type_node { Place, Point, Restaurant, WC, Parking_lot, Smarket };

typedef std::pair<int, int> Coordinate;

struct Node
{
	Coordinate coordinate;
	Type_node type;
	//-1 == footwalk
	// 1 == roadway
	std::set<std::tuple<Coordinate,int> > neighbors;
	std::string name;
	std::string info;

	//wait to be implemented
	Node() = default;
	void Init(Coordinate coordinate, Type_node type, std::set<std::tuple<Coordinate,int> >, std::string info);	
};

class Map
{
public:
	//This function is prepared for Weixing Feng
	Map();
	~Map() = default;

	//return the shortest path by driving
	std::vector<Coordinate> shortest_Navigation_Car(Coordinate from, Coordinate to) const;
	//return the shortest path by walking
	std::vector<Coordinate> shortest_Navigation_Walk(Coordinate from, Coordinate to) const;

	std::vector<Node> getPlace() const;
	std::vector<Node> getWC() const;
	std::vector<Node> getParking_lot() const;
	std::vector<Node> getSmarket() const;
	std::vector<Node> getRestaurant() const;

	std::string Info(Coordinate) const;

private:
	std::map<Coordinate, Node> adj_Matrix;
};

#endif // !MAP_H

