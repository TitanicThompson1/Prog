#include <iostream>
#include <iomanip>
#include "gerir_clientes.h"
#include "ficheiros.h"
#include "gerir_pacotes.h"
#include "get_out.h"
#include "compra.h"
#include "verificacao.h"
#include "formatacao.h"

using namespace std;

int main() {
	int dec, pacote;
	int client_nif;
	string continua, id, clients_ficheiro, packs_ficheiro;
	int did_it, existe_pac;

Menu_Agencia:																		//Menu Agencia: aqui o utilizador poderá escolher
																					//se quer ir para o Menu dos Clientes ou dos Pacotes
	system("cls");
	clients_ficheiro = le_linha("agency.txt", 4);
	packs_ficheiro = le_linha("agency.txt", 5);
	
	ler_ficheiro("agency.txt");
	cout << endl << "Selecione o menu que quer aceder:"
		<< endl << "1- Clientes"
		<< endl << "2- Pacotes"
		<< endl << "3- Comprar pacote"
		<< endl
		<< endl << "[-1] Sair" << endl;

	cin >> dec;

	while (dec != 1 && dec != 2 && dec!=-1 && dec!=3) {															//Garante que dec é 1 ou 2 ou -1
		cin.clear();														
		cin.ignore(100, '\n');
		cerr << "Erro. Numero invalido. Por favor introduza um numero valido:  "; cin >> dec;
	}

	switch (dec)
	{
	case 1:
		
		goto Menu_Clientes;				
		break;
	case 2:
		
		goto Menu_Pacotes;
		break;
	case 3:

		goto Menu_Comprar;
	case -1:
		exit(0);

	default:
		cerr << "If you are reading this message, you are a bloody hacker.";
		exit(1);
		break;
	}

Menu_Clientes:

	system("cls");
	cout << "Selecione a opcao que deseja efectuar:" << endl											//Menu de Clientes
		<< "1- Ver clientes" << endl
		<< "2- Adicionar cliente" << endl
		<< "3- Eliminar cliente" << endl
		<< "4- Alterar cliente" << endl
		<< endl
		<< "[0] Voltar" << endl
		<< "[-1] Sair" << endl;


	cin >> dec;

	while (dec < -1 || dec > 4 || cin.fail()) {																			//Garante que dec está entre 0 e 4
		cin.clear();
		cin.ignore(100, '\n');
		cerr << "Erro. Numero invalido. Por favor introduza um numero valido:  "; cin >> dec;
	}
	
	switch (dec)
	{
	case 0:

		goto Menu_Agencia;
		break;
	case -1:

		exit(0);
		break;
	case 1:
		goto Menu_Cliente_Ver;

		
	case 2:

		system("cls");
		adiciona_cliente(clients_ficheiro);
		

		system("cls");

		cout << "Cliente adicionado! :D" << endl;
		dec = opcao_a_realizar();

		if (dec == 0) {

			goto Menu_Clientes;
		}
		else {			

			exit(0);
		}
		break;
	case 3:
		system("cls");

		if (ficheiro_vazio(clients_ficheiro)) {

			cout << "O ficheiro esta vazio!" << endl;
		}else {
			lista_clientes_em_ficheiro(clients_ficheiro);
			cout << endl;
			eliminar_cliente(clients_ficheiro);

			system("cls");



			cout << "Cliente eliminado! :D" << endl;
		}
		dec = opcao_a_realizar();

		if (dec == 0) {

			goto Menu_Clientes;
		}
		else {

			exit(0);
		}
		break;
	case 4:
		system("cls");
		if (ficheiro_vazio(clients_ficheiro)) {

			cout << "O ficheiro esta vazio!" << endl;
		}
		else {
			lista_clientes_em_ficheiro(clients_ficheiro);
			cout << endl;

			alterar_cliente(clients_ficheiro);

			system("cls");

			cout << "Cliente alterado! :D" << endl;
		}
		dec = opcao_a_realizar();

		if (dec == 0) {

			goto Menu_Clientes;
		}
		else {

			exit(0);
		}
		break;

	default:
		cerr << "If you are reading this message, you are a bloody hacker.";
		exit(1);
		break;
	}


Menu_Pacotes:																						//Menu dos pacotes

	system("cls");
	cout << "Selecione a opcao que deseja efectuar:" << endl
		<< "1- Ver pacotes" << endl
		<< "2- Criar pacote" << endl
		<< "3- Eliminar pacote" << endl
		<< "4- Alterar pacote" << endl
		<< endl
		<< "[0] Voltar" << endl
		<< "[-1] Sair" << endl;

	cin >> dec;

	while (dec < -1 || dec > 4 || cin.fail()) {
		cin.clear();
		cin.ignore(100, '\n');
		cerr << "Erro. Numero invalido. Por favor introduza um numero valido:  "; cin >> dec;
	}
	switch (dec)
	{
	case -1:										//sai do programa
		exit(0);
	case 0:
		goto Menu_Agencia;							
		break;
	case 1:
		goto Menu_Pacote_Ver;
		break;
	case 2:

		system("cls");										//cria pacote

		criar_pacote(packs_ficheiro);

		system("cls");

		cout << "Pacote criado! :D" << endl;

		dec = opcao_a_realizar();
		if (dec == 0) {

			goto Menu_Pacotes;
		}
		else {

			exit(0);
		}
	case 3:
			
		system("cls");												//elimina pacote
		if (ficheiro_vazio(packs_ficheiro)) {

			cout << "O ficheiro esta vazio!" << endl;
		}
		else {
			lista_pacotes_em_ficheiro(packs_ficheiro);
			cout << endl;
			eliminar_pacote(packs_ficheiro);

			system("cls");
			cout << "Pacote eliminado! :D" << endl;
		}
		dec = opcao_a_realizar();
		if (dec == 0) {

			goto Menu_Pacotes;
		}
		else {

			exit(0);
		}
	case 4:

		system("cls");											//altera campo do pacote
		if (ficheiro_vazio(packs_ficheiro)) {

			cout << "O ficheiro esta vazio!" << endl;
		}
		else {
			lista_pacotes_em_ficheiro(packs_ficheiro);
			cout << endl;
			alterar_pacote(packs_ficheiro);
			system("cls");

			cout << "Pacote alterado! :D" << endl;
		}
		dec = opcao_a_realizar();
		if (dec == 0) {

			goto Menu_Pacotes;
		}
		else {

			exit(0);
		}

	default:
		cerr << "If you are reading this message, you are a bloody hacker.";
		exit(1);
		break;
	}

Menu_Comprar:														//Menu comprar pacote

	system("cls");
	if (ficheiro_vazio(clients_ficheiro) || ficheiro_vazio(packs_ficheiro)) {

		cout << "O ficheiro dos clientes e/ou dos pacotes esta vazio!" << endl;
	}
	else {
		lista_clientes_em_ficheiro(clients_ficheiro);

			cout << endl << "Qual o nif do cliente que quer comprar um pacote?  "; cin >> client_nif;

			while (!procura_em_ficheiro(to_string(client_nif), "nif.txt"))
			{
				cerr << "Erro. NIF nao encontrado. Porfavor introduza um NIF valido:  "; cin >> client_nif;

			}

		system("cls");

		lista_pacotes_em_ficheiro(packs_ficheiro);

		cout << endl << "Qual o pacote que quer comprar? (os pacotes com um numero negativo estao esgotados)"; cin >> pacote;

		while (pacote > stoi(le_linha(packs_ficheiro, 0)) || cin.fail() || pacote < 1) {									//verifica se id é valido e se existe
			cin.clear();
			cin.ignore(1000, '\n');
			cerr << "Erro. Pacote nao existe. Introduza um pacote valido: "; cin >> pacote;

		}

		cout << "Tem a certeza que quer comprar este pacote? (S/N)  ";

		cin >> continua;
		while (continua != "N" && continua != "S") {
			cerr << "Erro. Introduza uma opcao valida: (S/N)  "; cin >> continua;
		}
		if (continua == "N") {
			goto Menu_Agencia;
		}
		else {
			did_it = compra_pacote(clients_ficheiro, to_string(pacote), to_string(client_nif), packs_ficheiro);
		}

		system("cls");
		if (did_it == 0) {
			cout << "Pacote comprado! :D" << endl;
		}
		else if (did_it == 1) {
			cerr << "O cliente ja comprou este pacote! :(" << endl;
		}
		else {
			cerr << "Pacote esgotado! :(" << endl;
		}
	}
	dec = opcao_a_realizar();
	if (dec == 0) {

		goto Menu_Agencia;				
	}
	else {

		exit(0);										//sai do programa
	}	
Menu_Cliente_Ver:														//Menu de visualização de clientes

	system("cls");

	cout << "Selecione a opcao que deseja efectuar:" << endl
		<< "1- Ver ficheiro" << endl
		<< "2- Ver informacao de todos os clientes " << endl
		<< "3- Ver informacao de um cliente" << endl
		<< endl
		<< "[0] Voltar" << endl
		<< "[-1] Sair" << endl;

	cin >> dec;

	while (dec < -1 || dec > 3 || cin.fail()) {																			//Garante que dec está entre 0 e 4
		cin.clear();
		cin.ignore(100, '\n');
		cerr << "Erro. Numero invalido. Por favor introduza um numero valido:  "; cin >> dec;
	}

	switch (dec)
	{
	case 1:														//le ficheiro
		system("cls");

		ler_ficheiro(clients_ficheiro);

		dec = opcao_a_realizar();
		if (dec == 0) {

			goto Menu_Cliente_Ver;
		}
		else {

			exit(0);
		}
		break;
	case 2:													//le todos os clientes de modo formatado
		
		system("cls");

		le_clientes_formatado(clients_ficheiro);

		dec = opcao_a_realizar();
		if (dec == 0) {

			goto Menu_Cliente_Ver;
		}
		else {

			exit(0);
		}
		break;
	case 3:													//le um cliente de modo formatado

		system("cls");
		
		if (ficheiro_vazio(clients_ficheiro)) {

			cout << "O ficheiro esta vazio!" << endl;
		}else {

			lista_clientes_em_ficheiro(clients_ficheiro);

			cout << endl << "Introduza o nif do cliente que pretende ver  "; cin >> client_nif;

			while (cin.fail() || verifica_NIF(client_nif) != 9 || !procura_em_ficheiro(to_string(client_nif), "nif.txt")) {			
																											
				cin.clear();																						
				cin.ignore(1000, '\n');																																											
				cerr << "NIF invalido. Por favor introduza um NIF:  "; cin >> client_nif;																														
			}
			system("cls");
			le_cliente_formatado(clients_ficheiro,to_string(client_nif));

		}
		dec = opcao_a_realizar();
		if (dec == 0) {

			goto Menu_Cliente_Ver;
		}
		else {

			exit(0);
		}
		break;
	case -1:
		exit(0);
	case 0:
		goto Menu_Clientes;
		break;
	default:
		break;
	}

Menu_Pacote_Ver:													//Menu de visualização de pacotes

	system("cls");

	cout << "Selecione a opcao que deseja efectuar:" << endl
		<< "1- Ver ficheiro" << endl
		<< "2- Ver informacao de todos os pacotes " << endl
		<< "3- Ver informacao de um pacote" << endl
		<< endl
		<< "[0] Voltar" << endl
		<< "[-1] Sair" << endl;
	cin >> dec;

	while (dec < -1 || dec > 3 || cin.fail()) {																			//Garante que dec está entre 0 e 4
		cin.clear();
		cin.ignore(100, '\n');
		cerr << "Erro. Numero invalido. Por favor introduza um numero valido:  "; cin >> dec;
	}

	switch (dec)
	{
	case 1:												//le ficheiro de pacotes

		system("cls");										

		ler_ficheiro(packs_ficheiro);

		dec = opcao_a_realizar();
		if (dec == 0) {

			goto Menu_Pacote_Ver;
		}
		else {

			exit(0);
		}
		break;

	case 2:													//le pacotes de um modo formatado

		system("cls");

		le_pacotes_formatado(packs_ficheiro);

		dec = opcao_a_realizar();
		if (dec == 0) {

			goto Menu_Pacote_Ver;
		}
		else {

			exit(0);
		}
		break;
	case 3:												//le um pacote especifico de um modo formatado

		system("cls");
		if (ficheiro_vazio(packs_ficheiro)) {

			cout << "O ficheiro esta vazio!" << endl;
		}else {

			lista_pacotes_em_ficheiro(packs_ficheiro);

			cout << endl << "Introduza o numero do pacote que pretende aceder:  "; cin >> id;

			existe_pac = stoi(le_linha(packs_ficheiro, 0));

			while (stoi(id) < 1 || stoi(id) > existe_pac) {																	//Guarante que pacote existe

				cerr << "Erro. Pacote nao existente. Introduza pacote valido:  "; cin >> id;
			
			}

			system("cls");

			le_pacote_formatado(packs_ficheiro, id);

		}
		dec = opcao_a_realizar();
		if (dec == 0) {

			goto Menu_Pacote_Ver;
		}
		else {

			exit(0);
		}
		break;
	case -1:
		exit(0);
	case 0:
		goto Menu_Pacotes;
		break;
	default:
		break;
	}
}