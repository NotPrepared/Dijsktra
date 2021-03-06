// Dijsktra.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "Graph.h"
#include "Knoten.h"


int main()
{
	Knoten* a = new Knoten(12, 2, "a");
	Knoten* b = new Knoten(5, 5, "b");
	Knoten* c = new Knoten(20, 5, "c");
	Knoten* d = new Knoten(3, 10, "d");
	Knoten* e = new Knoten(10, 10, "e");
	Knoten* f = new Knoten(16, 10, "f");
	Knoten* g = new Knoten(5, 15, "g");
	Knoten* h = new Knoten(13, 15, "h");
	Knoten* i = new Knoten(20, 13, "i");
	Knoten* j = new Knoten(9, 20, "j");
	Knoten* k = new Knoten(20, 20, "k");
	
	a->addNachbar(b);
	a->addNachbar(c);
	b->addNachbar(d);
	b->addNachbar(e);
	c->addNachbar(i);
	c->addNachbar(e);
	d->addNachbar(g);
	e->addNachbar(f);
	e->addNachbar(e);
	f->addNachbar(h);
	g->addNachbar(h);
	g->addNachbar(j);
	h->addNachbar(i);
	h->addNachbar(k);
	i->addNachbar(k);
	
	vector<Knoten*> knotenliste;
	knotenliste.push_back(a);
	knotenliste.push_back(b);
	knotenliste.push_back(c);
	knotenliste.push_back(d);
	knotenliste.push_back(e);
	knotenliste.push_back(f);
	knotenliste.push_back(g);
	knotenliste.push_back(h);
	knotenliste.push_back(i);
	knotenliste.push_back(j);
	knotenliste.push_back(k);

	Graph* dijkstragraph = new Graph(knotenliste);
	dijkstragraph->dijsktra(a);

    return 0;
}

