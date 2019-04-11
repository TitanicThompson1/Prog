#include <iostream>
#include <vector>
#include <string>
using namespace std;

void bubblesort(vector<string> &v) {
	string temp;
	for (int j = 0; j < v.size(); j++) {
		for (int i = 0; i < v.size() - j - 1;i++) {
			if (v[i] > v[i + 1]) {
				temp = v[i];
				v[i] = v[i + 1];
				v[i + 1] = temp;
			}
		}
	}

}

int main() {

	vector<string> v = { "Ricardo", "Erica", "Luis","Ze","Adriana" };
	bubblesort(v);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	return 0;

}