/*
 * Titulacion.h
 *
 *  Created on: 13 de abr. de 2016
  *      Author: Javier Ballesteros Morón
				Carlos Licha de la Encarnación
 */

#ifndef TITULACIONES_H_
#define TITULACIONES_H_
#include <iostream>
#include "Colapreferencias.h"
#include "Pruebas.h"
#include "unistd.h"
#include "student.h"
#include "ilist.h"
#include "ListaEstudiantes.h"
#include "ListaAdmitidos.h"
#include "Grado.h"
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <string>

#include "string"

using namespace std;

//Clase utilizada para administrar de forma sencilla y eficiente los grados que necesitamos para nuestra aplicación, Esta clase
//Es la que carga los grados del archivo de texto degrees.txt y está pensada para devolver en grado que nosotros necesitemos introduciendo
//su código de identificación.

class Titulaciones {

	IList<Grado*> *grados; //Lista con todos los grados disponibles
public:
	Titulaciones();
	~Titulaciones();
	//PRE: grados->empty() == false, g>0 , g<=7
	//POST:Introduciendo la id del grado correspondiente nos devuelve dicho grado como parámetro de salida.
	void getGrado(int g,Grado *&grado);


	void showGrado(int g);
};



#endif /* TITULACIONES_H_ */
