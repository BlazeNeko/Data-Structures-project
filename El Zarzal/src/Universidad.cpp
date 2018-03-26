/*
 * Universidad.cpp
 *
 *  Created on: 12 de abr. de 2016
  *      Author: Javier Ballesteros Morón
				Carlos Licha de la Encarnación
 */

#include "Universidad.h"

using namespace std;

Universidad::Universidad() {
	// TODO Auto-generated constructor stub
	g = new Titulaciones();
	this->lista = new SList();

}

Universidad::Universidad(SList* l) {

	g = new Titulaciones();
	this->lista = l;


}
//todo trabajar aqui





Universidad::~Universidad() {
	delete g;
	delete lista;

	// TODO Auto-generated destructor stub
}



void Universidad::recprocess(Student*& s) {
	Grado *gaux = NULL;
	Student *saux = NULL;
	if (s->firstpref() != -1) {
		g->getGrado(s->firstpref(), gaux);

		if (gaux->addStudent(s, saux)) {
			if (saux != NULL) {
				recprocess(saux);
			}
		} else { //caso en el que no sea admitido , automaticamente se vuelve a hacer con la siguiente opcion que ya administra el addstudent
			recprocess(s);
		}
	}

}

void Universidad::process() {
	lista->moveToBegin();
	Student *s;

	while (!lista->end()) { //Esto clasifica a los alumnos en grados
		lista->consult(s);
		recprocess(s);
		lista->next();
	}

}

void Universidad::showGrado(int i) {
	g->showGrado(i);
}

void Universidad::matriculation() {
	ifstream source;
	ofstream destination;
	Grado* degree;

	string code, surn1, surn2, name, dni, idstring;
	int id;
	source.open("matyrenuncias.txt", ios::in);

	for (id = 1; id <= 7; id++) {

		stringstream streamstr;
		string str;
		string namefile;
		streamstr << id;
		streamstr >> str;
		namefile = str + ".txt";
		destination.open(namefile.c_str(), ios::out | ios::trunc);
		g->getGrado(id, degree);

		destination << str + " " + degree->getName() << endl;
		destination << " " << endl;

		destination.close();
	}
	/*	destination.open("1.txt", ios::out | ios::trunc);

	 destination.close();
	 destination.open("2.txt", ios::out | ios::trunc);
	 destination.close();
	 destination.open("3.txt", ios::out | ios::trunc);
	 destination.close();
	 destination.open("4.txt", ios::out | ios::trunc);
	 destination.close();
	 destination.open("5.txt", ios::out | ios::trunc);
	 destination.close();
	 destination.open("6.txt", ios::out | ios::trunc);
	 destination.close();
	 destination.open("7.txt", ios::out | ios::trunc);
	 destination.close();
	 */
	while (!source.eof()) {

		getline(source, code, '#');
		if (!source.eof()) {
			getline(source, idstring, '#');
			id = atoi(idstring.c_str());
			getline(source, surn1, '#');
			getline(source, surn2, '#');
			getline(source, name, '#');
			getline(source, dni);

			if (code == "MAT") {
				g->getGrado(id, degree);
				degree->admitted(surn1, surn2, name, dni);

				for (int x = 1; x <= 7; x++) {
					g->getGrado(x, degree);
					degree->remove_wt(surn1, surn2, name);
					degree->remove_at(surn1, surn2, name);
				}

			} else if (code == "REN") { //code = REN
				g->getGrado(id, degree);
				degree->gives_up(surn1, surn2, name, dni);
				for (int x = 1; x <= 7; x++) {
					g->getGrado(x, degree);
					degree->remove_wt(surn1, surn2, name);
				}
			}

		}

	}
}

void Universidad::mainMenu() {
	cout
			<< "-------------------------------UNIVERSIDAD EL ZARZAL----------------------------------"
			<< endl;
	cout << "" << endl;
	int x;
	int i;
	Grado *aux;
	string cadena;
	string volver = "";
	string surn;

	cout << "	1-Asigna todos los estudiantes a los correspondientes grados."
			<< endl;
	cout << "" << endl;

	cout << "	2-Información acerca de los grados que ofrece la universidad"
			<< endl;
	cout << "" << endl;

	cout << "	3-Información de estudiante" << endl;
	cout << "" << endl;

	cout << "	4-Preparativos para matriculación" << endl;
	cout << "" << endl;

	cout << "	5-Matriculación" << endl;
	cout << "" << endl;

	cout << "	6-Mostrar información de los grados después de la matriculación" << endl;
	cout << "" << endl;

	cout << "	7-Mostrar los estudiantes de un grado que contengan el caracter introducido" << endl;
	cout << "" << endl;

	cout << "	8-Mostrar nota mínima de un grado después de la matriculación" << endl;
	cout << "" << endl;

	cout << "	9-Finalizar" << endl;
	cout << "" << endl;

	cout << "Introduzca la opción deseada: " << endl;
	cout << "" << endl;
	cin >> x;
	switch (x) {
	case 1:

		cout << "Asigna todos los estudiantes a los correspondientes grados."
				<< endl;
		usleep(3000000);
		cout << "" << endl;
		process();
		cout << " Los estudiantes han sido procesados" << endl;
		cout << " Regresando al menú principal..." << endl;
		usleep(2000000);

		cout << "" << endl;
		mainMenu();

		break;

	case 2:
		cout << "Información acerca de los grados que ofrece la universidad:"
				<< endl;
		cout << "" << endl;

		cout << "01# Grado en Ingenieria Informatica en Ingenieria del Software"
				<< endl;

		cout << "" << endl;
		cout
				<< "02# Grado en Ingenieria Informatica en Ingenieria de Computadores"
				<< endl;
		cout << "" << endl;
		cout << "03# Grado en Ingenieria de Sonido e Imagen en Telecomunicacion"
				<< endl;
		cout << "" << endl;
		cout << "04# Grado en Ingenieria Civil Construcciones Civiles" << endl;
		cout << "" << endl;
		cout << "05# Grado en Ingenieria Civil Hidrologia" << endl;
		cout << "" << endl;
		cout << "06# Grado en Ingenieria Civil Transportes y Servicios Urbanos"
				<< endl;
		cout << "" << endl;
		cout << "07# Grado en Edificacion" << endl;
		cout << "" << endl;

		cout << "Introduzca la ID grado del que desea saber mas." << endl;

		cin >> i;

		switch (i) {
		case 1:
			cout
					<< "01# Grado en Ingenieria Informatica en Ingenieria del Software"
					<< endl;
			g->getGrado(i, aux);
			aux->show();
			cout << " " << endl;
			cout << " " << endl;
			cout
					<< "Pulse cualquier tecla + enter para volver al menú principal"
					<< endl;
			cin >> volver;
			mainMenu();
			break;
		case 2:
			cout
					<< "02# Grado en Ingenieria Informatica en Ingenieria de Computadores"
					<< endl;
			g->getGrado(i, aux);
			aux->show();
			cout << " " << endl;
			cout << " " << endl;
			cout
					<< "Pulse cualquier tecla + enter para volver al menú principal"
					<< endl;
			cin >> volver;
			mainMenu();
			break;
		case 3:
			cout
					<< "03# Grado en Ingenieria de Sonido e Imagen en Telecomunicacion"
					<< endl;
			g->getGrado(i, aux);
			aux->show();
			cout << " " << endl;
			cout << " " << endl;
			cout
					<< "Pulse cualquier tecla + enter para volver al menú principal"
					<< endl;
			cin >> volver;
			mainMenu();
			break;
		case 4:
			cout << "04# Grado en Ingenieria Civil Construcciones Civiles"
					<< endl;
			g->getGrado(i, aux);
			aux->show();
			cout << " " << endl;
			cout << " " << endl;
			cout
					<< "Pulse cualquier tecla + enter para volver al menú principal"
					<< endl;
			cin >> volver;
			mainMenu();
			break;
		case 5:
			cout << "05# Grado en Ingenieria Civil Hidrologia" << endl;
			g->getGrado(i, aux);
			aux->show();
			cout << " " << endl;
			cout << " " << endl;
			cout
					<< "Pulse cualquier tecla + enter para volver al menú principal"
					<< endl;
			cin >> volver;
			mainMenu();
			break;
		case 6:
			cout
					<< "06# Grado en Ingenieria Civil Transportes y Servicios Urbanos"
					<< endl;
			g->getGrado(i, aux);
			aux->show();
			cout << " " << endl;
			cout << " " << endl;
			cout
					<< "Pulse cualquier tecla + enter para volver al menú principal"
					<< endl;
			cin >> volver;
			mainMenu();
			break;
		case 7:
			cout << "07# Grado en Edificacion" << endl;
			g->getGrado(i, aux);
			aux->show();
			cout << " " << endl;
			cout << " " << endl;
			cout
					<< "Pulse cualquier tecla + enter para volver al menú principal"
					<< endl;
			cin >> volver;
			mainMenu();
			break;

		default:
			cout << "No existe el grado seleccionado" << endl;
			cout << " " << endl;
			cout << " " << endl;
			cout
					<< "Pulse cualquier tecla + enter para volver al menú principal"
					<< endl;
			cin >> volver;
			mainMenu();
			break;
		}

		break;
	case 3:

		cout << "Indroduzca el DNI del estudiante que desea saber sus datos"
				<< endl;
		cin >> cadena;
		studentinfo(cadena);

		cout << " " << endl;
		cout << " " << endl;
		cout << "Pulse cualquier tecla + enter para volver al menú principal"
				<< endl;
		cin >> volver;
		mainMenu();
		break;

	case 4:
		cout << "Realizando los preparativos para la matriculación" << endl;
		cout << " " << endl;
		Grado *grado;
		for (int x = 1; x <= 7; x++) { //Esto vuelca las listas en árboles
			this->g->getGrado(x, grado);
			grado->insertTrees();
		}

		cout << "Aplicación lista." << endl;

		cout << " " << endl;
		cout << " " << endl;
		cout << "Pulse cualquier tecla + enter para volver al menú principal"
				<< endl;
		cin >> volver;
		mainMenu();
		break;

	case 5:

		cout << "Matriculando" << endl;
		matriculation();

		cout << " " << endl;
		cout << " " << endl;
		cout << "Pulse cualquier tecla + enter para volver al menú principal"
				<< endl;
		cin >> volver;
		mainMenu();
		break;

	case 6:

		cout << "Mostrar los grados que ofrece la universidad:"
		<< endl;
		cout << "" << endl;

		cout << "01# Grado en Ingenieria Informatica en Ingenieria del Software"
				<< endl;

		cout << "" << endl;
		cout
				<< "02# Grado en Ingenieria Informatica en Ingenieria de Computadores"
				<< endl;
		cout << "" << endl;
		cout << "03# Grado en Ingenieria de Sonido e Imagen en Telecomunicacion"
				<< endl;
		cout << "" << endl;
		cout << "04# Grado en Ingenieria Civil Construcciones Civiles" << endl;
		cout << "" << endl;
		cout << "05# Grado en Ingenieria Civil Hidrologia" << endl;
		cout << "" << endl;
		cout << "06# Grado en Ingenieria Civil Transportes y Servicios Urbanos"
				<< endl;
		cout << "" << endl;
		cout << "07# Grado en Edificacion" << endl;
		cout << "" << endl;

		cout << "Introduzca la ID grado del que desea saber mas." << endl;

		cin >> i;

		switch (i) {
		case 1:

			g->getGrado(i, aux);
			aux->show_at();
			cout << " " << endl;
			cout << " " << endl;
			cout
					<< "Pulse cualquier tecla + enter para volver al menú principal"
					<< endl;
			cin >> volver;
			mainMenu();
			break;
		case 2:

			g->getGrado(i, aux);
			aux->show_at();
			cout << " " << endl;
			cout << " " << endl;
			cout
					<< "Pulse cualquier tecla + enter para volver al menú principal"
					<< endl;
			cin >> volver;
			mainMenu();
			break;
		case 3:

			g->getGrado(i, aux);
			aux->show_at();
			cout << " " << endl;
			cout << " " << endl;
			cout
					<< "Pulse cualquier tecla + enter para volver al menú principal"
					<< endl;
			cin >> volver;
			mainMenu();
			break;
		case 4:

			g->getGrado(i, aux);
			aux->show_at();
			cout << " " << endl;
			cout << " " << endl;
			cout
					<< "Pulse cualquier tecla + enter para volver al menú principal"
					<< endl;
			cin >> volver;
			mainMenu();
			break;
		case 5:

			g->getGrado(i, aux);
			aux->show_at();
			cout << " " << endl;
			cout << " " << endl;
			cout
					<< "Pulse cualquier tecla + enter para volver al menú principal"
					<< endl;
			cin >> volver;
			mainMenu();
			break;
		case 6:

			g->getGrado(i, aux);
			aux->show_at();
			cout << " " << endl;
			cout << " " << endl;
			cout
					<< "Pulse cualquier tecla + enter para volver al menú principal"
					<< endl;
			cin >> volver;
			mainMenu();
			break;
		case 7:

			g->getGrado(i, aux);
			aux->show_at();
			cout << " " << endl;
			cout << " " << endl;
			cout
					<< "Pulse cualquier tecla + enter para volver al menú principal"
					<< endl;
			cin >> volver;
			mainMenu();
			break;

		default:
			cout << "No existe el grado seleccionado" << endl;
			cout << " " << endl;
			cout << " " << endl;
			cout
					<< "Pulse cualquier tecla + enter para volver al menú principal"
					<< endl;
			cin >> volver;
			mainMenu();
			break;
		}
		break;

	case 7:

		cout << "Seleccione el grado del que desea saber el estudiante :"
				<< endl;
				cout << "" << endl;

				cout << "01# Grado en Ingenieria Informatica en Ingenieria del Software"
						<< endl;

				cout << "" << endl;
				cout
						<< "02# Grado en Ingenieria Informatica en Ingenieria de Computadores"
						<< endl;
				cout << "" << endl;
				cout << "03# Grado en Ingenieria de Sonido e Imagen en Telecomunicacion"
						<< endl;
				cout << "" << endl;
				cout << "04# Grado en Ingenieria Civil Construcciones Civiles" << endl;
				cout << "" << endl;
				cout << "05# Grado en Ingenieria Civil Hidrologia" << endl;
				cout << "" << endl;
				cout << "06# Grado en Ingenieria Civil Transportes y Servicios Urbanos"
						<< endl;
				cout << "" << endl;
				cout << "07# Grado en Edificacion" << endl;
				cout << "" << endl;

				cout << "Introduzca la ID grado del que desea saber mas." << endl;

				cin >> i;

				switch (i) {

				case 1:

					cout<<"Introduzca los caracteres del apellido de los estudiantes que desea buscar"<<endl;
					cin >>surn;
					g->getGrado(i, aux);
					aux->show_by_similarities(surn);
					cout << " " << endl;
					cout << " " << endl;
					cout
							<< "Pulse cualquier tecla + enter para volver al menú principal"
							<< endl;
					cin >> volver;
					mainMenu();
					break;

				case 2:

					cout<<"Introduzca los caracteres del apellido de los estudiantes que desea buscar"<<endl;
										cin >>surn;
										g->getGrado(i, aux);
										aux->show_by_similarities(surn);
										cout << " " << endl;
										cout << " " << endl;
										cout
												<< "Pulse cualquier tecla + enter para volver al menú principal"
												<< endl;
										cin >> volver;
										mainMenu();
										break;
				case 3:

					cout<<"Introduzca los caracteres del apellido de los estudiantes que desea buscar"<<endl;
										cin >>surn;
										g->getGrado(i, aux);
										aux->show_by_similarities(surn);
										cout << " " << endl;
										cout << " " << endl;
										cout
												<< "Pulse cualquier tecla + enter para volver al menú principal"
												<< endl;
										cin >> volver;
										mainMenu();
										break;
				case 4:

					cout<<"Introduzca los caracteres del apellido de los estudiantes que desea buscar"<<endl;
										cin >>surn;
										g->getGrado(i, aux);
										aux->show_by_similarities(surn);
										cout << " " << endl;
										cout << " " << endl;
										cout
												<< "Pulse cualquier tecla + enter para volver al menú principal"
												<< endl;
										cin >> volver;
										mainMenu();
										break;
				case 5:

					cout<<"Introduzca los caracteres del apellido de los estudiantes que desea buscar"<<endl;
										cin >>surn;
										g->getGrado(i, aux);
										aux->show_by_similarities(surn);
										cout << " " << endl;
										cout << " " << endl;
										cout
												<< "Pulse cualquier tecla + enter para volver al menú principal"
												<< endl;
										cin >> volver;
										mainMenu();
										break;
				case 6:

					cout<<"Introduzca los caracteres del apellido de los estudiantes que desea buscar"<<endl;
										cin >>surn;
										g->getGrado(i, aux);
										aux->show_by_similarities(surn);
										cout << " " << endl;
										cout << " " << endl;
										cout
												<< "Pulse cualquier tecla + enter para volver al menú principal"
												<< endl;
										cin >> volver;
										mainMenu();
										break;
				case 7:

					cout<<"Introduzca los caracteres del apellido de los estudiantes que desea buscar"<<endl;
										cin >>surn;
										g->getGrado(i, aux);
										aux->show_by_similarities(surn);
										cout << " " << endl;
										cout << " " << endl;
										cout
												<< "Pulse cualquier tecla + enter para volver al menú principal"
												<< endl;
										cin >> volver;
										mainMenu();
										break;


				default:
					cout << "No existe el grado seleccionado" << endl;
					cout << " " << endl;
					cout << " " << endl;
					cout
							<< "Pulse cualquier tecla + enter para volver al menú principal"
							<< endl;
					cin >> volver;
					mainMenu();
					break;
				}

	case 8:
		cout << "Mostrar los grados que ofrece la universidad:"
		<< endl;
		cout << "" << endl;

		cout << "01# Grado en Ingenieria Informatica en Ingenieria del Software"
				<< endl;

		cout << "" << endl;
		cout
				<< "02# Grado en Ingenieria Informatica en Ingenieria de Computadores"
				<< endl;
		cout << "" << endl;
		cout << "03# Grado en Ingenieria de Sonido e Imagen en Telecomunicacion"
				<< endl;
		cout << "" << endl;
		cout << "04# Grado en Ingenieria Civil Construcciones Civiles" << endl;
		cout << "" << endl;
		cout << "05# Grado en Ingenieria Civil Hidrologia" << endl;
		cout << "" << endl;
		cout << "06# Grado en Ingenieria Civil Transportes y Servicios Urbanos"
				<< endl;
		cout << "" << endl;
		cout << "07# Grado en Edificacion" << endl;
		cout << "" << endl;

		cout << "Introduzca la ID grado del que desea saber mas." << endl;

		cin >> i;

		switch (i) {
		case 1:

			g->getGrado(i, aux);
			cout << aux->get_tree_min_grade() << endl;
			cout << " " << endl;
			cout << " " << endl;
			cout
					<< "Pulse cualquier tecla + enter para volver al menú principal"
					<< endl;
			cin >> volver;
			mainMenu();
			break;
		case 2:

			g->getGrado(i, aux);
			cout << aux->get_tree_min_grade() << endl;
			cout << " " << endl;
			cout << " " << endl;
			cout
					<< "Pulse cualquier tecla + enter para volver al menú principal"
					<< endl;
			cin >> volver;
			mainMenu();
			break;
		case 3:

			g->getGrado(i, aux);
			cout << aux->get_tree_min_grade() << endl;
			cout << " " << endl;
			cout << " " << endl;
			cout
					<< "Pulse cualquier tecla + enter para volver al menú principal"
					<< endl;
			cin >> volver;
			mainMenu();
			break;
		case 4:

			g->getGrado(i, aux);
			cout << aux->get_tree_min_grade() << endl;
			cout << " " << endl;
			cout << " " << endl;
			cout
					<< "Pulse cualquier tecla + enter para volver al menú principal"
					<< endl;
			cin >> volver;
			mainMenu();
			break;
		case 5:

			g->getGrado(i, aux);
			cout << aux->get_tree_min_grade() << endl;
			cout << " " << endl;
			cout << " " << endl;
			cout
					<< "Pulse cualquier tecla + enter para volver al menú principal"
					<< endl;
			cin >> volver;
			mainMenu();
			break;
		case 6:

			g->getGrado(i, aux);
			cout << aux->get_tree_min_grade() << endl;
			cout << " " << endl;
			cout << " " << endl;
			cout
					<< "Pulse cualquier tecla + enter para volver al menú principal"
					<< endl;
			cin >> volver;
			mainMenu();
			break;
		case 7:

			g->getGrado(i, aux);
			cout << aux->get_tree_min_grade() << endl;
			cout << " " << endl;
			cout << " " << endl;
			cout
					<< "Pulse cualquier tecla + enter para volver al menú principal"
					<< endl;
			cin >> volver;
			mainMenu();
			break;

		default:
			cout << "No existe el grado seleccionado" << endl;
			cout << " " << endl;
			cout << " " << endl;
			cout
					<< "Pulse cualquier tecla + enter para volver al menú principal"
					<< endl;
			cin >> volver;
			mainMenu();
			break;
		}
		break;

	case 9:

		cout << "FINALIZANDO APLICACIÓN..." << endl;
		usleep(1000000);
		cout << "  ." << endl;
		usleep(1000000);
		cout << "  ." << endl;
		usleep(1000000);
		cout << "  ." << endl;
		usleep(2000000);
		cout << "¡¡¡HASTA OTRA!!!" << endl;
		break;

	default:
		cout << "La opcion escogida no existe" << endl;
		cout << " " << endl;
		cout << " " << endl;
		cout << "Pulse cualquier tecla + enter para volver al menú principal"
				<< endl;
		cin >> volver;
		mainMenu();
	}

}

void Universidad::studentinfo(string dni) {
	bool enc = false;
	lista->moveToBegin();
	while (!lista->end() && !enc) {
		Student * aux;
		lista->consult(aux);
		if (aux->getDNI() == dni) {
			enc = true;
			aux->show();
		}
		lista->next();

	}
	if (!enc)
		cout << "No existe ningun estudiante con ese DNI" << endl;

}

