//Ordene um vetor
/*
Faça um programa que use o algoritmos Quick Sort para ordenar um vetor em ordem crescente.
Entrada:
A entrada consiste em vários números inteiros, que devem ser inseridos no vetor. O final 
da entrada é sinalizado pelo número -1, que não deve ser inserido no vetor.
Saída:
Na saída, o programa deve mostrar como ficou o vetor em ordem crescente. 


Exemplo de entrada:         Exemplo de saída:
1 4 2 6 5 4 7 -1            1 2 4 4 5 6 7
2 0 4 7 3 -1                0 2 3 4 7
*/

#include <iostream>
#include <math.h>
using namespace std;

void quickSort(int vetor[], int i, int j)
{
    int trab, esq, dir, pivo;
    esq = i;
    dir = j;
    pivo = vetor[(int)round((esq + dir) / 2.0)];
    do
    {
        while (vetor[esq] < pivo)
            esq++;
        while (vetor[dir] > pivo)
            dir--;
        if (esq <= dir)
        {
            trab = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = trab;
            esq++;
            dir--;
        }
    } while (esq <= dir);
    if (dir - i >= 0)
        quickSort(vetor, i, dir);
    if (j - esq >= 0)
        quickSort(vetor, esq, j);
}

int main()
{
    int num, i, vetor[20], j;
    
    for(i = 0; i < 20; i++){
        cin>>num;
        if( num != -1)
            vetor[i] = num;
        else 
            break;
    }
    
    quickSort(vetor, num, i);
    
    for(j = 1; j <= i; j++){
        cout<<vetor[j]<<" ";
    }
    

    return 0;
}