/*
 * Listaestudiantes.h
 *
 *  Created on: 30/3/2016
  *      Author: Javier Ballesteros Morón
				Carlos Licha de la Encarnación
 */

#ifndef LISTAESTUDIANTES_H_
#define LISTAESTUDIANTES_H_

#include "ilist.h"
#include "student.h"
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <string>


using namespace std;

/*Esta clase está diseñada para utilizar una lista con punto de interés con la función específica de administar Student* es decir,
 * estudiantes por orden de nota de mayor a menor, para ello cuenta con multitud de métodos extrapolados de ésta como
 * moveToBegin(), next(),back() y otros que ayudan a facilitar el trabajo de las clases contenedoras de ésta como first() o removefirst(),
 * consult().
 * Su único método de inserción es InsertInOrder ya que queremos que esté ordenada por nota de los estudiantes.
 */




class SList{
private:
	IList<Student*> *l;
	int tamanio;

public:

	SList();
	//Si el parámetro introducido es 1 se cargarán los estudiantes del archivo de texto "students.txt"
	//En caso contrario cargará 10 estudiantes creados específicamente para hacer pruebas
	SList(int i);

	~SList();

	//POST: Añade a un estudiante a la lista, la cual está ordenada por notas.
	//Complejidad:O(n)
	void insertInOrder(Student *&s);

	//POST: Muestra todos los estudiantes de la lista, si está vacía lo notifica por pantalla
	//Complejidad:O(n)
	void show();

	//Devuelve el atributo tamanio
	//Complejidad:O(1)
	int getTamanio() const;

	//Devuelve el primero de la lista como parámetro
	//Complejidad:O(1)
	void first(Student *&s);

	//Devuelve el último de la lista como parámetro
	//Complejidad:O(1)
	void last(Student *&s);


	//POST: Mueve el punto de interés al final de la lista
	//COMP:   O(1)
	bool end();

	//POST: Avanza una posición el punto de interés en la lista
	void next();

	//POST: Retrasa una posición el punto de interés en la lista
	//COMP:   O(1)
	void back();

	//POST: Mueve el punto de interés a la primera posición de la lista
	//COMP:   O(1)
	void moveToBegin();

	//PRE: list empty() != false
	//POST: Devuelve en el parámetro de salida el Student del nodo al que esté apuntando el punto
	 //de interés
	// COMP:   O(1)
	void consult(Student *&aux);



	//Elimina el primero de la lista(nodo)
	//Complejidad:O(1)
	void removefirst();

	//Elimina el último de la lista(nodo)
	//Complejidad:O(1)
	void removelast();

	//Si la lista está vacia devuelve true, si no, devuelve false
	//Complejidad:O(1)
	bool empty();

	//Si el estudiante está en esta lista lo elimina y devuelve true, si no está devuelve false
	//Complejidad:O(n)
	bool removeStudent(Student *&s);



};

#endif /* LISTAESTUDIANTES_H_ */
