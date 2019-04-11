#include <iostream>

using namespace std;

int main() {

	int a, b, c;
	float media;
	cout << "A ? ";
	cin >> a;
	cout << "B ? ";
	cin >> b;
	cout << "C ? ";
	cin >> c;
	media = (float) (a + b + c) / 3;
	cout << "media	= " << media << endl << "A-media	= " << a - media <<endl<< "B-media	= " << b - media <<endl<< "C-media	= " << c - media;
	return 0;


}