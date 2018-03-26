/*
 * ListaAdmitidos.cpp
 *
 *  Created on: 30/3/2016
 *      Author: Javier Ballesteros Morón
				Carlos Licha de la Encarnación
 */

#include "ListaAdmitidos.h"

//TODO: Te falta un metodo que señale al ultimo de la lista;
	//Esto lo utilizaras para que en la clase grado si la lista esta llena lo cojas, lo quites de ahi ya que vas a meter al otro con mas nota
	//y lo insertes en lista de estudiantes(LA que usas como lista de espera)

//TODO recuerda que si quieres meter a un estudiante de la lista de admitidos a la de espera tienes que usar el metodo
	//student->degraded(int idgrado) para que el propio estudiante lo sepa y lo almacene
	//Si fuese a ser al reves de la lista de espera de alguna a la de admitidos se hace son student->admited(int idgrado)

//Todo un metodo bool que te diga cuando la lista esta llena es para ahorrarte trabajo
AList::AList() {
	this->admitidos=new SList();
	this->maxtamanio=30;
	this->notaMinima=0;
}

AList::AList(SList* sl) {
	this->admitidos=sl;
	this->maxtamanio=30;
	this->notaMinima=0;
}

AList::AList(int maxtamanio) {
	this->admitidos=new SList();
	this->maxtamanio=maxtamanio;
	this->notaMinima=0;
}



AList::~AList() {
	delete admitidos;
}

void AList::addStudent(Student *&s) {
	Student *aux;
	if(admitidos->getTamanio()< maxtamanio){
		admitidos->insertInOrder(s);
		admitidos->last(aux);
		notaMinima= aux->getGrade();
		aux = NULL;
	}
}

float AList::getNotaMinima() const {
	return notaMinima;
}

int AList::getMaxtamanio() const {
	return maxtamanio;
}

int AList::getTamanioLE() const {
	return this->admitidos->getTamanio();
}

bool AList::full() {
	bool lleno=false;
	if(admitidos->getTamanio() == maxtamanio){
		lleno =true;
	}
	return lleno;
}

void AList::removelast() {
	admitidos->removelast();
	Student *aux;
	admitidos->last(aux);
	notaMinima= aux->getGrade();
	aux = NULL;
}

void AList::last(Student*& s) {
	admitidos->last(s);
}



void AList::show() {
	admitidos->show();
	cout<<"La nota minima es: "<<notaMinima<<endl;
	cout<<"Ocupación "<<admitidos->getTamanio()<<"/"<<maxtamanio<<endl;
}

bool AList::removeStudent(Student*& s) {
	return admitidos->removeStudent(s);

}

void AList::moveToBegin() {
	admitidos->moveToBegin();
}

void AList::next() {
	admitidos->next();
}

bool AList::end() {
	return admitidos->end();
}

void AList::consult(Student*& s) {
	admitidos->consult(s);
}
