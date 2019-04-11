#include <iostream>

using namespace std;

int main() {

	int n;
	int soma = 0, menor, maior, quants_n = 0;
	float media;
	bool another_one = true;


	cin >> n;
	
	menor = n;
	maior = n;

	while (n != 0 && another_one) {
		soma = soma + n;
		quants_n++;
		if (menor > n) {
			menor = n;
		}
		if (maior < n) {
			maior = n;
		}
		cin >> n;
		if (cin.fail()) {
			if (cin.eof()) {
				another_one = false;
			}
		}

	}

	media = (float)soma / quants_n;
	cout << "soma=  " << soma << endl << "media=  " << media << endl << "menor=  " << menor << endl << "maior=  " << maior << endl << "comprimento=  " << quants_n;
	return 0;
}