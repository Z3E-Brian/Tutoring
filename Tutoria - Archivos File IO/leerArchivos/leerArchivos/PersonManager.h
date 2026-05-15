#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "FileManager.h"
#include "Person.h"

using namespace std;

class PersonManager
{
public:
	void savePeopleToFile(const vector<Person>&,const string&);
	vector<Person> loadPeopleFromFile(const string&);
	void displayPeople(const vector<Person>&);
private:
	FileManager fileManager;
};

