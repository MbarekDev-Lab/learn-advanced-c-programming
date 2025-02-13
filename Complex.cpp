#include "Complex.h"


using namespace std;
namespace testclassesComplex
{
	//Complex::Complex(){}
	Complex::Complex(double real, double imaginary) :real(real), imaginary(imaginary) {}
	
	Complex::Complex(const Complex &other) {
		cout << " Copy " << endl;
		real = other.real;
		imaginary = other.imaginary;
	}

	// member function called anly by obj 
	const Complex& Complex::operator=(const Complex& other) {
		cout << "Assignment operator running" << endl;
		if (this == &other) {
			return *this; // handle self assignment 
		}
		real = other.real;
		imaginary = other.imaginary;
		return *this;
	}

	ostream& operator<<(ostream& out, const Complex& c) {
		out << "(" << c.getReal() << ", " << c.getImaginary() << ")";
		return out;
	}

	Complex operator+(const Complex& c1, const Complex& c2) {
		return Complex(c1.getReal() + c2.getReal(), c1.getImaginary() + c2.getImaginary());
	}

	Complex operator+(const Complex& c1, double d)
	{
		return Complex(c1.getReal() + d, c1.getImaginary());
	}

	Complex operator+(double d, const Complex& c1) {
		return Complex( c1.getReal() +d , c1.getImaginary());
	}

	bool Complex::operator==(const Complex& other)const {
		return (real == other.real) && (imaginary == other.imaginary);
	}
} // end of testclassesComplex
