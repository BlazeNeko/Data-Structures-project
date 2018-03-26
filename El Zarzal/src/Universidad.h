/*
 * Universidad.h
 *
 *  Created on: 12 de abr. de 2016
 *      Author: Javier Ballesteros Morón
				Carlos Licha de la Encarnación
 */

#ifndef UNIVERSIDAD_H_
#define UNIVERSIDAD_H_

#include <string.h>
#include "Grado.h"
#include "ListaEstudiantes.h"
#include "student.h"
#include "Titulaciones.h"
#include "unistd.h"
#include <sstream>
#include <fstream>

using namespace std ;

/*La clase Universidad es la clase que engloba a todas las demás, todas las otras clases han sido creadas para que esta pueda existir
 * su función es representar la universidad de EL ZARZAL y todo para lo que sirve esta, desde administrar sus grados a guardar los estudiantes
 * matriculados en archivos de texto, la clase cumple con todos los requisitos pedidos en el proyecto y permite realizar todas las partes
 * que se han pedido en este.
 * Se administra a través del método mainMenu().
 *
 */


class Universidad {



	SList *lista;    //Ordenada por nota
	Titulaciones *g;

	//Se encarga del proceso de administración de los estudiantes para distribuirlos por los diferentes grados seǵun el criterio
		//de preferencias de cada estudiante donde se decide si accede a los grados que quiere o no dependiendo de su nota
		//respecto a la del resto.
		//Se complementa con el método process para realizar dicha acción ya que este realiza la administración de un estudiante
		//y process inicializa este método con cada uno de los estudiantes dela lista
		//PRE:g contiene los  grados por orden de id , lista contiene los estudiantes que se van a procesar
		//POST: Asigna a los estudiantes a los diferentes grados según  la nota y las preferencias de cada estudiante
		//Complejidad: O(n*log n)
void recprocess(Student *&s);



public:
	Universidad();//este no se usará jamás
	Universidad(SList *l);
	~Universidad();

	//Se encarga del proceso de administración de los estudiantes para distribuirlos por los diferentes grados seǵun el criterio
	//de preferencias de cada estudiante donde se decide si accede a los grados que quiere o no dependiendo de su nota
	//respecto a la del resto.
	//Se complementa con el método recprocess() para realizar dicha acción ya que este inicializa la llamada y recprocess hace el proceso
	//PRE:g contiene los grados por orden de id , lista contiene los estudiantes que se van a procesar
	//POST: Asigna a los estudiantes a los diferentes grados según la nota y las preferencias de cada estudiantes
	//Complejidad: O(n*log n)
	void process();



	//POST:Si el dni coincide con alguno de los estudiantes muestra su información: su nombre y apellidos, nota ,dni , si ha
	//sido admitido en algún grado o no y los grados en los que se encuentra en lista de espera.
	//Complejidad: O(n)
	void studentinfo(string dni);

	//PRE: Árboles con la información de los alumnos.
	//El método de matriculación carga todos los datos del fichero matyrenuncias.txt y comprueba linea por linea si la petición es posible
	//si se pide Renuncia o matriculación REN o  MAT respectivamente ,primero comprueba que los datos del fichero correspondan a un estudiante con solicitud
	//En caso contrario notifica del error por pantalla.
	//POST: Si los requisitos con cumplidos pueden pasar 2 cosas:
	//Si el código es MAT: Saca al estudiante del árbol de admitidos del grado correspondiente y del árbol de espera de todos los demás
		//grados, además lo escribe en el fichero.txt del grado correspondiente.
	//Si el código e REN: Elimina al estudiante del árbol de admitidos al que renuncia y del árbol de espera de todos los demás grados.
	//Además el estudiante con más nota del árbol de espera de ese grado se inserta en el árbol de admitidos y se elimina del árbol de
	//espera del grado correspondiente
	//Complejidad: O(n)
	void matriculation();


	//PRE: g debe contener los grados en orden de identificación de menor a mayor
	//POST: Muestra el grado cuya id coincida con el parámetro introducido
	//Complejidad: O(n*log n)
	void showGrado(int i);


	//Menú del proyecto el cual es la interfaz de este y es el que permite acceder a cada una de las 9 opciones del proyecto
	//funciona introduciendo datos desde la consola, y una vez revisada una opción permite volver al menú principal pulsando cualquier
	//tecla + enter
	//Además el método cuenta con delays para que resulte visualmente más atractivo en algunas opciones.
	void mainMenu();


};



#endif /* UNIVERSIDAD_H_ */
