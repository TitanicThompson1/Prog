#include <iostream>
#include <string>

using namespace std;

bool isHydroxide(string compound) {

	bool result;
	int len=compound.length();
	
	if (compound[len - 1] == 'H' && compound[len - 2] == 'O') {
		return true;
	}
	return false;
}

int main() {
	string teste = "MgO";
	cout << isHydroxide(teste);
	return 0;
}