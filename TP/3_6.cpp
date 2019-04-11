#include <iostream>
#include <iomanip>

using namespace std;

bool bissexto(int ano) {
	if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0) {
		//cout << "true";
		return true;
	}
	else {
		//cout << "falso";
		return false;
	}
}

int dias_no_mes(int mes, int ano) {
	if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
		return 31;

	}
	else  if (mes == 4 || mes == 6 || mes == 9 || mes == 11 ) {
		return 30;

	}
	else if (bissexto(ano)) {
		return 29;

	}
	else {
		return 28;
	}
}

int qualquer_dia(int ano, int mes, int dia) {

	int s, a, c, ds;
	s = ano / 100;
	a = ano % 100;
	if ((mes == 1 && bissexto(ano)) || mes == 4 || mes == 7) {
		c = 6;

	}
	else if ((mes == 2 && bissexto(ano)) || mes == 2) {
		c = 2;
	}
	else if (mes == 2 || mes == 3 || mes == 11) {

		c = 3;
	}
	else if (mes == 5) {
		c = 1;
	}
	else if (mes == 6) {
		c = 4;

	}
	else if (mes == 9 || mes == 12) {
		c = 5;
	}
	else {
		c = 0;
	}

	ds = (5 * a / 4 + c + dia - 2 * (s % 4) + 7) % 7;

	return ds;
}

void mostra_mes(int ano, int mes) {

	switch (mes)
	{
	case 1:
		cout << "  " <<"Janeiro";
		break;
	case 2:
		cout << "  "  << "Fevereiro";
		break;
	case 3:
		cout << "  "  << "Marco";
		break;
	case 4:
		cout << "  "  << "Abril";
		break;
	case 5:
		cout << "  "  << "Maio";
		break;
	case 6:
		cout << "  "  << "Junho";
		break;
	case 7:
		cout << "  "  << "Julho";
		break;
	case 8:
		cout << "  "  << "Agosto";
		break;
	case 9:
		cout << "  "  << "Setembro";
		break;
	case 10:
		cout << "  "  << "Outubro";
		break;
	case 11:
		cout << "  "  << "Novembro";
		break;
	case 12:
		cout << "  "  << "Dezembro";
		break;
	default:
		break;
	}

	cout << setw(5) << "/" << ano << endl;
	for (int dia = 0; dia <= 6; dia++) {
		if (dia == 0) {
			cout << setw(5) << "Dom";
		}
		else if (dia == 1) {
			cout << setw(5) << "Seg";
		}
		else if (dia == 2) {
			cout << setw(5) << "Ter";

		}
		else if (dia == 3) {
			cout << setw(5) << "Qua";

		}
		else if (dia == 4) {
			cout << setw(5) << "Qui";

		}
		else if (dia == 5) {
			cout << setw(5) << "Sex";

		}
		else {
			cout << setw(5) << "Sab";

		}

		

	}
	cout << endl;
}

int main() {
	/*
	int dia = qualquer_dia(1999,02,04);
	if (dia==0){
		cout << "Sabado";
	}
	else if (dia == 1) {
		cout << "Domingo";
	}
	else if (dia == 2) {
		cout << "Segunda-feira";

	}
	else if (dia == 3) {
		cout << "Terca-feira";


	}
	else if (dia == 4) {
		cout << "Quarta-feira";

	}
	else if (dia == 5) {
		cout << "Quinta-feira";

	}
	else {
		cout << "Sexta-feira";
	}
	*/
	mostra_mes(2011, 01);
	return 0;
}