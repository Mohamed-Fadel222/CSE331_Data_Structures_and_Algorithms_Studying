#include "ASU-F23-Tut03-Ex06-Polynomial-Class-Exercise-Header.hpp"
#include <iostream>
using namespace std;

int main() {
    int degree;
    cout << "Please enter the degree: ";
    cin >> degree;
    cout << "Please enter the " << degree << " coefficients, space-separated: ";
    float* coeffs = new float[degree];
    for (int i = 0; i < degree; i++) cin >> coeffs[i];
    Polynomial poly1(degree, coeffs);
    cout << "\n------------- Polynomial #1: -------------\n" << poly1; // Same as poly.display();
    int x;
    cout << "Enter X value to evaluate: ";
    cin >> x;
    cout << "Result: " << poly1.evaluate(x) << endl;
    int degree2 = 3;
    float coeffs2[] = { 4.0f, 5.0f, 4.0f };

    Polynomial poly2(degree2, coeffs2);
    cout << "\n------------- Polynomial #2: -------------\n" << poly2;

    Polynomial poly3;
    poly3 = poly1 + poly2;
    cout << "\n------------- Polynomial #3 (after #3 = #1 + #2): -------------\n" << poly3;

    // Polynomial poly4 = poly3; // This uses the copy constructor, not the assignment operator!
    Polynomial poly4;
    poly4 = poly3;
    cout << "\n------------- Polynomial #4 (after #4 = #3): -------------\n" << poly3;

    poly3.add_1_to_all_coeffs();
    cout << "\n------------- Polynomial #3 (after add_1_to_all_coeffs): -------------\n" << poly3;
    cout << "\n------------- Polynomial #4: -------------\n" << poly4;
}