//REC - COMBINAÇÃO
/*
Considere a função Comb(n,k), que representa o número de grupos distintos com k pessoas que 
podem ser formados a partir de n pessoas. 


Por exemplo, Comb(4,3) = 4, pois com 4 pessoas (A, B, C, D), é possível formar 4 diferentes 
grupos: ABC, ABD, ACD e BCD. 

Podemos calcular a combinação de n elementos k a k por:

           {n,        k = 1
comb(n,k)= {1,        k = n
           {comb(n−1,k−1)+comb(n−1,k),   caso contrario

Implemente uma função recursiva para calcular Comb(n, k).

Entrada:
A entrada consiste de dois inteiros, que correspondem aos valores de n e k, respectivamente.
Saída:
O programa deve mostrar o valor de comb(n,k), conforme os exemplos abaixo:


Exemplo de entrada:       Exemplo de saída:
5 3                       10
4 3                       4   
*/
#include <iostream>
using namespace std;

int comb(int n, int k){
    if(k == 1)
        return n;
    else if(k == n)
        return 1;
    else 
        return comb(n - 1, k - 1) + comb(n - 1, k);
}

int main(){
    
    int n, k;
    
    cin>>n>>k;
    
    cout<<comb(n, k)<<endl;
    
    return 0;
}