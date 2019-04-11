#include <iostream>

using namespace std;

int main() {

	int long long n, n1, len = 0, frst, last;
	bool defintly_not_cap = false;

	cout << "n?  ";
	cin >> n;
	n1 = n;

	while (n1 != 0) {
		len++;
		n1 = n1 / 10;
		
	}
	cout << len << endl;

	while (!defintly_not_cap && len>=2 ) {
		frst = n / (pow(10, len - 1));
		last = n % 10;
		cout << frst << endl;
		cout << last << endl;

		if (frst != last) {
			defintly_not_cap = true;
		}
		else {
			n = n - frst*pow(10, len - 1) - last;
			n = n / 10;
			cout << n << endl;
		}
		len = len - 2;

	}
	if (defintly_not_cap) {
		cout << "Nao e capicua";
		
	}
	else {
		cout << "E capicua";

	}
	return 0;
}