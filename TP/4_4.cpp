#include <iostream>
#include <string>
#include <vector>

using namespace std;

string normalizeName(string name) {
	bool remove_spaces = true;
	string result, the_result="";
	

	for (int i = 0; i < name.length(); i++) {
		if (remove_spaces && name[i] == ' ') {
			continue;
		}
		else if (int(name[i]) <= 122 && int(name[i]) >= 97) {
			//cout << name[i];
			remove_spaces = false;
			result += char(int(name[i]) - 32);

		}else if (name[i] == ' ') {
			
			result += name[i];
			remove_spaces = true;

		}
		else {
			result += name[i];
		}

		
	}
	
	
	
	//split string by space

	if (result[result.length() - 1] != ' ') {
		result += ' ';
	}
	int ini_i = 0, j=0;

	vector<string> v1;

	for (int i = 0; i < result.length(); i++) {
		
		if (result[i] == ' ') {
			//cout << result.substr(ini_i, i - ini_i) << endl;
			v1.push_back(result.substr(ini_i, i - ini_i));
			ini_i = i+1;
			
		}

	}
	result = "";
	for (int i = 0; i < v1.size(); i++) {
		if (v1[i] == "DE" || v1[i] == "DA" || v1[i] == "DO" || v1[i] == "DAS" || v1[i] == "DOS" || v1[i] == "E") {
			continue;
		}
		else {
			result += v1[i] + ' ';
		}
	}

	if (result[result.length() - 1] == ' ') {
		result = result.substr(0, result.length() - 1);
	}
	
	return result;
}

int main() {
	string ola;
	int comp = 0;
	ola = "     Manuel  das olivias do  e da  das  Antonio     Rodrigo de Francos  ";
	
	cout << normalizeName(ola);
	
	return 0;

}