#include "LocationGraph.h"
#include <algorithm>

// *** currently not in use. Probably won't be? Don't want to delete just yet... **** //


//void AddEdge(Node& s, Node& d, Graph& g) {
//	auto it = std::find_if(g.nodeVec.begin(),
//		g.nodeVec.end(),
//		find_node(s));
//
//	if (it != g.nodeVec.end()) {
//		// check if source node is already connected to the destination node
//		// throw if that's the case - error in Game Data
//		auto k = std::find_if(s.connectedNodes.begin(),
//			s.connectedNodes.end(),
//			find_node(d));
//
//		if (k != s.connectedNodes.end()) {
//			std::cout << s.name << " already has Node " << d.name << '\n';
//			exit(EXIT_FAILURE);
//		}
//
//		// check if destination node already exists in graph. If that's the case,
//		// then just connect these nodes
//		auto j = std::find_if(g.nodeVec.begin(),
//			g.nodeVec.end(),
//			find_node(d));
//
//		if (j != g.nodeVec.end()) {	// if destination node also exists in graph, then just connect nodes
//			s.connectedNodes.push_back(d);
//			//auto p = std::find_if(g.nodeVec.begin(), 
//			//	g.nodeVec.end(), 
//			//	[&s](const Node& a) { return a.name == s.name; });
//
//			j->connectedNodes.push_back(s);
//			//it->connectedNodes.push_back(d);
//			//if (p != g.nodeVec.end()) {
//			//	p->connectedNodes.push_back(d);
//			//}
//
//			d.connectedNodes.push_back(s);
//			Edge n(s, d);
//			Edge e(d, s);
//			g.edgeVec.push_back(n);
//			g.edgeVec.push_back(e);
//		}
//		else {	// otherwise connect nodes and add the node to the graph
//			s.connectedNodes.push_back(d);
//			d.connectedNodes.push_back(s);
//			g.nodeVec.push_back(d);
//			Edge n(s, d);
//			Edge e(d, s);
//			g.edgeVec.push_back(n);
//			g.edgeVec.push_back(e);
//		}
//	}
//	else {	// if node doesn't exist, connect it to it's destination node and add both to graph
//		s.connectedNodes.push_back(d);
//		d.connectedNodes.push_back(s);
//		//j->connectedNodes.push_back(s);
//		//it->connectedNodes.push_back(d);
//		g.nodeVec.push_back(s);
//		g.nodeVec.push_back(d);
//		Edge n(s, d);
//		Edge e(d, s);
//		g.edgeVec.push_back(n);
//		g.edgeVec.push_back(e);
//	}
//}

void AddE(Node& s, Node& d, Graph& g) {
	std::unordered_map<std::string, std::vector<Node>>::iterator t = g.map.find(s.name);
	
	if (t != g.map.end()) {
		// check if source is already connected to destination node, throw if that's the case
		auto k = g.map.find(s.name)->second;
		for (auto n : k) {
			if (d == n) {
				std::cout << s.name << " already has node " << d.name << '\n';
				exit(EXIT_FAILURE);
			}
		}

		// otherwise, the destination already exists in the map and we just
		// need to connect both OR destination node doesn't exist and we need
		// to connect both. Either way, this is solved by the following
		g.map[d.name].push_back(s);
		g.map[s.name].push_back(d);

		//// check if destination node already exists in map, if so, connect both
		//std::unordered_map<std::string, std::vector<Node>>::iterator j = g.map.find(d.name);

		//if (j != g.map.end()) {
		//	g.map[d.name].push_back(s);
		//	g.map[s.name].push_back(d);
		//}
		//else {	// if not, connect nodes and add destination node to graph
		//	g.map[d.name].push_back(s);
		//	g.map[s.name].push_back(d);

		//}



	}
	else {
		g.map[s.name].push_back(d);
		g.map[d.name].push_back(s);

	}

}