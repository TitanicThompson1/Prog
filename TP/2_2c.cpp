#include <iostream>

using namespace std;

int main() {
	double a, b, c;
	double max,min,middle;
	cout << "a b c ?";
	cin >> a >> b >> c;

	if (a > b && a > c) {
		max = a;
		if (b > c) {
			min = c;
			middle = b;
		}
		else {
			min = b;
			middle = c;
		}
	}
	else if (b > c) {
		max = b;
		if (a > c) {
			middle = a;
			min = c;
		}
		else {
			middle = c;
			min = a;
		}

	}
	else {
		max = c;
		if (b > a) {
			middle = b;
			min = a;
		}
		else {
			middle = a;
			min = b;

		}
	}

	if (max >= (min + middle)) {

		cout << "\nImpossivel serem lados de um triangulo\n";

	}
	else {
		cout << "\nE possivel serem lados de um triangulo\n";
	}
	
	return 0;
}