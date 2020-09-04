#include "stdafx.h"
#include "Knoten.h"


Knoten::Knoten(int coordX, int coordY, string name)
{
	m_coordX = coordX;
	m_coordZ = coordY;
	m_aktuelleKosten = 999.0f;
	m_name = name;
}

Knoten::~Knoten()
{
}

int Knoten::getX()
{
	return m_coordX;
}

int Knoten::getZ()
{
	return m_coordZ;
}

float Knoten::getC()
{
	return m_aktuelleKosten;
}

map<Knoten*, float> Knoten::getNachbarKnoten()
{
	return m_nachbarknoten;
}

void Knoten::setC(float c)
{
	m_aktuelleKosten = c;
}

void Knoten::addNachbar(Knoten * nachbar)
{
	float x = (float)nachbar->getX();
	float z = (float)nachbar->getZ();

	float distance = 0.0f;
	x = x * x;
	z = z * z;
	distance = sqrt(x + z);
	m_nachbarknoten[nachbar] = distance;
}

string Knoten::getName()
{
	return m_name;
}
