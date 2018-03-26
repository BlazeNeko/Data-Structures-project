/*
 * CompareStudent.cpp
 *
 *  Created on: 11 de may. de 2016
 *      Author: Javier Ballesteros Morón
				 Carlos Licha de la Encarnación
 */

#include "CompareStudent.h"

namespace std {

CompareStudent::CompareStudent() {
	// TODO Auto-generated constructor stub

}

CompareStudent::~CompareStudent() {
	// TODO Auto-generated destructor stub
}

int CompareStudent::operator ()(Student* s1, Student* s2) {
	if (s1->getSurn1() == s2->getSurn1()) {

		if (s1->getSurn2() == s2->getSurn2()) {
			if (s1->getName() == s2->getName()) {
				return 0;
			} else if (s1->getName() < s2->getName()) {
				return -1;
			} else {
				return 1;
			}

		} else if (s1->getSurn2() < s2->getSurn2()) {
			return -1;
		} else {
			return 1;
		}

	} else if (s1->getSurn1() < s2->getSurn1()) {
		return -1;
	} else {
		return 1;
	}

}

} /* namespace std */
