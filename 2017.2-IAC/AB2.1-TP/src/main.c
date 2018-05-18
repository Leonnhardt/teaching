#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long double contartempo()
{
  	time_t timer;
  	struct tm y2k = {0};
  	long double seconds;
  	y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
  	y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;
  	time(&timer);
  	seconds = difftime(timer, mktime(&y2k));
  	return seconds;
}

void recursao(long double i, long double j, long double n)
{
	i = contartempo();
	if ( i == (j + 2) )
	{
		return;
	}else
	{
		n += 10 * sizeof(int);
		printf("%0.Lf bytes estão alocados.\n", n);
		malloc( 10 * sizeof(int));
	}
	recursao(i, j, n);
}

void main()
{
	unsigned long long int i, contador, qtd;
	int oquefazer;
	long double j;
	j = contartempo();
	printf("Digite 1 para executar um processo de leve utilização da memória e da CPU. Caso queira usar o máximo de ambas, digite 0:\n");
	scanf("%d", &oquefazer);
	if ( oquefazer == 1 )
	{
		recursao(0, j, 0);
		return;
	}else
	{
		for ( i = 0; i < 10; i = 0 )
		{
			contador = 0;
			while( contador < 5 )
			{
				qtd += 200 * sizeof(int);
				printf("Estão alocados: %lli bytes\n", qtd);
				malloc(200 * sizeof(int));
				contador ++;			
			}
		}
	}
	
}
