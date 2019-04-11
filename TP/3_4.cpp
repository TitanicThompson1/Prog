#include <iostream>

using namespace std;

double round(double x, unsigned n) {

	float y;
	y = (float)floor(x * pow(10, n) + 0.5) / pow(10, n);
	return y;
}

int main() {
	float x,y;
	int n;

	cout << "x n ? ";
	cin >> x >> n;
	 
	y = round(x, n);
	cout << y << endl;

	return 0;


}