/*
 * Colapreferencias.h
 *
 *  Created on: 22 de mar. de 2016
 *      Author: Javier Ballesteros Morón
				Carlos Licha de la Encarnación
 */

#ifndef COLAPREFERENCIAS_H_
#define COLAPREFERENCIAS_H_
#include "queue.h"


/*La cola de preferencias está diseñada para almacenar las identificaciones de los grados a los que se quiere acceder
 * estos grados están asignados a valores enteros del 1 al 7 y son los siguientes
 *
 * 01#Grado en Ingeniería Informática en Ingenieria del Software
02#Grado en Ingeniería  Informática en Ingenieria de Computadores
03#Grado en Ingeniería  de Sonido e Imagen en Telecomunicación
04#Grado en Ingeniería  Civil Construcciones Civiles
05#Grado en Ingeniería  Civil Hidrologia
06#Grado en Ingeniería  Civil Transportes y Servicios Urbanos
07#Grado en Edificación

Si el entero introducido no coincidiese con ninguno de estos no dejaría introducirlo e informaria del error por pantalla
 *
 */
namespace std {

class Cola_preferencias {

private:
	Queue<int> cola;


public:
	Cola_preferencias();

	//PRE: Parámetros de entrada int>=1 y int<=7
	//POST:Crea una lista con los parámetros introducidos con prioridad de izda a dcha
	//complejidad O(1)
	Cola_preferencias(int a);

	//PRE: Parámetros de entrada int>=1 y int<=7
	//POST:Crea una lista con los parámetros introducidos con prioridad de izda a dcha
	//complejidad O(1)
	Cola_preferencias(int a,int b);

	//PRE: Parámetros de entrada int>=1 y int<=7
	//POST:Crea una lista con los parámetros introducidos con prioridad de izda a dcha
	//complejidad O(1)
	Cola_preferencias(int a,int b,int c);

	//PRE: Parámetros de entrada int>=1 y int<=7
	//POST:Crea una lista con los parámetros introducidos con prioridad de izda a dcha
	//complejidad O(1)
	Cola_preferencias(int a,int b,int c,int d);

	//PRE: Parámetros de entrada int>=1 y int<=7
	//POST:Crea una lista con los parámetros introducidos con prioridad de izda a dcha
	//complejidad O(1)
	Cola_preferencias(int a,int b,int c,int d,int e);


	~Cola_preferencias();

	//PRE:  id>0 y <8 para que se inserte realmente
	//POST: inserta en la cola la id del grado deseado
	//complejidad O(1)
	void insertar(int id);

	//PRE: cola.empty() == false;
	//POST: Devuelve el valor de la primera id de la cola
	//complejidad O(1)
	int primero();

	//PRE: cola.empty() == false;
	//POST: Elimina la primera id de la cola
	void desencolar();

	//POST: Muestra por orden de prioridad de izquierda a derecha las id de los grados a los que queremos acceder
	// si esta vacia lo mostrara por mensaje
	//complejidad O(n)
	void mostrar();

	//POST: Muestra por orden de prioridad de arriba a abajo las id de los grados a los que queremos acceder y su nombre
		// si esta vacia lo mostrara por mensaje
	//complejidad O(n)
	void mostrarEX();

	//POST: devuelve true si la cola está vacia y false si no lo está
	//complejidad O(1)
	bool vacia();
};

} /* namespace std */

#endif /* COLAPREFERENCIAS_H_ */
