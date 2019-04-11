#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

int main() {

	int n1, n2, answer;
	clock_t t;

	srand(time(NULL));

	n1 = rand() % 8 + 2;
	n2 = rand() % 8 + 2;

	cout << n1 << " x " << n2 << " ?  ";
	t = clock();
	cin >> answer;
	t = clock()-t;
	t = (float)t / CLOCKS_PER_SEC;
	if (answer != n1 * n2) {
		cout << "Muito mau! Vai levar tau tau";

	}
	else if (t < 5) {
		cout << "Bom";

	}
	else if (t <= 10) {
		cout << "Satisfaz";

	}
	else {
		cout << "Insuficiente";

	}
	return 0;
}