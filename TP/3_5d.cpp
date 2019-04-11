#include <iostream>

using namespace std;

void writeFracc(int numerator, int denominator) {
	cout << numerator << "/" << denominator << endl;

}

int mdc(int a, int b) {
	int temp;
	while (b != 0) {
		temp = a;
		a = b;
		b = temp % b;
	}
	return a;
}

void reduceFracc(int &numerator, int &denominator) {
	int a = numerator, b = denominator, temp, mdc;

	while (b != 0) {
		temp = a;
		a = b;
		b = temp % b;
	}
	mdc = a;
	numerator = numerator / a;
	denominator = denominator / a;
}


void operaFracc(int den1, int num1, int den2, int num2, int &den3, int &num3, char op) {

	switch (op)
	{
	case '+':
		if (den1 == den2) {
			den3 = den1;
			num3 = num1 + num2;
			reduceFracc(num3, den3);
			break;
		}
		else {
			
			den3 = den1 * den2 ;
			num3 = num1 * den2 + num2 * den1;
			
			reduceFracc(num3, den3);
			break;

		}
	case '-':
		if (den1 == den2) {
			den3 = den1;
			num3 = num1 - num2;
			break;
		}
		else {

			den3 = den1 * den2;
			num3 = num1 * den2 - num2 * den1;
			reduceFracc(den3, num3);
			break;

		}
	case '*':
		den3 = den2 * den1;
		num3 = num1 * num2;
		reduceFracc(den3, num3);
		break;

	case '/':
		num3 = num1 * den2;
		den3 = den1 * num2;
		reduceFracc(den3, num3);
		break;

	default:
		break;
	}

}

int main() {
	int num1 = 3, num2 = 5, den1 = 7, den2 = 9, a=0, b=0;
	char op = '*';

	operaFracc(den1, num1, den2, num2, a, b, op);
	writeFracc(b, a);
	return 0;
}