#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::sort;

void geraProximoConjunto(int *conjunto, int sizorig, int sizsub)
{
	
}

int main(int argc, char *argv[])
{   
	if(argc < 3) 
	{
		cout << "Uso: " << argv[0] << " [tamanho conj. original] [tamanho"
			" subconjuntos] [elemento1] [elemento2] ..." << endl;
		return 1;
	}

	int sizorig = atoi(argv[1]);
	int sizsub = atoi(argv[2]);

	if(argc != sizsub + 3) 
	{
		cout << "Erro: Numero incorreto de elementos fornecidos." << endl
			<< "Esperados: " << sizsub << endl
			<< "Recebidos: " << (argc - 3) << endl;
		return 2;
	}

	if(sizsub > sizorig) 
	{
		cout << "Erro: Subconjuntos não podem ser maior que o conjunto original" 
			<< endl;
		return 3;
	}

	int conjunto[argc-3];
	for(int i = 3; i < argc; i++)
		conjunto[i-3] = atoi(argv[i]);

	// Como a definição do problema não especificou que a entrada estaria
	// ordenada, sejamos um pouco cautelosos.
	// Algoritmo da libc++ deveria checar se o vetor já está ordenado e não
	// prejudicar (muito) a performance.
	sort(conjunto, conjunto+sizsub);

	for(int i = 0; i < sizsub; i++)
		cout << conjunto[i] << " ";
	
	cout << endl;

	geraProximoConjunto(conjunto, sizorig, sizsub);
}
