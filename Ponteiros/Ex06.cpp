//Elementos pares e positivos de um vetor
/*
Faça um programa que leia inicialmente o tamanho N de um vetor de inteiros.

Depois, o programa deve ler N números inteiros e os inseri-los no vetor.

Finalmente, varra o vetor usando um ponteiro, e determine quantos elementos são pares e positivos.  

Entrada:
A entrada consiste de 2 linhas:
- a primeira linha contém apenas um inteiro N, que corresponde ao tamanho do vetor
- na segunda linha, tem-se N inteiros, separados por um espaço em branco.

Saída:
Na saída, o programa deve mostrar o número de elementos pares e positivos inseridos no vetor.

Exemplo de entrada:       Exemplo de saída:
6                         3
-2 40 32 -51 70 -22 	
*/

#include <iostream>
using namespace std;

int main() {
    
    int n; //tamanho do vetor
    int *v = NULL; //ponteiro vetor
    
    cin >> n; 
    
    v = new int [n]; //aloc dinamica
    
    //entrada de dados
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    
    int cont = 0;
    
    for(int i = 0; i < n; i++){
        if(v[i] % 2 == 0 && v[i] > 0)
            cont++;
    }
    
    cout << cont <<endl;
    
    delete [] v;
    
    return 0; 
}