#define _USE_MATH_DEFINES


#include <iostream>
#include <cmath>

using namespace std;

int main() {

	int n, fact=1;
	float result = 1;

	cout << "n?  ";
	cin >> n;

	for (int i = 1; i < n; i++) {
		fact = fact * i;
		result = result + (float)1 / fact;


	}
	cout << result;
	return 0;
	
	
}


