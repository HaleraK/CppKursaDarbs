#include <string>
#include <iostream>
#include <vector>

#include <fstream>
#include <iostream>
#include <filesystem>

#include "Drawing.h"

using std::string;
using std::vector;
using namespace std;

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

}

int Drawing::getCountTags() {
	return Drawing::tags.size();
}

string Drawing::getTag(int i) {
	return Drawing::tags[i];
}

void Drawing::serilization(string path) {

	//string userNick, string id, string title, string fileName, string dateAndTimeOfAdd, vector<string> tags, string description

	//#Структура файла Drawing.d
	//userNick{...}
	//title{...}
	//fileName{...}
	//dateAndTimeOfAdd{...}
	//tags{{...}{...}{...}{...}{...} ... }
	//description{...}

	ofstream out(path + Drawing::getId() + ".d", ios_base::trunc | ios_base::out);

	if (!out.is_open()) // если файл небыл открыт
	{
		return;
	}

	out << "#Drawing " << Drawing::getId() << endl;
	out << "userNick{" << Drawing::getUserNick() << "}" << endl;
	out << "id{" << Drawing::getId() << "}" << endl;
	out << "title{" << Drawing::getTitle() << "}" << endl;
	out << "fileName{" << Drawing::getFileName() << "}" << endl;
	out << "dateAndTimeOfAdd{" << Drawing::getDateAndTimeOfAdd() << "}" << endl;

	out << "tags{";
	for (int i = 0; i < Drawing::getCountTags(); i++) {
		out << "{" << Drawing::getTag(i) << "}";
	}
	out << "}" << endl;

	out << "description{" << Drawing::getDescription() << "}" << endl;

	out.close();

}

void Drawing::deserilization(const std::filesystem::directory_entry file) {

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

		getline(in, buffer);

		if (Drawing::isComment(buffer)) {
			continue;
		}
		paramType = Drawing::getParamName(buffer);

		if (paramType == "{error}") {
			continue;
		}

		if (paramType == "userNick") {
			Drawing::setUserNick(Drawing::getParam(buffer, posStart));
		}
		if (paramType == "title") {
			Drawing::setTitle(Drawing::getParam(buffer, posStart));
		}
		if (paramType == "fileName") {
			Drawing::setFileName(Drawing::getParam(buffer, posStart));
		}
		if (paramType == "dateAndTimeOfAdd") {
			Drawing::setDateAndTimeOfAdd(Drawing::getParam(buffer, posStart));
		}
		if (paramType == "description") {
			Drawing::setDescription(Drawing::getParam(buffer, posStart));
		}
		if (paramType == "id") {
			Drawing::setId(Drawing::getParam(buffer, posStart));
		}

		if (paramType == "tags") {

			posStart += paramType.length() + 1;

			while (true) {

				vecBuffer.push_back(Drawing::getParam(buffer, posStart));
				posStart += vecBuffer.back().length() + 1;

				if ((posStart + 1) >= buffer.length()) {
					break;
				}

			}
			Drawing::addTags(vecBuffer);
		}

	}

	in.close();

}

string Drawing::getParamName(string buffer) {
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

bool Drawing::isComment(string buffer) {
	if (buffer[0] == '#') {
		return true;
	}
	else {
		return false;
	}
}

string Drawing::getParam(string buffer, int posStart) {
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