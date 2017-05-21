#include <testclass.hpp>
#include <catch.hpp>

SCENARIO("Default constructor") {
	Complex c;
	REQUIRE(c.number.real()==0.0);
	REQUIRE(c.number.imag()==0.0);
}

SCENARIO("constructor with params") {
complex< double >x(1.0, 2.0);
	Complex c(x);
	REQUIRE(c.number.real() == 1.0);
	REQUIRE(c.number.imag() == 2.0);
}

SCENARIO("copy constructor") {
complex< double >x(1.0, 2.0);
	Complex c(x);
  Complex d(c)
	REQUIRE(d.number.real() == 1.0);
	REQUIRE(d.number.imag() == 2.0);
}

SCENARIO("operator*") {
complex< double >x(7.0, 6.0);
complex< double >y(5.0, 4.0);
complex< double >z(11.0, 58.0);
	Complex c1(x);
	Complex c2(y);
	Complex c3(z);
	REQUIRE((c1*c2)==c3);
}

SCENARIO("operator/") {
complex< double >x(7.0, 6.0);
complex< double >y(7.0, 6.0);
complex< double >z(1.0, 0.0);
	Complex c1(x);
	Complex c2(y);
	Complex c3(z);
	REQUIRE((c1/c2)==c3);
}

SCENARIO("operator +=") {
complex< double >x(13.0, 1.0);
complex< double >y(7.0, 6.0);
complex< double >z(20.0, 7.0);
	Complex c1(x); 
	Complex c2(y);
	Complex c3(z);
	REQUIRE((c1+=c2)==c3);
}

SCENARIO("operator -=") {
complex< double >x(13.0, 10.0);
complex< double >y(7.0, 6.0);
complex< double >z(6.0, 4.0);
	Complex c1(x); 
	Complex c2(y);
	Complex c3(z);
	REQUIRE((c1-=c2)==c3);
}

SCENARIO("operator *=") {
complex< double >x(7.0, 6.0);
complex< double >y(5.0, 4.0);
complex< double >z(11.0, 58.0);
	Complex c1(x); 
	Complex c2(y);
	Complex c3(z);
	REQUIRE((c1*=c2)==c3);
}

SCENARIO("operator /=") {
complex< double >x(7.0, 6.0);
complex< double >y(7.0, 6.0);
complex< double >z(1.0, 0.0);
	Complex c1(x); 
	Complex c2(y);
	Complex c3(z);
	REQUIRE((c1/=c2)==c3);
}

SCENARIO("operator =") {
complex< double >x(7.0, 6.0);
	Complex c1(x); 
	Complex c2=c1;
	REQUIRE(c2==c1);
}

SCENARIO("operator ==") {
complex< double >x(7.0, 6.0);
	Complex c1(x); 
	Complex c2(x);
	REQUIRE(c1==c2);
}
