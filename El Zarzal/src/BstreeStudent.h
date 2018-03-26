/*
 * BstreeStudent.h
 *
 *  Created on: 11 de may. de 2016
 *      Author: Javier Ballesteros Morón
				Carlos Licha de la Encarnación
 */

#ifndef BSTREESTUDENT_H_
#define BSTREESTUDENT_H_

#include "student.h"
#include "ListaEstudiantes.h"
#include "bstree.h"
#include "CompareStudent.h"
#include "ListaAdmitidos.h"
#include "string"

using namespace std;

/*La clase BstreeStudent es principalmente una estructura de datos de árboles binarios específicamente diseñada para guardar
 * de forma ordenada instancias de la clase Student* , es decir, los estudiantes que usamos en el proyecto por orden alfabético
 * con prioridad de surn1 > surn2 > name.
 *
 * La clase cuenta con multitud de métodos de administración del contenido de ésta, insert(), insert_from_list()...
 * así como otros que permiten trabajar a clases que contienen a esta como show() o show_by_similarities()
 */

class BstreeStudent {

	BSTree <Student*,CompareStudent> *tree;

	//Método privado que complementa a su versión pública sin una "p" delante del nombre.
	//POST: Muestra el nombre, apellidos, dni y nota media de todos los estudiantes del árbol
		//complejidad o(n.log n)
	void pshow( BSTree <Student*,CompareStudent> *bt);

	//Método privado que complementa a su versión pública sin una "p" delante del nombre
	//PRE : bst->empty() == false
	//POST : devuelve la nota del estudiante con menor nota del grado
	//complejidad o(log n)
	float pmin_grade(BSTree <Student*,CompareStudent> *bst, float &grade);

	//PRE: Los caracteres introducidos deben pertenecer a al menos un alumno
	//POST :Devuelve como return el sub-árbol en el que su raíz es el primer estudiante con apellido empezado por los caracteres
		//introducidos
	//complejidad o(log n)
	BSTree<Student *, CompareStudent> * similarities(BSTree<Student *, CompareStudent> *bst,string &surname );


	//Este es el método privado, se ayuda del método público que lo complementa.
	//PRE : tree->empty() == false
	//POST :Muestra por pantalla los estudiantes cuyo apellido empiece con la cadena de caracteres introducida
		//si no hay ninguno introducido, muestra por pantalla que no hay ninguno que coincida.
	//complejidad o(log n)
	void pshow_by_similarities(BSTree<Student *, CompareStudent> *bt,string surname);



public:
	//Constructor por defecto, crea un árbol vacío
	BstreeStudent();
	~BstreeStudent();

	//Este es el método para llamarlo desde fuera, se ayuda del método privado con una "p" delante de su mismo nombre y el
		//método similarities()
	//PRE : tree->empty() == false
	//POST :Muestra por pantalla los estudiantes cuyo apellido empiece con la cadena de caracteres introducida
		//si no hay ninguno introducido muestra por pantalla que no hay ninguno que coincida
	//complejidad o(log n)
	void show_by_similarities(string surname);

	//POST: Devuelve true si el árbol está vacío y false en caso contrario
	//complejidad o(1)
	bool empty();

	//POST: Inserta al estudiante introducido en el parámetro
	//complejidad o(log n)
	void insert_student(Student *s);

	//Este es el método para llamarlo desde fuera, se ayuda del método privado con una "p" delante de su mismo nombre
	//PRE : tree->empty() == false
	//POST : devuelve la nota del estudiante con menor nota del grado
	//complejidad o(log n)
	float min_grade();


	//Envia todo el contenido de la lista de estudiantes al árbol y lo ordena por apellidos y nombre
	//PRE: sl->empty() == false , tree->empty() == true
	//POST: Vuelca todos los estudiantes de sl a tree ordenados por apellido1 >apellido2 > nombre
	//complejidad o(n.log n)
	void insert_from_list(SList *&sl);

	//Envia todo el contenido de la lista de admitidos al árbol y lo ordena por apellidos y nombre
	//PRE: as->empty() == false , tree->empty() == true
	//POST: Vuelca todos los estudiantes de al a tree ordenados por apellido1 >apellido2 > nombre
	//complejidad o(n.log n)
	void insert_form_list(AList *&al);

	//POST:Si el estudiante con los parámetros introducidos está en el árbol devuelve true, si no false
	//complejidad o(log n)
	bool exist(string surn,string surn2,string name);


	//POST:Si el estudiante con los parámetros introducidos está en el árbol devuelve true y lo elimina, si no false
	//complejidad o(log n)
	bool exist_del(string surn,string surn2,string name);

	//Este es el método para llamarlo desde fuera, se ayuda del método privado con una "p" delante de su mismo nombre
	//POST: Muestra el nombre, apellidos y dni y nota media de todos los estudiantes del árbol
	//complejidad o(n.log n)
	void show();
};



#endif /* BSTREESTUDENT_H_ */
