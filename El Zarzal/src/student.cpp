/*
 * student.cpp
 *
 *  Created on: 16/2/2016
  *      Author: Javier Ballesteros Morón
				Carlos Licha de la Encarnación
 */

#include "student.h"

Student::Student() {
	this->surn1  = "Tanjauser";
	this->surn2  = "Disousa";
	this->name   = "Facundo";
	this->dni    = "80225715Z";
	this->grade  = 5.0;
	pref = new Cola_preferencias(2,7,3,4,1);
	accepted =false;
	daccepted = -1;
	topref  =pref->primero();
	waitq = new Queue<int>();

}

Student::Student(string surn1, string surn2, string name, string dni, float grade){
	this->surn1  = surn1;
	this->surn2  = surn2;
	this->name   = name;
	this->dni    = dni;
	this->grade  = grade;
	pref = new Cola_preferencias(2,7,3,4,1);
	accepted =false;
	daccepted = -1;
	topref  =pref->primero();
	waitq = new Queue<int>();
}

Student::Student(string surn1, string surn2, string name, string dni,
		float grade, Cola_preferencias* pref) {
	this->surn1  = surn1;
		this->surn2  = surn2;
		this->name   = name;
		this->dni    = dni;
		this->grade  = grade;
		accepted =false;
		daccepted = -1;
		this->pref = pref;
		topref  =this->pref->primero();
		waitq = new Queue<int>();

}


void Student::show(){
	cout << this->surn1 << " " << this->surn2 << " " << this->name << " \t " << this->dni << " \t\t" << this->grade << endl;
	if(accepted){
	cout<<"The student has been accepted on the degree: "<<daccepted<<endl;
	}
	else{
		cout<<"The student has not  been accepted on any degree "<<endl;
	}
		cout<<"His waiting queue is: "<<endl;
		show_waitq();

}

void Student::showD() {
	cout << this->surn1 << " " << this->surn2 << " " << this->name << " \t " << this->dni << " \t\t" << this->grade << endl;
}

float Student::getGrade () const {
	return this->grade;
}


string Student::getDNI () const {
	return this->dni;
}


string Student::getName () const {
	return this->name;
}

string Student::getSurn1 () const {
	return this->surn1;
}

string Student::getSurn2 () const {
	return this->surn2;
}

bool Student::operator>(const Student& e) {
	return (this->grade > e.grade);
}
bool Student::operator< (const Student &e){
	return (this->grade < e.grade);
}

bool Student::operator== (const Student &e){
	string name1, name2;

	name1 = getSurn1() + getSurn2() + getName();
	name2 = e.surn1 + e.surn2 + e.name;
	return (name1 == name2);
}

Student::~Student() {
	delete pref;
	delete waitq;

}

bool Student::isAccepted() const {
	return accepted;
}







void Student::nextpref() {
	if(pref->vacia()){

			//TODO: cout<<"AVISO:"<<endl;
			//cout<<"La cola esta vacia no se pueden procesar las siguientes porque no existen"<<endl;
		}
	else{
	waitq->enqueue(pref->primero());
	pref->desencolar();
	if(pref->vacia()){
		//cout<<"AVISO:"<<endl;
		//cout<<"La cola esta vacía no hay una peticion después de la anterior"<<endl;
		topref = -1;
	}
	else{
	topref = pref->primero();
	}

	}
}

void Student::admitted(int id) {
	this->accepted =true;
	daccepted = id;
	if(id != pref->primero()){
	Queue<int> *aux=new Queue<int>;
		int i;
		bool stop =false;

		while(!waitq->empty()){
			i=waitq->front();

			waitq->dequeue();
			aux->enqueue(i);

		}

		while(!aux->empty() && !stop){
			i=aux->front();
			aux->dequeue();
			if(i == id){
			stop=true;
			}
			else{
			waitq->enqueue(i);
			}

		}
		delete aux;

	}

}

void Student::show_waitq() {
	if(waitq->empty()){
		cout<<"The waiting list is empty"<<endl;;
	}
	else{
	Queue<int> *aux=new Queue<int>;
	int i;
	while(!waitq->empty()){
		i=waitq->front();
		waitq->dequeue();
		aux->enqueue(i);
		cout<<i<<"  ";
	}

	while(!aux->empty()){
		i=aux->front();
		aux->dequeue();
		waitq->enqueue(i);
	}
	cout<<" "<<endl;
	delete aux;
	}
}

int Student::getDaccepted() const {
	return daccepted;
}


int Student::getTopref() const {
	return topref;
}

void Student::degraded() {
	this->accepted =false;
	daccepted = -1;
	this->nextpref();

}

string Student::getAllName() {
	string str;
	str = name + surn1 + surn2;
	return str;
}

int Student::firstpref() {
	return pref->primero();
}
