#include <iostream>
#include <vector>

using namespace std;

vector<int> readIntVector(int nElem) {
	vector<int> v1;
	int valor;
	for (int i = 0; i < nElem; i++) {
		cout << i << "  ";
		cin >> valor;
		v1.push_back(valor);
	}
	return v1;
}

int searchValueInVector(const vector<int> &v, int value) {

	for (size_t i = 0; i < v.size(); i++) {
		if (v[i] == value) {
			return i;
		}
	}
	return -1;
}
vector<int> searchMultValuesInIntVector(const vector<int> &v, int value) {

	vector<int> index;
	for (size_t i = 0; i < v.size(); i++) {

		if (v[i] == value) {
			index.push_back(i);
		}
	}
	return index;
}

void showIntVector(vector<int> a) {
	for (size_t i = 0; i < a.size(); i++) {
		cout << a[i] << endl;
	}
}
int main() {
	const int nElem = 3;
	vector<int> a,index;

	a = readIntVector(nElem);
	index = searchMultValuesInIntVector(a, 5);
	showIntVector(index);
	return 0;
}