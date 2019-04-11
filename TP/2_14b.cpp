#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	float delta, rq = 1, rqn, dif, n, umnum;
	int nMaxIter, i = 1, casdec=0;

	cout << "n delta nMaxIter ?  ";
	cin >> n >> delta >> nMaxIter;
	dif = n;
	umnum = delta;

	while (umnum < 0.9999) {
		
		umnum = umnum * 10;
		casdec++;

	}

	while (i<nMaxIter || dif>delta) {

		rqn = (float)((float)rq + n / rq) / 2;
		dif = n - pow(rqn, 2);
		i++;
		rq = rqn;

	}
	cout << fixed << setprecision(casdec) << rqn;
	return 0;
}