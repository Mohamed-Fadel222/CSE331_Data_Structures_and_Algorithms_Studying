
// The most important tip in your life regarding operator overloading:
// If it gets too confusing, write it as if it is a method
// For example; replace "operator+" with "add"

#include <iostream>
using namespace std;

class Number {
private:                                                             // The default visibility scope
    int val = 0;
public:
    Number(int i) : val(i) {}                                        // Constructor with initialization list; same as { this->val = i; }
    int get_val() const { return val; }                              // Getter
    void set_val(int i) { val = i; }                                 // Setter
    // ------------------------------------- //
    // Operator Overloading Inside the Class //
    // ------------------------------------- //
    Number& operator++() { val++; return *this; }                    // Prefix,  ++i
    Number operator++(int) { Number temp(val); val++; return temp; } // Postfix, i++
    // P.S. The compiler uses the int argument to distinguish between the prefix and postfix increment operators. It doesn't actually use it.
    // P.S. Which is better for incrementing, i++ or ++i ? i++ creates a temporary object.. If a copy is not needed, then it is inefficient.
    Number operator+(Number const& number) { return Number(this->val + number.val); }
    // P.S. const& vs. const Number& https://stackoverflow.com/a/19415853/
    friend ostream& operator<<(ostream& out, const Number& number) { out << "Number: " << number.val << endl; return out; }
    // P.S. Why return out; ?        https://stackoverflow.com/a/61739522/
    // P.S. Why friend? Because operator<< takes as arguments an output stream (ostream) and something else
    // Unlike the previous operators, the first argument is NOT an object of the class itself
    // As discussed in the section, by default member methods defined in a Class will have an implicit first argument "this" pointer to the object itself
    // Therefore, without "friend", the first argument would be a pointer to Number object, which is not what operator<< expects
    // The question thus becomes; why does "friend" remove "this"?
    // The answer is that "friend" means that the function or class that has "friend" attribute is an EXTERNAL entity that can access this object's private contents
    // In other words, "friend" means that this function is actually NOT a member of the class!
    // And despite it not being a member method, we could use "number.val", even though "val" is private
    // Thus "friend" allowed us to do two things here:
    // 1. Remove "this" as the first arg to the operator<< method
    // 2. Use private variable "val" in a function that is not part of the class
};
// -------------------------------------- //
// Operator Overloading Outside the Class //
// -------------------------------------- //
// P.S. Which way is better?     https://stackoverflow.com/q/2425906/
// Number& operator++(Number& n) { n.set_val(n.get_val()+1); return n; }
// Number operator++(Number& n, int) { Number temp(n.get_val()); n.set_val(n.get_val()+1); return temp; }
// Number operator+(Number const& num1, Number const& num2) { return Number(num1.get_val() + num2.get_val()); }
// ostream& operator<<(ostream& out, const Number& number) { out << "Number: " << number.get_val() << endl; return out; }
// P.S. Note how now we needed to replace the implicitly defined "this" with an actual object of Number.
// P.S. Note how we used setters and getters now, since we don't have access to the private variable "val" anymore
// P.S. Note how operator<< is no longer friends with us anymore!! :(

int main() {
    Number three(3);
    Number four(4);
    Number number(10);
    cout << three + four;
    cout << number++; // Prints 10, then increments to 11
    cout << ++number; // Increments to 12, then prints 12
    // Note how we are cout-ing the object itself, NOT number.get_val()
    // Thanks to operator<< we can do that
    // Thanks to "return out;", we can also do the following:
    cout << three << four << number << "Print all you want";
}

