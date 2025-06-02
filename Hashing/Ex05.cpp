//Inserção de Elementos
/*
O algoritmo de inserção de chaves é mostrado abaixo:

HASH-INSERT(T,m,k)
    i <- 0
    do
        j <- h(k,i,m)
        if T[j].status != 1
            T[j].k <- k
            T[j].status=1
            return j
        else
            i <- i+1
    while i!=m
    return -1
Faça uma função que implemente este algoritmo. Esta função deve retornar a posição onde a chave foi 
inserida na tabela hash, ou -1 se não for possível inseri-la (tabela cheia). Use a sondagem linear para 
escolher a posição de inserção da chave. Sua função deve ter o seguinte cabeçalho:

int hash_insert(dado t[], int m, int k)
Faça então um programa que leia o tamanho desejado m
 para a tabela hash e as chaves a serem inseridas.

Depois, o programa deve criar uma tabela de tamanho m
 inicialmente vazia (todas as posições preenchidas com -1), e ir inserindo as chaves digitadas.

Ao final, seu programa deve mostrar a tabela depois das inserções. 

Entrada:
A entrada consiste de duas linhas:
- a primeira linha irá conter o tamanho m
 da tabela (um número inteiro)
- a segunda linha consiste de vários inteiros positivos, correspondentes aos valores das chaves a serem 
inseridas. Esta linha termina com o número 0, que não deve ser inserido na tabela.

Saída:
Na saída, o programa deve mostrar a tabela preenchida, como no exemplo abaixo.
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
/*--------------------------------//---------------------------------*/
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

int main(){
    //Declare variables:
    dado T[100];
    int m, k;
    int j;
    
    cin>>m;
    
    //Inicialização de todas as posições do vetor de struct T[] com 0.
    for(int i = 0; i < m; i++){
        T[i].status = 0; 
        T[i].k = -1;
    }
    
    //Entrada de Dados: 
    cin>>k;
    while(k != 0){
        hash_insert(T, m, k);
        cin>>k;
    }

    
    for(j = 0; j < m; j++){
        cout<<T[j].k<<" "; 
    }
    
    return 0; 
}