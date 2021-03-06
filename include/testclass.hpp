#include<iostream>
#include<complex>
#include <cctype>
using namespace std;

class Complex {
public:
	complex< double >number;
	Complex() {
		number = 0;
	}
	Complex(complex< double >number) {
		this->number = number;
	}
	Complex(const Complex&c) {
		this->number = c.number;
	}
	void add(complex< double >x, complex< double >y) {
		number = x + y;
		cout << "\nProceeding with summ...";
		cout << "\n" << conj(x) << " + " << conj(y) << " = " << conj(number)<<endl;
	}
	void sub(complex< double >x, complex< double >y) {
		number = x-y;
		cout << "\nProceeding with substraction...";
		cout << "\n" << conj(x) << " - " << conj(y) << " = " << conj(number)<<endl;
	}
	
	void mult(std::complex< double >x,int y) {
		std::complex< double >buf(double(y), 0.0);
		number = x * buf;
		cout << "\nProceeding with multiplication...";
		cout << "\n" << conj(x) << " * " << y << " = " << conj(number) << endl;
	}
	
	void div(std::complex< double >x, int y) {
		try {
			if (y != 0) {
				std::complex< double >buf(double(y), 0.0);
				this->number = x / buf;
				cout << "\nProceeding with division...";
				cout << "\n" << conj(x) << " / " << y << " = " << conj(number) << endl;
			}
			else throw "Can't divide by zero!";
		}
		catch (char *err) {
			cout << "\nProceeding with division...";
			cout << "\n" << conj(x) << " / " << 0;
			cout << "\nError:" << err;
			cout << "\nChange another number...";
				char str[64];
				cin >> str;
				int new_num;
				if (isdigit(str[0])) {
					new_num = atoi(str);
					cout << new_num;
				}
				div(x, new_num);
			}
		}

	Complex operator +(const Complex& c) {
		Complex buf(*this);
		buf.number += c.number;
		return buf;
	}
	Complex operator -(const Complex& c) {
		Complex buf(*this);
		buf.number -= c.number;
		return buf;
	}
	Complex operator *(const Complex& c) {
		Complex buf(*this);
		buf.number *= c.number;
		return buf;
	}
	Complex operator /(const Complex& c) {
		Complex buf(*this);
		buf.number /= c.number;
		return buf;
	}
	Complex operator +=(const Complex& c) {
		number += c.number;
		return *this;
	}
	Complex operator -=(const Complex& c) {
		number -= c.number;
		return *this;
	}
	Complex operator *=(const Complex& c) {
		number *= c.number;
		return *this;
	}
	Complex operator /=(const Complex& c) {
		number /= c.number;
		return *this;
	}
	Complex operator =(const Complex& c) {
		number = c.number;
		return *this;
	}
	bool operator ==(const Complex& c) {
		if(this->number==c.number)
		return true;
		else return false;
	}
	
};
