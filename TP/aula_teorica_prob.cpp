#include <iostream>

using namespace std;

int main()
{
	int num = 0;
	char ch;
	ch = cin.peek();
	while (ch != '\n')
	{
		cout << ch << " " ;
		if (ch >= '0' && ch <= '9')
			num = num * 10 + ch - '0';
		cin.ignore(1); 
		ch = cin.peek();

	}
	cout << endl;
	cout << "num =" << num << endl;

	return 0;

}