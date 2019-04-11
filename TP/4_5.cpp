#include <iostream>
#include <string>
using namespace std;

struct Fraction {
	int numerator;
	int denominator;
};

Fraction readFracc() {
	Fraction fac1;
	char sep;
	cin >> fac1.numerator >> sep >> fac1.denominator;
	if (fac1.denominator == 0) {
		fac1.numerator = 0;

	}
}