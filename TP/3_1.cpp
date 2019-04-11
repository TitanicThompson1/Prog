#include <iostream>
#include <cmath>



using namespace std;

double distance(double x1, double y1, double x2, double y2) {
	double dis;
	dis = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	return dis;
}

double calcula_area(double x1, double y1, double x2, double y2, double x3, double y3) {
	double a, b, c, s, area;

	a = distance(x1, y1, x2, y2);
	b = distance(x2, y2, x3, y3);
	c = distance(x3, y3, x1, y1);

	s = (double)(a + b + c) / 2;

	area = sqrt(s*(s - a)*(s - b)*(s - c));

	return area;

}


int main()
{
	double xa, ya, xb, yb, xc, yc, area;


	cout << "Introduza as coordenasdas do 1 ponto:  ";
	cin >> xa >> ya;
	cout << "Introduza as coordenasdas do 2 ponto:  ";
	cin >> xb >> yb;
	cout << "Introduza as coordenasdas do 3 ponto:  ";
	cin >> xc >> yc;

	area = calcula_area(xa, ya, xb, yb, xc, yc);

	cout << "Area do triangulo:  " << area;
	return 0;
}