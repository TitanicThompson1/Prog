#include <iostream>
#include <iomanip>

using namespace std;

bool isPrime(int x) {

	for (int i = 2; i <= sqrt(x); i++) {

		if (x%i == 0) {
			return false;
		}

	}
	return true;
}

int main() {
	
	bool primo;
	int a=7;
	if (isPrime(a)) {
		cout << "True" << endl;
	}
	else {
		cout << "false" << endl;
	}
	return 0;

}