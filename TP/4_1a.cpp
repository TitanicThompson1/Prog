#include <iostream>
#include <cstring>

using namespace std;

bool isHydroxide( char compound[]) {

	bool result;
	int len;
	len = strlen(compound);
	if (compound[len - 1] == 'H' && compound[len - 2] == 'O') {
		return true;
	}
	return false;
}

int main() {
	char teste[10] = "MgOH";
	cout << isHydroxide(teste);
	return 0;
}