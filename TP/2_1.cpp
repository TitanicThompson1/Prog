#include <iostream>

using namespace std;

int main()
{
	float a, b, c, d, e, f, x, y;
	float dem, numix,numiy;

	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;
	cout << "d = ";
	cin >> d;
	cout << "e = ";
	cin >> e;
	cout << "f = ";
	cin >> f;
	numix = c * e - b * f;
	dem = a*e - b * d;
	numiy = a * f - c * d;

	if ((numix == 0 || numiy == 0) && dem == 0)
		cout << "Sistema indeterminado";
	else if (dem == 0)
		cout << "Sistema impossivel";
	else {
		x = (float)(c*e - b * f) / (a*e - b * d);
		y = (float)(a*f - c * d) / (a*e - b * d);

		cout << "x = " << x << endl << "y = " << y;
	}

	
	return 0;
}