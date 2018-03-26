/*
 * CompareStudent.h
 *
 *  Created on: 11 de may. de 2016
 *      Author: Javier Ballesteros Morón
				Carlos Licha de la Encarnación
 */

#ifndef COMPARESTUDENT_H_
#define COMPARESTUDENT_H_

#include "student.h"
/*La clase CompareStudent es utilizada como parámetro de construcción de nuestros árboles binarios BSTree<Student*,CompareStudent> *tree
 * y es usada para establecer la colocación por orden alfabético de menor a mayor de los Student* , es decir los estudiantes que
 * tienen una solicitud.
 *
 */
namespace std {

class CompareStudent {
public:

	CompareStudent();
	~CompareStudent();
	int operator() (Student *s1,Student *s2);
};

} /* namespace std */

#endif /* COMPARESTUDENT_H_ */
