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
		for (int j = i + 1; j < v.size(); j++) {
			if (v[i] == v[j]) {
				apagaEssaMerda(v, j);
			}
		}
	}
}

void bubblesort(vector<int> &v) {
	int temp;
	for (int j = 0; j < v.size(); j++) {
		for (int i = 0; i < v.size() - j - 1; i++) {
			if (v[i] > v[i + 1]) {
				temp = v[i];
				v[i] = v[i + 1];
				v[i + 1] = temp;
			}
		}
	}

}

vector<int> uniao (const vector<int> &v1, const vector<int> &v2) {
	vector<int> result;
	for (int i = 0; i < v1.size(); i++) {
		result.push_back(v1[i]);
	}

	for (int i = 0; i < v2.size(); i++) {
		result.push_back(v2[i]);
	}
	removeDuplicates(result);
	bubblesort(result);
	return result;
}
vector<int> intersection(const vector<int> &v1, const vector<int> &v2) {
	vector<int> result;

	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v2.size(); j++) {
			if (v1[i] == v2[j]) {

				result.push_back(v1[i]);

			}
		}
	}
	return result;
}
int main() {
	vector<int> v1 = { 1,2,3,5,6,8 };
	vector<int> v2 = { 1,4,3,5,6,9 };
	vector<int> result;
	result = intersection(v1, v2);
	for (int i = 0; i < result.size(); i++) {
	
		cout << result[i] << endl;
	}
}