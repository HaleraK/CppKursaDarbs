#pragma once

#include <string>
#include <iostream>
#include <vector>

#include <fstream>
#include <iostream>
#include <filesystem>

using std::string;
using std::vector;

class Drawing {
public:

	Drawing() {

	}
	
	Drawing(string userNick, string id, string title, string fileName, string dateAndTimeOfAdd, vector<string> tags, string description) {
		constructor(userNick, id, title, fileName, dateAndTimeOfAdd);
		addTags(tags);
		setDescription(description);
	}

	Drawing(string userNick, string id, string title, string fileName, string dateAndTimeOfAdd, vector<string> tags) {
		constructor(userNick, id, title, fileName, dateAndTimeOfAdd);
		addTags(tags);
	}

	Drawing(string userNick, string id, string title, string fileName, string dateAndTimeOfAdd, string description) {
		constructor(userNick, id, title, fileName, dateAndTimeOfAdd);
		setDescription(description);
	}

	Drawing(string userNick, string id, string title, string fileName, string dateAndTimeOfAdd) {
		constructor(userNick, id, title, fileName, dateAndTimeOfAdd);
	}

	void constructor(string userNick, string id, string title, string fileName, string dateAndTimeOfAdd);

	bool isOneWord(string value);

	void setUserNick(string value);
	string getUserNick();

	void setId(string value);
	string getId();

	void setTitle(string value);
	string getTitle();

	void setDescription(string value);
	string getDescription();

	void setFileName(string value);
	string getFileName();

	void setDateAndTimeOfAdd(string value);
	string getDateAndTimeOfAdd();

	void addTag(string add);
	void addTags(vector<string> add);

	void delTag(string del);
	void delTags(vector<string> del);

	bool isCorrectTag(string tag);
	int searchTag(string tag);
	bool isDoubleTag(string tag);

	string getTags();
	string getTag(int i);

	int getCountTags();

	void serilization(string path);
	void deserilization(const std::filesystem::directory_entry file);

	string getParamName(string buffer);
	bool isComment(string buffer);
	string getParam(string buffer, int posStart);

private:
	string userNick;
	string id;
	string title;
	string description;
	string fileName;
	string dateAndTimeOfAdd;

	vector<string> tags;
};