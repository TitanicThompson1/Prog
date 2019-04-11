#include <iostream>
#include <string>

using namespace std;

bool sequenceSearch(string s, int nc, char c) {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == c) {
			
			int j=i+1;
			while (s[j] == c) {
				
				j++;
			}
			if ((j - i) >= nc) {
				return true;
			}
		}

	}
	return false;

}

int main() {
	string test = "o o";
	cout << sequenceSearch(test, 1, 'R');
	return 0;

}