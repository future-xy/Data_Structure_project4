#pragma once

#ifndef MAP_H
#define MAP_H

#include <map>
#include <vector>
#include <set>
#include <utility>
#include <string>

enum Type_node { Place, Point, Restaurant, WC, Parking_lot, Smarket };

struct Node
{
	int x, y;
	Type_node type;
	std::set<std::pair<int, int> > neighbors;
	std::string name;
	std::string info;

	//wait to be implemented
	void Init(int x, int y, Type_node type, std::set<std::pair<int, int> >, std::string info);	
};

class Map
{
public:
	//These two functions are prepared for Weixing Feng
	Map();
	~Map();

	
	std::vector<std::pair<int, int> > shortest_Navigation(std::pair<int, int> from, std::pair<int, int> to);
	
	std::vector<Node> Place() const;
	std::vector<Node> WC() const;
	std::vector<Node> Parking_lot() const;
	std::vector<Node> Smarket() const;
	std::vector<Node> Restaurant() const;

	std::string Info(std::pair<int, int>);
	
private:
	std::map<std::pair<int, int>, Node> adj_Matrix;
};

#endif // !MAP_H

