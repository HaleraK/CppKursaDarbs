#include <string>
#include <iostream>
#include <vector>
#include <sstream> 
#include "User.h"
#include "Drawing.h"

#include "CheckForMistakes.h"
#include "Menu.h"
#include "Print.h"
#include "TimsortUser.h"
#include "TimsortDrawing.h"

using std::string;
using std::vector;

bool check() {

	bool isAllCorrect = true;

	std::cout << "------------------------------------------------\n";
	std::cout << "Autocheck users and drawings\n";
	std::cout << "------------------------------------------------\n";

	if (!checkNicks()) {
		isAllCorrect = false;
	}
	if (!checkLogins()) {
		isAllCorrect = false;
	}
	if (!checkDrawingsIds()) {
		isAllCorrect = false;
	}

	if (isAllCorrect) {
		std::cout << "------------------------------------------------\n";
		std::cout << "There no double nicks, logins and drawing ids\n";
		std::cout << "------------------------------------------------\n";
	}

	return isAllCorrect;

	cin.get();

}

bool checkNicks() {
	vector<int> problems;
	timSortUsers(3, sizeof(users()) / sizeof(users()[0]));

	for (int i = 0; i < users().size(); i++) {
		for (int j = 0; j < users().size(); j++) {
			if ((users()[i].getNick() == users()[j].getNick()) && (i != j)) {
				if (!isInArrayElem(problems, i)) {
					problems.push_back(i);
				}
			}
		}
	}

	if (problems.size() > 0) {

		std::cout << "------------------------------------------------\n";
		std::cout << "Users have doubled or more nicks\n";
		std::cout << "------------------------------------------------\n";

		tableUsers('a', problems);
		return false;

	}
	return true;

}

bool checkLogins() {
	vector<int> problems;
	timSortUsers(4, sizeof(users()) / sizeof(users()[0]));

	for (int i = 0; i < users().size(); i++) {
		for (int j = 0; j < users().size(); j++) {
			if ((users()[i].getLogin() == users()[j].getLogin()) && (i != j)) {
				if (!isInArrayElem(problems, i)) {
					problems.push_back(i);
				}
			}
		}
	}

	if (problems.size() > 0) {

		std::cout << "------------------------------------------------\n";
		std::cout << "Users have doubled or more login names\n";
		std::cout << "------------------------------------------------\n";

		tableUsers('a', problems);
		return false;

	}
	return true;

}

bool checkDrawingsIds() {
	vector<int> problems;
	timSortDrawings(2, sizeof(drawings()) / sizeof(drawings()[0]));

	for (int i = 0; i < drawings().size(); i++) {
		for (int j = 0; j < drawings().size(); j++) {
			if ((drawings()[i].getId() == drawings()[j].getId()) && (i != j)) {
				if (!isInArrayElem(problems, i)) {
					problems.push_back(i);
				}
			}
		}
	}

	if (problems.size() > 0) {

		std::cout << "------------------------------------------------\n";
		std::cout << "Drawings have doubled or more ids\n";
		std::cout << "------------------------------------------------\n";

		tableDrawings('a', problems);
		return false;

	}
	return true;

}


bool isInArrayElem(vector<int> array, int el) {

	if (!array.empty()) {
		for (int i = 0; i < array.size(); i++) {
			if (el == array[i]) {
				return true;
			}
		}
	}
	return false;
}

