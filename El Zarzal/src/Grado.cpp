/*
 * ListaAdmitidos.h
 *
 *  Created on: 30/3/2016
 *      Author: Javier Ballesteros Morón
				 Carlos Licha de la Encarnación
 */

#include "Grado.h"

int Grado::getId() const {
	return ID;
}

const string& Grado::getName() const {
	return name;
}

float Grado::notaCorte() const {
	return this->al->getNotaMinima();
}

Grado::Grado() {
	this->ID = 0;
	this->name = "EmptyDegree";
	this->plazasDisp = 10;
	this->al = new AList(plazasDisp);
	this->waitl = new SList();
	this->at = new BstreeStudent();
	this->wt = new BstreeStudent();
}

Grado::Grado(int ID, string name, int plazasDisp) {
	this->ID = ID;
	this->name = name;
	this->plazasDisp = plazasDisp;
	this->al = new AList(plazasDisp);
	this->waitl = new SList();
	this->at = new BstreeStudent();
	this->wt = new BstreeStudent();
}

Grado::~Grado() {
	delete al;
	delete waitl;
	delete at;
	delete wt;
}

//TODO no se si funcionara quedan pruebas que hacer
bool Grado::addStudent(Student *&s, Student *&exit) {
	bool accepted = false;
	exit = NULL;

	if (!al->full()) {
		al->addStudent(s);
		accepted = true;
		s->admitted(ID);
	}

	else {
		if (s->getGrade() > al->getNotaMinima()) {
			al->last(exit); //se coje el ultimo
			al->removelast(); //se elimina de la
			al->addStudent(s); //se mete el nuevo en la
			accepted = true;
			waitl->insertInOrder(exit); //se mete el que ha salido en waitl
			s->admitted(ID); //se notifica al primero que ha sido admitido
			exit->degraded(); //al que ha salido se le notifica que ha sido degradado con lo cual se corre su lista de pref a la siguiente
		} else {
			waitl->insertInOrder(s);
			s->nextpref();
		}
	}
	return accepted;

}

int Grado::getPlazasDisp() const {
	return plazasDisp;
}

void Grado::firstWaitl(Student*&s) {
	waitl->moveToBegin();
	waitl->first(s);
}

void Grado::insertTrees() {
	this->at->insert_form_list(this->al);
	this->wt->insert_from_list(this->waitl);
}

void Grado::admitted(string surn1, string surn2, string name, string dni) {
	if (at->exist_del(surn1, surn2, name) == true) {
		ofstream destination;

		stringstream streamstr;
		string str;
		string namefile;
		streamstr << this->ID;
		streamstr >> str;
		namefile = str + ".txt";
		destination.open(namefile.c_str(), ios::out | ios::app); //para empezar al final
		destination << surn1 + " " + surn2 + " " + name + " " + dni << endl;
		destination.close();
	} else {
		cout << "Error, el estudiante " << surn1 << " " << surn2 << " " << name
				<< " " << dni << " "
				<< "No ha se encuentra en la lista de amitidos del grado " << ID
				<< endl;
	}
}

void Grado::remove_wt(string surn1, string surn2, string name) {
	if (!wt->empty()) {
		wt->exist_del(surn1, surn2, name);
	}
	if (!waitl->empty()) {
		Student* aux;
		waitl->first(aux);
		if (aux->getName() == name && aux->getSurn1() == surn1
				&& aux->getSurn2() == surn2)
			waitl->removefirst();
	}
}

void Grado::gives_up(string surn1, string surn2, string name, string dni) {
	Student* aux;
	if (at->exist_del(surn1, surn2, name)) {
		if (!waitl->empty()) {

			waitl->first(aux);
			waitl->removefirst(); //eliminamos el primero que acabamos de sacar para dejar oportunidad al resto
			if (aux != NULL) {
				at->insert_student(aux);
				if (!wt->empty())
					wt->exist_del(aux->getSurn1(), aux->getSurn2(),
							aux->getName());
			}
		}

	} else {
		cout << "Error de renuncia, el estudiante " << surn1 << " " << surn2 << " "
				<< name << " " << dni << " "
				<< " No ha se encuentra en la lista de amitidos del grado "
				<< ID << endl;
	}
	//todo: seguir por aqui
}

void Grado::show_at() {
	cout << "Contenido del grado en " << this->name << endl;
	cout << "Codigo de identificación del grado: " << this->ID << endl;
	cout << " " << endl;
	cout << "Contenido de la lista de admitidos:" << endl;
	cout << " " << endl;
	at->show();
}

void Grado::remove_at(string surn1, string surn2, string name) {
	if (!at->empty()) {
		at->exist_del(surn1, surn2, name);
	}
}

void Grado::show() {
	cout << "Contenido del grado en " << this->name << endl;
	cout << "Codigo de identificación del grado: " << this->ID << endl;
	cout << " " << endl;
	cout << "Contenido de la lista de admitidos:" << endl;
	cout << " " << endl;
	al->show();
	cout << " " << endl;
	cout << " " << endl;
	cout << "Contenido de la lista espera:" << endl;
	cout << " " << endl;
	waitl->show();
	if (waitl->empty()) {
		cout << "La lista esta vacía" << endl;
	}
	cout << "Plazas disponibles:" << this->plazasDisp << endl;

}

void Grado::removeStudent(Student*& s) {
	Student *aux;
	al->removeStudent(s);
	waitl->first(aux);
	waitl->removefirst();
	al->addStudent(aux);
	aux->admitted(this->ID);
	s->degraded();
	aux = NULL;

}

float Grado::get_tree_min_grade() const {
	return this->at->min_grade();
}

void Grado::show_by_similarities(string surname) {
	at->show_by_similarities(surname);
}
/*
 * Grados.cpp
 *
 *  Created on: 30/3/2016
 *      Author: Blaze Neko
 */

