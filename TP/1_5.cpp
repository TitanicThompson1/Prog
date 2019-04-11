#include <iostream>

using namespace std;

int main()
{
	int t_h1,t_m1,t_s1,t_h2,t_m2,t_s2;
	int tdf, thf, tmf, tsf;
	int soma_s;

	cout << "Tempo 1 (horas minutos segundos) ? ";
	cin >> t_h1 >> t_m1 >> t_s1;
	cout << "Tempo 2 (horas minutos segundos) ? ";
	cin >> t_h2 >> t_m2 >> t_s2;
	
	
	soma_s = (t_h1 + t_h2) * 60 * 60 + (t_m1 + t_m2) * 60 + t_s1 + t_s2;
	tsf = soma_s % 60;
	soma_s= soma_s
	tmf
}