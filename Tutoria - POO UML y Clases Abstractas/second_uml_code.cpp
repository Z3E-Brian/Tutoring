#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Clase base: FileSystemElement
class FileSystemElement {
public:
    FileSystemElement() {}
    virtual ~FileSystemElement() {}

    virtual  string getName() const = 0;
    virtual int getSize() const = 0;
    virtual void print(const  string& upper_path) const = 0;
    virtual  string toString() const = 0;
};

// Clase File que hereda de FileSystemElement
class File : public FileSystemElement {
private:
     string name;
    int size;

public:
    File(const  string& name, int size) : name(name), size(size) {}
    ~File() {}

     string getName() const override {
        return name;
    }

    int getSize() const override {
        return size;
    }

    void print(const  string& upper_path) const override {
         cout << upper_path + "/" + name << " (" << size << " bytes)" <<  endl;
    }

     string toString() const override {
        return name + " (" +  to_string(size) + " bytes)";
    }
};

// Clase Directory que hereda de FileSystemElement
class Directory : public FileSystemElement {
private:
     string name;
     vector<FileSystemElement*> elements;

public:
    Directory(const  string& name) : name(name) {}
    ~Directory() {
        for (auto element : elements) {
            delete element;
        }
    }

     string getName() const override {
        return name;
    }

    int getSize() const override {
        int totalSize = 0;
        for (const auto& element : elements) {
            totalSize += element->getSize();
        }
        return totalSize;
    }

    void print(const  string& upper_path) const override {
         string fullPath = upper_path + "/" + name;
         cout << fullPath << " (dir)" <<  endl;
        for (const auto& element : elements) {
            element->print(fullPath);
        }
    }

     string toString() const override {
        return name + " (dir)";
    }

    FileSystemElement* add(FileSystemElement* element) {
        elements.push_back(element);
        return element;
    }
};

int main() {
    // Crear un directorio principal
    Directory* root = new Directory("root");

    // Crear archivos y anadirlos al directorio principal
    root->add(new File("file1.txt", 100));
    root->add(new File("file2.txt", 200));

    // Crear un subdirectorio y anadirle archivos
    Directory* subDir = new Directory("subdir");
    subDir->add(new File("file3.txt", 300));
    subDir->add(new File("file4.txt", 400));

    // Anadir el subdirectorio al directorio principal
    root->add(subDir);

    // Imprimir la estructura del sistema de archivos
    root->print("");

    // Liberar memoria
    delete root;

    return 0;
}
