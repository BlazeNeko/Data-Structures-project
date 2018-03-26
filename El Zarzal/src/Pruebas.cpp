/*
 * Pruebas.cpp
 *
 *  Created on: 22 de mar. de 2016
 *      Author: Javier Ballesteros Morón
				 Carlos Licha de la Encarnación
 */

#include "Pruebas.h"


using namespace std;

Pruebas::Pruebas() {
}

Pruebas::~Pruebas() {
}

void Pruebas::p_student_operators() {
	cout<<"En esta prueba demostraremos el correcto funcionamiento de los módulos operator >, < y == "<<endl;
	cout<<" "<<endl;
	cout<<"Estos módulos sirven para ver si un estudiantes tiene mas nota que otro"<<endl;
	cout<<"O si son el mismo estudiante respectivamente"<<endl;

	usleep(5000000);

	cout<<"Para ello creamos a 4 estudiantes con sus siguientes notas: "<<endl;
	cout<<"Apu,9.0 / Kylo,6.00 / Samuel,6.00 y Fran,5.0"<<endl;

	Student *apu= new Student("Nahasapee","mapetilon","Apu","70990099G",9.0);
	Student *kylo= new Student("Ren","Skywalker","Kylo","3232121Z",6.00);
	Student *samuel= new Student("L.","Jackson","Samuel","672121Y",6.00);
	Student *fran=new Student("Gonzalez","Da Silva","Fran","647821Y",5.0);

	cout<<"Ahora comparemos utilizando > a Apu y kylo, Kylo y Samuel ,Fran y Samuel"<<endl;
	usleep(4000000);
	cout<<"Apu > Kylo: ";
	if(*apu > *kylo){
		cout<<"true"<<endl;
	}
	else{
		cout<<"false"<<endl;
	}
	cout<<"Kylo > Samuel: ";
		if(*kylo > *samuel){
			cout<<"true"<<endl;
		}
		else{
			cout<<"false"<<endl;
		}
		cout<<"Fran > Samuel: ";
			if(*fran >*samuel){
				cout<<"true"<<endl;
			}
			else{
				cout<<"false"<<endl;
			}

			usleep(4000000);
			cout<<" "<<endl;

	cout<<"A continuacion comparemos utilizando < a Apu y kylo, Kylo y Samuel ,Fran y Samuel"<<endl;

	cout<<"Apu < Kylo: ";
	if(*apu <*kylo){
			cout<<"true"<<endl;
		}
		else{
			cout<<"false"<<endl;
		}
		cout<<"Kylo < Samuel: ";
			if(*kylo < *samuel){
				cout<<"true"<<endl;
			}
			else{
				cout<<"false"<<endl;
			}
			cout<<"Fran < Samuel: ";
				if(*fran <*samuel){
					cout<<"true"<<endl;
				}
				else{
					cout<<"false"<<endl;
				}

				usleep(4000000);
				cout<<" "<<endl;

	cout<<"Y por ultimo comparemos utilizando == a Apu y kylo, Kylo y Samuel ,Fran y Samuel"<<endl;
	cout<<"Todos deberian dar falso pues ninguno es el mismo estudiante"<<endl;

				cout<<"Apu == Kylo: ";
				if(*apu ==*kylo){
						cout<<"true"<<endl;
					}
					else{
						cout<<"false"<<endl;
					}
					cout<<"Kylo == Samuel: ";
						if(*kylo == *samuel){
							cout<<"true"<<endl;
						}
						else{
							cout<<"false"<<endl;
						}
						cout<<"Fran == Samuel: ";
							if(*fran ==*samuel){
								cout<<"true"<<endl;
							}
							else{
								cout<<"false"<<endl;
							}

//TODO alomejor falta un ultimo caso en el que el estudiante sea el mismo que queremos
							cout<<" "<<endl;

delete apu;
delete samuel;
delete kylo;
delete fran;
}

void Pruebas::p_student_nextpref() {
	cout<<"Para las pruebas del módulo nextpref() crearemos un estudiante cualquiera con cola de preferencias:"<<endl;
	cout<<"De izda a dcha: 4 3 7 2 1"<<endl;
	Cola_preferencias *c = new Cola_preferencias(4,3,7,2,1);
	cout<<""<<endl;
	Student *pr = new Student("Marco","Rubio","Pablo","80225716Z",5.0,c);
	usleep(2000000);
	c = NULL;

	cout<<"Mostramos la cola de espera y el primer valor de la cola de preferencias: "<<endl;

	pr->show_waitq();
	cout<<"EL primer valor de la cola es: "<<pr->getTopref()<<endl;

	usleep(4000000);
	cout<<""<<endl;

	cout<<"A continuación llamamos al módulo nextpref() con esto desencolamos el primer valor de pref y lo metemos en cola de espera"<<endl;
	cout<<"Mostramos la cola de espera y el primer valor de la cola de preferencias: "<<endl;
	pr->nextpref();
	pr->show_waitq();
	cout<<"EL primer valor de la cola es: "<<pr->getTopref()<<endl;

	usleep(4000000);
	cout<<""<<endl;

	cout<<"Volvemos a llamar al módulo nextpref() con esto desencolamos el primer valor de pref y lo metemos en cola de espera"<<endl;
	cout<<"Mostramos la cola de espera y el primer valor de la cola de preferencias: "<<endl;
	pr->nextpref();
	pr->show_waitq();
	cout<<"EL primer valor de la cola es: "<<pr->getTopref()<<endl;

	usleep(4000000);
	cout<<""<<endl;

	cout<<"Lo hacemos una vez mas: "<<endl;
	pr->nextpref();
	pr->show_waitq();
	cout<<"EL primer valor de la cola es: "<<pr->getTopref()<<endl;

	usleep(4000000);
	cout<<""<<endl;

	cout<<"Por último lo hacemos 2 veces más para ver que mostraría si la cola de preferencias se quedase vacia "<<endl;
	cout<<"EL valor de topref cambiaría a -1 para indicar que no contienen ningun valor válido"<<endl;
	cout<<" aun asi todos los valores irian a la cola de espera: "<<endl;
	pr->nextpref();
	pr->nextpref();
	pr->show_waitq();
	cout<<"EL primer valor de la cola es: "<<pr->getTopref()<<endl;

	delete pr;
}

void Pruebas::p_student_admited() {
	cout<<"Ahora probaremos el módulo admited(int id)"<<endl;
	cout<<""<<endl;
	cout<<"Para el correcto funcionamiento de este módulo necesitaremos que la id en la que va a ser admitido"<<endl;
	cout<<"Se encuentre o bien en la cola de espera(waitq) o bien en la primera posicion de la cola preferencias(pref)"<<endl;
	cout<<""<<endl;
	usleep(7000000);

	cout<<"Para la primera prueba utilizaremos al siguiente estudiante que se muestra en pantalla"<<endl;
	cout<<"Está en lista de espera para los grados ID 2 e id 7 en ese orden"<<endl;
	cout<<""<<endl;
	Student *pr = new Student("Marco","Rubio","Pablo","80225716Z",5.0);
	pr->nextpref();
	pr->nextpref();
	pr->show();

	cout<<""<<endl;
	usleep(4000000);
	cout<<"A continuación llamando al módulo admited(7) haremos que sea admitido en el grado 7"<<endl;
	cout<<"Quedando aun así en lista de espera para el grado 2 pero actualizandose su información"<<endl;
	cout<<""<<endl;
	pr->admitted(7);
	pr->show();

	cout<<""<<endl;
	usleep(7000000);
cout<<"-------------------------------------"<<endl;
	cout<<"Probemos ahora el caso de otro estudiante, este estudiante está en lista de espera en los grados 3 y 4"<<endl;
	cout<<"Pero lo primero en su cola de referencias por procesar es el grado 2"<<endl;
	cout<<""<<endl;
	Cola_preferencias *c= new Cola_preferencias(3,4,2);
	Student *pr2 = new Student("Gadella","Sousa","Laura","646899832Y",8.20,c);
	c= NULL;
	pr2->nextpref();
	pr2->nextpref();
	pr2->show();

	cout<<""<<endl;
	usleep(4000000);

	cout<<"Llamamos al módulo admited(2), de esta manera la estudiante es admitida en el grado 2 pero su cola de espera no se modifica"<<endl;
	cout<<""<<endl;
	pr2->admitted(2);
	pr2->show();



	cout<<""<<endl;
	usleep(7000000);
	cout<<"-------------------------------------"<<endl;
	cout<<"Por último veremos el caso del siguiente estudiante, está en la lista de espera de los grados 2,7,3"<<endl;
	cout<<""<<endl;
	Student *pr3 = new Student("Gomez","De la Cruz","María","803357892Q",6.30);
	pr3->nextpref();
	pr3->nextpref();
	pr3->nextpref();
	pr3->show();
	cout<<""<<endl;
	usleep(4000000);

	cout<<"Ahora llamamos al módulo admited(2) la estudiante ha sido admitida en su primera opcion"<<endl;
	cout<<"Por tanto se elimina toda su lista de espera"<<endl;
	cout<<""<<endl;
	pr3->admitted(2);
	pr3->show();
	cout<<""<<endl;

	delete pr3;
	delete pr2;
	delete pr;

}

void Pruebas::p_student() {
cout<<"INICIO PRUEBAS CLASE STUDENT"<<endl;
cout<<""<<endl;
cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
cout<<"INICIO PRUEBAS MÓDULOS OPERADORES"<<endl;


	usleep(5000000);
	 p_student_operators();
	cout<<""<<endl;
cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
cout<<"INICIO PRUEBAS MÓDULO NEXTPREF()"<<endl;
	usleep(5000000);
	 p_student_nextpref();
	cout<<""<<endl;
cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
cout<<"INICIO PRUEBAS MÓDULO ADMITED()"<<endl;
	usleep(5000000);
	 p_student_admited();
	cout<<""<<endl;
	cout<<"FIN PRUEBAS CLASE STUDENT"<<endl;
}

void Pruebas::p_colapreferencias() {

	Cola_preferencias *c = new Cola_preferencias();
	cout<<"INICIO DE LA PRUEBA COLA_PREFERENCIA"<<endl;
	cout<<""<<endl;
	cout<<"Atencion esta prueba tiene retrasos de varios segundos entre partes para leer adecuadamente el procedimiento"<<endl;
	usleep(5000000);

	cout<<""<<endl;
	cout<<"-Insertamos  4 identificaciones 1 , 3 , 5 , 7  "<<endl;
	cout<<""<<endl;

	cout<<"Lo mostraremos por pantalla con mostar() y luego de forma extendida con mostrarEX()"<<endl;
	cout<<""<<endl;

	c->insertar(1);
	c->insertar(3);
	c->insertar(5);
	c->insertar(7);
	c->mostrar();
	c->mostrarEX();
	usleep(9000000);
	cout<<""<<endl;
	cout<<"-Ahora introduciremos la id 9 pero al no existir en el repertorio nos dirá que no existe y no se insertará, volvemos a mostrar"<<endl;
	usleep(9000000);
	cout<<""<<endl;

	c->insertar(9);
	c->mostrar();
	c->mostrarEX();

	usleep(9000000);
	cout<<""<<endl;

	cout<<"-Por último eliminamos las 2 primeras ids 1 y 3 del principio de la cola y volvemos a mostrar"<<endl;
	cout<<""<<endl;

	usleep(9000000);
	c->desencolar();
	c->desencolar();

	c->mostrar();

	usleep(9000000);

	cout<<"FIN DE LA PRUEBA COLA_PREFERENCIA"<<endl;

	delete c;

}



void Pruebas::p_l_estudiantes() {

	SList *l = new SList();
	cout<<"INICIO DE LA PRUEBA LISTA ESTUDIANTES"<<endl;
	cout<<""<<endl;
	cout<<"Atencion esta prueba tiene retrasos de varios segundos entre partes para leer adecuadamente el procedimiento"<<endl;
	usleep(5000000);

	cout<<"Para ello creamos a 4 estudiantes con sus siguientes notas: "<<endl;
	cout<<"Apu,9.0 / Kylo,8.00 / Samuel,6.00 y Fran,5.0"<<endl;

	Student *apu= new Student("Nahasapee","mapetilon","Apu","70990099G",9.0);
	Student *kylo= new Student("Ren","Skywalker","Kylo","3232121Z",6.00);
	Student *samuel= new Student("L.","Jackson","Samuel","672121Y",8.00);
	Student *fran=new Student("Gonzalez","Da Silva","Fran","647821Y",5.0);
	cout<<"Los insertamos en la lista y deberían aparecerordenados por nota"<<endl;
	cout<<""<<endl;

	l->insertInOrder(*&apu);
	l->insertInOrder(*&kylo);
	l->insertInOrder(*&samuel);
	l->insertInOrder(*&fran);
	l->show();

	usleep(9000000);

	cout<<""<<endl;
	cout<<"Como el resto de métodos de la clase son muy sencillos, vamos a probar el removeStudent. Para ello vamos a borrar a Samuel y luego mostramos"<<endl;
	usleep(9000000);
	cout<<""<<endl;

	l->removeStudent(*&samuel);
	l->show();

	cout<<"FIN DE LA PRUEBA LISTA ESTUDIANTES"<<endl;

	delete l;
}

void Pruebas::p_l_admitidos() {

	AList *l=new AList(3);
	cout<<"INICIO DE LA PRUEBA LISTA ADMITIDOS";
	cout<<""<<endl;
	cout<<"Atencion esta prueba tiene retrasos de varios segundos entre partes para leer adecuadamente el procedimiento"<<endl;
	usleep(5000000);

	cout<<"Esta clase reuutiliza la mayoría de los métodos de la clase ListaEstudiantes, por lo que estas pruebas serán breves"<<endl;
	cout<<"Para ello creamos a 4 estudiantes con sus siguientes notas: "<<endl;
	cout<<"Apu,9.0 / Kylo,8.00 / Samuel,6.00 y Fran,5.0"<<endl;

	Student *apu= new Student("Nahasapee","mapetilon","Apu","70990099G",9.0);
	Student *kylo= new Student("Ren","Skywalker","Kylo","3232121Z",6.00);
	Student *samuel= new Student("L.","Jackson","Samuel","672121Y",8.00);
	Student *fran=new Student("Gonzalez","Da Silva","Fran","647821Y",5.0);
	cout<<""<<endl;

	cout<<"Hemos creado una lista con una capacidad máxima de 3 estudiantes, por lo que vamos a insertar a Apu, Kylo, Samuel y Fran. El de menor nota quedará fuera,"<<endl;
	cout<<"Entre alumno y alumno comprobaremos el estado de la lista."<<endl;
	cout<<" "<<endl;

	l->addStudent(*&apu);
	if(!l->full())
		cout<<"Apu añadido correctamente, queda espacio en la lista"<<endl;
	else
		cout<<"Lista llena. Si Apu tenia más nota que el último de la lista, entra en su lugar. Si no no entra."<<endl;
	cout<<" "<<endl;

	l->addStudent(*&kylo);
	if(!l->full())
		cout<<"Kylo añadido correctamente, queda espacio en la lista"<<endl;
	else
		cout<<"Lista llena. Si Kylo tenia más nota que el último de la lista, entra en su lugar. Si no no entra."<<endl;
	cout<<" "<<endl;

	l->addStudent(*&samuel);
	if(!l->full())
		cout<<"Samuel añadido correctamente, queda espacio en la lista"<<endl;
	else
		cout<<"Lista llena. Si Samuel tenia más nota que el último de la lista, entra en su lugar. Si no no entra."<<endl;
	cout<<" "<<endl;

	l->addStudent(*&fran);
	if(!l->full())
		cout<<"Fran añadido correctamente, queda espacio en la lista"<<endl;
	else
		cout<<"Lista llena. Si Fran tenia más nota que el último de la lista, entra en su lugar. Si no no entra."<<endl;
	cout<<" "<<endl;

	cout<<"ahora comprobamos cómo ha quedado la lista"<<endl;
	l->show();

	usleep(9000000);

	cout<<""<<endl;
	cout<<"Como el resto de métodos de la clase son muy sencillos, vamos a probar el removeStudent. Para ello vamos a borrar a Samuel y luego mostramos"<<endl;
	usleep(9000000);
	cout<<""<<endl;

	l->removeStudent(*&samuel);
	l->show();

	cout<<"FIN DE LA PRUEBA LISTA ESTUDIANTES"<<endl;

	delete l;
}

void Pruebas::p_grado() {

	Grado *g=new Grado(01,"Programación de Videojuegos", 2);
	cout<<"INICIO DE LA PRUEBA GRADO"<<endl;
	cout<<""<<endl;
	cout<<"Atencion esta prueba tiene retrasos de varios segundos entre partes para leer adecuadamente el procedimiento"<<endl;
	usleep(5000000);

	cout<<"Para ello creamos a 4 estudiantes con sus siguientes notas: "<<endl;
	cout<<"Apu,9.0 / Kylo,8.00 / Samuel,6.00 y Fran,5.0"<<endl;

	Student *apu= new Student("Nahasapee","mapetilon","Apu","70990099G",9.0);
	Student *kylo= new Student("Ren","Skywalker","Kylo","3232121Z",6.00);
	Student *samuel= new Student("L.","Jackson","Samuel","672121Y",8.00);
	Student *fran=new Student("Gonzalez","Da Silva","Fran","647821Y",5.0);
	cout<<""<<endl;
//todo corregir
	cout<<"El grado creado tiene 2 plazas libres. Los dos alumnos con más nota entrarán en la lista de admitidos, el resto pasarán a la lista de espera"<<endl;
	//g->addStudent(*&apu);
	//g->addStudent(*&kylo);
	//g->addStudent(*&samuel);
	//g->addStudent(*&fran);
	g->show();

	usleep(9000000);


	cout<<"FIN DE LA PRUEBA GRADO"<<endl;

	delete g;

}
