// TimeDateEvenet.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "EventCollection.h"


	void printEvent(const Event & e) {
		std::cout << e.getName() << std::endl;
	}

	int main() {
		EventCollection e;

		Event OOP("OOP",
			24, 3, 2023,
			11, 0, 0,
			13, 0, 0
		);

		Event DSTR("DIS",
			24, 3, 2023,
			13, 0, 0,
			14, 0, 0
		);

		Event DIS("DSTR",
			24, 3, 2023,
			11, 0, 0,
			14, 0, 0
		);

		Event GEOM("GEOM",
			24, 3, 2023,
			14, 0, 0,
			16, 0, 0
		);

		Event ev("Name",
			25, 3, 2023,
			22, 0, 0,
			23, 0, 0
		);


		e.addEvent(OOP);
		e.addEvent(DIS);
		e.addEvent(DSTR);
		e.addEvent(GEOM);
		e.addEvent(ev);

		BulgarianDate argDate(24, 3, 2023);

		EventCollection res = e.maxEvents(argDate);
		res.print();
	}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
