//Sondagem Quadratica
/*
Usando a função hash_aux(), faça uma função que implemente a sondagem quadrática, dada por:

h(k,i,m)=(h′(k,m)+ (c1 * i) + (c2* i ^ 2)) mod m

Esta função deve ter o seguinte cabeçalho: 

int hash2(int k, int i, int m, int c1, int c2)

onde k é a chave a ser inserida, m é o tamanho da tabela hash, e i é o número da tentativa.
Depois faça um programa que leia os valores de k, m, c1 e c2 e faça uso desta função para retornar as posições da 
sondagem quadrática.

Entrada:
A entrada consiste  uma única llinha com 4 inteiros, correspondentes aos valores de k, m, c1 e c2, respectivamente. 

Saída:
Na saída, o programa deve mostrar todas as posições da sondagem quadrática para as entradas dadas.

Exemplos de entrada:    	Exemplos  de saída:
4 9 1 3                     4 8 0 7 2 3 1 5 6
-4 11 1 3                   7 0 10 4 4 10 0 7 9 6 9
25 9 1 3                    7 2 3 1 5 6 4 8 0
*/

#include <iostream>
#include <cmath>
using namespace std; 

struct dados
{
    int k; // chave
    int status; // 0:vazio, 1:ocupado, 2:removido
};

int hash_aux(int k, int m)
{
    int h;
    h =  k % m; 
    if (h < 0)
        h = h + m; // se negativo, ajusta para o intervalo [0, m-1]
    return h;
}

//------------------------------------//---------------------------------//

int hash2(int k, int i, int m, int c1, int c2){
    int h;
    
    h = (hash_aux(k, m) + (c1*i) + (c2 * int(pow(i, 2)))) % m;
    
    return h;
}

//------------------------------------//---------------------------------//

int main(){
    
    int k, m, c1, c2, i;
    
    cin>>k>>m>>c1>>c2;
    
    for(i = 0; i < m; i++){
        cout<<hash2(k, i, m, c1, c2)<<" ";
    }
    
    return 0;
}