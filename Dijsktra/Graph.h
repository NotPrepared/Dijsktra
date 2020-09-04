#pragma once
#include "Knoten.h"
#include <vector>
#include <list>
#include <map>
#include <set>
class Graph
{
public:
	Graph(vector<Knoten*> knoten);
	~Graph();
	void dijsktra(Knoten* startknoten);

	bool isInClosed(Knoten * knoten);

	bool isInOpen(Knoten * knoten);

private:
	vector<Knoten*> m_knotenliste;
	vector<Knoten*> m_closedList;
	vector<Knoten*> m_openList;
}; 

