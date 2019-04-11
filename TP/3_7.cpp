#include <iostream>
#include <climits>

using namespace std;

long factorial_ite(int n) {
	int i = 1;
	long fact = 1;
	int maximo = 12;
	if (n > maximo) {
		cout << "Overflow"<< endl;
		return 0;
	}
	else {
		while (i <= n && fact < LONG_MAX / i) {
			fact = fact * i;
			i++;
		}
		return fact;
	}
	
}

long recursive_fact(int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	else if (n>12) {
		return 0;

	}
	else {
		return n * recursive_fact(n - 1);
	}
}

int main() {
	int n;
	cin >> n;
	cout << recursive_fact(n);
	return 0;
}