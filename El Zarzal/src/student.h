/*
 * student.h
 *
 *  Created on: 16/2/2016
 *      Author: Javier Ballesteros Morón
				Carlos Licha de la Encarnación
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include <iostream>
#include "Colapreferencias.h"
#include "queue.h"
using namespace std;

/*La clase Student contiene la información necesaria de cada estudiante, Surn1,Surn2,Name,dni y Grade además de atributos relacionados
 * con su aceptacion en los grados:
 * 	 	accepted - nos informa si el estudiante has sido agregado en algun grado o no
 * 		daccepted - contiene la id del grado en el que ha sido admitido, si no ha sido admitido en ningun grado contiene el valor -1
 * 		pref - es una cola la cual contiene las id de los grados a los que queremos acceder y no han sido procesados por estricto orden
 * 		topref - es un entero que contiene el valor de la primera posición de la cola pref en el caso de que esté vacia tendra valor -1
 * 		waitq - es una cola que contiene los grados que están en lista de espera, al principio se encuentra siempre vacia
 *
 *La función de esta clase es contener las solicitudes y los datos relativos a un estudiante específico para asi poder mostrarlos por pantalla
 *	con mayor eficiencia, además que ofrece la composición básica para otras clases mas complejas, aparte de ser usada para búsqueda y comparacion
 *	con otros estudiantes el objeto estudiante sabe en qué grados esta en espera y si ha sido aceptado en 1
 *
 *A medida que procesamos cada estudiante en los distintos cursos el objeto estudiantes también se va actualizando puesto que todo eso debe
 *ser informacion accesible y visible para la aplicacion final.
 *
 */

class Student {

private:
	string  surn1;
	string  surn2;
	string  name;
	string  dni;
	float   grade;
	bool accepted;
	int daccepted;
	int topref;
	Cola_preferencias *pref;
	Queue<int> *waitq;





public:

	Student  ();
	Student  (string surn1, string surn2, string name, string dni, float grade);
	Student  (string surn1, string surn2, string name, string dni, float grade,Cola_preferencias *pref);
	~Student ();

	string getDNI     () const;
	string getSurn1   () const;
	string getSurn2   () const;
	string getName    () const;
	float  getGrade   () const;
	int getTopref() const;
	int getDaccepted() const;


	//POST: Si accepted == false devuelve false , si no devuelve true
	//Complejidad O(1)
	bool isAccepted() const;


	string getAllName();

	//Te da la primera id de la cola de preferencias
	int	firstpref();



	//PRE: Para que funcione correctamente pref->vacia() != true
	//POST: Desencola pref, topref tendrá ahora el nuevo valor de pref->primero(), el valor desencolado se encola
		// en waitq(Cola de espera) si pref estaba vacia antes o después de desencolar mostrará por pantalla que la cola esta vacia
		//y topref tendrá valor -1 si pref no tiene ningun valor
	//Complejidad O(1)
	void nextpref();

	//PRE: id >=1 , id<=7 la id del grado debe estar o en la lista de espera(waitq) o ser el primero de la cola preferencias(pref)
	//POST: accepted =true; daccepted= id si la id estaba en la cola de espera elimina todas las ids posteriores a ella,
		//si no, deja la cola igual
	//Complejidad O(n)
	void admitted(int id);


	//PRE: El estudiante debe estar ya en un grado es decir Accepted==true ,Daccepted>=1 Daccepted<=7
	//POST: Accepted =false ,Daccepted =-1 desencola el primer valor de pref y lo mete en waitq
	//Complejidad O(1)
	void degraded();

	//POST:Muestra por pantalla de izda a dcha por orden de preferencia las id de los grados en los que el estudiante está
	//en lista de espera, si la lista está vacía enseña un mensaje por pantalla que lo dice.
	//Complejidad O(n)
	void show_waitq();


	//POST:Muestra por pantalla Surn1, Surn2,Name,Dni,grade, Si está admitido o no en algun grado y en caso afirmativo en cual
	//Además de la cola de espera.
	//Complejidad O(n)
	void   show       ();

	//POST:Muestra una información reducida para que se vea en las listas de espera y admitidos
	//Complejidad O(1)
	void   showD();

	//PRE:
	//POST: Devuelve true si la nota del Estudiante de la izquierda es mayor que la nota del de la derecha
		//Si no devuelve false;
	//Complejidad O(1)
	bool   operator>  (const Student &e);

	//POST: Devuelve true si la nota del Estudiante de la izquierda es menor que la nota del de la derecha
			//Si no devuelve false;
	//Complejidad O(1)
	bool   operator<  (const Student &e);

	//POST: Devuelve true si el name, surn1 y surn2 de ambos estudiantes coincide, si no devuelve false
	//Complejidad O(1)
	bool   operator== (const Student &e);


};


#endif /* STUDENT_H_ */
