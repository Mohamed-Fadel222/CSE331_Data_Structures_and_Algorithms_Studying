#include <iostream>

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle() {} // Default constructor required, read from line 38
    Rectangle(double len, double wid) : length(len), width(wid) {}
    Rectangle(Rectangle& rect) { // Copy Constructor
        std::cout << "\nCustom copy constructor invoked" << std::endl;
        length = rect.length;
        width = rect.width;
    }
    void operator=(Rectangle& rect) { // Assignment Operator
        std::cout << "\nOverloaded assignment operator invoked" << std::endl;
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

    Rectangle rectangle2 = rectangle; // The "=" used here invokes the copy constructor!
    std::cout << "\nRectangle2 Area: " << rectangle2.calculateArea() << std::endl;
    std::cout << "Rectangle2 Perimeter: " << rectangle2.calculatePerimeter() << std::endl;

    Rectangle rectangle3;
    // The above line of code will not work without a default constructor!
    // Some students may remember that "default constructors are created automatically"
    // This is true only if you do not define other constructors; which we clearly aren't doing
    // We defined two constructors (the one that takes length and width, and the copy constructor)
    // Therefore, if I want to write this line without errors, I need to write the default constructor.
    rectangle3 = rectangle; // The "=" used here invokes the overloaded assignment operator!
    // It is very important to notice the difference between the two "=" in lines 32 and 42.
    std::cout << "\nRectangle3 Area: " << rectangle3.calculateArea() << std::endl;
    std::cout << "Rectangle3 Perimeter: " << rectangle3.calculatePerimeter() << std::endl;

    return 0;
}

