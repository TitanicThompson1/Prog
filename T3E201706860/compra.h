#pragma once
#include <iostream>

using namespace std;

/*
@Adiciona um certo pacote a um cliente;
nome_ficheiro_client: nome do ficheiro de clientes;
pacote_comprar: numero identificador do pacote a comprar;
nif_cliente_comprar: NIF do cliente que compra o pacote;
RETURN: 0, se não ocorrer erros; 1, se o cliente já tiver comprado o pacote; 2, se o pacote estiver esgotado;
*/
int compra_pacote(string nome_ficheiro_client, string pacote_comprar, string nif_cliente_comprar, string nome_ficheiro_pack);