#include <iostream>

using namespace std;

int main() {

	int n;
	int soma=0, menor, maior,quants_n=0;
	float media;

	cin >> n;
	menor = n;
	maior = n;

	while (n != 0) {
		soma = soma + n;
		quants_n++;
		if (menor > n) {
			menor = n;
		}
		if (maior < n) {
			maior = n;
		}
		cin >> n;

	}

	media = (float) soma / quants_n;
	cout << "soma=  " << soma << endl << "media=  " << media << endl << "menor=  " << menor << endl << "maior=  " << maior << endl << "comprimento=  " << quants_n;
	return 0;
}