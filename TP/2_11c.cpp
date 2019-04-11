#define _USE_MATH_DEFINES


#include <iostream>
#include <cmath>

using namespace std;

int main() {

	int n, fact = 1;
	bool soma = false;
	float result = 1,x;

	cout << "n x?  ";
	cin >> n >> x;

	for (int i = 1; i < n; i++) {
		fact = fact * i;
		if (soma) {
			result = result + (float)pow(x, i) / fact;
			soma = false;
		}
		else {
			result = result - (float)pow(x, i) / fact;
			soma = true;
		}
		
	}
	cout << result;
	return 0;
}