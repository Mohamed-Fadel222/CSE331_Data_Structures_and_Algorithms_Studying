#include "ASU-F23-Tut03-Ex06-Polynomial-Class-Exercise-Header.hpp"

// "::" is called the Scope Resolution Operator
// Read more about it in https://learn.microsoft.com/en-us/cpp/cpp/scope-resolution-operator
Polynomial::Polynomial() {} // Need an empty constructor to use assignment operator
Polynomial::Polynomial(int degree, float coeffs[]) : degree(degree), coeffs(coeffs) {}
Polynomial::~Polynomial() { delete[] coeffs; }
void Polynomial::display(ostream& out = cout) const { // We set cout as default value for output stream
    out << "\nMy degree is: " << degree << endl;
    for (int i = 0; i < degree; i++) {
        out << coeffs[i] << "*X^" << i;
        if (i != degree - 1) cout << " + ";
    }
    out << "\n\n";
}
float Polynomial::evaluate(float x) const {
    float result = 0;
    for (int i = 0; i < degree; i++) {
        result += coeffs[i] * pow(x, i);
    }
    return result;
}
void Polynomial::operator=(Polynomial const& poly) {
    cout << "\nOverloaded assignment operator invoked!\n";
    degree = poly.degree;
    coeffs = new float[degree];
    for (int i = 0; i < degree; i++) coeffs[i] = poly.coeffs[i];
}
void Polynomial::add_1_to_all_coeffs() { for (int i = 0; i < degree; i++) coeffs[i]++; }

Polynomial operator+(Polynomial const& poly1, Polynomial const& poly2) {
    int new_poly_degree = max(poly1.degree, poly2.degree);
    float* new_poly_coeffs = new float[new_poly_degree];
    for (int i = 0; i < new_poly_degree; i++) {
        if (i < poly1.degree && i < poly2.degree) {
            new_poly_coeffs[i] = poly1.coeffs[i] + poly2.coeffs[i];
        } else if (i < poly1.degree) {
            new_poly_coeffs[i] = poly1.coeffs[i];
        } else if (i < poly2.degree) {
            new_poly_coeffs[i] = poly2.coeffs[i];
        }
    }
    return Polynomial(new_poly_degree, new_poly_coeffs);
}
ostream& operator<<(ostream& out, Polynomial const& poly) { poly.display(out); return out; }
