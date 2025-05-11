//Raiz Quadrada:
/*
Dado um número real positivo x, podemos calcular √x usando o seguinte algoritmo recursivo:

raiz(x,x0,ϵ)= {x0  |x0^2| <= e}                                {}//Sistema de eq. 
              {raiz(x, x0^2 + x / 2x0, e)}, caso contrario     {}//Sistema de eq. 

onde:

- x: é o número do qual se quer calcular a raiz

- x0: é uma estimativa inicial para √x

- ε: é um limitante superior para o erro

Faça um programa que leia os valores de x, x0 e ε, e retorne o valor de √x, com 4 casas decimais. 
Você pode assumir que estes valores serão sempre positivos.

O cálculo deve ser feito usando uma função recursiva.

Entrada: 
A entrada consiste 3 valores reais e positivos, correspondentes a x, x0 e ε.

Saída: 
O programa deve mostrar o valor de √x, com a precisão desejada.


Exemplo de entrada:             Exemplo de saída:
125 1 0.001	                    11.1803
5 1 0.0001	                    2.2361
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double raiz(double x, double x0, double e){
    if(abs(pow(x0, 2) - x) <= e)
        return x0;
    else
        return raiz(x, (((x0*x0) + x )/ (2 * x0)), e);
}

int main (){
    
    //Declare Variables:
    double x, x0, e;
    
    //Data input: 
    cin>>x>>x0>>e;
    
    //Data output: 
    cout<<fixed<<setprecision(4);
    cout<<raiz(x, x0, e)<<endl;
    
    return 0;
}