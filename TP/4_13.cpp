#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>

using namespace std;

void showTime(int a[]) {
	cout << sizeof(a);
}
int main() {
	string name;
	unsigned int age;
	cout << "Name and age  ";
	cin >> name >> age;
	cout << name << ' - ' << age << endl;

	return 0;
	
}