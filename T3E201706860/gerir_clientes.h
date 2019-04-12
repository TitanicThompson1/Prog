#pragma once
#include <iostream>
#include <fstream>
#include "gerir_clientes.h"
#include "ficheiros.h"

using namespace std;

/*
	@Adiciona um cliente num dado ficheiro
	fich: nome do ficheiro;
	RETURN: void
	*/
void adiciona_cliente(const string fich);

/*
	@Elimina um cliente num dado ficheiro
	fich: nome do ficheiro;
	RETURN: void
	*/
void eliminar_cliente(const string fich);

/*
	@Altera um campo de um cliente num dado ficheiro
	fich: nome do ficheiro;
	RETURN: void
	*/
void alterar_cliente(string fich);