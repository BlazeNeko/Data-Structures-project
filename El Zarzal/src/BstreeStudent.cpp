/*
 * BstreeStudent.cpp
 *
 *  Created on: 11 de may. de 2016
 *      Author: Javier Ballesteros Morón
				Carlos Licha de la Encarnación
 */

#include "BstreeStudent.h"

using namespace std;

BstreeStudent::BstreeStudent() {
	// TODO Auto-generated constructor stub
	tree = new BSTree<Student*, CompareStudent>();

}

BstreeStudent::~BstreeStudent() {
	// TODO Auto-generated destructor stub
	delete tree;
}

void BstreeStudent::pshow(BSTree<Student*, CompareStudent>* bt) {
//se muestra bien porque es in order primero left -root -right

	if (!bt->empty()) {

		BSTree<Student*, CompareStudent>* auxt;
		auxt = bt->left();
		if (auxt != NULL) {
			pshow(auxt);
		}

		bt->root()->showD(); //muestro al estudiante de la raiz

		auxt = bt->right();
		if (auxt != NULL) {
			pshow(auxt);
		}

	}
}

void BstreeStudent::insert_from_list(SList* &sl) {

	sl->moveToBegin();
	Student *aux;

	while (!sl->end()) {
		sl->consult(aux);
		tree->insert(aux);
		sl->next();
	}

}

void BstreeStudent::insert_form_list(AList*& al) {
	al->moveToBegin();
	Student *aux;

	while (!al->end()) {
		al->consult(aux);
		tree->insert(aux);
		al->next();
	}
}

bool BstreeStudent::exist_del(string surn, string surn2, string name) {
	bool enc = false;
	Student *s = new Student(surn, surn2, name, " ", 0);
	enc = tree->exist(s);
	if (enc == true) {
		tree->remove(s);
	}
	delete s;

	return enc;
}

bool BstreeStudent::exist(string surn, string surn2, string name) {
	bool enc = false;
	Student *s = new Student(surn, surn2, name, " ", 0);
	enc = tree->exist(s);
	delete s;
	return enc;
}

void BstreeStudent::insert_student(Student* s) {
	tree->insert(s);
}

bool BstreeStudent::empty() {
	return tree->empty();
}

float BstreeStudent::pmin_grade(BSTree<Student*, CompareStudent> *bt, float &grade) {
	if (!bt->empty()) {

		BSTree<Student*, CompareStudent>* auxt;
		auxt = bt->left();
		if (auxt != NULL) {
			pmin_grade(auxt, grade);

		}
		if(bt->root()->getGrade()< grade){
			grade = bt->root()->getGrade();
		}

		auxt = bt->right();
		if (auxt != NULL) {
			pmin_grade(auxt, grade);
		}

	}
	return grade;

}

float BstreeStudent::min_grade() {
	float grade =10;
	return pmin_grade(this->tree,grade);
}

BSTree<Student*, CompareStudent>* BstreeStudent::similarities(
		BSTree<Student*, CompareStudent>* bst, string& surname) {
	 BSTree<Student*, CompareStudent> *aux = NULL;
	    BSTree<Student*, CompareStudent> *auxT = NULL;
	    if (bst->root()->getSurn1().find(surname) == 0) {
	        aux = bst;
	    } else {
	        if (surname < bst->root()->getSurn1()) {
	            auxT = bst->left();
	            if (auxT != NULL) {
	                aux = similarities(auxT, surname);
	            }

	        } else {
	            auxT = bst->right();
	            if (auxT != NULL) {
	                aux = similarities(auxT, surname);
	            }
	        }
	    }
	    return aux;
}

void BstreeStudent::pshow_by_similarities(
		BSTree<Student*, CompareStudent>* bt,string surname) {
	if (!bt->empty()) {

			BSTree<Student*, CompareStudent>* auxt;
			auxt = bt->left();
			if (auxt != NULL) {
				pshow_by_similarities(auxt,surname);

			}
			 if (bt->root()->getSurn1().find(surname) == 0){
				 bt->root()->showD();

			 }

			auxt = bt->right();
			if (auxt != NULL) {
				pshow_by_similarities(auxt,surname);
			}

		}
}

void BstreeStudent::show_by_similarities(string surname) {
	BSTree<Student*, CompareStudent>* bt;

	bt = similarities(tree,surname);
	if(bt != NULL)
	pshow_by_similarities(bt,surname);
	else{
		cout<<"No existe ningún estudiante que coincida con la búsqueda"<<endl;
	}


}

void BstreeStudent::show() {
	this->pshow(tree);

}

