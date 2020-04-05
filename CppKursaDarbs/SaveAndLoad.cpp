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
		std::cout << "------------------------------------------------\n";
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
			save();
			break;
		}
		case (2): {
			load();
			break;
		}
		case (3): {
			save();
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

		ofstream out(pathUsers + users()[i].getNick() + ".u", ios::binary);
		out.write((char*)&users()[i], sizeof(users()[i]));
		//in.read((char*)S, sizeof(S));          //в случае с массивом можно и так
		out.close();

	}

	for (int i = 0; i < drawings().size(); i++) {

		ofstream out(pathDrawings + drawings()[i].getId() + ".u", ios::binary);
		out.write((char*)&drawings()[i], sizeof(drawings()[i]));
		//in.read((char*)S, sizeof(S));          //в случае с массивом можно и так
		out.close();

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

	//fs::create_directories(pathUsers);
	for (auto& p : fs::directory_iterator(pathUsers)) {

		User tmp;

		ifstream in(p.path(), ios::binary);
		in.read((char*)&tmp, sizeof(User));
		in.close();

		users().push_back(tmp);

	}

	//fs::create_directories(pathDrawings);
	for (auto& p : fs::directory_iterator(pathDrawings)) {

		Drawing tmp;

		ifstream in(p.path(), ios::binary);
		in.read((char*)&tmp, sizeof(Drawing));
		in.close();

		drawings().push_back(tmp);

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