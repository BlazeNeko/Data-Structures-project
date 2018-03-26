/*
 * Grados.h
 *
 *  Created on: 30/3/2016
 *      Author: Javier Ballesteros Morón
				 Carlos Licha de la Encarnación
 */

#ifndef GRADO_H_
#define GRADO_H_

#include "ListaEstudiantes.h"
#include "ListaAdmitidos.h"
#include "string"
#include "BstreeStudent.h"
#include <sstream>
#include <fstream>
using namespace std;

/*Clase pensada para administrar los Student*,  los estudiantes de un modo aún más abstracto, es decir utilizando como atributos instancias
 * de clases que administran estudiantes, el propósito de la clase es administrar sus listas y estudiantes como lo haría un grado real,
 * por tanto tiene un código de identificación ID, un nombre (name) , un número de plazas que puede ofrecer  y estructuras de datos
 * que administren a los estudiantes que quieren acceder a dicho grado.
 *
 * La clase cuenta con métodos para mostrar, para administrar sus estructuras de datos y para complementar el proceso de Asignación de
 * estudiantes y Matriculación necesarias .
 *
 */




class Grado {
private:
	int ID;                //Código de identificación del grado
	string name;			//Nombre del grado
	int plazasDisp;			//Número de plazas disponibles que tiene inicialmente el grado
	AList *al;				//Lista de admitidos del grado con tamaño máximo igual a las plazas disponibles ordenada por nota de los student
	SList *waitl;			//Lista de espera del grado, sin tamaño máximo, ordenada por nota de los student
	BstreeStudent *at;      //Arbol de admitidos usado durante y después de la matriculación ordenado por apellidos y nombre de los student
	BstreeStudent *wt;		//Arbol de admitidos usado durante y después de la matriculación ordenado por apellidos y nombre de los student

public:
	Grado();

	//Constructor que designa la id del grado, su nombre y el tamaño de la lista de admitidos y el número de plazas disponibles
	//Además inicializa todas las estructuras de datos como vacías
	//ESTE ES EL
	Grado(int ID, string name, int plazasDisp);
	~Grado();

	//Este es el método que se llama desde la interfáz del menú principal tras seleccionar la opción 7 y el grado
	//PRE: al->empty() == false
	//POST: Muestra en pantalla a todos los estudiantes cuyo apellido empiece por la cadena introducida
	//pertenecientes a al(lista de admitidos) si no hay ninguno lo muestra por pantalla
	//complejidad o(log n)
	void show_by_similarities(string surname);

	//PRE: at->empty() == false, at contiene el student con los parámetros introducidos
	//POST: Si el student se encuentra en at (árbol de admitidos) lo elimina, y si la lista de espera no está vacía inserta en la lista de
	//admitidos al de mayor nota y lo borra de  wt (arbol de espera)
	//Si el student se encuentra en at (arbol de admitidos) lo elimina, y si la lista de espera  está vacía  no hace nada más
	//Si el student no se encuentra en at muestra un error de renuncia por pantalla
	//complejidad o(log n)
	void gives_up(string surn1, string surn2, string name, string dni);

	//POST: Muestra por pantalla el nombre del grado y los student de su árbol de admitidos
	//complejidad o(log n)
	void show_at();

	//PRE: at->empty() == false
	//POST: Si el estudiante con los parámetros introducidos pertenece al árbol de admitidos at lo elimina.
	//complejidad o(log n)
	void remove_at(string surn1, string surn2, string name);

	//PRE: wt->empty() == false
	//POST: Si el estudiante con los parámetros introducidos pertenece al árbol de espera wt lo elimina.
	//Y si es el primero de la lista de espera también, para reducir aún mas la complejidad del algoritmo.
	//complejidad o(log n)
	void remove_wt(string surn1, string surn2, string name);

	//PRE: at->empty() = false , at contiene al estudiante con los parámetros introducidos
	//POST:Si las precondiciones se cumplen elimina al estudiante de la lista de admitidos at y
	//lo escribe en el archivo de texto correspondiente a la ID del grado en el que está,
	//Si las precondiciones no se cumplen muestra por pantalla  que hay un error.
	//complejidad o(log n)
	void admitted(string surn1, string surn2, string name, string dni);

	//PRE: Estudiante creado con todos los datos.
	//Post: Coloca al estudiante en la lista de espera o la lista de admitidos, según su nota y si hay hueco o no
	//Complejidad:o(n)
	bool addStudent(Student *&s, Student *&exit);

	//PRE: El estudiante que se quiere eliminar debe estar en la lista al
	//Post: Elimina al estudiante s del grado
	//Complejidad:O(1)
	void removeStudent(Student *&s);

	//PRE:al->empty() = false
	//POST: devuelve en el parámetro e salida el primer estudiante de la lista waitl
	//Complejidad:O(1)
	void firstWaitl(Student *&s);

	//Getters de los atributos
	//Complejidad:O(1)
	int getId() const;

	const string& getName() const;

	int getPlazasDisp() const;

	//PRE:Al menos un estudiante en al.
	//Post:Devuelve notaMinima de al. Si al está vacía, la nota sera 0
	//Complejidad:O(1)
	float notaCorte() const;

	//PRE: al->empty() == false , waitl->empty() == false,  at->empty() == true,wt->empty()== true
	//Arboles vacíos y listas que no lo estén.
	//POST: Copia todo el contenido de al a at (lista de admitidos a árbol de admitidos)
	//y de waitl a wt (lista de espera a árbol de espera)
	//complejidad o(log n)
	void insertTrees();

	//PRE: at->empty() == false
	//POST:Devuelve la nota del estudiante con menor nota de todo at (árbol de admitidos)
	//complejidad o(n)
	float get_tree_min_grade() const;

	//POST: Muestra la información del grado incluido el contenido de su lista al(lista admitidos) y waitl(lista espera)
	//Complejidad:O(N)
	void show();
};

#endif /* GRADO_H_ */
