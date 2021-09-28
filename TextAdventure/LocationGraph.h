#pragma once

#include <iostream>
#include <vector>
#include <entt/entt.hpp>
#include <memory>
#include <unordered_map>
#include <algorithm>

// entire file likely obsolete at this point. Not deleting just yet... Original solution for connecting 
// locations was a graph implementation

struct Location;

struct Node {
	entt::entity Location;
	std::string name;
	//std::vector<Node> connectedNodes;	// obsolete?

	Node(std::string name, entt::entity& Location) :name(name), Location(Location) {}
	Node() = default;

	bool operator== (const Node& m) const {	// obsolete?
		return (Location == m.Location && name == m.name);
	}

};


struct find_node {
	Node id;
	find_node(Node& i) :id(i) {}
	bool operator() (const Node& m) const {
		return m.name == id.name;
	}
};

struct Edge {
	Node src, dest;
	Edge(Node& s, Node& d) {
		src = s;
		dest = d;
	}

	Edge() = default;
};

struct Graph {
	//std::vector<Edge> edgeVec;	// obsolete?
	//std::vector<Node> nodeVec;	// obsolete?
	std::unordered_map<std::string, std::vector<Node>> map;
};

void AddEdge(Node& s, Node& d, Graph& g);	// obsolete?

void AddE(Node& s, Node& d, Graph& g);




