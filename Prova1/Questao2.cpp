//ORD - BUBBLE SORT 3
/*
Altere a função bubbleSort, mostrada abaixo para ordenar um vetor de números reais em ordem decrescente. 

Depois faça um programa que leia vários números reais e use esta função para ordenar este vetor em ordem decrescente.

Ao final, o programa deve mostrar o vetor ordenado em ordem decrescente.

void bubbleSort(int vetor[], int tamanho)
{
    int i, j; // contadores
    int trab;
    bool troca;
    int limite;
    troca = true;
    limite = tamanho - 1;

    while (troca)
    {
        troca = false;
        for (i = 0; i < limite; i++)
            if (vetor[i] > vetor[i + 1])
            {
                trab = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = trab;
                j = i;
                troca = true;
            }
        limite = j;
    }
}
Entrada
A entrada consiste de uma única linha com vários números reais. O final da entrada é sinalizado pelo elemento -1, que não deve ser inserido no vetor.
Saída
O programa deve mostrar os elementos do vetor, em ordem decrescente, conforme o exemplo abaixo:

Exemplo de entrada:     Exemplo de saída:         
4.1 1.2 2.7 3.5 -1	    4.1 3.5 2.7 1.2
*/

#include <iostream>
using namespace std;

void bubbleSort(double vetor[], int tamanho){
    int i, j; // contadores
    double trab;//muda o tipo, para que todos os valores na saida sejam booleanos
    bool troca;
    int limite;
    troca = true;
    limite = tamanho - 1;
    while (troca)
    {
        troca = false;
        for (i = 0; i < limite; i++)
            if (vetor[i] < vetor[i + 1])//o sinal de < ao em vez de > é o que troca a ordem do vetor para decrescente
            {
                trab = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = trab;
                j = i;
                troca = true;
            }
        limite = j;
    }
} 

int main(){
    
    double n, vet[20];
    int i;
    
    for(i = 0; i < 20; i++){
        cin>>n; 
        if(n != -1)
            vet[i] = n;
        else 
            break;
    }
    
    //Chama a função
    bubbleSort(vet, i);
    
    //Mostra todas as posições com um espaço entre elas
    for(int j = 0; j < i; j++){
        cout<<vet[j]<<" ";
    }
    
    return 0;
}