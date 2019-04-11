#include <iostream>

using namespace std;

int main() {

	float num1, num2, result;
	char op;
	cout << "numero  operacao  numero  ";
	cin >> num1 >> op >> num2;

	switch (op)
	{
	case '*':
		result = num1 * num2;
		break;
	case '+':
		result = num1 + num2;
		break;
	case '-':
		result = num1 - num2;
		break;
	case '/':
		result = (float)num1 / num2;
		break;
	
	
	}
	cout << "Resultado --->  " << result;
	
}