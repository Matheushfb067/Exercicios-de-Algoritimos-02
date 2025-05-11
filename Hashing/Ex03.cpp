//Hash-Pesquisa
/*
O algoritmo de pesquisa em uma tabela hash é mostrado abaixo:

HASH-SEARCH(T,m,k)
    i <- 0
    do
        j <- h(k,i,m)
        if T[j].k = k
            return j
        i <- i+1
    while (T[j].status!=0 and i<m)
    return -1
Faça uma função que implemente este algoritmo. Esta função deve retornar a posição onde a 
chave foi encontrada na tabela hash, ou -1 se a chave não estiver na tabela. Use a sondagem 
linear para fazer a sondagem na tabela. Sua função deve ter o seguinte cabeçalho:

int hash_search(dado t[], int m, int k)
Faça então um programa que leia o tamanho desejado m
 para a tabela hash e insira várias chaves nesta.

Depois, o programa deve ler o elemento a ser procurado e retornar a posição em que este se encontra. 
Se o elemento não estiver na tabela, uma mensagem deve ser mostrada. 

Entrada:
A entrada consiste de três linhas:
- a primeira linha irá conter o tamanho m
 da tabela (um número inteiro)
- a segunda linha consiste de vários inteiros positivos, correspondentes aos valores das chaves a 
serem inseridas. Esta linha termina com o número 0, que não deve ser inserido na tabela.
- a última linha tem um único inteiro, que corresponde à chave que queremos verificar.

Saída:
Na saída, o programa deve mostrar onde a chave foi encontrada, ou uma mensagem dizendo que a chave 
não está na tabela, como no exemplo abaixo.


Exemplo de entrada:                	Exemplo  de saída:
11                                  Chave 15 encontrada na posicao 5 
10 22 31 4 15 28 17 88 59 0
15

9                                   Chave 10 nao encontrada
2 1 5 7 0
10
*/


#include <iostream>
using namespace std; 

struct dado{
    int k; 
    int status;//0: vazio / 1:ocupado
};

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

int hash_insert(dado T[], int m, int k){
    int i = 0; 
    int j;    
    
    do{
        j = hash1(k, i, m);
        if(T[j].status != 1){
            T[j].k = k;
            T[j].status = 1;
            return j;
        }
        else
            i = i + 1;
    }while(i != m);
    
    return -1;
}

/*--------------------------------//---------------------------------*/
int hash_search(dado T[], int m, int k){
    int i = 0;
    int j;
    
    do{
        j = hash1(k, i, m);
        if(T[j].k == k)
            return j;
        i += 1;
    }while(T[j].status != 0 && i < m);
    
    return -1;
}

int main (){
    
    int m, k, pos = -1, x;
    dado T[100];
    
     cin>>m;
    
    //Inicialização de todas as posições do vetor de struct T[] com 0.
    for(int i = 0; i < m; i++){
        T[i].status = 0; 
        T[i].k = -1;
    }
    
    cin>>k;
    
    while(k != 0){
        hash_insert(T, m, k);
        cin>>k;
    }
    
    cin>>x;
    
    pos = hash_search(T, m, x);
    
    if(pos != -1)
        cout<<"Chave "<<x<<" encontrada na posicao "<<pos<<endl;
    else
        cout<<"Chave "<<x<<" nao encontrada"<<endl;
    
    return 0;
}