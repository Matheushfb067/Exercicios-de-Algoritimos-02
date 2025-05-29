//Inserindo elementos em um vetor
/*
Faça um programa que leia inicialmente o tamanho N de um vetor de inteiros.

Depois, o programa deve alocar dinamicamente um vetor de N posições.

Em seguida, o programa deve ler N números inteiros e os inseri-los no vetor,
usando um segundo ponteiro para esta tarefa: se o vetor é v, e o ponteiro é p, 
você deve usar p para apontar para a posição correta do vetor, e usar este ponteiro 
para inserir o elemento no vetor.

Finalmente, varra o vetor usando um ponteiro, e mostre o seu conteúdo.  

Entrada:
A entrada consiste de 2 linhas:
- a primeira linha contém apenas um inteiro N, que corresponde ao tamanho do vetor
- na segunda linha, tem-se N inteiros, separados por um espaço em branco.

Saída:
Na saída, o programa deve mostrar os elementos inseridos.


Exemplo de entrada:          Exemplo de saída:
4                            40 32 51 70
40 32 51 70	
*/

#include <iostream>
using namespace std;

int main(){
    
    int n;//tamanho do vetor
    int *v = NULL, *p = NULL; //ponteiros
    int i; //contador
    
    cin >> n;
    
    v = new int[n]; //alocação de memoria
    
    //Faz 'p' apontar para o a primeira posição do vetor
    p = v;
    
    for(i = 0; i < n; i++){
        cin >> *p; //Entrando com os valores no vetor
        p++;
    }
    
    //Reinicia 'p' para a o inicio do vetor antes de exibir!
    p = v;
    
    for(i = 0; i < n; i++){
        cout<< *p << " ";
        p++;
    }
    
    delete [] v;
    
    return 0;
}