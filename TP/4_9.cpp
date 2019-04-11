#include <iostream>
#include <vector>
#include <string>

using namespace std;

int  binarySearch(const  vector<string>  &v, string  value) {
	int bottom = 0, top = v.size() - 1, middle, result = -1;
	bool found = false;

	while (bottom <= top && found == false) {
		
		middle = (top+bottom)/ 2;
		if (v[middle] == value) {
			found = true;
			result = middle;
		}
		else if (v[middle] < value) {
			bottom = middle+1;

		}
		else {
			top = middle - 1;
		}
	}
	return result;
}
int main() {
	vector<string> v = { "Adriana","Luis","Miguel","Ricardo","Tiago","Ze" };
	int pos = binarySearch(v,"Miguel");
	cout << pos;
}