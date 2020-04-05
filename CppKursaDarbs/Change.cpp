#include <string>
#include <iostream>
#include <vector>
#include <sstream> 

#include "User.h"
#include "Drawing.h"
#include "Menu.h"
#include "Change.h"
#include "Search.h"
#include "Print.h"
#include "Add.h"

using namespace std;

void change() {

	string choise;
	int numChoise;

	while (true) {
		if (returnToMenu()) { break; }

		std::cout << "------------------------------------------------\n";
		std::cout << "1 Change user\n";
		std::cout << "2 Change drawing\n";
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
			changeUser();
			break;
		}
		case (2): {
			changeDrawing();
			break;
		}
		default:
			errorMsg();
			break;
		}
	}
}

void changeUser() {

	string choise;
	string value;
	vector<string> ids;
	int numChoise;
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

		outUser(i, 'a');

		while (true) {
			if (returnToMenu()) { break; }

			std::cout << "------------------------------------------------\n";
			std::cout << "You can change:\n";
			std::cout << "------------------------------------------------\n";
			std::cout << "1 Name\n";
			std::cout << "2 Surname\n";
			std::cout << "3 Nick\n";
			std::cout << "4 Login\n";
			std::cout << "5 Password\n";
			std::cout << "6 Date of Registration\n";
			std::cout << "7 About\n";
			std::cout << "8 Add Drawing Id\n";
			std::cout << "9 Add Drawing Ids\n";
			std::cout << "10 Delete Drawing Id\n";
			std::cout << "11 Delete Drawing Ids\n";
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

			if (isToMenu(choise)) {
				returnToMenu() = true;
				break;
			}
			else {
				if (numChoise < 12 && numChoise > 0) {
					break;
				}
			}
		}

		if (returnToMenu()) { break; }



		std::cout << "------------------------------------------------\n";
		std::cout << "Please input parametr/parametrs (input 0 to go main menu):\n";
		std::cout << "------------------------------------------------\n";

		cin.clear();
		//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::getline(std::cin, value);

		if (isToMenu(value)) {
			returnToMenu() = true;
			break;

		}

		switch (numChoise) {
		case (0): {
			returnToMenu() = true;
			break;
		}
		case (1): {
			users()[i].setName(value);
			break;
		}
		case (2): {
			users()[i].setSurname(value);
			break;
		}
		case (3): {
			users()[i].setNick(value);
			break;
		}
		case (4): {
			users()[i].setLogin(value);
			break;
		}
		case (5): {
			users()[i].setPassword(value);
			break;
		}
		case (6): {
			users()[i].setDateOfReg(value);
			break;
		}
		case (7): {
			users()[i].setAbout(value);
			break;
		}
		case (8): {
			users()[i].addDrawingID(value);
			break;
		}
		case (9): {
			int pos = 0;

			while (true) {
				if (value.length() > pos) {
						ids.push_back(createOneWord(value, pos));
						pos += ids.back().length() + 1;
				}
				else {
					break;
				}
			}

			users()[i].addDrawingIDs(ids);
			break;
		}
		case (10): {
			users()[i].delDrawingID(value);
			break;
		}
		case (11): {
			int pos = 0;

			while (true) {
				if (value.length() > pos) {
					ids.push_back(createOneWord(value, pos));
					pos += ids.back().length() + 1;
				}
				else {
					break;
				}
			}

			users()[i].delDrawingIDs(ids);
			break;
		}
		default:
			errorMsg();
			break;
		}

		if (numChoise > 0 && numChoise < 12) {
			outUser(i, 'a');
		}

	}

}

void changeDrawing() {

	string choise;
	string value;
	vector<string> tags;
	int numChoise;
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

		outDrawing(i, 'a');

		std::cout << "------------------------------------------------\n";
		std::cout << "You can change:\n";
		std::cout << "------------------------------------------------\n";
		std::cout << "1 Title\n"; 
		std::cout << "2 Owner\n";
		std::cout << "3 Id\n";
		std::cout << "4 File name\n";
		std::cout << "5 Date and time of cretion\n";
		std::cout << "6 Description\n";
		std::cout << "7 Add tag\n";
		std::cout << "8 Add tags\n";
		std::cout << "9 Delete tag\n";
		std::cout << "10 Delete tags\n";
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
			drawings()[i].setTitle(value);
			break;
		}
		case (2): {
			drawings()[i].setUserNick(value);
			break;
		}
		case (3): {
			drawings()[i].setId(value);
			break;
		}
		case (4): {
			drawings()[i].setFileName(value);
			break;
		}
		case (5): {
			drawings()[i].setDateAndTimeOfAdd(value);
			break;
		}
		case (6): {
			drawings()[i].setDescription(value);
			break;
		}
		case (7): {
			drawings()[i].addTag(value);
			break;
		}
		case (8): {
			int pos = 0;

			while (true) {
				if (value.length() > pos) {
					tags.push_back(createOneWord(value, pos));
					pos += tags.back().length() + 1;
				}
				else {
					break;
				}
			}
			drawings()[i].addTags(tags);
			break;
		}
		case (9): {
			drawings()[i].delTag(value);
			break;
		}
		case (10): {
			int pos = 0;

			while (true) {
				if (value.length() > pos) {
					tags.push_back(createOneWord(value, pos));
					pos += tags.back().length() + 1;
				}
				else {
					break;
				}
			}

			drawings()[i].delTags(tags);
			break;
		}

		default:
			errorMsg();
			break;
		}
	}

	if (numChoise > 0 && numChoise < 11) {
		outDrawing(i, 'a');
	}

}