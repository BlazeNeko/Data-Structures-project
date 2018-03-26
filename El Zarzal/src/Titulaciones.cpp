/*
 * Titulacion.cpp
 *
 *  Created on: 13 de abr. de 2016
 *      Author: carlos
 */

#include "Titulaciones.h"

using namespace std;

Titulaciones::Titulaciones() {
	// TODO Auto-generated constructor stub
	grados= new IList<Grado*>() ;
	ifstream source;
	Grado *g;

/*	Grado *g1 = new Grado(1,"Grado en Ingenieria Informatica en Ingenieria del Software",45);//40
		Grado *g2 = new Grado(2,"Grado en Ingenieria Informatica en Ingenieria de Computadores",45);//40
		Grado *g3 = new Grado(3,"Grado en Ingenieria de Sonido e Imagen en Telecomunicacion",30);//25
		Grado *g4 = new Grado(4,"Grado en Ingenieria Civil Construcciones Civiles",35);//35
		Grado *g5 = new Grado(5,"Grado en Ingenieria Civil Hidrologia",25);//25
		Grado *g6 = new Grado(6,"Grado en Ingenieria Civil Transportes y Servicios Urbanos",20);//20
		Grado *g7 = new Grado(7,"Grado en Edificacion",15);//10
		grados->insert(g7);
		grados->insert(g6);
		grados->insert(g5);
		grados->insert(g4);
		grados->insert(g3);
		grados->insert(g2);
		grados->insert(g1);

*/
	string ID;
	string name;
	string plazasDisp;

	source.open("degrees.txt",ios::in);
	grados->moveToBegin();

	while(!source.eof()){
		getline(source, ID, '#');

		if(!source.eof()){

		getline(source, name, '#');
		getline(source, plazasDisp);
		}
		g=new Grado(atoi(ID.c_str()), name, atoi(plazasDisp.c_str()));

		grados->next();
		this->grados->insert(g);


	}
	source.close();

}

Titulaciones::~Titulaciones() {
	delete grados;
	// TODO Auto-generated destructor stub
}

void Titulaciones::getGrado(int g, Grado*& grado) {
	int i=1;
	grados->moveToBegin();
	while(i<g){
		i++;
		grados->next();
	}
	grados->consult(grado);
}

void Titulaciones::showGrado(int g) {
	int i=1;
	Grado *gra;
		grados->moveToBegin();
		while(i<g){
			i++;
			grados->next();
		}
		grados->consult(gra);
		gra->show();
}


