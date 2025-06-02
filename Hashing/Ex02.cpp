//Sondagem linear
/*
Usando a função hash_aux(), faça uma função que implemente a sondagem linear, dada por:

h(k,i,m)=(h′(k,m)+i)modm

Esta função deve ter o seguinte cabeçalho: 

int hash1(int k, int i, int m)
onde k é a chave a ser inserida, m é o tamanho da tabela hash e i é o número da tentativa.

Depois faça um programa qiue leia os valores de k e m e faça uso desta função para retornar 
as posições da sondagem linear.

Entrada:
A entrada consiste  uma única llinha com 2 inteiros, correspondentes aos valores de k e m, respectivamente. 

Saída:
Na saída, o programa deve mostrar todas as posições da sondagem linear para as entradas dadas.

Exemplo de entrada                 Exemplo de Saída:
4 11                               4 5 6 7 8 9 10 0 1 2 3
25 9                               7 8 0 1 2 3 4 5 6
-4 11	                           7 8 9 10 0 1 2 3 4 5 6
*/

#include <iostream>
using namespace std; 

int hash_aux(int k, int m){
    int h;
    
    h = k % m;
    
    if(h < 0)
        h = h + m;
        
    return h;
}

int hash1(int k, int i, int m){
    int h;
    
    h = (hash_aux(k,m) + i) % m; 
    
    return h;
}

int main(){
    int k, i, m;
    
    cin>>k>>m;
    
    for (int i = 0; i < m; i++)
        cout<<hash1(k,i,m)<<" ";
    
    return 0; 
}