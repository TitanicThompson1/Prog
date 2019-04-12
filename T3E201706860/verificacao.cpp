#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
/*
@Determina quantos digitos tem o nif
nif: numero de identificação fiscal
RETURN: numero de digitos do nif
*/
int verifica_NIF(int nif) {
	int digitos = 0;
	while (nif != 0) {

		nif = nif / 10;
		digitos++;
	}
	return digitos;
}


