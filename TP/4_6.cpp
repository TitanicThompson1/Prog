#include <iostream>
#include <string>

using namespace std;

void readIntArray(int a[], int nElem) {
	for (int i = 0; i < nElem; i++) {
		cout << i << "  ";
		cin >> a[i];
	}
}
int searchValueInIntArray(const int a[], int nElem, int value) {
	
	for (int i = 0; i < nElem; i++) {
		if (a[i] == value) {
			return i;
		}
	}
	return -1;
}
int searchMultValuesInIntArray(const int a[], int nElem, int value, int index[]) {

	int result = 0, j = 0;
	for (int i = 0; i < nElem; i++) {

		if (a[i] == value) {
			index[j] = i;
			result++;
			j++;
		}
	}
	return result;
}
void showIntArray(int a[], int nElem) {
	for (int i = 0; i < nElem; i++) {
		cout << a[i];
	}
}
int main() {
	const int nElem = 5;
	int a[nElem];
	int index[nElem];

	readIntArray(a, nElem);
	cout << searchMultValuesInIntArray(a, nElem, 5, index) << endl;
	showIntArray(index, nElem);
	return 0;
}