#include "FileManager.h"

using namespace std;

    void FileManager::save(const vector<string>& lines, const string& fileName) {
        try
        {
            ofstream file(fileName);
            for (const string& line : lines) {
                file << line << '\n';
            }

            file.close();
            cout << "Archivo guardado exitosamente." << endl;
        }
        catch (const exception& ex)
        {
            cerr << "No se pudo abrir el archivo para escritura." << ex.what() << endl;

        }
    }

    vector<string> FileManager::load(const string& fileName) {
        try
        {
            vector<string> lines;
            ifstream file(fileName);

            string line;
            while (getline(file, line)) {
                lines.push_back(line);
                cout << line<<endl;
            }
            file.close();
            cout << "Archivo cargado exitosamente." << endl;
            return lines;
        }
        catch (const exception& ex)
        {
            cerr << "No se pudo abrir el archivo para lectura: " << ex.what() << endl;
            return vector<string>();
        }
    }
