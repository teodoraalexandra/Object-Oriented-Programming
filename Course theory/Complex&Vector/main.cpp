#include <iostream>
#include <vector>

class Complex {
public:
    int real;
    int imaginary;

    Complex(int _real = 0, int _imaginary = 0) : real (_real), imaginary (_imaginary) {}
    ~Complex() {}
    int getReal() { return this->real ; }
    int getImaginary() { return this->imaginary; }
};

Complex operator + (Complex const &c1, Complex const &c2)
{
    return Complex(c1.real + c2.real, c1.imaginary + c2.imaginary);
}

Complex operator / (Complex const &c1, int c2)
{
    return Complex(c1.real/c2, c1.imaginary/c2);
}

bool operator == (Complex const &c1, Complex const &c2)
{
    return (c1.real == c2.real and c1.imaginary == c2.imaginary);
}

std::ostream& operator <<(std::ostream& os, const Complex& c)
{
    os << c.real << " + " << c.imaginary << " i ";
    return os;
}

template <typename T>
class Vector
{
private:
    std::vector<T> vec;

public:
    Vector(std::vector<T> v) : vec{ v } {}
    //~Vector() {}

    void printAll() {
        for (auto m : vec) {
            std::cout << m << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    Complex a{}, b {1, 2}, c {6, 4}, d { b };
    assert(a.getReal() == 0 and a.getImaginary() == 0);
    assert(c.getImaginary() == 4);
    assert(b == d);
    Complex res1  = c/2;
    std::cout << res1 << "\n";

    Vector<std::string> v1 {std::vector<std::string> {"hello", "bye"}};
    v1.printAll();
    Vector<Complex> v2 {std::vector<Complex> {a, b, c, d}};
    v2.printAll();
    return 0;
}