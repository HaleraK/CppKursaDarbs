#pragma once

#include <string>
#include <iostream>
#include <vector>

#include <fstream>
#include <iostream>
#include <filesystem>

using std::string;
using std::vector;

class User {

public:

	User() {
		forbiddenForNameAndSurname() = { '1','2','3','4','5','6','7','8','9','0','-','_','=','+','[',']','{','}','/','\\','\'','"',';',':','`','~','<','>',',','.','?','!','@','#','$','%','^','&','*','(',')','|' };
		forbidden() = { '{' , '}' };
	}

	User(string name, string surname, string nick, string login, string password, string dateOfReg, string about) {
		
		constructor(name, surname, nick, login, password, dateOfReg);
		User::setAbout(about);

	}

	User(string name, string surname, string nick, string login, string password, string dateOfReg) {
		
		constructor(name, surname, nick, login, password, dateOfReg);

	}

	User(string name, string surname, string nick, string login, string password, string dateOfReg, string about, vector<string> drawingsIDs) {

		constructor(name, surname, nick, login, password, dateOfReg);
		User::setAbout(about);
		User::addDrawingIDs(drawingsIDs);

	}

	void constructor(string name, string surname, string nick, string login, string password, string dateOfReg);

	bool isOneWord(string value);
	bool isFobiddenInWord(string input, vector<char> forbiddenV);

	void setName(string value);
	string getName();

	void setSurname(string value);
	string getSurname();

	void setNick(string value);
	string getNick();

	void setLogin(string value);
	string getLogin();

	void setPassword(string value);
	string getPassword();

	void setDateOfReg(string value);
	string getDateOfReg();

	void setAbout(string value);
	string getAbout();

	void addDrawingID(string add);
	void addDrawingIDs(vector<string> add);

	void delDrawingID(string del);
	void delDrawingIDs(vector<string> del);

	bool isCorrectDrawingID(string id);
	int searchDrawingID(string id);
	bool isDoubleDrawingID(string id);

	string getDrawingIDs();
	string getDrawingID(int i);

	int getCountDrawingIDs();

	void serilization(string path);
	void deserilization(const std::filesystem::directory_entry file);

	string getParamName(string buffer);
	bool isComment(string buffer);
	string getParam(string buffer, int posStart);

private:
	bool isCorrect;

	string name;
	string surname;
	string nick;
	string login;
	string password;
	string dateOfReg;
	string about;

	vector<string> drawingIDs;

	static vector<char> &forbiddenForNameAndSurname() {
		static vector<char> f;
		return f;
	}

	static vector<char> &forbidden() {
		static vector<char> f;
		return f;
	}

};