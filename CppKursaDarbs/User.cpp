#include <string>
#include <iostream>
#include <vector>

#include "User.h"

using std::string;
using std::vector;

void User::constructor(string name, string surname, string nick, string login, string password, string dateOfReg) {

	User::forbiddenForNameAndSurname() = { '1','2','3','4','5','6','7','8','9','0','-','_','=','+','[',']','{','}','/','\\','\'','"',';',':','`','~','<','>',',','.','?','!','@','#','$','%','^','&','*','(',')','|' };
	User::setName(name);
	User::setSurname(surname);
	User::setNick(nick);
	User::setLogin(login);
	User::setPassword(password);
	User::setDateOfReg(dateOfReg);

};

bool User::isOneWord(string value) {

	for (int i = 0; i < value.length(); ++i) {
		if (value[i] == ' ') {
			return false;
		}
	}

	return true;

};

void User::setName(string value) {

	for (int i = 0; i < value.length(); ++i) {
		for (int j = 0; j < User::forbiddenForNameAndSurname().size(); ++j) {
			if (value[i] == User::forbiddenForNameAndSurname()[j]) {
				return;
			}
		}	
	}

	if (User::isOneWord(value)) {
		User::name = value;
	}

};

string User::getName() {
	return User::name;
};

void User::setSurname(string value) {

	for (int i = 0; i < value.length(); ++i) {
		for (int j = 0; j < User::forbiddenForNameAndSurname().size(); ++j) {
			if (value[i] == User::forbiddenForNameAndSurname()[j]) {
				return;
			}
		}
	}

	if (User::isOneWord(value)) {
		User::surname = value;
	}

};

string User::getSurname() {
	return User::surname;
};

void User::setNick(string value) {

	if (User::isOneWord(value)) {
		User::nick = value;
	}

};

string User::getNick() {
	return User::nick;
};

void User::setLogin(string value) {

	if (User::isOneWord(value)) {
		User::login = value;
	}

};

string User::getLogin() {
	return User::login;
};

void User::setPassword(string value) {

	if (User::isOneWord(value)) {
		User::password = value;
	}
	
};
string User::getPassword() {
	return User::password;
};

void User::setDateOfReg(string value) {

	if (User::isOneWord(value)) {
		User::dateOfReg = value;
	}

};

string User::getDateOfReg() {
	return User::dateOfReg;
};

void User::setAbout(string value) {

	User::about = value;
	
};
string User::getAbout() {
	return User::about;
};

void User::addDrawingID(string add) {

	if (User::isCorrectDrawingID(add) && !User::isDoubleDrawingID(add) && User::isOneWord(add)) {
		User::drawingIDs.push_back(add);
	}

};

void User::addDrawingIDs(vector<string> add) {

	for (int i = 0; i < add.size(); i++) {

		if (User::isCorrectDrawingID(add[i]) && !User::isDoubleDrawingID(add[i]) && User::isOneWord(add[i])) {
			User::drawingIDs.push_back(add[i]);
		}

	}

};

void User::delDrawingID(string del) {

	int i = -1;

	if (User::isCorrectDrawingID(del)) {

		i = User::searchDrawingID(del);

		if (i != -1) {
			User::drawingIDs.erase(drawingIDs.begin() + i);
		}
	}

};

void User::delDrawingIDs(vector<string> del) {

	int j = -1;

	for (int i = 0; i < del.size(); i++) {
		if (User::isCorrectDrawingID(del[i])) {

			j = User::searchDrawingID(del[i]);

			if (j != -1) {
				User::drawingIDs.erase(drawingIDs.begin() + j);
			}
		}
	}

};

bool User::isCorrectDrawingID(string id) {

	// id рисунка должно начинаться с ника пользователя

	if (id.find(User::getNick()) != std::string::npos) {
		
		for (int i = 0; i < User::getName().length(); i++) {
			if (!(id[i] == User::getNick()[i])) {
				return false;
			}
		}
		return true;
	}

	return false;

};

int User::searchDrawingID(string id) {

	for (int i = 0; i < User::drawingIDs.size(); i++) {
		if (id == User::drawingIDs[i]) {
			return i;
		}
	}

	return -1;

};

bool User::isDoubleDrawingID(string id) {

	for (int i = 0; i < User::drawingIDs.size(); i++) {
		if (id == User::drawingIDs[i]) {
			return true;
		}
	}

	return false;

};

string User::getDrawingIDs() {

	string out = "";

	for (int i = 0; i < User::drawingIDs.size(); i++) {
		out += User::drawingIDs[i] + ", ";
	}

	return out;

};

int User::getCountDrawingIDs() {
	return User::drawingIDs.size();
}