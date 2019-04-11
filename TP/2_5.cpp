#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	float a, b, c, bin;
	float x1, x2,xr,xi;
	
	cout << "a b c ?";
	cin >> a >> b >> c;

	bin = pow(b, 2) - 4 * a*c;
	if (bin > 0) {
		x1 = (-b - sqrt(bin)) / (2 * a);
		x2 = (-b + sqrt(bin)) / (2 * a);
		
		cout << fixed << setprecision(3) << "x1=   " << x1 << endl << "x2=   " << x2 << endl;
	}
	else if (bin == 0) {
		x1 = -b / (2*a);
		x2 = x1;

		cout << fixed << setprecision(3) << "x1=   " << x1 << endl << "x2=   " << x2 << endl;

	}
	else {
		xr = (float)(-b) / (2 * a);
		xi = (float)sqrt(-bin) / (2 * a);

		cout << fixed << setprecision(3) << "x1=   " << xr << " + " << xi << "i" << endl << "x2=   " << xr << " + " << -xi << "i" << endl;

	}
	return 0;
}