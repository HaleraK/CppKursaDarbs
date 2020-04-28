#include <string>
#include <vector>
#include <sstream> 

#include <fstream>
#include <iostream>
#include <filesystem>

#include <stdio.h>
#include <windows.h>

#include "SaveAndLoad.h"
#include "Menu.h"

#include "User.h"
#include "Drawing.h"
#include "CheckForMistakes.h"

//Файлы будут храниться в папках
//	data/Drawings - файлы по типу drawing.d
//	data/Users - файлы по типу user.u

using std::string;
using std::vector;
using namespace std;

namespace fs = std::filesystem;



void saveLoad() {

	string choise;
	int numChoise;

	while (true) {
		if (returnToMenu()) { break; }

		std::cout << "------------------------------------------------\n";
		std::cout << "Save/load menu\n";
		std::cout << "\n";
		std::cout << "1 Save\n";
		std::cout << "2 Save and load\n";
		std::cout << "3 Load without save\n";
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
			if (check()) {
				save();
			}
			else {
				std::cout << "------------------------------------------------\n";
				std::cout << "Cancelling save\n";
				std::cout << "------------------------------------------------\n";
			}

			break;
		}
		case (2): {
			if (check()) {
				save();
				load();
			}
			else {
				std::cout << "------------------------------------------------\n";
				std::cout << "Cancelling save and load\n";
				std::cout << "------------------------------------------------\n";
			}
			break;
		}
		case (3): {
			load();
			break;
		}
		default:
			errorMsg();
			break;
		}
	}

}

void save() {

	delFiles();

	string pathUsers = "data/Users/";
	string pathDrawings = "data/Drawings/";

	for (int i = 0; i < users().size(); i++) {
		users()[i].serilization(pathUsers);
	}

	for (int i = 0; i < drawings().size(); i++) {
		drawings()[i].serilization(pathDrawings);
	}

}

void load() {

	if (!users().empty()) {
		std::cout << users()[0].getNick() << "\n";
	}

	users().clear();
	drawings().clear();

	string pathUsers = "data/Users/";
	string pathDrawings = "data/Drawings/";

	for (auto& p : fs::directory_iterator(pathUsers)) {

		users().push_back(User());
		users().back().deserilization(p);

	}

	for (auto& p : fs::directory_iterator(pathDrawings)) {

		drawings().push_back(Drawing());
		drawings().back().deserilization(p);

	}

}

void delFiles() {

	for (int i = 0; i < forDelDrawings().size(); i++) {
	
		string toDel = "data/Drawings/" + forDelDrawings()[i] + ".d";
		char delItem[200];
		strcpy_s(delItem, toDel.c_str());
		remove(delItem);

	}
	forDelDrawings().clear();

	for (int i = 0; i < forDelUsers().size(); i++) {

		string toDel = "data/Users/" + forDelUsers()[i] + ".u";
		char delItem[200];
		strcpy_s(delItem, toDel.c_str());
		remove(delItem);

	}
	forDelUsers().clear();

}