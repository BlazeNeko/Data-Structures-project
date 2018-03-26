/*
 * Pruebas.h
 *
 *  Created on: 22 de mar. de 2016
 *      Author: Javier Ballesteros Morón
				Carlos Licha de la Encarnación
 */

#ifndef PRUEBAS_H_
#define PRUEBAS_H_
#include "Colapreferencias.h"
#include "unistd.h"
#include "Grado.h"

namespace std {

class Pruebas {
public:
	Pruebas();
	~Pruebas();
	void p_student();

	void p_student_operators();

	void p_student_nextpref();

	void p_student_admited();
	//Al tratarse de una clase muy sencilla haremos sus pruebas en un solo módulo
	void p_colapreferencias();

	void p_l_estudiantes();

	void p_l_admitidos();

	void p_grado();
};

} /* namespace std */

#endif /* PRUEBAS_H_ */
