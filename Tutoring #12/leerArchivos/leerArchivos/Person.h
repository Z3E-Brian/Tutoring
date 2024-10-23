#pragma once
#include <string>

using namespace std;

class Person
{
public:
    string firstName;
    string lastName;
    int age;
    string gender;
    Person(const string&, const string&, int, const string&);
};

