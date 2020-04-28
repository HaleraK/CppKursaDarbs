#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <sstream> 

using std::string;
using std::vector;

bool check();

bool checkNicks();
bool checkLogins();
bool checkDrawingsIds();

bool isInArrayElem(vector<int> array, int el);