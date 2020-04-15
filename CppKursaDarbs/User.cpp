#include <string>
#include <iostream>
#include <vector>

#include <fstream>
#include <iostream>
#include <filesystem>

#include "User.h"

using std::string;
using std::vector;
using namespace std;

void User::constructor(string name, string surname, string nick, string login, string password, string dateOfReg) {

	User::forbiddenForNameAndSurname() = { '1','2','3','4','5','6','7','8','9','0','-','_','=','+','[',']','{','}','/','\\','\'','"',';',':','`','~','<','>',',','.','?','!','@','#','$','%','^','&','*','(',')','|' };
	User::forbidden() = { '{' , '}' };
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

bool User::isFobiddenInWord(string input, vector<char> forbiddenV) {

	for (int i = 0; i < input.length(); ++i) {
		for (int j = 0; j < forbiddenV.size(); ++j) {
			if (input[i] == forbiddenV[j]) {
				return true;
			}
		}
	}
	return false;

}

void User::setName(string value) {

	if (User::isFobiddenInWord(value, User::forbiddenForNameAndSurname())) {
		return;
	}
	if (User::isFobiddenInWord(value, User::forbidden())) {
		return;
	}
	if (User::isOneWord(value)) {
		User::name = value;
	}

};

string User::getName() {
	return User::name;
};

void User::setSurname(string value) {

	if (User::isFobiddenInWord(value, User::forbiddenForNameAndSurname())) {
		return;
	}
	if (User::isFobiddenInWord(value, User::forbidden())) {
		return;
	}
	if (User::isOneWord(value)) {
		User::surname = value;
	}

};

string User::getSurname() {
	return User::surname;
};

void User::setNick(string value) {

	if (User::isFobiddenInWord(value, User::forbidden())) {
		return;
	}
	if (User::isOneWord(value)) {
		User::nick = value;
	}

};

string User::getNick() {
	return User::nick;
};

void User::setLogin(string value) {

	if (User::isFobiddenInWord(value, User::forbidden())) {
		return;
	}
	if (User::isOneWord(value)) {
		User::login = value;
	}

};

string User::getLogin() {
	return User::login;
};

void User::setPassword(string value) {

	if (User::isFobiddenInWord(value, User::forbidden())) {
		return;
	}
	if (User::isOneWord(value)) {
		User::password = value;
	}
	
};
string User::getPassword() {
	return User::password;
};

void User::setDateOfReg(string value) {

	if (User::isFobiddenInWord(value, User::forbidden())) {
		return;
	}
	if (User::isOneWord(value)) {
		User::dateOfReg = value;
	}

};

string User::getDateOfReg() {
	return User::dateOfReg;
};

void User::setAbout(string value) {

	if (User::isFobiddenInWord(value, User::forbidden())) {
		return;
	}
	User::about = value;
	
};
string User::getAbout() {
	return User::about;
};

void User::addDrawingID(string add) {

	if (User::isFobiddenInWord(add, User::forbidden())) {
		return;
	}
	if (User::isCorrectDrawingID(add) && !User::isDoubleDrawingID(add) && User::isOneWord(add)) {
		User::drawingIDs.push_back(add);
	}

};

void User::addDrawingIDs(vector<string> add) {

	for (int i = 0; i < add.size(); i++) {
		if (User::isFobiddenInWord(add[i], User::forbidden())) {
			continue;
		}
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

string User::getDrawingID(int i) {
	return User::drawingIDs[i];
};

void User::serilization(string path) {

	//#Структура файла User.u
	//name{...}
	//surname{...}
	//nick{...}
	//login{...}
	//password{...}
	//dateOfReg{...}
	//about{...}
	//drawingsIDs{{...}{...}{...}{...}{...} ... }

	ofstream out(path + User::getNick() + ".u", ios_base::trunc | ios_base::out);

	if (!out.is_open()) // если файл небыл открыт
	{
		return; 
	}

	out << "#User " << User::getNick() << endl;
	out << "name{" << User::getName() << "}" << endl;
	out << "surname{" << User::getSurname() << "}" << endl;
	out << "nick{" << User::getNick() << "}" << endl;
	out << "login{" << User::getLogin() << "}" << endl;
	out << "password{" << User::getPassword() << "}" << endl;
	out << "dateOfReg{" << User::getDateOfReg() << "}" << endl;
	out << "about{" << User::getAbout() << "}" << endl;

	out << "drawingIDs{";
	for (int i = 0; i < User::getCountDrawingIDs(); i++) {
		out << "{" << User::getDrawingID(i) << "}";
	}
	out << "}" << endl;

	out.close();

}

void User::deserilization(const std::filesystem::directory_entry file) {

	string buffer;
	string paramType;
	int posStart = 0;
	vector<string> vecBuffer;

	ifstream in(file, ios_base::in);

	if (!in.is_open()) // если файл небыл открыт
	{
		return;
	}

	while (!in.eof()) {

		getline(in , buffer);

		if (User::isComment(buffer)) {
			continue;
		}
		paramType = User::getParamName(buffer);

		if (paramType == "{error}") {
			continue;
		}

		if (paramType == "name") {
			User::setName(User::getParam(buffer, posStart));
		}
		if (paramType == "surname") {
			User::setSurname(User::getParam(buffer, posStart));
		}
		if (paramType == "nick") {
			User::setNick(User::getParam(buffer, posStart));
		}
		if (paramType == "login") {
			User::setLogin(User::getParam(buffer, posStart));
		}
		if (paramType == "password") {
			User::setPassword(User::getParam(buffer, posStart));
		}
		if (paramType == "dateOfReg") {
			User::setDateOfReg(User::getParam(buffer, posStart));
		}
		if (paramType == "about") {
			User::setAbout(User::getParam(buffer, posStart));
		}

		if (paramType == "drawingIDs") {

			posStart += paramType.length() + 1;

			while (true) {

				vecBuffer.push_back(User::getParam(buffer, posStart));
				posStart += vecBuffer.back().length() + 1;

				if ((posStart + 1) >= buffer.length()) {
					break;
				}

			}
			User::addDrawingIDs(vecBuffer);
		}

	}

	in.close();

}

string User::getParamName(string buffer) {
	string out;

	if (buffer[0] == '{') {
		return "";
	}

	for (int i = 0; i < buffer.length(); i++) {

		if (buffer[i] == '{') {
			return out;
		}
		out += buffer[i];

	}

	return "{error}";
}

bool User::isComment(string buffer) {
	if (buffer[0] == '#') {
		return true;
	}
	else {
		return false;
	}
}

string User::getParam(string buffer, int posStart) {
	string out;
	bool start = false;
	bool end = false;

	for (int i = posStart; i < buffer.length(); i++) {

		if (start == true) {
			if (buffer[i] == '}') {
				end = true;
				break;
			}
			out += buffer[i];
		}
		if (buffer[i] == '{') {
			start = true;
		}

	}

	if (start && end) {
		return	out;
	}
	else {	
		return "";
	}

}