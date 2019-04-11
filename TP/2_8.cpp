#include <iostream>

using namespace std;

int main() {
	int n;
	float q, j, result;
	cout << "n q j ?";
	cin >> n >> q >> j;
	result = q;
	for (int i = 1; i <= n; i++) {
		result = result + result * ((float)j / 100);
	}
	cout << result;
	return 0;
}