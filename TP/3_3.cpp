#include <iostream>

using namespace std;

double raiz_quadrada(float n, float delta, int nMaxIter) {
	float dif, rq = 1, rqn;
	int i=1;

	dif = n;
	while (i<nMaxIter && delta<dif) {

		rqn = (float)((float)rq + n / rq) / 2;
		dif = sqrt(pow(n - pow(rqn, 2),2));
		i++;
		rq = rqn;

	}
	return rqn;
}

int main() {

	float delta, rq = 1, rqn, dif, n;
	int nMaxIter, i = 1;

	cout << "n delta nMaxIter ?  ";
	cin >> n >> delta >> nMaxIter;
	

	rqn = raiz_quadrada(n, delta, nMaxIter);
	cout << rqn << endl;
	return 0;
}