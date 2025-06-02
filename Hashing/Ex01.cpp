//hash_aux
/*
Faça uma  função que implemente o método da divisão, dado por:

h(k,m)=k % m

Se o valor resultante for negativo, você deve somar m
 a ele.

A sua função deve ter o seguinte cabeçalho: 

int hash_aux(int k, int m)
onde k é a chave a ser inserida, e m é o tamanho da tabela hash.

Depois faça um programa qiue leia vários valores de k e m e faça uso desta função 
para retornar o valor dela.

Entrada:
A entrada consiste  de várias llinhas. Cada linha terá 2 inteiros, correspondentes aos 
valores de k e m, respectivamente. O final da entrada ocorre quando forem digitados valores
nulos para k e m.

Saída:
Para cada par de valores k e m, o programa deve mostrar o valor da função hash.

Exemplo de Entrada:                  Exemplo de saída: 
4 11                                 4
-4 3                                 2 
25 15                                10
17 17                                0
0 0
*/

#include <iostream>
using namespace std; 

int hash_aux(int k, int m){
    int h;
    
    h = k % m; 
    
    if(h < 0)
        h = h + m;
    
    return h;
}


int main(){
    
    //Declare Variables: 
    int k, m; 
    int h; 
    
    cin>>k>>m;
    
    while(k != 0 && m != 0){
        h = hash_aux(k,m);
        cout<<h<<endl;
        cin>>k>>m;
    }
    
    return 0;
}
