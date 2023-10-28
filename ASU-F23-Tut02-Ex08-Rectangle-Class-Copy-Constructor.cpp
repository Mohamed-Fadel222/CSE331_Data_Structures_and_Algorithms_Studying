#include <iostream>

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double len, double wid) : length(len), width(wid) {}
    Rectangle(Rectangle& rect) { // Copy Constructor
        std::cout << "\nCustom copy constructor invoked" << std::endl;
        length = rect.length;
        width = rect.width;
    }
    double calculateArea() { return length * width; }
    double calculatePerimeter() { return 2 * (length + width); }
};

int main() {

    double length = 35, width = 15;
    Rectangle rectangle(length, width);
    std::cout << "\nRectangle Area: " << rectangle.calculateArea() << std::endl;
    std::cout << "Rectangle Perimeter: " << rectangle.calculatePerimeter() << std::endl;
    Rectangle rectangle2 = rectangle; // Making a copy with copy constructor only
    std::cout << "\nRectangle2 Area: " << rectangle2.calculateArea() << std::endl;
    std::cout << "Rectangle2 Perimeter: " << rectangle2.calculatePerimeter() << std::endl;

    return 0;
}

