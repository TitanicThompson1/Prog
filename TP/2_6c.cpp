#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	int j;
	bool primo = true;

	for (int i = 2; i <= 10000; i++) {
		j = 2;
		primo = true;

		while (primo && j<= (int)sqrt(i)) {
			
			if (i%j == 0) {
				primo = false;

			}
			j++;
			
		}

		if (primo) {
			cout << i << " ";
		}

	}
	return 0;
}