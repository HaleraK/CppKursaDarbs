#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <sstream> 

using std::string;
using std::vector;

int searchUserByNick(string value);
int searchDrawingById(string value);

vector<int> searchUsersByNick(string input);
vector<int> searchDrawingsById(string input);

vector<int> searchByParamUser(string input);
vector<int> searchByParamDrawing(string input);

void searchUser();
void searchDrawing();
void search();