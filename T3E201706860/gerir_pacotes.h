#pragma once
#include <string>;

using namespace std;

/*
	@Adiciona um pacote num dado ficheiro
	nome_ficheiro: nome do ficheiro;
	RETURN: void
	*/
void criar_pacote(const string nome_ficheiro);

/*
	@Elimina um pacote num dado ficheiro
	nome_ficheiro: nome do ficheiro;
	RETURN: void
	*/
void eliminar_pacote(string nome_ficheiro);

/*
	@Altera um campo de um pacote num dado ficheiro
	nome_ficheiro: nome do ficheiro;
	RETURN: void
	*/
void alterar_pacote(string nome_ficheiro);