#include <iostream>
#include <vector>
#include "ficheiros.h"
using namespace std;

/*
@Adiciona um certo pacote a um cliente;
nome_ficheiro_client: nome do ficheiro de clientes;
pacote_comprar: numero identificador do pacote a comprar;
nif_cliente_comprar: NIF do cliente que compra o pacote;
RETURN: 0, se não ocorrer erros; 1, se o cliente já tiver comprado o pacote; 2, se o pacote estiver esgotado;
*/
int compra_pacote(string nome_ficheiro_client, string pacote_comprar, string nif_cliente_comprar, string nome_ficheiro_pack) {

	int index = encontra_linha(nome_ficheiro_client, nif_cliente_comprar) + 3;					//index= indice da linha dos pacotes comprados em clients.txt
	int index2 = (stoi(pacote_comprar) - 1) * 8 + 7;											//index2= indice da linha dos nº de pacotes vendidos			
	string pacotes = le_linha(nome_ficheiro_client, index);										//pacotes= lista dos pacotes já vendidos

	if (stoi(le_linha(nome_ficheiro_pack, index2 - 6)) < 0) {											//Identifica se o pacote está esgotado
		return 2;
	}
	
	if (pacotes == "-") {
																								//se não houver pacotes comprados, 
		substitui_index_num_ficheiro(index, pacote_comprar, nome_ficheiro_client);				//adiciona o pacote ao ficheiro dos clientes
	}
	else {
		vector<string> pacote = le_pacotes_de_clientes(nome_ficheiro_client, nif_cliente_comprar);			//verfica se o cliente nao
		for (int i = 0; i < pacote.size(); i++) {															//nao comprou o pacote anteriormente
				
			if (pacote.at(i) == pacote_comprar) {
				return 1;
			}
		}

		
	}
	
	int novo = stoi(le_linha(nome_ficheiro_pack, index2))+1;												//novo= novo valor dos lugares vendidos

	substitui_index_num_ficheiro(index2, to_string(novo),nome_ficheiro_pack);								//atualiza lugares vendidos

	if (le_linha(nome_ficheiro_pack, index2) == le_linha(nome_ficheiro_pack, index2 - 1)) {									//Se, ao adicionar o pacote, 
																												//o nº de pac. vendidos= nº pac. disponiveis,
		substitui_index_num_ficheiro(index2 - 6, "-" + le_linha(nome_ficheiro_pack, index2 - 6), nome_ficheiro_pack);			//atualiza o pacote para esgotado
	}

	if(pacotes != "-" ) {

		substitui_index_num_ficheiro(index, pacotes + " ; " + pacote_comprar, nome_ficheiro_client);				//atualiza os pacotes comprados no ficheiro clientes
	}
	return 0;
}