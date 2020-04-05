#include <string>
#include <iostream>
#include <vector>

#include "Drawing.h"

using std::string;
using std::vector;

void Drawing::constructor(string userNick, string id, string title, string fileName, string dateAndTimeOfAdd) {

	Drawing::setUserNick(userNick);
	Drawing::setId(id);
	Drawing::setTitle(title);
	Drawing::setFileName(fileName);
	Drawing::setDateAndTimeOfAdd(title);

};

bool Drawing::isOneWord(string value) {

	for (int i = 0; i < value.length(); ++i) {
		if (value[i] == ' ') {
			return false;
		}
	}

	return true;

};

void Drawing::setUserNick(string value) {

	if (Drawing::isOneWord(value)) {
		Drawing::userNick = value;
	}

};

string Drawing::getUserNick() {
	return Drawing::userNick;
};

void Drawing::setId(string value) {

	if (Drawing::isOneWord(value)) {
		Drawing::id = value;
	}

};

string Drawing::getId() {
	return Drawing::id;
};

void Drawing::setTitle(string value) {

	if (Drawing::isOneWord(value)) {
		Drawing::title = value;
	}

};
string Drawing::getTitle() {
	return Drawing::title;
};

void Drawing::setDescription(string value) {

	Drawing::description = value;
	
};
string Drawing::getDescription() {
	return Drawing::description;
};

void Drawing::setFileName(string value) {

	if (Drawing::isOneWord(value)) {
		Drawing::fileName = value;
	}

};

string Drawing::getFileName() {
	return Drawing::fileName;
};

void Drawing::setDateAndTimeOfAdd(string value) {

	if (Drawing::isOneWord(value)) {
		Drawing::dateAndTimeOfAdd = value;
	}

};

string Drawing::getDateAndTimeOfAdd() {
	return Drawing::dateAndTimeOfAdd;
};

void Drawing::addTag(string add) {

	if (Drawing::isCorrectTag(add) && !Drawing::isDoubleTag(add) && Drawing::isOneWord(add)) {
		Drawing::tags.push_back(add);
	}

};

void Drawing::addTags(vector<string> add) {

	for (int i = 0; i < add.size(); i++) {

		if (Drawing::isCorrectTag(add[i]) && !Drawing::isDoubleTag(add[i]) && Drawing::isOneWord(add[i])) {
			Drawing::tags.push_back(add[i]);
		}

	}

};
void Drawing::delTag(string del) {

	int i = -1;

	if (Drawing::isCorrectTag(del)) {

		i = Drawing::searchTag(del);

		if (i != -1) {
			Drawing::tags.erase(tags.begin() + i);
		}
	}

};

void Drawing::delTags(vector<string> del) {

	int j = -1;

	for (int i = 0; i < del.size(); i++) {
		if (Drawing::isCorrectTag(del[i])) {

			j = Drawing::searchTag(del[i]);

			if (j != -1) {
				Drawing::tags.erase(tags.begin() + j);
			}
		}
	}

};

int Drawing::searchTag(string tag) {
	
	for (int i = 0; i < tags.size(); i++) {
		if (tag == tags[i]) {
			return i;
		}
	}

	return -1;

};

bool Drawing::isDoubleTag(string tag) {

	for (int i = 0; i < tags.size(); i++) {
		if (tag == tags[i]) {
			return true;
		}
	}

	return false;

};

bool Drawing::isCorrectTag(string tag) {
	if (tag[0] == '#') {
		return true;
	}
	else {
		return false;
	}
}

string Drawing::getTags() {

	string out = "";

	for (int i = 0; i < tags.size(); i++) {
		out += tags[i] + ", ";
	}

	return out;

};

int Drawing::getCountTags() {
	return Drawing::tags.size();
}