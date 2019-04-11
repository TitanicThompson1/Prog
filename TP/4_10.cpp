#include <iostream>
#include <vector>
#include <string>

using namespace std;

void apagaEssaMerda(vector<int> &v, int index) {
	int temp;
	for (int i = index; i < v.size() - 1; i++) {
		temp = v[i];
		v[i] = v[i + 1];
		v[i + 1] = temp;
	}
	v.resize(v.size() - 1);

}

void  removeDuplicates(vector<int>  &v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = i+1; j < v.size(); j++) {
			if (v[i] == v[j]) {
				apagaEssaMerda(v, j);
			}
		}
	}
}

int main() {
	vector<int> v = { 1,1,5,9,8,5,7,9 };
	removeDuplicates(v);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	return 0;
}