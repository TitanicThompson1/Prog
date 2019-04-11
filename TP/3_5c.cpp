#include <iostream>

using namespace std;

void reduceFracc(int &numerator, int &denominator) {
	int a = numerator, b = denominator, temp, mdc;

	while (b != 0) {
		temp = a;
		a = b;
		b = temp % b;
	}
	mdc = a;
	numerator = numerator / a;
	denominator = denominator / a;
}

void writeFracc(int numerator, int denominator) {
	cout << numerator << "/" << denominator;

}

int main() {
	int a = 188, b = 200;

	reduceFracc(a, b);
	writeFracc(a, b);
	return 0;
}