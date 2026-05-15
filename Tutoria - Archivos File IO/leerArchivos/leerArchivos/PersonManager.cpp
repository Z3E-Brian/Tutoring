#include "PersonManager.h"

void PersonManager::savePeopleToFile(const vector<Person>& people, const string& fileName) {
    vector<string> lines;
    for (const Person& person : people) {
        string line = person.firstName + "," + person.lastName + ";" + to_string(person.age) + "*" + person.gender;
        lines.push_back(line);
    }

    fileManager.save(lines, fileName);
}

vector<Person> PersonManager::loadPeopleFromFile(const string& fileName) {
    vector<string> loadedLines = fileManager.load(fileName);
    vector<Person> loadedPeople;

    for (string& line : loadedLines) {
        string firstName="", lastName="", gender = "";
        int age = 0;
        if (!line.empty()) {

            istringstream iss(line);
            iss >> firstName >> lastName >> age >> gender;

            loadedPeople.push_back(Person(firstName, lastName, age, gender));
        }
    }

    return loadedPeople;
}

void PersonManager::displayPeople(const vector<Person>& people) {
    for (const Person& person : people) {
        cout << "Nombre: " << person.firstName << " " << person.lastName << ", Edad: " << person.age << ", Genero: " << person.gender << std::endl;
    }
}