#include <iostream>

using namespace std;

int main()
{
	int a, b, c;
	int max, min, middle;
	cout << "a b c ?";
	cin >> a >> b >> c;

	if (a > b && a > c) {
		max = a;
		if (b > c) {
			min = c;
			middle = b;
		}
		else {
			min = b;
			middle = c;
		}
	}
	else if (b > c) {
		max = b;
		if (a > c) {
			middle = a;
			min = c;
		}
		else {
			middle = c;
			min = a;
		}

	}
	else {
		max = c;
		if (b > a) {
			middle = b;
			min = a;
		}
		else {
			middle = a;
			min = b;

		}
	}

	
	
	


	cout << "maximo = " << max << "\nminimo = " << min << endl;
	cout << max << "  " << middle << "  " << min;
	return 0;

}

