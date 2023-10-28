#include <iostream>
#include <cmath>
using namespace std;

class Polynomial {

    int degree;
    float* coeffs;

public:
    Polynomial() {} // Need an empty constructor to use assignment operator
    Polynomial(int degree, float coeffs[]) : degree(degree), coeffs(coeffs) {}
    void display(ostream& out = cout) const { // We set cout as default value for output stream
        out << "\nMy degree is: " << degree << endl;
        for (int i = 0; i < degree; i++) {
            out << coeffs[i] << "*X^" << i;
            if (i != degree - 1) cout << " + ";
        }
        out << "\n\n";
    }
    float evaluate(float x) const {
        float result = 0;
        for (int i = 0; i < degree; i++) {
            result += coeffs[i] * pow(x, i);
        }
        return result;
    }
    void operator=(Polynomial const& poly) {
        cout << "\nOverloaded assignment operator invoked!\n";
        degree = poly.degree;
        coeffs = new float[degree];
        for (int i = 0; i < degree; i++) coeffs[i] = poly.coeffs[i];
    }
    void add_1_to_all_coeffs() { for (int i = 0; i < degree; i++) coeffs[i]++; }
    friend Polynomial operator+(Polynomial const&, Polynomial const&);
};

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

int main() {
    int degree1 = 3;
    float coeffs1[] = { 1.0f, 1.0f, 1.0f };
    Polynomial poly1(degree1, coeffs1);
    int degree2 = 3;
    float coeffs2[] = { 1.0f, 1.0f, 1.0f };
    Polynomial poly2(degree2, coeffs2);
    for (int i = 0; i < 100000000; i++) poly1 + poly2;
    cout << "Done exploding your RAM :)" << endl;
    getchar(); // Just so that the program doesn't close before we go check Task Manager
}