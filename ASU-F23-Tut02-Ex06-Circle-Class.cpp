#include <iostream>
#include <cmath>

const double PI = 3.14159;

class Circle {
private:
    double radius;

public:
    Circle(double rad) : radius(rad) {} // Constructor with initialization list; same as:
                                        // Circle(double rad) { radius = rad; }
    double calculateArea() { return PI * pow(radius, 2); } // Requires <cmath>
    double calculateCircumference() { return 2 * PI * radius; }
};

int main() {

    double radius;
    std::cout << "Input the radius of the circle: ";
    std::cin >> radius;
    Circle circle(radius); // This is NOT the same as using "new"!!!!! Stack vs. Heap memory!
                           // NOT identical to Circle* circle = new Circle(radius)
    std::cout << "Area: " << circle.calculateArea() << std::endl;
    std::cout << "Circumference: " << circle.calculateCircumference() << std::endl;

    return 0;
}

