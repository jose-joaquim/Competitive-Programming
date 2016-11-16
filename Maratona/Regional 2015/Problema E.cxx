#include <stdio.h>

int main(int argc, char *argv[])
{
	long long int N, B;

	scanf("%lld %lld", &N, &B);

	// busca binária para encontrar o X
	long long int ini = 0, fim = N / 2, meio, X = 0;

	/*
	    busca binária para encontrar o maior valor possível
	    de X que satisfaça a inequação: 4*X*(N - X) < B
	    o X é o valor da caixa anteior à casca certa
	*/
	while (ini <= fim)
	{
		meio = (ini + fim) / 2;
		if (4 * meio * (N - meio) < B)
		{
			X = meio;
			ini = meio + 1;
		}
		else
			fim = meio - 1;
	}

	long long int resto_feijoes = B - 4 * X * (N - X);
	long long int casca = X + 1;
	long long int lim = N + (casca - 1) * (-2);
	long long int coordX = casca, coordY = casca;
	long long int resto;

	// tenta colocar a maior qte. possível na primeira linha
	if(resto_feijoes >= lim)
	{
		resto_feijoes -= lim;
		coordY += (lim - 1);
	}
	else
	{
		resto = resto_feijoes % lim;
		coordY += (resto - 1);
		resto_feijoes -= resto;
	}
	
	if(resto_feijoes > 0)
	{
		// tenta colocar a maior qte. possível na primeira coluna
		if(resto_feijoes >= lim - 1)
		{
			resto_feijoes -= (lim - 1);
			coordX += (lim - 1);
		}
		else
		{
			resto = resto_feijoes % (lim - 1);
			coordX += resto;
			resto_feijoes -= resto;
		}

		// tenta colocar a maior qte. possível na segunda linha
		if(resto_feijoes > 0)
		{
			if(resto_feijoes >= lim - 1)
			{
				resto_feijoes -= (lim - 1);
				coordY -= (lim - 1);
			}
			else
			{
				resto = resto_feijoes % (lim - 1);
				coordY -= resto;
				resto_feijoes -= resto;
			}
			
			// tenta colocar a maior qte. possível na segunda coluna
			if(resto_feijoes > 0)
				coordX -= resto_feijoes;
		}
	}

	printf("%lld %lld\n", coordX, coordY);

	return 0;
}

/*#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char **argv)
{
	int N, B, aux1 = 0, aux2 = 0, aux3 = 0;
	int i, j;
	std::cin >> N >> B;
	j = 0; i = 0; aux2 = N;
	while(B != 0){
		j = aux3;
		while(j < N && B != 0){
			j++; B--;
		}
		aux3++;
		if(B == 0) break;
		aux1++;
		i = aux1;
		while(i < N && B != 0){
			i++; B--;
		}
		if(B == 0) break;		
		//aux2--;
		j = aux2;
		while(j > 0 && B != 0){
			j--; B--;			
		}
		if(B == 0) break;
		aux2--;
		N--;
		i = N;
		while(i > aux1+1 && B != 0){
			i--; B--;
		}
		if(B == 0) break;		
	}
	if(i == 0){
		cout << i+1 << " " << j << std::endl;
	}else if(j == 0){
		cout << i << " " << j+1 << std::endl;
	}else{		
		cout << i << " " << j << std::endl;
	}
	//cout << B << endl;
	return 0;
}*/

