#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include "ficheiros.h"


using namespace std;
	/*
	@Lê ficheiro e mostra na consola
	Nome_ficheiro: nome do ficheiro a ler
	RETURN: void
	*/
void ler_ficheiro(string nome_ficheiro) {
	
	

	ifstream infile(nome_ficheiro);								//stream do ficheiro a ler
	string linha;												//linha que se está a ler no ficheiro
	bool inicio = true;											//identifica se a linha a ler é a primeira


	while (getline(infile, linha)) {
		if (inicio && linha == "") {			
																// Se o ficheiro estiver vazio
			cout << "Ficheiro vazio! :(" << endl;				// Avisa que ficheiro está vazio na consola
			return;
		}
		inicio = false;											//atualiza inicio
		cout << linha << endl;									// Escreve linha na consola
	}
}

	/*
	@Adiciona uma linha no fim do ficheiro
	linha: linha a substituir
	nome_ficheiro: nome do ficheiro a ler
	RETURN: void
	*/
void adiciona_a_ficheiro(string linha, const string nome_ficheiro) {
	

	ofstream ficheiro;												//ficheiro a adicionar a linha

	ficheiro.open(nome_ficheiro, ios::app);							//abre ficheiro em modo app
	
	ficheiro << linha << endl;										//escreve no ficheiro

	ficheiro.close();												//fecha o ficheiro
}

	/*
	@Procura uma string num dado ficheiro;
	valor_a_procurar: string a procurar no ficheiro;
	nome_ficheiro: nome do ficheiro a procurar;
	RETURN: true se existir em ficheiro, falso caso contrário.
	*/
bool procura_em_ficheiro(string valor_a_procurar, const string nome_ficheiro) {
	
	ifstream ficheiro(nome_ficheiro);						//ficheiro a procurar
	string temp;											//linha do ficheiro
	while (ficheiro >> temp) {

		if (temp == valor_a_procurar) {
			ficheiro.close();
			return true;
		}

	}
	ficheiro.close();
	return false;
}

	/*
	@Lê um ficheiro, procura a primeira ocurrencia de uma linha e substitui-a;
	@Se não a encontrar, manda uma mensagem de erro.
	velho: Valor que se quer substituir
	novo: Valor novo
	nome_ficheiro: nome do ficheiro;
	RETURN: void
	*/
void substitui_linha_num_ficheiro(string velho, string novo, string nome_ficheiro) {

	ifstream infile(nome_ficheiro);							//stream do ficheiro inicial
	ofstream outfile("temp_slnf.txt");						//stream do ficheiro final
	string linha;											//linha do ficheiro
	bool encontrou_linha = false;							//identifica se encontrou a linha pretendida

	while (getline(infile, linha)) {
		if (linha == velho && !encontrou_linha) {			

			outfile << novo << endl;
			encontrou_linha = true;
		}
		else {

			outfile << linha << endl;

		}
	}

	if (!encontrou_linha) {
		cerr << "Erro. Linha Não encontrada.";				
	}
	infile.close();
	outfile.close();
	remove(nome_ficheiro.c_str());
	rename("temp_slnf.txt", nome_ficheiro.c_str());

}

	/*
	@Procura uma dada linha num dado ficheiro;
	nome_ficheiro: nome do ficheiro;
	linha: string a encontrar;
	RETURN: Se encontrar, retorna o indice da linha. Caso contrario, retorna -1.
	*/
int encontra_linha(string nome_ficheiro, string linha) {

	string temp;										//linha do ficheiro
	ifstream infile(nome_ficheiro);						//stream do ficheiro a procurar
	int i = 0;
	while (getline(infile, temp)) {
		if (linha == temp) {
			infile.close();
			return i;
		}
		i++;

	}
	infile.close();
	return -1;
}

	/*
	@Copia todo o conteudo de um ficheiro para outro novo.
	nome_ficheiro: nome do ficheiro;
	nome_copia: nome do ficheiro para onde se quer fazer a copia;
	RETURN: void
	*/
void copia_ficheiro(string nome_ficheiro, string nome_copia) {

	ifstream infile(nome_ficheiro);						//stream do ficheiro originial
	ofstream outfile(nome_copia);						//stream do ficheiro cópia
	string temp;
	while (getline(infile, temp)) {
		outfile << temp << endl;
	}
	infile.close();
	outfile.close();

}

	/*
	@Lê um ficheiro, procura uma linha pelo index e substitui-a;
	@Se não a encontrar, manda uma mensagem de erro.
	index: indice da linha a substituir
	novo: string que se quer colocar
	nome_ficheiro: nome do ficheiro;
	RETURN: void
	*/
void substitui_index_num_ficheiro(int index, string novo,string nome_ficheiro) {

	ifstream infile(nome_ficheiro);							//ficheiro inicial
	ofstream outfile("temp_slnf.txt");						//ficheiro final
	string linha;											//linha do ficheiro
	bool encontrou_linha = false;							//identifica se encontrou a linha
	int i = 0;												//indice

	while (getline(infile, linha)) {
		if (i == index ) {

			outfile << novo << endl;
			encontrou_linha = true;
		}
		else {

			outfile << linha << endl;

		}
		i++;
	}

	if (!encontrou_linha) {
		cerr << "Erro. Linha Não encontrada.";
	}

	infile.close();																//fecha os ficheiros, apaga o antigo e dá o nome do antigo ao novo
	outfile.close();
	remove(nome_ficheiro.c_str());
	rename("temp_slnf.txt", nome_ficheiro.c_str());

}
	
/*
	@Elimina as linhas de indice entre i_inf e i_sup (inclusive);
	i_inf: indice da primeira linha a eliminar
	i_sup: indice da ultima linha a eliminar
	nome_ficheiro: nome do ficheiro;
	RETURN: void
	*/
void elimina_linhas_do_ficheiro(int i_inf, int i_sup, string nome_ficheiro) {

	ifstream infile(nome_ficheiro);							//stream do ficheiro de input
	ofstream outfile("temp_el.txt");						//stream do ficheiro de output (o final)
	int i = 0;												//indice da linha que está a ler
	string temp;											//linha que está a ler

	while (getline(infile, temp)) {

		if (i<i_inf || i>i_sup) {							//copia todas as linhas para outfile, exepto as que quer eliminar
			outfile << temp << endl;
		}
		i++;

	}
	infile.close();
	outfile.close();

	remove(nome_ficheiro.c_str());
	rename("temp_el.txt", nome_ficheiro.c_str());

}

	/*
	@Retorna a linha de indicie = index.
	nome_ficheiro: nome do ficheiro;
	index: indice da linha a ler;
	RETURN: uma string que contem a linha.
	*/
string le_linha(string nome_ficheiro, int index) {

	ifstream infile(nome_ficheiro);							//stream do ficheiro a ler
	int i = 0;												//indice da linha a ler
	string temp;											//linha que está a ler

	while (getline(infile, temp)) {
		if (i == index) {
			return temp;
		}
		i++;
	}
	infile.close();
}

/*
	@Retorna a linha de indicie = index.
	nome_ficheiro: nome do ficheiro;
	index: indice da linha a ler;
	RETURN: um char que contem a linha.
	*/

	/*
	@Lista a consola todos os clientes neste formato:
	@"Nome_de_cliente" - "NIF_de_cliente"
	nome_ficheiro: nome do ficheiro;
	RETURN: void
	*/
void lista_clientes_em_ficheiro(const string nome_ficheiro) {

	ifstream infile(nome_ficheiro);						//stream do ficheiro a ler
	string temp;										//linha que está a ler
	int index = 0;										//indice da linha que está a ler

	cin.ignore();

	while (getline(infile, temp)) {

		if (index % 6 == 0) {							//identifica a linha em que se encontra (entre 0 e 4)
														//uma vez que cada linha corresponde a um campo
			cout << temp << " - ";
		}
		else if (index % 6 == 1) {

			cout << temp << endl;
		}
		index++;
	}
	infile.close();
}

	/*
	@Elimina uma linha de conteudo linha_a_eli de um ficheiro.
	nome_ficheiro: nome do ficheiro;
	linha_a_eli: linha que se quer eliminar
	RETURN: void
	*/
void elimina_linha(string nome_ficheiro, string linha_a_eli) {

	ifstream infile(nome_ficheiro);							//stream do ficheiro de input
	ofstream outfile("temp_el.txt");						//stream do ficheiro de output
	string temp;											//linha que se está a ler
		
	while (getline(infile, temp)) {
		if (temp != linha_a_eli) {

			outfile << temp << endl;
		}
	}

	infile.close();
	outfile.close();

	remove(nome_ficheiro.c_str());
	rename("temp_el.txt", nome_ficheiro.c_str());
}

	/*
	@Lista a consola todos os pacotes neste formato:
	@"Numero_do_pacote" : "Localidades a visitar"
	nome_ficheiro: nome do ficheiro;
	RETURN: void
	*/
void lista_pacotes_em_ficheiro(const string nome_ficheiro) {

	ifstream infile(nome_ficheiro);							//stream do ficheiro a ler
	string temp;											//linha que está a ler
	int index = -1;											//indice da linha que está a ler (começa em -1 para ignorar a primeira linha)

	cin.ignore();

	while (getline(infile, temp)) {
		if (index % 8 == 0 && index != -1) {
			cout << temp << " : ";
		}
		else if (index % 8 == 1 && index != -1) {
			cout << temp << endl;
		}
		index++;
	}
	infile.close();
}

/*
@Lê os pacotes que um determinado cliente comprou e põe-os num vetor;
nome_ficheiro: nome do ficheiro a ler;
nif: NIF do cliente a ler;
RETURN: vetor com os pacotes que o cliente comprou.
*/
vector<string> le_pacotes_de_clientes(const string nome_ficheiro, string nif) {

	ifstream infile(nome_ficheiro);					//stream do ficheiro a ler
	string temp;									//linha que se está a ler
	vector<string> result;							// vetor contendo o resulado
	istringstream pacotes;							//stream dos pacotes comprados
	int i = 0, index_pac;							//i= indice da linha; index_pac= numero identificador do pacote


	while (getline(infile, temp)) {

		if (nif == temp) {
			index_pac = i + 3;
			break;
		}
		i++;
	}
	infile.close();
	pacotes.str(le_linha(nome_ficheiro, index_pac));

	while (pacotes >> temp) {
		if (temp != ";") {

			result.push_back(temp);
		}
	}
	
	return result;
}

/*
@deteta se ficheiro está vazio
nome_ficheiro: nome do ficheiro a ler
RETURN: true se o ficheiro estiver vazio, false caso contrario;
*/
bool ficheiro_vazio(const string nome_ficheiro) {
	
	ifstream infile(nome_ficheiro);
	string temp;
	getline(infile, temp);

	if (temp == "") {
		return true;
	}
	return false;
}