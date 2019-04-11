#include <iostream>

using namespace std;

int main() {

	int n;
	bool soma = true;
	float result=0;

	cout << "n?  ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		if (soma) {
			result = result + ((float)4 / (2 * i + 1));
			soma = false;
		}
		else {
			result = result - ((float)4 / (2 * i + 1));
			soma = true;
		}
		
	}
	cout << result;
	return 0;
}
