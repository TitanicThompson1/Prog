#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "gerir_pacotes.h"
#include "ficheiros.h"


using namespace std;

	/*
	@Adiciona um pacote num dado ficheiro
	nome_ficheiro: nome do ficheiro;
	RETURN: void
	*/
void criar_pacote(const string nome_ficheiro) {

	ifstream infile(nome_ficheiro);
	bool ficheiro_vazio = false;

	string string_id;
	getline(infile, string_id);

	if (string_id=="") {															//verifica se o ficheiro está vazio
		string_id = "0";															//se estiver, id=0;
		ficheiro_vazio = true;
	}

	int id = stoi(string_id);														//incrementa um valor ao id;
	id++;										

	infile.close();

	if (!ficheiro_vazio) {
		substitui_linha_num_ficheiro(string_id, to_string(id), "packs.txt");		//atualiza numero de pacotes existentes em packs.txt

	}
	else {
		adiciona_a_ficheiro("1", "packs.txt");
	}
	
	ofstream outfile;
	outfile.open(nome_ficheiro, ios::app);
	

	vector<string> local; 
	string temp;
	string decisao;

	cin.ignore();
	cout << "Introduza o principal local turistico de destino:  "; getline(cin,temp);					//o utilizador introduz os dados

	local.push_back(temp);

	cout << "Existem mais destinos a visitar? (S/N)  "; cin >> decisao;

	while (decisao != "S" && decisao != "N") {

		cerr << "Comando errado. Por favor introduza N (Nao) ou S (Sim):  "; cin >> decisao;
	}

	while (decisao == "S") {

		cin.ignore();
		cout << "Introduza outro local turistico de destino:  "; getline(cin,temp);
		local.push_back(temp);
		cout << "Deseja continuar? (S/N)  "; cin >> decisao;
		while (decisao != "S" && decisao != "N") {

			cerr << "Comando errado. Por favor introduza N (Nao) ou S (Sim):  "; cin >> decisao;
		}
	}

	int ano_ini, mes_ini, dia_ini;
	int ano_fim, mes_fim, dia_fim;
	
	cout << "Introduza a data de inicio da viagem: (YYYY MM DD)  "; cin >> ano_ini >> mes_ini >> dia_ini;

	while (cin.fail()) {																						//prevenção de erro
		cin.clear();
		cin.ignore(1000, '\n');
		cerr << "Erro. Intoduza uma data valida: (YYYY MM DD)  "; cin >> ano_ini >> mes_ini >> dia_ini;
	}																						

	cout << "Introduza a data do fim da viagem: (YYYY MM DD)  "; cin >> ano_fim >> mes_fim >> dia_fim;

	while (cin.fail()) {																							//prevenção de erro
		cin.clear();
		cin.ignore(1000, '\n');
		cerr << "Erro. Intoduza uma data valida: (YYYY MM DD)  "; cin >> ano_fim >> mes_fim >> dia_fim;
	}
	
	int preco;
	cout << "Introduza o preco por pessoa:  "; cin >> preco;

	while (cin.fail()) {																							//prevenção de erro
		cin.clear();
		cin.ignore(1000, '\n');
		cerr << "Erro. Intoduza um preco valido:  "; cin >> preco;

	}

	int lug_criados;
	cout << "Introduza os lugares disponiveis:  "; cin >> lug_criados;

	while (cin.fail()) {																		//prevenção de erro
		cin.clear();
		cin.ignore(1000, '\n');
		cerr << "Erro. Intoduza um numero valido:  "; cin >> lug_criados;

	}
	int lug_vend = 0;

	if (!ficheiro_vazio) {
		outfile << "::::::::::" << endl;
	}

	outfile << to_string(id) << endl;																//formata os locais turisticos
	outfile << local[0];	

	if (local.size() > 1) {
		
		outfile << " - ";
		for (int i = 1; i < local.size(); i++) {

			outfile << local[i];

			if (i != local.size() - 1) {

				outfile << ", ";
			}
		}
	}


	outfile << endl;																				//formata a data de inicio e de fim de viagem
	outfile << to_string(ano_ini) << "/";

	if (mes_ini < 10) {
		outfile << "0";
	}

	outfile << to_string(mes_ini) << "/"; 

	if (dia_ini < 10) {
		outfile << "0";
	}

	outfile <<to_string(dia_ini) << endl;

	outfile << to_string(ano_fim) << "/";

	if (mes_fim < 10) {
		outfile << "0";
	}

	outfile << to_string(mes_fim) << "/";

	if (dia_fim < 10) {
		outfile << "0";
	}


	outfile << to_string(dia_fim) << endl;

	outfile << to_string(preco) << endl;

	outfile << to_string(lug_criados) << endl;

	outfile << "0" << endl;
}

	/*
	@Elimina um pacote num dado ficheiro
	nome_ficheiro: nome do ficheiro;
	RETURN: void
	*/
void eliminar_pacote(string nome_ficheiro) {
	
	int id, index;
	int pac_max;
	cout << "Qual o identificador do pacote a eliminar?  "; cin >> id;
	
	pac_max = stoi(le_linha(nome_ficheiro, 0));

	while (id < 0 || id > pac_max) {																	//Guarante que pacote existe MELHORAR!!

		cerr << "Erro. Pacote nao existente. Introduza pacote valido:  "; cin >> id;
	}
	index = 1 + (id - 1) * 8;																			//calcula o indice da linha a substituir

	elimina_linhas_do_ficheiro(index, index + 7, nome_ficheiro);										//elimina o pacote
	string id_inicial = le_linha(nome_ficheiro, 0);
	string id_renomear;
	int id_renomar_int;

	for (int i = id; i < stoi(id_inicial); i++) {		
																										//renomeia os id dos pacotes posteriores ao que se eliminou
		index = 1 + (i-1) * 8;
		id_renomear = le_linha(nome_ficheiro, index);
		id_renomar_int = stoi(id_renomear);
		if (id_renomar_int < 0) {

			substitui_index_num_ficheiro(index, to_string(id_renomar_int + 1), nome_ficheiro);
		}else {

			substitui_index_num_ficheiro(index, to_string(id_renomar_int - 1), nome_ficheiro);
		}
	}


	string id_final = to_string(stoi(id_inicial) - 1);
	substitui_index_num_ficheiro(0, id_final, nome_ficheiro);
}

	/*
	@Altera um campo de um pacote num dado ficheiro
	nome_ficheiro: nome do ficheiro;
	RETURN: void
	*/
void alterar_pacote(string nome_ficheiro) {

	int campo_a_alterar, index;
	int id;
	
	cout << "Introduza o numero identificador do pacote:  "; cin >> id;

	while ( id > stoi(le_linha("packs.txt",0)) || cin.fail() || id<1) {									//verifica se id é valido e se existe
		cin.clear();
		cin.ignore(1000, '\n');
		cerr << "Erro. Pacote nao existente. Introduza um numero valido: "; cin >> id;					
		
	}

	cout << "Campo a alterar:  "
		<< endl << "0 - Principal local turistico de destino "
		<< endl << "1 - Data de inicio da viagem "
		<< endl << "2 - Data de fim da viagem "
		<< endl << "3 - Preco por pessoa "
		<< endl << "4 - Numero de pacotes disponiveis;" << endl;
	cin >> campo_a_alterar;

	while (campo_a_alterar < 0 || campo_a_alterar > 4) {														//verifica se o campo_a_alterar é valido
		cerr << "Campo invalido. Porfavor escolha um campo entre 0 e 4"; cin >> campo_a_alterar;
	}

	index = 1 + (id - 1) * 8 + (campo_a_alterar + 1);														//calcula o indice da linha a substituir

	string valor, temp, decisao, valor_f;
	vector<string> local;
	int ano, mes, dia, valor_int;

	switch (campo_a_alterar)																		//Se o campo a alterar for
																									//o principal local turistico de destino
	{																								//é necessario formatar de acordo
	case 0:
		cin.ignore();
		cout << "Introduza o principal local turistico de destino:  "; getline(cin, temp);

		local.push_back(temp);

		cout << "Existem mais destinos a visitar? (S/N)  "; cin >> decisao;

		while (decisao != "S" && decisao != "N") {

			cerr << "Comando errado. Por favor introduza N (Nao) ou S (Sim):  "; cin >> decisao;
		}

		while (decisao == "S") {
			cin.ignore();
			cout << "Introduza outro local turistico de destino:  "; getline(cin, temp);
			local.push_back(temp);
			cout << "Deseja continuar? (S/N)  "; cin >> decisao;
			while (decisao != "S" && decisao != "N") {

				cerr << "Comando errado. Por favor introduza N (Nao) ou S (Sim):  "; cin >> decisao;
			}

		}
		
		valor_f = local[0];

		if (local.size() > 1) {

			valor_f+= " - ";
			for (int i = 1; i < local.size(); i++) {

				valor_f+= local[i];

				if (i != local.size() - 1) {

					valor_f+= ", ";
				}
			}
		}

		//valor já está formatado

		substitui_index_num_ficheiro(index, valor_f, "packs.txt");
		break;
	case 1:																								//Necessario formatar as datas 
			
		cout << "Introduza a data de inicio da viagem: (YYYY MM DD)  "; cin >> ano >> mes >> dia;

		while (cin.fail()) {																			//prevenção de erro
			cin.clear();
			cin.ignore(1000, '\n');
			cerr << "Erro. Intoduza uma data valida: (YYYY MM DD)  "; cin >> ano >> mes >> dia;
		}

		valor_f = to_string(ano) + "/";

		if (mes < 10) {
			valor_f += "0";
		}

		valor_f+=to_string(mes) + "/";

		if (dia < 10) {
			valor_f += "0";
		}

		valor_f += to_string(dia);

		substitui_index_num_ficheiro(index, valor_f, "packs.txt");
		break;
	case 2:

		cout << "Introduza a data do fim da viagem: (YYYY MM DD)  "; cin >> ano >> mes >> dia;

		while (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cerr << "Erro. Intoduza uma data valida: (YYYY MM DD)  "; cin >> ano >> mes>> dia;
		}

		valor_f = to_string(ano) +"/";

		if (mes < 10) {
			valor_f += "0";
		}

		valor_f += to_string(mes) + "/";

		if (dia < 10) {
			valor_f += "0";
		}

		valor_f += to_string(dia);

		substitui_index_num_ficheiro(index, valor_f, "packs.txt");
		break;

	case 3:

		cout << "Introduza o preco por pessoa:  "; cin >> valor_int;

		while (cin.fail()) {															//prevenção de erro
			cin.clear();
			cin.ignore(1000, '\n');
			cerr << "Erro. Intoduza um preco valido:  "; cin >> valor_int;

		}

		substitui_index_num_ficheiro(index, to_string(valor_int), "packs.txt");
		break;

	case 4:

		cout << "Introduza os lugares disponiveis:  "; cin >> valor_int;

		while (cin.fail()) {																//prevenção de erro
			cin.clear();
			cin.ignore(1000, '\n');
			cerr << "Erro. Intoduza um numero valido:  "; cin >> valor_int;

		}
		
		substitui_index_num_ficheiro(index, to_string(valor_int), "packs.txt");
		break;
	default:

		cerr << "If you are reading this message, you are a bloody hacker.";
		exit(1);
		break;
	}

}