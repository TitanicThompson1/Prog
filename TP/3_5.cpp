#include <iostream>

using namespace std;

bool readFracc(int &numerator, int &denominator) {
	char sep;
	cout << "numerador separador denominador ?";
	cin >> numerator >> sep >> denominator;
	if (!cin.fail() && denominator != 0 && sep == '/') {
		return true;

	}
	else {
		numerator = 0;
		denominator = 0;
		return false;
	}
}

int main() {
	int a = 0, b = 1;
	
	cout << readFracc(a, b) << endl;
	return 0;
}