#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <sstream> 

using std::string;
using std::vector;

void printUser();
void printDrawing();
void printUsers();
void printDrawings();
void print();

void outUser(int i, char type);
void outDrawing(int i, char type);
void tableUsers(char type, vector<int> elements);
void tableDrawings(char type, vector<int> elements);