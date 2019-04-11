#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float ro, m, r;
	cout << "Introduza a massa especifica do material (Kg/m3) ";
	cin >> ro;
	cout << "Introduza o raio  (m) ";
	cin >> r;
	m = ((float)4 / 3)*M_PI*ro*pow(r, 3);
	cout << "Massa da esfera (Kg) " << m;
	return 0;

}
