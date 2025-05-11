//Mostrando e contando
/*
Faça uma função usando o algoritmo Bubble Sort, que mostre toda vez que a variável trab receber 
um novo valor, o valor que ela recebeu. Por ultimo faça um contador, que conte quantas vezes a 
variável troca recebe o valor true.
Entrada:
A entrada consiste em um valor inteiro que corresponde a quantidade de valores que irá adicionar no vetor. 
Em seguida, deverá entrar com os números inteiros que irão ser inseridos no vetor.
Saída:
Na saída, o programa deve mostrar "New trab:" e os valores que a variável trab recebeu e por fim 
"Contador:" com o valor contado.


Exemplo de entrada                  Exemplo de saída
5                                   New trab:11
7 4 9 11 5	                        New trab:7
                                    New trab:9
                                    New trab:7
                                    Contador:4
3
1 5 9	                            Contador:0
*/

#include <iostream>
using namespace std;

void bubbleSort(int vetor[], int tamanho)
{
    int i, j, contador = 0; // contadores
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
                cout << "New trab:" << trab << endl;
                contador++;
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = trab;
                j = i;
                troca = true;
            }
        limite = j;
    }
    
    cout << "Contador:" << contador << endl;
}

int main(){
    
    int num_vetor, vetor[20];
    
    cin>>num_vetor;

    for(int i = 0 ; i < num_vetor; i++){
        cin>>vetor[i];
    }
    
    bubbleSort(vetor, num_vetor);
    
    return 0;
}