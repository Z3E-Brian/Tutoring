#include <iostream>

// Polymorphism is the ability to use a single interface to represent different data types.
/*
int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

// Polymorphism can be achieved using function overloading.

class Animal {
public:
    virtual void makeSound() {
        std::cout << "Some generic animal sound" << std::endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() override {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Meow!" << std::endl;
    }
};

void playSound(Animal* animal) {
    animal->makeSound();
}

int main() {
    Dog dog;
    Cat cat;
    playSound(&dog); // Output: Woof!
    playSound(&cat); // Output: Meow!
    return 0;
}
*/
// Abstract classes are classes that cannot be instantiated 
// and are used to define an interface for derived classes.


class Shape {
public:
    virtual void draw() = 0;  // Función virtual pura
    virtual double area() = 0; // Otra función virtual pura
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a circle" << std::endl;
    }

    double area() override {
        return 3.14 * radius * radius;
    }

private:
    double radius;
};

class Rectangle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a rectangle" << std::endl;
    }

    double area() override {
        return width * height;
    }

private:
    double width, height;
};

int main() {
    Shape* shape1 = new Circle();
    Shape* shape2 = new Rectangle();
    shape1->draw();  // Output: Drawing a circle
    shape2->draw();  // Output: Drawing a rectangle

    delete shape1;
    delete shape2;
    return 0;
}