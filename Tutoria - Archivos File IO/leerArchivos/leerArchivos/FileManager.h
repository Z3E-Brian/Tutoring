#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class FileManager
{
public:
	void save(const vector<string>&, const string&);
	vector<string> load(const string&);
private:

};

