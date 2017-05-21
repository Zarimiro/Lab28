#include<iostream>
#include<complex>
#include <cctype>
using namespace std;

class Complex {
	complex< double >number;
public:
	Complex() {
		number = 0;
	}
	Complex(complex< double >number) {
		this->number = number;
	}
	Complex(const Complex&c) {
		this->number = c.number;
	}
	
	void print(ostream&) {

		cout << "\nComplex number: " << real(number)<<" + "<<imag(number)<<"i";
	}
	void set(istream&) {
		double x, y;
		cin >> x;
		cin >> y;
		complex< double >z(x, y);
		number = z;
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
	
	friend ostream & operator <<(ostream&, const Complex& );
	friend istream& operator >> (istream&, Complex&);

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

ostream & operator <<(ostream& out,  Complex& d) {
	d.print(out);
	return out;
}

istream & operator >>(istream& in,  Complex& d) {
	d.set(in);
	return in;
}
