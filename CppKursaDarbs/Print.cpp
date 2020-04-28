#include <string>
#include <iostream>
#include <vector>
#include <sstream> 
#include <iomanip>

#include "User.h"
#include "Drawing.h"
#include "Menu.h"
#include "Print.h"
#include "Search.h"
#include "TimsortUser.h"
#include "TimsortDrawing.h"

using namespace std;

void print() {

	string choise;
	int numChoise;

	while (true) {
		if (returnToMenu()) { break; }

		std::cout << "------------------------------------------------\n";
		std::cout << "Print about\n";
		std::cout << "\n";
		std::cout << "1 One user\n";
		std::cout << "2 One drawing\n";
		std::cout << "3 Users\n";
		std::cout << "4 Drawings\n";
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
			printUser();
			break;
		}
		case (2): {
			printDrawing();
			break;
		}
		case (3): {
			printUsers();
			break;
		}
		case (4): {
			printDrawings();
			break;
		}
		default:
			errorMsg();
			break;
		}
	}
}

void printUser() {

	string choise;
	int numChoise;
	int i;

	while (true) {
		if (returnToMenu()) { break; }

		while (true) {

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

		std::cout << "------------------------------------------------\n";
		std::cout << "Print informations about " << users()[i].getNick() << " user\n";
		std::cout << "\n";
		std::cout << "1 All\n";
		std::cout << "2 Without login, pasword and about\n";
		std::cout << "3 Only nick and users drawings\n";
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
			outUser(i, 'a');
			break;
		}
		case (2): {
			outUser(i, 'm');
			break;
		}
		case (3): {
			outUser(i, 's');
			break;
		}
		default:
			errorMsg();
			break;
		}
	}
};

void printDrawing() {

	string choise;
	int numChoise;
	int i;

	while (true) {
		if (returnToMenu()) { break; }

		while (true) {

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

		std::cout << "------------------------------------------------\n";
		std::cout << "Print informations about " << drawings()[i].getId() << " drawing\n";
		std::cout << "\n";
		std::cout << "1 All\n";
		std::cout << "2 Without description\n";
		std::cout << "3 Only user nick, title, id and file name\n";
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
			outDrawing(i, 'a');
			break;
		}
		case (2): {
			outDrawing(i, 'm');
			break;
		}
		case (3): {
			outDrawing(i, 's');
			break;
		}
		default:
			errorMsg();
			break;
		}
	}
};

void printUsers() {

	string choise;
	int numChoise;
	bool con = false;

	while (true) {
		if (returnToMenu()) { break; }

		while (true) {
			if (returnToMenu()) { break; }

			std::cout << "------------------------------------------------\n";
			std::cout << "Sort users by\n";
			std::cout << "\n";
			std::cout << "1 Without\n";
			std::cout << "2 Name\n";
			std::cout << "3 Surname\n";
			std::cout << "4 Nick\n";
			std::cout << "5 Login\n";
			std::cout << "6 Password\n";
			std::cout << "7 Date by registration\n";
			std::cout << "0 Main menu\n";
			std::cout << "------------------------------------------------\n";

			cin.clear();
			//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::getline(std::cin, choise);

			if (isToMenu(choise)) {
				returnToMenu() = true;
				break;
			}

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
				con = true;
				break;
			}
			case (2): {
				timSortUsers(1, users().size());
				con = true;
				break;
			}
			case (3): {
				timSortUsers(2, users().size());
				con = true;
				break;
			}
			case (4): {
				timSortUsers(3, users().size());
				con = true;
				break;
			}
			case (5): {
				timSortUsers(4, users().size());
				con = true;
				break;
			}
			case (6): {
				timSortUsers(5, users().size());
				con = true;
				break;
			}
			case (7): {
				timSortUsers(6, users().size());
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

		if (returnToMenu()) { break; }

		std::cout << "------------------------------------------------\n";
		std::cout << "Print informations about users\n";
		std::cout << "\n";
		std::cout << "1 All\n";
		std::cout << "2 Without login, pasword and about\n";
		std::cout << "3 Only nick and users drawings\n";
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
			tableUsers('a', { -1 });
			break;
		}
		case (2): {
			tableUsers('m', { -1 });
			break;
		}
		case (3): {
			tableUsers('s', { -1 });
			break;
		}
		default:
			errorMsg();
			break;
		}
	}
};

void printDrawings() {

	string choise;
	int numChoise;
	bool con = false;

	while (true) {
		if (returnToMenu()) { break; }

		while (true) {
			if (returnToMenu()) { break; }

			std::cout << "------------------------------------------------\n";
			std::cout << "Sort drawings by\n";
			std::cout << "\n";
			std::cout << "1 Without\n";
			std::cout << "2 Owner\n";
			std::cout << "3 Drawing Id\n";
			std::cout << "4 Title\n";
			std::cout << "5 File name\n";
			std::cout << "6 Date and time of add\n";
			std::cout << "0 Main menu\n";
			std::cout << "------------------------------------------------\n";

			cin.clear();
			//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::getline(std::cin, choise);

			if (isToMenu(choise)) {
				returnToMenu() = true;
				break;
			}

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
				con = true;
				break;
			}
			case (2): {
				timSortDrawings(1, drawings().size());
				con = true;
				break;
			}
			case (3): {
				timSortDrawings(2, drawings().size());
				con = true;
				break;
			}
			case (4): {
				timSortDrawings(3, drawings().size());
				con = true;
				break;
			}
			case (5): {
				timSortDrawings(4, drawings().size());
				con = true;
				break;
			}
			case (6): {
				timSortDrawings(5, drawings().size());
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

		if (returnToMenu()) { break; }

		std::cout << "------------------------------------------------\n";
		std::cout << "Print informations about drawings\n";
		std::cout << "\n";
		std::cout << "1 All\n";
		std::cout << "2 Without description\n";
		std::cout << "3 Only user nick, title, id and file name\n";
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
			tableDrawings('a', { -1 });
			break;
		}
		case (2): {
			tableDrawings('m', { -1 });
			break;
		}
		case (3): {
			tableDrawings('s', { -1 });
			break;
		}
		default:
			errorMsg();
			break;
		}
	}
}

void outUser(int i, char type) {
	std::cout << "------------------------------------------------\n";
	std::cout << "User (" << users()[i].getNick() << "):\n";
	std::cout << "\n";

	if (type == 'a') {
		std::cout << "LID: " << i << "\n";
		std::cout << "NICK: " << users()[i].getNick() << "\n";
		std::cout << "NAME: " << users()[i].getName() << "\n";
		std::cout << "SURNAME: " << users()[i].getSurname() << "\n";
		std::cout << "LOGIN: " << users()[i].getLogin() << "\n";
		std::cout << "PASSWORD: " << users()[i].getPassword() << "\n";
		std::cout << "DATE OF REGISTRATION: " << users()[i].getDateOfReg() << "\n";
		std::cout << "ABOUT: " << users()[i].getAbout() << "\n";
		std::cout << "DRAWINGS (" << users()[i].getCountDrawingIDs() << "): " << users()[i].getDrawingIDs() << "\n";
	}
	if (type == 'm') {
		std::cout << "LID: " << i << "\n";
		std::cout << "NICK: " << users()[i].getNick() << "\n";
		std::cout << "NAME: " << users()[i].getName() << "\n";
		std::cout << "SURNAME: " << users()[i].getSurname() << "\n";
		std::cout << "DATE OF REGISTRATION: " << users()[i].getDateOfReg() << "\n";
		std::cout << "DRAWINGS (" << users()[i].getCountDrawingIDs() << "): " << users()[i].getDrawingIDs() << "\n";
	}
	if (type == 's') {
		std::cout << "LID: " << i << "\n";
		std::cout << "NICK: " << users()[i].getNick() << "\n";
		std::cout << "DRAWINGS (" << users()[i].getCountDrawingIDs() << "): " << users()[i].getDrawingIDs() << "\n";
	}

	std::cout << "------------------------------------------------" << std::endl;;
};

void outDrawing(int i, char type) {
	std::cout << "------------------------------------------------\n";
	std::cout << "Drawing (" << drawings()[i].getId() << "):\n";
	std::cout << "\n";

	if (type == 'a') {
		std::cout << "LID: " << i << "\n";
		std::cout << "TITLE: " << drawings()[i].getTitle() << "\n";
		std::cout << "OWNER: " << drawings()[i].getUserNick() << "\n";
		std::cout << "ID: " << drawings()[i].getId() << "\n";
		std::cout << "FILE NAME: " << drawings()[i].getFileName() << "\n";
		std::cout << "DATE AND TIME OF CREATION: " << drawings()[i].getDateAndTimeOfAdd() << "\n";
		std::cout << "DESCRIPTION: " << drawings()[i].getDescription() << "\n";
		std::cout << "TAGS (" << drawings()[i].getCountTags() << "): " << drawings()[i].getTags() << "\n";
	}
	if (type == 'm') {
		std::cout << "LID: " << i << "\n";
		std::cout << "TITLE: " << drawings()[i].getTitle() << "\n";
		std::cout << "OWNER: " << drawings()[i].getUserNick() << "\n";
		std::cout << "ID: " << drawings()[i].getId() << "\n";
		std::cout << "FILE NAME: " << drawings()[i].getFileName() << "\n";
		std::cout << "DATE AND TIME OF CREATION: " << drawings()[i].getDateAndTimeOfAdd() << "\n";
		std::cout << "TAGS (" << drawings()[i].getCountTags() << "): " << drawings()[i].getTags() << "\n";
	}
	if (type == 's') {
		std::cout << "LID: " << i << "\n";
		std::cout << "TITLE: " << drawings()[i].getTitle() << "\n";
		std::cout << "OWNER: " << drawings()[i].getUserNick() << "\n";
		std::cout << "ID: " << drawings()[i].getId() << "\n";
		std::cout << "FILE NAME: " << drawings()[i].getFileName() << "\n";
	}

	std::cout << "------------------------------------------------" << std::endl;;
};

void tableUsers(char type, vector<int> elements) {
	if (elements.empty()) {
		return;
	}
	std::cout << "------------------------------------------------\n";
	std::cout << "Table users\n";
	std::cout << "\n";

	int j = 0;

	if (type == 'a') {
		std::cout << std::setw(4) << std::left << "LID"
			<< std::setw(16) << "NICK"
			<< std::setw(16) << "NAME"
			<< std::setw(16) << "SURNAME"
			<< std::setw(16) << "LOGIN"
			<< std::setw(16) << "PASSWORD"
			<< std::setw(16) << "DATE OF REG"
			<< std::setw(32) << "ABOUT"
			<< "DRAWINGS IDS"
			<< std::endl;
		std::cout << "\n";

		if (elements[0] != -1) {
			for (int i = 0; i < users().size(); i++) {
				if (j < elements.size()) {
					if ((i == elements[j])) {
						std::cout << std::setw(4) << std::left << i
							<< std::setw(16) << users()[i].getNick()
							<< std::setw(16) << users()[i].getName()
							<< std::setw(16) << users()[i].getSurname()
							<< std::setw(16) << users()[i].getLogin()
							<< std::setw(16) << users()[i].getPassword()
							<< std::setw(16) << users()[i].getDateOfReg();
						if (users()[i].getAbout().length() > 25) {
							std::cout << std::setw(32) << users()[i].getAbout().substr(0, 25) + "...";
						}
						else {
							std::cout << std::setw(32) << users()[i].getAbout();
						}
						if (users()[i].getDrawingIDs().length() > 25) {
							std::cout << "(" + to_string(users()[i].getCountDrawingIDs()) + ") " + users()[i].getDrawingIDs().substr(0, 25) + "...";
						}
						else  if (users()[i].getCountDrawingIDs() != 0) {
							std::cout << "(" + to_string(users()[i].getCountDrawingIDs()) + ") " + users()[i].getDrawingIDs().substr(0, 25);
						}
						std::cout << std::endl;
						j++;
					}
				}
			}
		}
		else if (elements[0] == -1) {
			for (int i = 0; i < users().size(); i++) {
				std::cout << std::setw(4) << std::left << i
					<< std::setw(16) << users()[i].getNick()
					<< std::setw(16) << users()[i].getName()
					<< std::setw(16) << users()[i].getSurname()
					<< std::setw(16) << users()[i].getLogin()
					<< std::setw(16) << users()[i].getPassword()
					<< std::setw(16) << users()[i].getDateOfReg();
				if (users()[i].getAbout().length() > 25) {
					std::cout << std::setw(32) << users()[i].getAbout().substr(0, 25) + "...";
				}
				else {
					std::cout << std::setw(32) << users()[i].getAbout();
				}
				if (users()[i].getDrawingIDs().length() > 25) {
					std::cout << "(" + to_string(users()[i].getCountDrawingIDs()) + ") " + users()[i].getDrawingIDs().substr(0, 25) + "...";
				}
				else  if (users()[i].getCountDrawingIDs() != 0) {
					std::cout << "(" + to_string(users()[i].getCountDrawingIDs()) + ") " + users()[i].getDrawingIDs().substr(0, 25);
				}
				std::cout << std::endl;
			}
		}

	}
	if (type == 'm') {
		std::cout << std::setw(4) << std::left << "LID"
			<< std::setw(16) << "NICK"
			<< std::setw(16) << "NAME"
			<< std::setw(16) << "SURNAME"
			<< std::setw(16) << "DATE OF REG"
			<< "DRAWINGS IDS"
			<< std::endl;
		std::cout << "\n";

		if (elements[0] != -1) {
			for (int i = 0; i < users().size(); i++) {
				if (j < elements.size()) {
					if ((i == elements[j])) {
						std::cout << std::setw(4) << std::left << i
							<< std::setw(16) << users()[i].getNick()
							<< std::setw(16) << users()[i].getName()
							<< std::setw(16) << users()[i].getSurname()
							<< std::setw(16) << users()[i].getDateOfReg();
						if (users()[i].getDrawingIDs().length() > 25) {
							std::cout << "(" + to_string(users()[i].getCountDrawingIDs()) + ") " + users()[i].getDrawingIDs().substr(0, 25) + "...";
						}
						else  if (users()[i].getCountDrawingIDs() != 0) {
							std::cout << "(" + to_string(users()[i].getCountDrawingIDs()) + ") " + users()[i].getDrawingIDs().substr(0, 25);
						}
						std::cout << std::endl;
						j++;
					}
				}
			}
		}
		else if (elements[0] == -1) {
			for (int i = 0; i < users().size(); i++) {
				std::cout << std::setw(4) << std::left << i
					<< std::setw(16) << users()[i].getNick()
					<< std::setw(16) << users()[i].getName()
					<< std::setw(16) << users()[i].getSurname()
					<< std::setw(16) << users()[i].getDateOfReg();
				if (users()[i].getDrawingIDs().length() > 25) {
					std::cout << "(" + to_string(users()[i].getCountDrawingIDs()) + ") " + users()[i].getDrawingIDs().substr(0, 25) + "...";
				}
				else  if (users()[i].getCountDrawingIDs() != 0) {
					std::cout << "(" + to_string(users()[i].getCountDrawingIDs()) + ") " + users()[i].getDrawingIDs().substr(0, 25);
				}
				std::cout << std::endl;
			}
		}

	}
	if (type == 's') {
		std::cout << std::setw(4) << std::left << "LID"
			<< std::setw(16) << "NICK"
			<< "DRAWINGS IDS"
			<< std::endl;
		std::cout << "\n";

		if (elements[0] != -1) {
			for (int i = 0; i < users().size(); i++) {
				if (j < elements.size()) {
					if ((i == elements[j])) {
						std::cout << std::setw(4) << std::left << i
							<< std::setw(16) << users()[i].getNick();
						if (users()[i].getDrawingIDs().length() > 25) {
							std::cout << "(" + to_string(users()[i].getCountDrawingIDs()) + ") " + users()[i].getDrawingIDs().substr(0, 25) + "...";
						}
						else  if (users()[i].getCountDrawingIDs() != 0) {
							std::cout << "(" + to_string(users()[i].getCountDrawingIDs()) + ") " + users()[i].getDrawingIDs().substr(0, 25);
						}
						std::cout << std::endl;
						j++;
					}
				}
			}
		}
		else if (elements[0] == -1) {
			for (int i = 0; i < users().size(); i++) {
				std::cout << std::setw(4) << std::left << i
					<< std::setw(16) << users()[i].getNick();
				if (users()[i].getDrawingIDs().length() > 25) {
					std::cout << "(" + to_string(users()[i].getCountDrawingIDs()) + ") " + users()[i].getDrawingIDs().substr(0, 25) + "...";
				}
				else  if (users()[i].getCountDrawingIDs() != 0) {
					std::cout << "(" + to_string(users()[i].getCountDrawingIDs()) + ") " + users()[i].getDrawingIDs().substr(0, 25);
				}
				std::cout << std::endl;
			}
		}
	}
	std::cout << "------------------------------------------------\n";
	
}

void tableDrawings(char type, vector<int> elements) {
	if (elements.empty()) {
		return;
	}
	std::cout << "------------------------------------------------\n";
	std::cout << "Table drawings\n";
	std::cout << "\n";

	int j = 0;

	if (type == 'a') {
		std::cout << std::setw(4) << std::left << "LID"
			<< std::setw(16) << "TITLE"
			<< std::setw(16) << "OWNER"
			<< std::setw(16) << "ID"
			<< std::setw(16) << "FILE NAME"
			<< std::setw(16) << "DATE AND TIME OF CREATION"
			<< std::setw(32) << "DESCRIPTION"
			<< "TAGS"
			<< std::endl;
		std::cout << "\n";

		if (elements[0] != -1) {
			for (int i = 0; i < drawings().size(); i++) {
				if (j < elements.size()) {
					if ((i == elements[j])) {
						std::cout << std::setw(4) << std::left << i
							<< std::setw(16) << drawings()[i].getTitle()
							<< std::setw(16) << drawings()[i].getUserNick()
							<< std::setw(16) << drawings()[i].getId()
							<< std::setw(16) << drawings()[i].getFileName()
							<< std::setw(16) << drawings()[i].getDateAndTimeOfAdd();
						if (users()[i].getAbout().length() > 25) {
							std::cout << std::setw(32) << drawings()[i].getDescription().substr(0, 25) + "...";
						}
						else {
							std::cout << std::setw(32) << drawings()[i].getDescription();
						}
						if (users()[i].getDrawingIDs().length() > 25) {
							std::cout << "(" + to_string(drawings()[i].getCountTags()) + ") " + drawings()[i].getTags().substr(0, 25) + "...";
						}
						else  if (users()[i].getCountDrawingIDs() != 0) {
							std::cout << "(" + to_string(drawings()[i].getCountTags()) + ") " + drawings()[i].getTags().substr(0, 25);
						}
						std::cout << std::endl;
						j++;
					}
				}
			}
		}
		else if (elements[0] == -1) {
			for (int i = 0; i < drawings().size(); i++) {
				std::cout << std::setw(4) << std::left << i
					<< std::setw(16) << drawings()[i].getTitle()
					<< std::setw(16) << drawings()[i].getUserNick()
					<< std::setw(16) << drawings()[i].getId()
					<< std::setw(16) << drawings()[i].getFileName()
					<< std::setw(16) << drawings()[i].getDateAndTimeOfAdd();
				if (users()[i].getAbout().length() > 25) {
					std::cout << std::setw(32) << drawings()[i].getDescription().substr(0, 25) + "...";
				}
				else {
					std::cout << std::setw(32) << drawings()[i].getDescription();
				}
				if (users()[i].getDrawingIDs().length() > 25) {
					std::cout << "(" + to_string(drawings()[i].getCountTags()) + ") " + drawings()[i].getTags().substr(0, 25) + "...";
				}
				else  if (users()[i].getCountDrawingIDs() != 0) {
					std::cout << "(" + to_string(drawings()[i].getCountTags()) + ") " + drawings()[i].getTags().substr(0, 25);
				}
				std::cout << std::endl;
			}
		}

	}
	if (type == 'm') {
		std::cout << std::setw(4) << std::left << "LID"
			<< std::setw(16) << "TITLE"
			<< std::setw(16) << "OWNER"
			<< std::setw(16) << "ID"
			<< std::setw(16) << "FILE NAME"
			<< std::setw(16) << "DATE AND TIME OF CREATION"
			<< "TAGS"
			<< std::endl;
		std::cout << "\n";

		if (elements[0] != -1) {
			for (int i = 0; i < drawings().size(); i++) {
				if (j < elements.size()) {
					if ((i == elements[j])) {
						std::cout << std::setw(4) << std::left << i
							<< std::setw(16) << drawings()[i].getTitle()
							<< std::setw(16) << drawings()[i].getUserNick()
							<< std::setw(16) << drawings()[i].getId()
							<< std::setw(16) << drawings()[i].getFileName()
							<< std::setw(16) << drawings()[i].getDateAndTimeOfAdd();
						if (users()[i].getDrawingIDs().length() > 25) {
							std::cout << "(" + to_string(drawings()[i].getCountTags()) + ") " + drawings()[i].getTags().substr(0, 25) + "...";
						}
						else  if (users()[i].getCountDrawingIDs() != 0) {
							std::cout << "(" + to_string(drawings()[i].getCountTags()) + ") " + drawings()[i].getTags().substr(0, 25);
						}
						std::cout << std::endl;
						j++;
					}
				}
			}
		}
		else if (elements[0] == -1) {
			for (int i = 0; i < drawings().size(); i++) {
				std::cout << std::setw(4) << std::left << i
					<< std::setw(16) << drawings()[i].getTitle()
					<< std::setw(16) << drawings()[i].getUserNick()
					<< std::setw(16) << drawings()[i].getId()
					<< std::setw(16) << drawings()[i].getFileName()
					<< std::setw(16) << drawings()[i].getDateAndTimeOfAdd();
				if (users()[i].getDrawingIDs().length() > 25) {
					std::cout << "(" + to_string(drawings()[i].getCountTags()) + ") " + drawings()[i].getTags().substr(0, 25) + "...";
				}
				else  if (users()[i].getCountDrawingIDs() != 0) {
					std::cout << "(" + to_string(drawings()[i].getCountTags()) + ") " + drawings()[i].getTags().substr(0, 25);
				}
				std::cout << std::endl;
			}
		}

	}
	if (type == 's') {
		std::cout << std::setw(4) << std::left << "LID"
			<< std::setw(16) << "TITLE"
			<< std::setw(16) << "OWNER"
			<< std::setw(16) << "ID"
			<< std::setw(16) << "FILE NAME"
			<< std::endl;
		std::cout << "\n";

		if (elements[0] != -1) {
			for (int i = 0; i < drawings().size(); i++) {
				if (j < elements.size()) {
					if ((i == elements[j])) {
						std::cout << std::setw(4) << std::left << i
							<< std::setw(16) << drawings()[i].getTitle()
							<< std::setw(16) << drawings()[i].getUserNick()
							<< std::setw(16) << drawings()[i].getId()
							<< std::setw(16) << drawings()[i].getFileName()
							<< std::endl;
						j++;
					}
				}
			}
		}
		else if (elements[0] == -1) {
			for (int i = 0; i < drawings().size(); i++) {
				std::cout << std::setw(4) << std::left << i
					<< std::setw(16) << drawings()[i].getTitle()
					<< std::setw(16) << drawings()[i].getUserNick()
					<< std::setw(16) << drawings()[i].getId()
					<< std::setw(16) << drawings()[i].getFileName()
					<< std::endl;
			}
		}

	}
	std::cout << "------------------------------------------------\n";
}