#include <string>
#include <iostream>
#include <vector>
#include <sstream> 

#include "User.h"
#include "Drawing.h"
#include "Menu.h"
#include "Add.h"
#include "Print.h"

using namespace std;

void add() {

	string choise;
	int numChoise;

	while (true) {
		if (returnToMenu()) { break; }

		std::cout << "------------------------------------------------\n";
		std::cout << "1 Add new user\n";
		std::cout << "2 Add new drawing\n";
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
			addUser();
			break;
		}
		case (2): {
			addDrawing();
			break;
		}
		default:
			errorMsg();
			break;
		}
	}
}

void addUser() {

	while (true) {
		if (returnToMenu()) { break; }
	
		createUser();

		if (returnToMenu()) { break; }

		outUser(users().size() - 1, 'a');

	}

}

void addDrawing() {

	while (true) {
		if (returnToMenu()) { break; }
		
		createDrawing();

		if (returnToMenu()) { break; }

		outDrawing(drawings().size() - 1, 'a');

	}

}

void createUser() {

	string value;
	vector<string> first6param;
	first6param.resize(6);
	string about;
	int pos;

	while (true) {
		if (returnToMenu()) { break; }

		value = "";

		first6param.clear();
		about = "";
		pos = 0;

		std::cout << "------------------------------------------------\n";
		std::cout << "Please input in this type (input 0 to go main menu), about not nessasary:\n";
		std::cout << "[name] [surname] [nick] [login] [password] [dateOfReg] [-about] \n";
		std::cout << "------------------------------------------------\n";

		//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin.clear();
		std::getline (std::cin, value);

		if (isToMenu(value)) {
			returnToMenu() = true;
			break;
		}

		for (int i = 0; i < 6; i++) {


			first6param.push_back(createOneWord(value, pos));
			pos += first6param[i].length() + 1;

			if (first6param[i] == "") {
				errorMsg();
				continue;
			}

		}

		if (value.length() > pos) {
			about = createLastParam(value, pos);
		}

		break;

	}

	if (!returnToMenu()) {

		if (about.empty()) {
			users().push_back(User(first6param[0], first6param[1], first6param[2], first6param[3], first6param[4], first6param[5]));
		}
		else {
			users().push_back(User(first6param[0], first6param[1], first6param[2], first6param[3], first6param[4], first6param[5], about));
		}
	}
}

void createDrawing() {

	string value;
	vector<string> first5param;
	first5param.resize(5);
	string description;
	vector<string> tags;
	int pos;

	while (true) {
		if (returnToMenu()) { break; }

		value = "";

		first5param.clear();
		description = "";
		pos = 0;

		std::cout << "------------------------------------------------\n";
		std::cout << "Please input in this type (input 0 to go main menu), tags and description not nessasary:\n";
		std::cout << "[owner] [drawingId] [title] [fileName] [dateAndTimeOfAdd] [-tags] [-description]\n";
		std::cout << "------------------------------------------------\n";

		cin.clear();
		//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::getline(std::cin, value);
		if (isToMenu(value)) {
			returnToMenu() = true;
			break;
		}

		for (int i = 0; i < 6; i++) {


			first5param.push_back(createOneWord(value, pos));
			pos += first5param[i].length() + 1;

			if (first5param[i] == "") {
				errorMsg();
				continue;
			}

		}

		while (true) {
			if (value.length() > pos) {
				if (value[pos] == '#') {
					tags.push_back(createOneWord(value, pos));
					pos += tags.back().length() + 1;
				}
				else {
					break;
				}
			}
			else {
				break;
			}
		}
				

		if (value.length() > pos) {
			description = createLastParam(value, pos);
		}

		break;

	}

	if (!returnToMenu()) {

		if (tags.empty() && description.empty()) {
			drawings().push_back(Drawing(first5param[0], first5param[1], first5param[2], first5param[3], first5param[4]));
		}
		if (!tags.empty() && description.empty()) {
			drawings().push_back(Drawing(first5param[0], first5param[1], first5param[2], first5param[3], first5param[4], tags));
		}
		if (tags.empty() && !description.empty()) {
			drawings().push_back(Drawing(first5param[0], first5param[1], first5param[2], first5param[3], first5param[4], description));
		}
		if (!tags.empty() && !description.empty()) {
			drawings().push_back(Drawing(first5param[0], first5param[1], first5param[2], first5param[3], first5param[4], tags, description));
		}
		
	}
}

string createOneWord(string input, int pos) {
	string out;
	int i = pos;
	while (true) {


		if (i < input.length()) {
			if ((input[i] != ' ')) {
				out += input[i];
				i++;
			}
			else {
				return out;
			}
		}
		else {
			return out;
		}

	}
	return out;
}

string createLastParam(string input, int pos) {
	string out;
	int i = pos;

	while (true) {

		if (i < input.length()) {
			out += input[i];
			i++;
		}
		else {
			return out;
		}

	}
}