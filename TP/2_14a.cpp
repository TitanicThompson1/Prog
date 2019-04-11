#include <iostream>

using namespace std;

int main() {

	float delta, rq = 1, rqn, dif, n;
	int nMaxIter, i=1;

	cout << "n delta nMaxIter ?  ";
	cin >> n >> delta >> nMaxIter;
	dif = n;

	while (i<nMaxIter || dif>delta) {
		
		rqn = (float)((float)rq + n / rq) / 2;
		dif = n - pow(rqn, 2);
		i++;
		rq = rqn;

	}
	cout << rqn;
	return 0;
}