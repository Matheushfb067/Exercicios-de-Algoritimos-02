//Maior elemento de um vetor
/*
Faça um programa que leia inicialmente o tamanho N de um vetor de inteiros.

Depois, o programa deve ler N números inteiros e os inseri-los no vetor.

Finalmente, varra o vetor usando um ponteiro, e retorne o maior elemento deste vetor.  

Entrada:
A entrada consiste de 2 linhas:
- a primeira linha contém apenas um inteiro N, que corresponde ao tamanho do vetor
- na segunda linha, tem-se N inteiros, separados por um espaço em branco.

Saída:
Na saída, o programa deve mostrar o maior elemento elemento inserido no vetor.

Exemplo de entrada:   Exemplo de saída:
4                     70
40 32 51 70	
*/

#include <iostream>
using namespace std; 

int main(){
    
    int n; //tamanho do vetor
    int *v = NULL; //ponteiro vetor
    
    cin >> n;
    
    v = new int[n]; //alocação de memoria
    
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    
    int ma = v[0]; 
    
    for(int i = 0; i < n; i++){
        if(ma < v[i])
            ma = v[i];
    }
    
    cout << ma << endl;
    
    delete [] v;
    
    return 0; 
}