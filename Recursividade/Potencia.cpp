//Potencia
/*
Faça uma função que ordene um vetor em ordem decrescente usando o algoritmo de ordenação Insertion Sort.

Entrada:
A entrada consiste em vários números inteiros, que devem ser inseridos no vetor. O final da entrada é 
sinalizado pelo número 0, que não deve ser inserido no vetor.

Saída:
Na saída, o programa deve mostrar como ficou o vetor em ordem decrescente. Não há espaço em branco após 
o último elemento.

Exemplo de entrada:                 Exemplo de saída:
7 4 1 2 9 11 0	                    11 9 7 4 2 1
2 15 4 7 3 0                        15 7 4 3 2
*/

#include <iostream>
using namespace std;

int potencia(int a, int n){
    if(n == 0)
        return 1;
    else
        return a*potencia(a, n-1);
}

int main(){
    
    //Declare Variables:
    int a, n;
    
    //Data input: 
    cin>>a>>n;
    
    //Data Output:    
    cout<<potencia(a, n)<<endl;
    
    return 0;
}