#include <iostream>
#include <string>

using namespace std;

/*
@Mostra na consola as opções que se pode realizar
não tem parametros de entrada
RETURN: 0 se o utilizador quiser voltar para o menu anterior, -1 se quiser sair do programa
*/
int opcao_a_realizar() {
	
	int dec;

	cout << endl << "[0] Voltar" << endl
			<< "[-1] Sair" << endl;
	cin >> dec;

	while ((dec != -1 && dec != 0) || cin.fail()) {

		cin.clear();
		cin.ignore(100, '\n');
		cerr << "Erro. Numero invalido. Por favor introduza um numero valido:  "; cin >> dec;
	}
	return dec;
}