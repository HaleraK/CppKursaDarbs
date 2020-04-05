#include <string>
#include <iostream>
#include <vector>
#include <sstream> 

#include "User.h"
#include "Drawing.h"
#include "Menu.h"
#include "Search.h"
#include "Print.h"

using namespace std;

using std::string;
using std::vector;



int searchUserByNick(string value) {

	for (int i = 0; i < users().size(); i++) {
		if (value == users()[i].getNick()) {
			return i;
		}
	}
	return -1;

}

int searchDrawingById(string value) {

	for (int i = 0; i < drawings().size(); i++) {
		if (value == drawings()[i].getId()) {
			return i;
		}
	}
	return -1;

}



vector<int> searchByParamUser(string input) {
	vector<int> outPrint;

	for (int i = 0; i < users().size(); i++) {
		if ((users()[i].getName().find(input) != std::string::npos)) {
			outPrint.push_back(i);
			continue;
		}
		if ((users()[i].getSurname().find(input) != std::string::npos)) {
			outPrint.push_back(i);
			continue;
		}
		if ((users()[i].getNick().find(input) != std::string::npos)) {
			outPrint.push_back(i);
			continue;
		}
		if ((users()[i].getLogin().find(input) != std::string::npos)) {
			outPrint.push_back(i);
			continue;
		}
		if ((users()[i].getPassword().find(input) != std::string::npos)) {
			outPrint.push_back(i);
			continue;
		}
		if ((users()[i].getDateOfReg().find(input) != std::string::npos)) {
			outPrint.push_back(i);
			continue;
		}
	}

	return outPrint;
}

vector<int> searchByParamDrawing(string input) {
	vector<int> outPrint;

	for (int i = 0; i < drawings().size(); i++) {
		if ((drawings()[i].getTitle().find(input) != std::string::npos)) {
			outPrint.push_back(i);
			continue;
		}
		if ((drawings()[i].getFileName().find(input) != std::string::npos)) {
			outPrint.push_back(i);
			continue;
		}
		if ((drawings()[i].getDateAndTimeOfAdd().find(input) != std::string::npos)) {
			outPrint.push_back(i);
			continue;
		}
		if ((drawings()[i].getDescription().find(input) != std::string::npos)) {
			outPrint.push_back(i);
			continue;
		}
		if ((drawings()[i].getId().find(input) != std::string::npos)) {
			outPrint.push_back(i);
			continue;
		}
		if ((drawings()[i].getUserNick().find(input) != std::string::npos)) {
			outPrint.push_back(i);
			continue;
		}
		
	}

	return outPrint;
}

void search() {

	string choise;
	int numChoise;

	while (true) {
		if (returnToMenu()) { break; }

		std::cout << "------------------------------------------------\n";
		std::cout << "Search user/drawing\n";
		std::cout << "------------------------------------------------\n";
		std::cout << "1 Search user\n";
		std::cout << "2 Search drawing\n";
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
			searchUser();
			break;
		}
		case (2): {
			searchDrawing();
			break;
		}
		default:
			errorMsg();
			break;
		}
	}
}

void searchUser() {

	string choise;
	string search;
	int numChoise;

	while (true) {
		if (returnToMenu()) { break; }

		std::cout << "------------------------------------------------\n";
		std::cout << "Search user by\n";
		std::cout << "------------------------------------------------\n";
		std::cout << "1 Nick\n";
		std::cout << "2 Any parametr\n";
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

		std::cout << "------------------------------------------------\n";
		std::cout << "Please input serch word\n";
		std::cout << "------------------------------------------------\n";

		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> search;

		switch (numChoise) {
		case (0): {
			returnToMenu() = true;
			break;
		}
		case (1): {
			outUser(searchUserByNick(search), 'a');
			break;
		}
		case (2): {
			tableUsers('a', searchByParamUser(search));
			break;
		}
		default:
			errorMsg();
			break;
		}
	}
}

void searchDrawing() {

	string choise;
	string search;
	int numChoise;

	while (true) {
		if (returnToMenu()) { break; }

		std::cout << "------------------------------------------------\n";
		std::cout << "Search drawing by\n";
		std::cout << "------------------------------------------------\n";
		std::cout << "1 Title\n";
		std::cout << "2 User\n";
		std::cout << "3 Full search\n";
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

		std::cout << "------------------------------------------------\n";
		std::cout << "Please input serch word\n";
		std::cout << "------------------------------------------------\n";

		cin.clear();
		//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::getline(std::cin, choise);

		switch (numChoise) {
		case (0): {
			returnToMenu() = true;
			break;
		}
		case (1): {
			outDrawing(searchDrawingById(search), 'a');
			break;
		}
		case (2): {
			tableDrawings('a', searchByParamDrawing(search));
			break;
		}
		default:
			errorMsg();
			break;
		}
	}
}