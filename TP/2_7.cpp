#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>



using namespace std;

int main() {

	cout << fixed << setprecision(6) << setw(5) << "ang ";
	cout << setw(10) << "sen";
	cout << setw(10) << "cos";
	cout << setw(10) << "tan" << endl;

	int ang;
	float rad;

	float seno, cosseno, tang;
	for (ang = 0; ang <= 90; ang = ang + 15) {
		rad = ((float)ang / 180)*M_PI;
		cout << setw(5) << ang;
		cout << setw(10) << sin(rad);
		cout << setw(10) << cos(rad);
		if (ang == 90) {
			cout << setw(10) << "infinito" << endl;

		}
		else {
			cout << setw(10) << tan(rad) << endl;

		}

	}
	
	return 0;
}