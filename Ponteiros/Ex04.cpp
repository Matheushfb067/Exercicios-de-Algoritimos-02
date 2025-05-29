//Média dos elementos de um vetor
/*
Faça um programa que leia inicialmente o tamanho N de um vetor de inteiros.

Depois, o programa deve ler N números inteiros e os inseri-los no vetor.

Finalmente, varra o vetor usando um ponteiro, e calcule a média dos elementos deste vetor.  

Entrada:
A entrada consiste de 2 linhas:
- a primeira linha contém apenas um inteiro N, que corresponde ao tamanho do vetor
- na segunda linha, tem-se N inteiros, separados por um espaço em branco.

Saída:
Na saída, o programa deve mostrar a média dos elementos inseridos no vetor, com 2 casas decimais.

Exemplo de entrada:         Exemplo de saída:
4                           48.25
40 32 51 70	
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    
    int n; //Qtd de elementos do vetor
    int *v = NULL; //ponteiro    
    int i;  //contador
    double media;

    cin >> n; 
    
    v = new int[n];
    
    double soma = 0;
    
    for (i = 0; i < n; i++){
        cin >> v[i];
        soma += v[i];
    }
    
    media = soma / n;
    
    cout << fixed << setprecision(2)<< media << endl;
    
    delete [] v;
    
    return 0;
}