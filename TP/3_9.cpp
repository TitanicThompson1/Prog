#include <iostream>

using namespace std;

double f(double x) {
	return sqrt(4-pow(x,2));
}

double integrateTR(double f(double), double a, double b, int n) {
	double area = 0, h = (double)(b - a) / n;
	for (int i = 1; i <= n; i++) {
		area = area + ((double)h / 2)*(f(a + (i - 1)*h) + f(a + i * h));

	}
	return area;
}
int main() {
	int a, b, n;
	cin >> a >> b >> n;
	cout << integrateTR(f, a, b, n);
	return 0;
}