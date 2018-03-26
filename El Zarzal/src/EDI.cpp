//============================================================================
// Name        : EDI.cpp
// Author      : Carlos Licha y Javier Ballesteros 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Colapreferencias.h"
#include "Pruebas.h"
#include "unistd.h"
#include "student.h"
#include "ilist.h"
#include "ListaEstudiantes.h"
#include "Titulaciones.h"
#include "ListaAdmitidos.h"
#include "Grado.h"
#include "Universidad.h"
#include "string"
#include "BstreeStudent.h"
using namespace std;




int main() {
SList *s=new SList(1);// 1 activa el que da en clase

	Universidad u(s);
	u.mainMenu();

delete s;

	return 0;
}
