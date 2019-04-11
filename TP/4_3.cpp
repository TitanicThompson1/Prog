#include <iostream>
#include <string>

using namespace std;

void decompose(string compound) {

	for (int i = 0; i < compound.length(); i++) {

		if (int(compound[i]) <= 90 && int(compound[i]) >= 65) {

			if (compound[i + 1] <= 122 && int(compound[i + 1]) >= 97) {
				cout << compound.substr(i, 2) << endl;
				i++;

			}
			else {
				cout << compound[i] << endl;
			}

		}
	}
}
