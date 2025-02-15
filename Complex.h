#pragma once
#ifndef COMPLEX_
#define COMPLEX_  // !COMPLEX_

#include <iostream>
using namespace std;

namespace testclassesComplex
{
	class Complex
	{
	
	private:
		double real;
		double imaginary;

	public:
		//Complex();
		Complex(const Complex &other);
		Complex(double real, double imaginarty);
		const Complex &operator=(const Complex &other);


		double getReal() const {
			return real;
		}

		double getImaginary() const {
			return imaginary;
		}

		bool operator==(const Complex& other)const;

	};

	ostream& operator<<(ostream& out, const Complex& c);
	
	Complex operator+(const Complex &c1 , const Complex &c2);
	Complex operator+(const Complex &c1, double d);
	Complex operator+(double d, const Complex &c1);

} // end of testclassesComplex

#endif // !COMPLEX_

// End of Complex.h
