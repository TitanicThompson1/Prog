#include <iostream>

using namespace std;

int main() {
	float peso, custo;

	cout << "Peso ?  ";
	cin >> peso;

	if (peso < 500) {
		custo = 5;
	}
	else if (peso <= 1000) {

		custo = 5 + ((int)(peso - 500) / 100)*	1.5;

	}
	else {
		custo = 12.5 + ((int)(peso - 1000) / 250) * 5;
	}
	cout << "Custo = " << custo;
	return 0;

}