#include "stdafx.h"
#include "Graph.h"
#include <iostream>



Graph::Graph(vector<Knoten*> knoten)
{
	m_knotenliste = knoten;
}

Graph::~Graph()
{
}

void Graph::dijsktra(Knoten * startknoten)
{
	Knoten* aktiverKnoten = startknoten;  //Setze Startknoten als ersten aktiven Knoten
	aktiverKnoten->setC(0.0f);
	while(true)  //Iteratives Verfahren
	{
		m_closedList.push_back(aktiverKnoten); //Aktiver Knoten in closed list
		map<Knoten*, float> nachbarKonten = aktiverKnoten->getNachbarKnoten(); //Alle Nachbarknoten des aktiven Knoten
		map<Knoten*, float>::iterator pos;

		for (pos = nachbarKonten.begin(); pos != nachbarKonten.end(); ++pos) //Iteriere über alle Nachbarn des aktiven Knoten
		{
			if (!isInClosed(pos->first)) //Wenn der Nachbar nicht schon in der closed ist
			{
				if (!isInOpen(pos->first)) //Wenn noch nicht besucht
				{
					float distanceForNewNode = pos->second + aktiverKnoten->getC();//entfernung zu nachbarn + c des aktuellen knoten
					pos->first->setC(distanceForNewNode); //Setze c wert für nachbarn
					m_openList.push_back(pos->first);	//Nachbar in openlist
				}
				else //Wenn der Knoten schon in der OpenList ist
				{
					float distanceForNewNode = pos->second + aktiverKnoten->getC();
					if (distanceForNewNode < pos->first->getC()) //Nur wenn neues c kleiner ist als bisheriges
					{
						pos->first->setC(distanceForNewNode);
					}
				}
			}

		}
		float cMin = 99999.0f;				//Kleinstes c aus openlist aka nächster aktiver knoten
		Knoten* minCKnoten = nullptr;
		vector<Knoten*>::iterator position;
		vector<Knoten*>::iterator postodelete;
		for (position = m_openList.begin(); position != m_openList.end(); ++position) //Erhalte kleinstes C aus Openlist und setze es als aktiven Knoten
		{
			Knoten* knotenTemp = *position;
			float CTemp = knotenTemp->getC();
			if (CTemp < cMin) //Wenn c des Knoten niedriger ist als Minwert
			{
				cMin = CTemp;
				minCKnoten = knotenTemp;
				postodelete = position;
			}

		}
		aktiverKnoten = minCKnoten; //Neuer aktiver Knoten
		if (m_openList.empty()) break; //Abbruchbedingung
		m_openList.erase(postodelete); //Lösche neuen aktiven Knoten aus Openlist
	}
	//Ausgabe der Knoten
	for (int i = 0; i < m_closedList.size(); i++)
	{
		std::cout << "Knoten " << m_closedList[i]->getName() << " hat den Abstand " << m_closedList[i]->getC() << " zu A" << std::endl;
	}
	
}

bool Graph::isInClosed(Knoten* knoten)
{
	for (size_t i = 0; i < m_closedList.size(); i++)
	{
		if (m_closedList[i] == knoten) return true;
	}
	return false;
}

bool Graph::isInOpen(Knoten* knoten)
{
	vector<Knoten*>::iterator pos;
	for (pos = m_openList.begin(); pos!= m_openList.end(); ++pos)
	{
		if (*pos == knoten) return true;
	}
	return false;
}