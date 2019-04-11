#include <iostream>

using namespace std;

int mdc(int m, int n) {
	if (m%n == 0) {
		return n;
	}
	else {
		return mdc(n, m%n);
	}
}

int main() {

	cout << mdc(100, 60);
}