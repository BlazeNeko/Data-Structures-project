/*
 * ListaAdmitidos.h
 *
 *  Created on: 30/3/2016
 *      Author: Javier Ballesteros Morón
				Carlos Licha de la Encarnación
 */

#ifndef LISTAADMITIDOS_H_
#define LISTAADMITIDOS_H_

#include "ListaEstudiantes.h"

/*Esta clase AList (lista de admitidos) está ideada para actuar como atributo de la clase Grado y funciona de una forma muy similar a
 * la clase SList(Lista de estudiantes) ya que es una estructura de datos lineal que administra a los Student* (Estudiantes) por nota de
 * mayor a menor
 * La diferencia con esta clase es que cuenta con un tamaño máximo y un atributo notaMinima el cual nos dice la nota del último estudiante
 * de la lista. Por tanto cuenta con métodos para saber si la lista está llena, vacía y para obtener y eliminar al último estudiante
 * de la lista pues el punto caliente de esta es siempre su última posición que es la que tiene mayor número de transiciones y
 * aplicaciones en las clases contenedoras. Como nace de la clase SList (Lista de estudiantes) contiene múchos métodos que son
 * directamente extrapolados de esta.
 *
 */

using namespace std;

class AList{
private:
	int maxtamanio;
	float notaMinima;
	SList *admitidos;

public:
	//POST: Crea una lista de estudiantes admitidos vacia
	AList();

	//POST: Crea una lista de estudiantes admitidos dada previamente una lista de estudiantes
	AList(SList *sl);

	AList(int maxtamanio);

	~AList();
	//PRE: Admitidos->tamanio != maxtamanio
	//Post: A�ade a un estudiante a la lista de admitidos
	//Complejidad:o(1)
	void addStudent(Student *&s);

	//POST:Devuelve la nota minima
	//Complejidad:O(1)
	float getNotaMinima() const;

	//POST:Devuelve Maxtamanio
	//Complejidad:O(1)
	int getMaxtamanio() const;
	int getTamanioLE()const;

	//devuelve true si la lista esta llena false en caso contrario
	//Complejidad:O(1)
	bool full();

	//Elimina el último de la lista(nodo)
	//Complejidad:O(1)
	void removelast();

	//Devuelve el último de la lista como parametro
	//Complejidad:O(1)
	void last(Student *&s);


	//POST: Muestra la lista entera de estudiantes, incluyendo la nota del último estudiante
	 //y el tamaño actual y máximo que puede tener
	//Complejidad:O(1)
	void show();

	//POST: Mueve el punto de interés de admitidos al inicio de la lista
	void moveToBegin();

	//PRE: admitidos->empty() == false admitidos->end() ==false
	//POST: mueve una posición hacia adelante el punto de interés
	void next();

	//POST: Devuelve true si el punto de interés está al final de la lista
	//y false en caso contrario
	bool end();

	//PRE: admitidos->empty() == false
	//POST:Devuelve el estudiante cuyo nodo ese en el punto de interés.
	void consult(Student *& s);

	//Si el estudiante está en esta lista lo elimina y devuelve true , si no está devuelve false
	//Complejidad:O(1)
	bool removeStudent(Student *&s);



};



#endif /* LISTAADMITIDOS_H_ */
