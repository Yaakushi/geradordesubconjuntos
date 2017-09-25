#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::sort;

void geraProximoConjunto(int *conjunto, int sizorig, int sizsub)
{
	if(conjunto[sizsub-1] == sizorig)
	{
		if(sizsub == 1)
		{
			conjunto[0] = 1;
			return;
		}
		//Caso o ultimo digito do prefixo atual seja o maior possivel, incrementa
		//o prefixo menor antes.
		geraProximoConjunto(conjunto, sizorig-1, sizsub-1);

		//E entao volta o final do prefixo atual para o menor valor possivel.
		conjunto[sizsub-1] = conjunto[sizsub-2] + 1;
	}
	else
	{
		// Caso contrario, apenas incrementa o final do prefixo atual.
		conjunto[sizsub-1]++;
	}
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
	// Caso o professor seja gentil e ja forneca a entrada ordenada, o 
	// algoritmo da libc++ deveria checar se o vetor já está ordenado e não
	// prejudicar (muito) a performance.
	sort(conjunto, conjunto+sizsub);

	geraProximoConjunto(conjunto, sizorig, sizsub);

	for(int i = 0; i < sizsub; i++)
	{
		cout << conjunto[i] << (i == (sizsub - 1) ? "" : " " );
	}
	cout << endl;
}
