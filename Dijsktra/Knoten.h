#pragma once
#include <vector>
#include <map>
#include <string>
using namespace std;
class Knoten
{
public:
	Knoten(int coordX, int coordY, string name);
	~Knoten();
	int getX();
	int getZ();
	float getC();
	map<Knoten*, float> getNachbarKnoten();
	void setC(float c);
	void addNachbar(Knoten* nachbar);
	string getName();
private:
	string m_name;
	int m_coordX;
	int m_coordZ;
	std::map<Knoten*, float> m_nachbarknoten;
	float m_aktuelleKosten; //c
};

