//
/*
Tal como a sondagem linear, a sondagem quadrática é uma técnica para encontrar uma

posição para inserir uma chave k em uma tabela hash. A expressão para esta técnica é:

h′(k,m)=kmodm
  (lembre-se de adicionar m ao resultado, se este for negativo)

h(k,i,m)=(h′(k,m)+c1⋅i+c2⋅i2)modm

Estas funções devem ter os seguintes cabeçalhos: 

int hash_aux(int k, int m)
int hash1(int k, int i, int m, int c1, int c2)
onde k é a chave a ser inserida, m é o tamanho da tabela hash, e i é o número da tentativa.



O algoritmo de pesquisa em uma tabela hash é mostrado abaixo:

HASH-SEARCH(T,m,k,c1,c2)
    i <- 0
    do
        j <- hash1(k,i,m,c1,c2)
        if T[j].k = k
            return j
        i <- i+1
    while (T[j].status!=0 and i<m)
    return -1
Faça uma função que implemente este algoritmo. Esta função deve retornar a posição 
onde a chave foi encontrada na tabela hash, ou -1 se a chave não estiver na tabela. 
Use a sondagem quadrática para fazer a sondagem na tabela. Sua função deve ter o 
seguinte cabeçalho:

int hash_search(dado t[], int m, int k, int c1, int c2)
Faça então um programa que leia o tamanho desejado m para a tabela hash e insira várias 
chaves nesta.

Depois, o programa deve ler o elemento a ser procurado e retornar a posição em que este 
se encontra. Se o elemento não estiver na tabela, uma mensagem deve ser mostrada. 

Entrada:
A entrada consiste de três linhas:
- a primeira linha irá conter o tamanho m da tabela (um número inteiro) e os valores de c1 e c2.
- a segunda linha consiste de vários inteiros positivos, correspondentes aos valores das chaves 
a serem inseridas. Esta linha termina com o número 0, que não deve ser inserido na tabela.
- a última linha tem um único inteiro, que corresponde à chave que queremos verificar.

Saída:
Na saída, o programa deve mostrar onde a chave foi encontrada, ou uma mensagem dizendo que a chave 
não está na tabela, como no exemplo abaixo.

Exemplo de entrada:                  	Exemplo  de saída:
11 1 3                                  15	Chave 15 encontrada na posicao 8 
10 22 31 4 15 28 17 88 59 0


11 1 3                                  Chave 19 nao encontrada
10 22 31 4 15 28 17 88 59 0
19
*/

