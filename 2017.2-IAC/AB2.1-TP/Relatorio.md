# Relatório 

    - Página do repositório do trabalho: https://github.com/Leonnhardt/teaching/tree/master/2017.2-IAC/AB2.1-TP
    

  - Discente 1: 
    Nome: Atalia Nogueira
    Matrícula: 17211298
    Distribuição da nota(%): 33,3

  - Discente 2:
    Nome:David Silva Alexandre
    Matrícula: 17210807
    Distribuição da nota(%): 33,3

  - Discente 3:
    Nome: Milena Bertulino
    Matrícula: 17210979
    Distribuição da nota(%): 33,3

# Resultados

Os gráficos estão no seguinte endereço: https://github.com/Leonnhardt/teaching/tree/master/2017.2-IAC/AB2.1-TP/Gr%C3%A1ficos

# Discussão

## Código do programa em C

Poderá ser acessado através do seguinte link: https://github.com/Leonnhardt/teaching/tree/master/2017.2-IAC/AB2.1-TP/src

Sobre o código:

A função contartempo() captura os segundos em tempo real, já a função recursão é um loop finito para medir o uso médio da UCP. Inicialmente tentamos plotar uma análise neste nível com 10 segundos, no entanto o programa crashava ou dava erro de segmentação, por este motivo depois de dias de tentativas em vão de resolver o problema sem sucesso nos adotamos uma nova abordagem: reduzimos este tempo para aproximadamente 3 segundos(a partir daí calculamos os resultados de uso intenso multiplicando o valor por 3 e fazendo simulações em tempo real).
Sobre o funcionamente do programa: O usuário escolherá se quer utilizar a UCP e a memória de forma extensiva ou não, caso o usuário digite o número um, a função contartempo() será chamada e armazenará os segundos atuais em uma variável, em seguida a função recursao() é chamada ela será um loop finito que começará com os segundos atuais e se encerrará quando o valor do tempo atual em segundos for igual ao tempo captado em um momento anterior + 2 segundos.
Tendo o usuário digitado zero em sua máquina e executado o programa, ocorrerá no uso máximo da UCP e memória, através do que se chama na computação de "loop infinito".

## Utilização intensa da UCP

Sem sombra de dúvidas o resultado deste experimento não foi algo esperado, a equipe não acreditava no que via: Um loop simples nós usamos a quase todo instante quando executado durante 10 segundos contínuamente consome mais de 60% da UCP. Os dados foram realmente incríveis e foi muito proveitosa tal experiência. No gráfico pode se notar o crescimento gradual do consumo da UCP, concluímos que o máximo de consumo foi aproximadamente 65 %. Inicialmente a equipe tentou com o código fonte abaixo colher as informações de uma única vez:

<imports aqui>

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
	if ( i == (j + 10) )
	{
		return;
	}else
	{
		n += 1 * sizeof(int);
		printf("%0.Lf bytes alocados.\n", n);
		malloc( 1 * sizeof(int));
	}
	recursao(i, j, n);
}

void main()
{
	long double j;
	j = contartempo();
	recursao(0, j, 0);
}
	
No entanto, um erro de Segmentação estava tirando o sono de toda a equipe e com a ajuda de alguns colegas conseguimos fazer algo parecido(mas não igual, muito menos melhor).
O novo programa está disponível no GitHub. Alguns passos para execução do mesmo são:
1) Ao digitar o número um, o programa usará levemente a UCP e a memória RAM;
2) Caso queira fazer o máximo uso de ambas, o usuário digitará zero.

No primeiro caso, quando o usuário digita um em seu teclado e executa o programa, o mesmo será executado em um timing semelhantes aos 10 segundos, e não iniciará nenhum processo filho.
O segundo caso será discutido no tópico a seguir.

## Utilização intensa da UCP e memória

Através do código citado acima(no tópico Código do programa em c) medimos o uso da UCP e da memória através da alocação de bytes. A parte da utilização intensa(através de um loop infinito) foi sem sombra de dúvidas a parte mais prazerosa e mais surpreendente de todo o experimento, a equipe ficou completamente supresa ao ver o próprio computador perecer completamente aos 40 segundos de uso intenso. Nós nunca imaginamos que algo assim fosse capaz de acontecer, no entanto tais fatos nos remetem a um pensamento que embora pouco usado é uma das maiores verdades da vida: até mesmo uma máquina tem seus limites. No gráfico é notável a evolução do uso intensivo, que alcança seu ápice aos 40 segundos, dali em diante o computador simplesmente trava e assim permanece até ter sua fonte de alimentação elétrica tirada a força.



