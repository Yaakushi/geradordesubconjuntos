#include <iostream>
#include <cstdlib>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void percorreArvore(int *conjunto, int sizorig, int sizsub, vector<int> cursub) 
{
	// Subconjunto encontrado!
	if(sizsub == 0) 
	{
		for(int i = cursub.size() - 1; i >= 0; i--) 
			cout << cursub[i] << (i != 0 ? " " : "");

		cout << endl;
		return;
	}

	// Corta se não for possível ter subconjunto ou se chegar numa folha sem 
	// subconjunto.
	if(sizorig == 0 || sizsub > sizorig)
		return;

	// Caso não seja nenhum dos casos bases acima, gera as duas folhas.
	int curelement = sizorig - 1;
	cursub.push_back(conjunto[curelement]);
	percorreArvore(conjunto, sizorig-1, sizsub-1, cursub);
	cursub.pop_back();
	percorreArvore(conjunto, sizorig-1, sizsub, cursub);
}

// Função desncessária para esconder a declaração do vector.
void enumeraSubconjuntos(int *conjunto, int sizorig, int sizsub) 
{
	vector<int> cursub;
	percorreArvore(conjunto, sizorig, sizsub, cursub);  
}

int main(int argc, char *argv[]) 
{
	if(argc < 3) 
	{
		cout << "Uso: " << argv[0] << " [tamanho conj. original] [tamanho"
			" subconjuntos]" << endl;
		return 1;
	}

	int sizorig = atoi(argv[1]);
	int sizsub = atoi(argv[2]);

	if(sizsub > sizorig) 
	{
		cout << "Erro: Subconjuntos não podem ser maior que o conjunto original" 
			<< endl;
		return 3;
	}

	int conjunto[sizorig];
	for(int i = 1; i <= sizorig; i++)
		conjunto[i-1] = i;

	enumeraSubconjuntos(conjunto, sizorig, sizsub);
}
