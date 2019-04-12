#include <iostream>
#include <fstream>
#include "Header.h"


using namespace std;

int main() {
	ifstream ficheiro;
	ficheiro.open("teste123.txt");
	if (ficheiro.fail()) {
		cerr << "Deu merda a abrir";
		exit(1);
	}
	else {
		ler_ficheiro(ficheiro);
	}
	return 0;
}