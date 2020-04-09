#include <string>
#include <iostream>
#include <vector>
#include <sstream> 

#include "User.h"
#include "Drawing.h"
#include "Menu.h"
#include "Del.h"
#include "Search.h"

using namespace std;

void del() {

	string choise;
	int numChoise;

	while (true) {
		if (returnToMenu()) { break; }

		std::cout << "------------------------------------------------\n";
		std::cout << "1 Delete\n";
		std::cout << "\n";
		std::cout << "1 User\n";
		std::cout << "2 Drawing\n";
		std::cout << "0 Main menu\n";
		std::cout << "------------------------------------------------\n";

		cin.clear();
		//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::getline(std::cin, choise);

		if (isInputNum(choise)) {
			stringstream geek(choise);
			geek >> numChoise;
		}
		else {
			numChoise = -1;
		}

		switch (numChoise) {
		case (0): {
			returnToMenu() = true;
			break;
		}
		case (1): {
			delUser();
			break;
		}
		case (2): {
			delDrawing();
			break;
		}
		default:
			errorMsg();
			break;
		}
	}
};

void delUser() {

	string choise;
	int i;

	while (true) {
		if (returnToMenu()) { break; }

		while (true) {
			if (returnToMenu()) { break; }

			std::cout << "------------------------------------------------\n";
			std::cout << "Please input users nick (input 0 to go main menu):\n";
			std::cout << "------------------------------------------------\n";

			cin.clear();
			//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::getline(std::cin, choise);

			if (isToMenu(choise)) {
				returnToMenu() = true;
				break;
			}

			i = searchUserByNick(choise);

			if (i != -1) {
				break;
			}
			else {
				errorMsg();
			}

		}

		if (isToMenu(choise)) {
			returnToMenu() = true;
			break;
		}

		forDelUsers().push_back(users()[i].getNick());
		users().erase(users().begin() + i);

		std::cout << "------------------------------------------------\n";
		std::cout << choise << " user deleted\n";
		std::cout << "------------------------------------------------\n";

	}

};

void delDrawing() {

	string choise;
	int i;

	while (true) {
		if (returnToMenu()) { break; }

		while (true) {
			if (returnToMenu()) { break; }

			std::cout << "------------------------------------------------\n";
			std::cout << "Please input drawing id (input 0 to go main menu):\n";
			std::cout << "------------------------------------------------\n";

			cin.clear();
			//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::getline(std::cin, choise);

			if (isToMenu(choise)) {
				returnToMenu() = true;
				break;
			}

			i = searchDrawingById(choise);

			if (i != -1) {
				break;
			}
			else {
				errorMsg();
			}

		}

		if (isToMenu(choise)) {
			returnToMenu() = true;
			break;
		}

		forDelDrawings().push_back(drawings()[i].getId());
		drawings().erase(drawings().begin() + i);

		std::cout << "------------------------------------------------\n";
		std::cout << choise << " drawing deleted\n";
		std::cout << "------------------------------------------------\n";

	}

};