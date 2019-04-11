#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

double executeOperation(string op) {
	istringstream instr(op);
	char oper;
	double n1, n2;
	instr >> n1 >> oper >> n2;
	switch (oper)
	{
	case '+':
		return n1 + n2;
	case '-':
		return n1 - n2;
	case '/':
		return (double)n1 / (double)n2;
	case '*':
		return n1 * n2;
	default:
		break;
	}


}
int main() {
	string ola = "1 / 3";
	double resp = executeOperation(ola);
	cout << resp;
}