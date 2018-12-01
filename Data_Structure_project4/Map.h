#pragma once

#ifndef MAP_H
#define MAP_H

#include <map>
#include <vector>
#include <set>
#include <utility>
#include <string>

enum Type_node { Place, Point, Restaurant, WC, Parking_lot, Smarket };

typedef std::pair<int, int> Coordinate;

struct Node
{
	Coordinate coordinate;
	Type_node type;
	std::set<Coordinate> neighbors;
	std::string name;
	std::string info;

	//wait to be implemented
	Node() = default;
	void Init(Coordinate coordinate, Type_node type, std::set<Coordinate>, std::string info);	
};

class Map
{
public:
	//These two functions are prepared for Weixing Feng
	Map();
	~Map();


	std::vector<Coordinate > shortest_Navigation(Coordinate from, Coordinate to);

	std::vector<Node> Place() const;
	std::vector<Node> WC() const;
	std::vector<Node> Parking_lot() const;
	std::vector<Node> Smarket() const;
	std::vector<Node> Restaurant() const;

	std::string Info(Coordinate);

private:
	std::map<Coordinate, Node> adj_Matrix;
};

#endif // !MAP_H

