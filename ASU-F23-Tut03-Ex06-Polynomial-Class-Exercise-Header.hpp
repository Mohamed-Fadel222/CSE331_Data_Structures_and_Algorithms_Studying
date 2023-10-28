#ifndef POLYNOMIAL
#define POLYNOMIAL

#include <iostream>
#include <cmath>
using namespace std;

class Polynomial {

private:
    int degree;
    float* coeffs;

public:
    Polynomial();
    Polynomial(int degree, float coeffs[]);
    ~Polynomial();
    void display(ostream& out) const;
    float evaluate(float x) const;
    void operator=(Polynomial const& poly);
    void add_1_to_all_coeffs();
    friend Polynomial operator+(Polynomial const&, Polynomial const&);
};

Polynomial operator+(Polynomial const& poly1, Polynomial const& poly2);
ostream& operator<<(ostream& out, Polynomial const& poly);

#endif /* POLYNOMIAL */
