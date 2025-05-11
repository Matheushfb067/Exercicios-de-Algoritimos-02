/*Busca Sequencial*/
/*
Faça um programa que leia vários valores inteiros e os armazene em um vetor. Depois, o programa deve 
ler um inteiro X e fazer uso da pesquisa sequencial para verificar se X está ou não no vetor. Se X for
encontrado no vetor, o programa deve indicar a posição onde o mesmo foi encontrado.

Entrada:
A entrada consiste em vários números inteiros, que devem ser inseridos no vetor. O final da entrada é 
sinalizado pelo número -1, que não deve ser inserido. Considere que não haverá mais do que 100 elementos. 
Após o número -1, será informado o valor de X.

Saída: 
Na saída, o programa deve mostrar a posição em que X foi encontrado no vetor, ou uma mensagem dizendo 
que X não foi encontrado, casoccontrário.

Exemplo de entrada:                       Exemplo de saída:
1 4 2 6 5 4 7 -1 9                        9 nao encontrado
2 0 4 7 3 -1 3                            3 encontrado na posicao 4
*/

#include <iostream>

using namespace std;

int main (){
    
    int vetor[10], x, i, num, j = 0, pos = -1; 
    
    for(i = 0; i < 99; i++){
        cin>>num;
        if(num != -1)
            vetor[i] = num;
        else
            break;
    }
        
    cin>>x; 
    
    for(j = 0; j <= i; j++){
        if(vetor[j] == x)
            pos = j;
    }
    
    if(pos != -1)
        cout<<x<<" encontrado na posição "<<pos<<endl;
    else
        cout<<x<<" não encontrado"<<endl;
    
    return 0;
}