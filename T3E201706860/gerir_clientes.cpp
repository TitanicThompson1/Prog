#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "gerir_clientes.h"
#include "verificacao.h"
#include "ficheiros.h"


using namespace std;

	/*
	@Adiciona um cliente num dado ficheiro
	fich: nome do ficheiro;
	RETURN: void
	*/
void adiciona_cliente(const string fich) {
	
	string nome, morada, pacotes, rua, andar, codpos, loc, temp, temporaria;
	int nif, agregado, num;
	bool ficheiro_vazio = false;
	ifstream infile(fich);

	cin.ignore();
	getline(infile, temporaria);												//
	if ( temporaria== "") {														//deteta se o ficheiro está vazio.
		ficheiro_vazio = true;													//
	}

	infile.close();

	ofstream outfile;
	outfile.open(fich, ios::app);

	if (!ficheiro_vazio) {														//Se ficheiro não estiver vazio
		outfile << "::::::::::" << endl;										//adiciona ao ficheiro o elemento de separação de clientes
	}

	cout << "Nome:  "; getline(cin, nome);

	cout << "NIF:  "; cin >> nif;
	while (cin.fail() || verifica_NIF(nif)!=9 || procura_em_ficheiro(to_string(nif), "nif.txt")) {			//
																											// Como o NIF irá servir de "chave",
		cin.clear();																						// é necessário garantir que o utilizador
		cin.ignore(1000, '\n');																				// introduza um NIF valido
		if (procura_em_ficheiro(to_string(nif), "nif.txt")) {												// daí esta prevençao de erro
			cerr << "NIF ja existente. Por favor introduza um NIF:  "; cin >> nif;							//
		}																									//
		else {																								//
																											//
			cerr << "NIF invalido. Por favor introduza um NIF:  "; cin >> nif;								//
		}																									//
	}																										//
	
	string nif_string = to_string(nif);


	cout << "Numero de pessoas no agregado familiar:  "; cin >> agregado;									//prevenção de erro do agregado
	while(cin.fail()) {																						//
																											//
		cin.clear();																						//
		cin.ignore(1000, '\n');																				//
		cerr << "Numero invalido. Por favor introduza um numero:  "; cin >> agregado;						//
		
	}

	cout << "Rua:  ";
	cin.ignore();
	getline(cin, rua);

	cout << "Numero da porta:  ";	
	cin >> num;
	while (cin.fail()) {																					//prevenção de erro do numero da porta
		cin.clear();																						//
		cin.ignore(1000, '\n');																				//
		cerr << "Numero invalido. Por favor introduza um numero:  "; cin >> num;							//

	}
	
	cout << "Apartamento ( '-' se viver numa casa):  "  ; cin >> andar;
	
	cout << "Codigo-Postal:  "; cin >> codpos;
	

	cout << "Localidade:  ";
	cin.ignore();
	getline(cin,loc);
	

	outfile << nome << endl << nif << endl << agregado << endl;
	outfile << rua << " / " << num << " / " << andar << " / " << codpos << " / " << loc << endl;			//
	outfile << "-" << endl;

	adiciona_a_ficheiro(nif_string, "nif.txt");																//função definida em ficheiros.cpp

	// nif.txt é o ficheiro que contem os NIFs de todos os clientes.
	// criei este ficheiro para ser mais facil detetar
	//se o nif que se quer adicionar já está na base de dados ou nao

}

	/*
	@Elimina um cliente num dado ficheiro
	fich: nome do ficheiro;
	RETURN: void
	*/
void eliminar_cliente(const string fich) {

	string temp, nif;
	int inicio = -1, fim, linha = 0;
	//ofstream outfile("newC.txt");
	int result, nif_int;

	cout << "Introduza o NIF do cliente a eliminar:  "; cin >> nif_int;

	while (cin.fail() || verifica_NIF(nif_int) != 9 || !procura_em_ficheiro(to_string(nif_int),"nif.txt")) {												//Deteção de erro do NIF
																									//pela razão já dita em cima.
		cin.clear();																				//
		cin.ignore(1000, '\n');																		//
		cerr << "NIF invalido. Por favor introduza um NIF:  "; cin >> nif_int;						//
	}

	nif = to_string(nif_int);
	
	linha = encontra_linha(fich, nif);																//Funçao definida em ficheiros.cpp;
	if (linha == 1) {								// Se se quiser eliminar						//Calcula o indice da primeira (inicio)
													// o primeiro cliente;							//e da ultima (fim) a eliminar
		inicio = linha - 1;							// Necessario pois o primeiro								
	}												// cliente não tem o separador ::::::::::
	else {
		inicio = linha - 2;							
	}
	
	fim = inicio + 5;

	elimina_linhas_do_ficheiro(inicio, fim, "clients.txt");				//elimina as linhas pretendidas do ficheiro;

	elimina_linha("nif.txt", nif);										//funçao definida em ficheiros.cpp
}
	
	/*
	@Altera um campo de um cliente num dado ficheiro
	fich: nome do ficheiro;
	RETURN: void
	*/
void alterar_cliente(string fich) {

	int campo_a_alterar, index=0, index_a_mudar;
	string nif, valor, linha;
	string rua, andar, codpos, loc, morada;
	vector<string> pacotes;
	int num;

	cout << "Introduza o nif do cliente:  "; cin >> nif;
	
	while (!procura_em_ficheiro(nif, "nif.txt")) {																	//funçâo definida em ficheiro.cpp
		cin.clear();																								//Verifica se o NIF introduzido está 
		cin.ignore(1000, '\n');																						//associado a um cliente.
		cerr << "Erro: o cliente em questao nao existe. Por favor introduza um numero valido:  "; cin >> nif;
	}

	cout << "Campo a alterar:  "
		<< endl << "0 - Nome "
		<< endl << "1 - NIF "
		<< endl << "2 - Agregado "
		<< endl << "3 - Morada " << endl;
		

	cin >> campo_a_alterar;
	

	while (cin.fail() || campo_a_alterar < 0 || campo_a_alterar>3) {												//prevenção de erro do campo a alterar
																													//
		cin.clear();																								//
		cin.ignore(1000, '\n');																						//
		cerr << "Numero invalido. Introduza um numero entre 0 a 3:  ";												//
		cin >> campo_a_alterar;																						//
	}	
		

	if (campo_a_alterar == 3) {
		
		cout << "Rua:  ";																							//pede a morada
		cin.ignore();
		getline(cin, rua);

		cout << "Numero da porta:  ";
		cin >> num;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cerr << "Numero invalido. Por favor introduza um numero:  "; cin >> num;

		}

		cout << "Apartamento ( '-' se viver numa casa):  "; cin >> andar;

		cout << "Codigo-Postal:  "; cin >> codpos;

		

		cout << "Localidade:  ";
		cin.ignore();
		getline(cin, loc);	
		valor = rua + " / " + to_string(num) + " / " + andar + " / " + codpos + " / " + loc;							//formata a morada
		
	}
	else {
		cout << "Introduza o valor:  "; cin >> valor;
	}

	while (campo_a_alterar == 1 && (verifica_NIF(stoi(valor)) != 9 || procura_em_ficheiro(valor, "nif.txt"))) {			//Verificação de validade do NIF
																														//caso seja este o campo a alterar
		if (verifica_NIF(stoi(valor)) != 9) {

			cerr << "Erro. NIF nao valido. Introduza novamente:  "; cin >> valor;
		}
		else if (procura_em_ficheiro(valor, "nif.txt")) {

			cerr << "NIF ja existente. Por favor introduza outro NIF:  "; cin >> valor;
		}
	}

	index_a_mudar = encontra_linha(fich, nif) - 1 + campo_a_alterar;									//encontra o NIF no ficheiro dado
																										//formula que determina o indice da linha a alterar																		

	substitui_index_num_ficheiro(index_a_mudar, valor, fich);											//substitui a linha pretendida
	
	if (campo_a_alterar == 1) {																	//atualiza o NIF em nif.txt se esse foi o campo a alterar
		substitui_linha_num_ficheiro(nif, valor, "nif.txt");
	}
}