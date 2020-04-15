#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <sstream> 
#include "User.h"
#include "Drawing.h"

using std::string;
using std::vector;

inline bool &endProgram() {
	static bool b;
	return b;
}

inline bool &returnToMenu() {
	static bool b;
	return b;
}

inline vector<User> &users() {
	static vector<User> u;
	return u;
}

inline vector<Drawing> &drawings() {
	static vector<Drawing> d;
	return d;
}

inline vector<string> &forDelDrawings() {
	static vector<string> d;
	return d;
}

inline vector<string> &forDelUsers() {
	static vector<string> d;
	return d;
}

bool isInputNum(string input);
bool isToMenu(string value);
void errorMsg();
void mainMenu();