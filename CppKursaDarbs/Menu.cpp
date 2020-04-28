#include <string>
#include <iostream>
#include <vector>
#include <sstream> 

#include "TimsortDrawing.h"
#include "TimsortUser.h"

#include "User.h"
#include "Drawing.h"

#include "Add.h"
#include "Change.h"
#include "Del.h"
#include "Print.h"
#include "Search.h"
#include "SaveAndLoad.h"
#include "CheckForMistakes.h"
#include "Help.h"

#include "Menu.h"

using namespace std;

bool isInputNum(string input) {
	std::size_t found = input.find_first_not_of("0123456789");

	if (found != std::string::npos)
	{
		return false;
	}
	return true;
}

bool isToMenu(string value) {
	if ((value == "0") || ((value[0] == '0') && (value.length() == 1))) {
		return true;
	}
	else {
		return false;
	}
}

void errorMsg() {
	std::cout << "------------------------------------------------\n";
	std::cout << "Error\n";
	std::cout << "------------------------------------------------\n";
}

void mainMenu() {
	cin.clear();
	//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	string choise;
	int numChoise;

	while (true) {

		system("cls");

		returnToMenu() = false;
		std::cout << "------------------------------------------------\n";
		std::cout << "Main menu\n";
		std::cout << "\n";
		std::cout << "1 Add new user/drawing\n";
		std::cout << "2 Change user/drawing\n";
		std::cout << "3 Delete user/drawing\n";
		std::cout << "4 Print information about users/drawings\n";
		std::cout << "5 Search users/drawings\n";
		std::cout << "6 Save/load\n";
		std::cout << "7 Check for mistakes\n";
		std::cout << "8 Help\n";
		std::cout << "0 Exit\n";
		std::cout << "------------------------------------------------\n";

		cin.clear();
		//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::getline(std::cin, choise);

		if (isInputNum(choise)) {
			stringstream geek(choise);
			geek >> numChoise;
		} else {
			numChoise = -1;
		}

		switch (numChoise) {
			case (0): {
				endProgram() = true;
				break;
			}
			case (1): {
				add();
				break;
			}
			case (2): {
				change();
				break;
			}
			case (3): {
				del();
				break;
			}
			case (4): {
				print();
				break;
			}
			case (5): {
				search();
				break;
			}
			case (6): {
				saveLoad();
				break;
			}
			case (7): {
				check();
				break;
			}
			case (8): {
				help();
				break;
			}
			default:
				errorMsg();
				cin.get();
				break;
		}

		if (endProgram()) {
			string choise;
			int numChoise;

			while (true) {
				bool con = false;
				if (returnToMenu()) { break; }

				std::cout << "------------------------------------------------\n";
				std::cout << "Exit menu\n";
				std::cout << "\n";
				std::cout << "1 Exit with save\n";
				std::cout << "2 Exit without save\n";
				std::cout << "0 Return to main menu\n";
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
					endProgram() = false;
					con = true;
					break;
				}
				case (1): {
					if (check()) {
						save();
						con = true;
					}
					else {
						endProgram() = false;
						con = true;
						std::cout << "------------------------------------------------\n";
						std::cout << "Cancelling save and exit\n";
						std::cout << "------------------------------------------------\n";
						cin.get();
					}
					break;
				}
				case (2): {
					con = true;
					break;
				}
				default:
					errorMsg();
					break;
				}

				if (con) {
					break;
				}
			}

			if (endProgram()) {

				std::cout << "------------------------------------------------\n";
				std::cout << "End of work\n";
				std::cout << "------------------------------------------------\n";
				cin.get();
				break;
			}
		}
	}
};