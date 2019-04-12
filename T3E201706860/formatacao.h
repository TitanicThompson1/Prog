#pragma once
#include <iostream>

using namespace std;

/*
@L� clientes de um ficheiro num modo formatado (na consola);
nome_ficheiro: nome do ficheiro a ler;
RETURN: void.
*/
void le_clientes_formatado(const string nome_ficheiro);

/*
	@L� um cliente de um ficheiro num modo formatado (na consola);
	nome_ficheiro: nome do ficheiro a ler;
	nif: NIF do cliente
	RETURN: void.
	*/
void le_cliente_formatado(const string nome_ficheiro, string nif);

/*
@L� pacotes de um ficheiro num modo formatado (na consola);
nome_ficheiro: nome do ficheiro a ler;
RETURN: void.
*/
void le_pacotes_formatado(const string nome_ficheiro);

/*
@L� um pacote de um ficheiro num modo formatado (na consola);
nome_ficheiro: nome do ficheiro a ler;
pacote: numero identificador do pacote a ler
RETURN: void.
*/
void le_pacote_formatado(const string nome_ficheiro, string pacote);