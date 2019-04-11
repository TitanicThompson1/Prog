#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	int j, i=2, numprimos=0;
	bool primo = true;
	
	while (numprimos<100) {
		
		j = 2;
		primo = true;

		while (primo && j <= (int)sqrt(i)) {

			if (i%j == 0) {
				primo = false;

			}
			j++;

		}

		if (primo) {
			cout << i << " ";
			numprimos++;
		}
		i++;
	}
	return 0;
}