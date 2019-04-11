
#include <iostream>
#include <cmath>


using namespace std;

int main()
{
	float xa, ya, xb, yb, xc, yc;
	float ab, bc, ca, s;
	float area;
	
	cout << "Introduza as coordenasdas do 1º ponto:  ";
	cin >> xa >> ya;
	cout << "Introduza as coordenasdas do 2º ponto:  ";
	cin >> xb >> yb;
	cout << "Introduza as coordenasdas do 3º ponto:  ";
	cin >> xc >> yc;

	ab = sqrt(pow(xb - xa, 2) + pow(yb - ya, 2));
	bc = sqrt(pow(xc - xb, 2) + pow(yc - yb, 2));
	ca = sqrt(pow(xa - xc, 2) + pow(ya - yc, 2));

	s = (float) (ab + bc + ca) / 2;

	area = sqrt(s*(s - ab)*(s - bc)*(s - ca));

	cout << "Area do triangulo:  " << area;
	return 0;
}