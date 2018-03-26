/*
 * Colapreferencias.cpp
 *
 *  Created on: 22 de mar. de 2016
 *      Author: Javier Ballesteros Morón
				Carlos Licha de la Encarnación
 */

#include "Colapreferencias.h"

namespace std {

Cola_preferencias::Cola_preferencias() {
	// TODO Auto-generated constructor stub

}

Cola_preferencias::~Cola_preferencias() {
	// TODO Auto-generated destructor stub
}

void Cola_preferencias::insertar(int id) {

	if(id>=1 && id<=7 )
	cola.enqueue(id);

	else{
		cout<<"El grado introducido no existe..."<<endl;
	}
}

int Cola_preferencias::primero() {
	int n;
	if(cola.empty())
		n=-1;

	else{
		n = cola.front();
	}
	return n;
}

void Cola_preferencias::desencolar() {
	return cola.dequeue();
}

void Cola_preferencias::mostrar() {
	Queue<int> aux;
	int i;

	if(cola.empty()){
		cout<<"La cola de preferencias está vacia"<<endl;

	}
	else{

	cout<<"Estos son los grados solicitados por el estudiante por orden de preferencia de izda a dcha: "	<<endl;
	while(!cola.empty()){
		cola.front(i);
		cout<<i<<"  ";
		aux.enqueue(i);
		cola.dequeue();
	}

	while(!aux.empty()){
		aux.front(i);
		cola.enqueue(i);
		aux.dequeue();
	}
	cout<<" "<<endl;
	}

}

Cola_preferencias::Cola_preferencias(int a) {
	cola.enqueue(a);
}


Cola_preferencias::Cola_preferencias(int a, int b) {
	cola.enqueue(a);
	cola.enqueue(b);
}

Cola_preferencias::Cola_preferencias(int a, int b, int c) {
	cola.enqueue(a);
	cola.enqueue(b);
	cola.enqueue(c);
}

Cola_preferencias::Cola_preferencias(int a, int b, int c, int d) {
	cola.enqueue(a);
	cola.enqueue(b);
	cola.enqueue(c);
	cola.enqueue(d);
}

Cola_preferencias::Cola_preferencias(int a, int b, int c, int d, int e) {
	cola.enqueue(a);
	cola.enqueue(b);
	cola.enqueue(c);
	cola.enqueue(d);
	cola.enqueue(e);
}

void Cola_preferencias::mostrarEX() {
	Queue<int> aux;
		int i;

		if(cola.empty()){
			cout<<"La cola de preferencias está vacia"<<endl;

		}

		else{

		cout<<"Estos son los grados solicitados por el estudiante por orden de preferencia de arriba a abajo: "	<<endl;
		while(!cola.empty()){
			cola.front(i);
			switch(i){
						case 1:
							cout<<"01# Grado en Ingenieria Informatica en Ingenieria del Software"<<endl;
							break;
						case 2:
							cout<<"02# Grado en Ingenieria Informatica en Ingenieria de Computadores"<<endl;
							break;
						case 3:
							cout<<"03# Grado en Ingenieria de Sonido e Imagen en Telecomunicacion"<<endl;
								break;
						case 4:
							cout<<"04# Grado en Ingenieria Civil Construcciones Civiles"<<endl;
							break;
						case 5:
							cout<<"05# Grado en Ingenieria Civil Hidrologia"<<endl;
							break;
						case 6:
							cout<<"06# Grado en Ingenieria Civil Transportes y Servicios Urbanos"<<endl;
							break;
						case 7:
							cout<<"07# Grado en Edificacion"<<endl;
							break;
			}


			aux.enqueue(i);
			cola.dequeue();
		}

		while(!aux.empty()){
			aux.front(i);
			cola.enqueue(i);
			aux.dequeue();
		}
		}
}

bool Cola_preferencias::vacia() {
	return cola.empty();
}

} /* namespace std */
