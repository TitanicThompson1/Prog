#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	int n;
	bool primo = true;
	cout << "n= ?  ";
	cin >> n;

	for (int i = 2; i <= sqrt(n) ; i++) {

		if (n%i == 0) {
			primo = false;
			break;
		}
	}
	if (primo) {
		cout << "is prime";

	}
	else {
		cout << "is not prime";

	}
	
	return 0;
}