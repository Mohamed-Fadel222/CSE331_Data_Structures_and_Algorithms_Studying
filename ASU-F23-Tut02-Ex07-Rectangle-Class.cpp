#include <iostream>

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double len, double wid) : length(len), width(wid) {}
    double calculateArea() { return length * width; }
    double calculatePerimeter() { return 2 * (length + width); }
};

int main() {

    double length, width;
    std::cout << "Input the length of the rectangle: ";
    std::cin >> length;
    std::cout << "Input the width of the rectangle: ";
    std::cin >> width;
    Rectangle rectangle(length, width);
    std::cout << "\nArea: " << rectangle.calculateArea() << std::endl;
    std::cout << "Perimeter: " << rectangle.calculatePerimeter() << std::endl;
    Rectangle rectangle2 = rectangle; // Making a copy, without copy constructor or assignment operator overloading
    return 0;
}
