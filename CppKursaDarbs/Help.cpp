#include <string>
#include <iostream>
#include <vector>
#include <sstream> 

#include "Menu.h"
#include "Help.h"

void help() {

	std::cout << "------------------------------------------------\n";
	std::cout << "Help\n";
	std::cout << "------------------------------------------------\n";
	std::cout << "Follow-up to the programm by input numbers\n";
	std::cout << "You can exit to main menu from any place input 0, at some place - -1\n";
	std::cout << "\n";
	std::cout << "User consist of\n";
	std::cout << "	- lid (local id, which can change after sorting)\n";
	std::cout << "	- name (size 1 word, forbbiden symbols like (\"!,),@...\")\n";
	std::cout << "	- surname (size 1 word, forbbiden symbols like (\"!,),@...\")\n";
	std::cout << "	- nick (size 1 word, forbbiden symbols - (\"{ ,}\")\n";
	std::cout << "	- login (size 1 word, forbbiden symbols - (\"{ ,}\")\n";
	std::cout << "	- password (size 1 word, forbbiden symbols - (\"{ ,}\")\n";
	std::cout << "	- date of registration (size 1 word, forbbiden symbols - (\"{ ,}\")\n";
	std::cout << "	- about (size unlimeted, forbbiden symbols - (\"{ ,}\")\n";
	std::cout << "	- drawing ids (size unlimeted, every id must contain at beginning users nick, forbbiden symbols - (\"{ ,}\")\n";
	std::cout << "\n";
	std::cout << "Drawing consist of\n";
	std::cout << "	- lid (local id, which can change after sorting)\n";
	std::cout << "	- owner (size 1 word, forbbiden symbols like \"!,),@...\")\n";
	std::cout << "	- title (size 1 word, forbbiden symbols - \"{ ,}\")\n";
	std::cout << "	- id (size 1 word, id must contain at beginning owners nick, forbbiden symbols - \"{ ,}\")\n";
	std::cout << "	- file name (size 1 word, forbbiden symbols - (\"{ ,}\")\n";
	std::cout << "	- date and time of add  (size 1 word, forbbiden symbols - (\"{ ,}\")\n";
	std::cout << "	- about (size unlimeted, forbbiden symbols - (\"{ ,}\")\n";
	std::cout << "	- tags (size unlimeted, tag must contain at beginning \"#\", forbbiden symbols - (\"{ ,}\")\n";
	std::cout << "\n";
	std::cout << "Don't recommend edit files manually";
	std::cout << "------------------------------------------------\n";
	std::cin.get();

};