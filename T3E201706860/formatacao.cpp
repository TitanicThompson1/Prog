#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "ficheiros.h"

using namespace std;
/*
@Lê clientes de um ficheiro num modo formatado (na consola);
nome_ficheiro: nome do ficheiro a ler;
RETURN: void.
*/
void le_clientes_formatado(const string nome_ficheiro) {

	ifstream infile(nome_ficheiro);										//stream do ficheiro a ler
	string temp;														//linha que ese está a ler
	int i = 0;															//indice da linha

	cout << setw(20) << left << "Nome";
	cout << "|";
	cout << setw(10) << left << "NIF";
	cout << "|";
	cout << setw(10) << left << "Agregado";
	cout << "|";
	cout << setw(60) << left << "Morada";
	cout << "|";
	cout << setw(30) << left << "Pacotes comprados" << endl;

	cout << "----------------------------------------------------------------------------------------------------------------------------" << endl;



	while (getline(infile, temp)) {
		if (i % 6 == 0) {

			cout << setw(20) << left << temp;
			cout << "|";
		}
		else if (i % 6 == 1 || i % 6 == 2) {

			cout << setw(10) << left << temp;
			cout << "|";
		}
		else if (i % 6 == 3) {

			cout << setw(60) << left << temp;
			cout << "|";
		}
		else if (i % 6 == 4) {

			cout << setw(30) << left << temp << endl;
		}

		i++;
	}
	infile.close();
}

	/*
	@Lê um cliente de um ficheiro num modo formatado (na consola);
	nome_ficheiro: nome do ficheiro a ler;
	nif: NIF do cliente
	RETURN: void.
	*/
void le_cliente_formatado(const string nome_ficheiro, string nif) {

	ifstream infile(nome_ficheiro);
	string temp;
	int index, i = 0;
	index = encontra_linha(nome_ficheiro, nif) - 1;


	while (getline(infile, temp))
	{
		if (i == index) {

			cout << "Nome:  " << temp << endl;
		}
		else if (i == index + 1) {

			cout << "NIF:  " << temp << endl;
		}
		else if (i == index + 2) {

			cout << "Agregado familiar:  " << temp << endl;
		}
		else if (i == index + 3) {

			cout << "Morada:  " << temp << endl;
		}
		else if (i == index + 4) {

			cout << "Pacotes:  " << temp << endl;
		}
		i++;
	}
	infile.close();
}

/*
@Lê pacotes de um ficheiro num modo formatado (na consola);
nome_ficheiro: nome do ficheiro a ler;
RETURN: void.
*/
void le_pacotes_formatado(const string nome_ficheiro) {

	ifstream infile(nome_ficheiro);
	string temp;
	int i = -1;

	cout << setw(6) << left << "N. ID";
	cout << "|";
	cout << setw(50) << left << "Principais destinos turisticos";
	cout << "|";
	cout << setw(12) << left << "Data inicio";
	cout << "|";
	cout << setw(12) << left << "Data fim";
	cout << "|";
	cout << setw(15) << left << "Preco p/pessoa";
	cout << "|";
	cout << setw(35) << left << "Lugares inicialmente disponiveis";
	cout << "|";
	cout << setw(18) << left << "Lugares vendidos" << endl;

	cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;



	while (getline(infile, temp)) {
		if (i % 8 == 0 && i !=-1) {

			cout << setw(6) << left << temp;
			cout << "|";
		}
		else if (i % 8 == 1 && i != -1) {

			cout << setw(50) << left << temp;
			cout << "|";
		}
		else if ((i % 8 == 2 || i % 8 == 3) && i != -1) {

			cout << setw(12) << left << temp;
			cout << "|";

		}else if (i % 8 == 4 && i != -1) {

			cout << setw(15) << left << temp;
			cout << "|";
		}
		else if (i % 8 == 5 && i != -1) {

			cout << setw(35) << left << temp;
			cout << "|";
		}
		else if (i % 8 == 6 && i != -1) {

			cout << setw(18) << left << temp << endl;

		}

		i++;
	}
	infile.close();
}

	/*
	@Lê um pacote de um ficheiro num modo formatado (na consola);
	nome_ficheiro: nome do ficheiro a ler;
	pacote: numero identificador do pacote a ler
	RETURN: void.
	*/
void le_pacote_formatado(const string nome_ficheiro, string pacote) {

	ifstream infile(nome_ficheiro);
	string temp;

	int index, i = 0;
	
	index = 1 + (stoi(pacote) - 1) * 8;													//calcula o indice da linha a substituir

	while (getline(infile, temp))
	{
		if (i == index) {

			cout << "Pacote:  " << temp << endl;
		}
		else if (i == index + 1) {

			cout << "Principal destino turistico:  " << temp << endl;
		}
		else if (i == index + 2) {

			cout << "Data de inicio:  " << temp << endl;
		}
		else if (i == index + 3) {

			cout << "Data de fim:  " << temp << endl;
		}
		else if (i == index + 4) {

			cout << "Preco por pessoa:  " << temp << endl;
		}
		else if (i == index + 5) {

			cout << "Lugares inicialmente disponiveis:  " << temp << endl;
		}
		else if (i == index + 6) {

			cout << "Lugares vendidos:  " << temp << endl;
		}
		i++;
	}
	infile.close();
}
