/*
 * ListaEstudiantes.cpp
 *
 *  Created on: 30/3/2016
 *      Author: Javier Ballesteros Morón
				Carlos Licha de la Encarnación
 */

#include "ListaEstudiantes.h"



SList::SList() {
	this->l=new IList<Student*>();
	this->tamanio=0;
}

SList::~SList() {
	delete l;
}

void SList::insertInOrder(Student *&s) {
	Student *aux ;
	if(!this->l->empty()){
		this->l->moveToBegin();
		this->l->consult(aux);
		while(*aux > *s && !l->end()){
			l->next();
			l->consult(aux);
		}
		l->insert(s);
		tamanio++;
	}
	else{
		l->insert(s);
		tamanio++;
	}
}

void SList::show() {
	Student *aux;
	if(l->empty()){
		cout<<"La lista esta vacía"<<endl;
	}
	else{
		l->moveToBegin();
		while(!l->end()){
			l->consult(aux);
			aux->showD();
			l->next();
		}
		cout<<"El tamaño de la lista es: "<<tamanio<<endl;
	}
}

int SList::getTamanio() const {
	return tamanio;
}



void SList::first(Student *&s) {
	l->moveToBegin();
	l->consult(s);
}

void SList::last(Student *&s) {
	l->moveToEnd();
	l->consult(s);
}

void SList::removefirst() {
	l->moveToBegin();
	l->remove();
	tamanio--;
}

void SList::removelast() {
	l->moveToEnd();
	l->remove();
	tamanio--;
}

bool SList::empty() {
	bool empty=false;
	if(tamanio == 0)
		empty=true;

	return empty;
}

SList::SList(int i) {
	if(i==1){

	ifstream source;

	int i;
	string spref;



	string name;
	string surn1;
	string surn2;
	string dni;
	string sgrade;
	string prefnumber;
	Cola_preferencias *colaP;
	Student *student;
	source.open("students.txt",ios::in);
	l = new IList<Student*>();

	while(!source.eof()){

		getline(source,name,'#'); //al final del fihero tiene que comprobar una ultima vez si ha llegado a ese mismo final
									//si no daria error
		if(!source.eof()){
		getline(source,surn1,'#');
		getline(source,surn2,'#');
		getline(source,dni,'#');
		getline(source,sgrade,'#');
		getline(source,prefnumber);

		colaP = new Cola_preferencias();
		i = atoi(prefnumber.c_str());

		while(i>0){
			getline(source,spref);
			colaP->insertar(atoi(spref.c_str()));
			i--;
		}

		student = new Student(name,surn1,surn2,dni,strtof(sgrade.c_str(),NULL),colaP);
		l->insert(student);
		this->tamanio++;
	}
	}


	source.close();

	}
	else{
		tamanio= 0;
		Cola_preferencias *ca1= new Cola_preferencias(1,3);
		Cola_preferencias *ca2= new Cola_preferencias(2);
		Cola_preferencias *ca3= new Cola_preferencias(1,3);
		Cola_preferencias *ca4= new Cola_preferencias(2,3);
		Cola_preferencias *ca5= new Cola_preferencias(1);
		Cola_preferencias *ca6= new Cola_preferencias(1,3);
		Cola_preferencias *ca7= new Cola_preferencias(3,1);
		Cola_preferencias *ca8= new Cola_preferencias(2,3);
		Cola_preferencias *ca9= new Cola_preferencias(1,3);
		Cola_preferencias *ca10= new Cola_preferencias(1,2,3);
		Student *a1 = new Student("a1"," "," ","", 6.0,ca1);
			Student *a2 = new Student("a2"," "," ","", 8.0,ca2);
			Student *a3 = new Student("a3"," "," ","" ,5.5,ca3);
			Student *a4 = new Student("a4"," "," ","", 7.0,ca4);
			Student *a5 = new Student("a5"," "," ","", 10.0,ca5);
			Student *a6 = new Student("a6"," "," ","", 9.0,ca6);
			Student *a7 = new Student("a7"," "," ","", 6.2,ca7);
			Student *a8 = new Student("a8"," "," ","", 6.0,ca8);
			Student *a9 = new Student("a9"," "," ","", 8.0,ca9);
			Student *a10 = new Student("a10"," "," ","", 5.0,ca10);
			l = new IList<Student*>();
			l->insert(a1);
			l->insert(a2);
			l->insert(a3);
			l->insert(a4);
			l->insert(a5);
			l->insert(a6);
			l->insert(a7);
			l->insert(a8);
			l->insert(a9);
			l->insert(a10);

	}





}

bool SList::removeStudent(Student*& s) {
	Student *aux;
	bool encontrado =false;
	if(!l->empty()){
		l->moveToBegin();
		while(!encontrado && !l->end()){
			l->consult(aux);
			if(*aux == *s){
				encontrado= true;
				l->remove();
				tamanio--;
			}
			else{
				l->next();
			}
		}
	}
	aux=NULL;
	return encontrado;
}

bool SList::end() {
	return l->end();
}

void SList::next() {
	l->next();
}

void SList::back() {
	l->back();
}

void SList::consult(Student* &aux) {
	 l->consult(aux);
}

void SList::moveToBegin() {
	l->moveToBegin();
}
