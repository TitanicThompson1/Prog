#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

/*
	@Lê ficheiro e mostra na consola
	Nome_ficheiro: nome do ficheiro a ler
	RETURN: void
	*/
void ler_ficheiro(string nome_ficheiro);

/*
	@Adiciona uma linha no fim do ficheiro
	linha: linha a substituir
	nome_ficheiro: nome do ficheiro a ler
	RETURN: void
	*/
void adiciona_a_ficheiro(string linha, const string nome_ficheiro);

/*
	@Procura uma string num dado ficheiro;
	valor_a_procurar: string a procurar no ficheiro;
	nome_ficheiro: nome do ficheiro a procurar;
	RETURN: true se existir em ficheiro, falso caso contrário.
	*/
bool procura_em_ficheiro(string valor, const string nome_ficheiro);

/*
	@Lê um ficheiro, procura a primeira ocurrencia de uma linha e substitui-a;
	@Se não a encontrar, manda uma mensagem de erro.
	velho: Valor que se quer substituir
	novo: Valor novo
	nome_ficheiro: nome do ficheiro;
	RETURN: void
	*/
void substitui_linha_num_ficheiro(string velho, string novo, string nome_ficheiro);

/*
	@Procura uma dada linha num dado ficheiro;
	nome_ficheiro: nome do ficheiro;
	linha: string a encontrar;
	RETURN: Se encontrar, retorna o indice da linha. Caso contrario, retorna -1.
	*/
int encontra_linha(string nome_ficheiro, string linha);

void copia_ficheiro(string nome_ficheiro, string nome_copia);

/*
	@Lê um ficheiro, procura uma linha pelo index e substitui-a;
	@Se não a encontrar, manda uma mensagem de erro.
	index: indice da linha a substituir
	novo: string que se quer colocar
	nome_ficheiro: nome do ficheiro;
	RETURN: void
	*/
void substitui_index_num_ficheiro(int index, string novo, string nome_ficheiro);

/*
	@Elimina as linhas de indice entre i_inf e i_sup (inclusive);
	i_inf: indice da primeira linha a eliminar
	i_sup: indice da ultima linha a eliminar
	nome_ficheiro: nome do ficheiro;
	RETURN: void
	*/
void elimina_linhas_do_ficheiro(int i_inf, int i_sup, string nome_ficheiro);

/*
	@Retorna a linha de indicie = index.
	nome_ficheiro: nome do ficheiro;
	index: indice da linha a ler;
	RETURN: uma string que contem a linha.
	*/
string le_linha(string nome_ficheiro, int index);

/*
@Lista a consola todos os clientes neste formato:
@"Nome_de_cliente" - "NIF_de_cliente"
nome_ficheiro: nome do ficheiro;
RETURN: void
*/
void lista_clientes_em_ficheiro(const string nome_ficheiro);

/*
	@Elimina uma linha de conteudo linha_a_eli de um ficheiro.
	nome_ficheiro: nome do ficheiro;
	linha_a_eli: linha que se quer eliminar
	RETURN: void
	*/
void elimina_linha(string nome_ficheiro, string linha_a_eli);
/*
	@Lista a consola todos os pacotes neste formato:
	@"Numero_do_pacote" : "Localidades a visitar"
	nome_ficheiro: nome do ficheiro;
	RETURN: void
	*/
void lista_pacotes_em_ficheiro(const string nome_ficheiro);

/*
@Lê os pacotes que um determinado cliente comprou e põe-os num vetor;
nome_ficheiro: nome do ficheiro a ler;
nif: NIF do cliente a ler;
RETURN: vetor com os pacotes que o cliente comprou.
*/
vector<string> le_pacotes_de_clientes(const string nome_ficheiro, string nif);

/*
@deteta se ficheiro está vazio
nome_ficheiro: nome do ficheiro a ler
RETURN: true se o ficheiro estiver vazio, false caso contrario;
*/
bool ficheiro_vazio(const string nome_ficheiro);
