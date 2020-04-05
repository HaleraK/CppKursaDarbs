#pragma once

#include <string>
#include <iostream>
#include <vector>

using std::string;
using std::vector;

class User {

public:

	User() {
		//forbiddenForNameAndSurname().resize(42);
		forbiddenForNameAndSurname() = { '1','2','3','4','5','6','7','8','9','0','-','_','=','+','[',']','{','}','/','\\','\'','"',';',':','`','~','<','>',',','.','?','!','@','#','$','%','^','&','*','(',')','|' };

	}

	User(string name, string surname, string nick, string login, string password, string dateOfReg, string about) {
		
		constructor(name, surname, nick, login, password, dateOfReg);
		User::setAbout(about);

	}

	User(string name, string surname, string nick, string login, string password, string dateOfReg) {
		
		constructor(name, surname, nick, login, password, dateOfReg);

	}

	void constructor(string name, string surname, string nick, string login, string password, string dateOfReg);

	bool isOneWord(string value);

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

	int getCountDrawingIDs();

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
	};

};