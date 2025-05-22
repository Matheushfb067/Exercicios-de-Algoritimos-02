#include <iostream>
using namespace std;

int main (){

    int vetor[5];
    int i;
    int *p;

    for(i = 0; i < 5; i++)
        vetor[i] = i;

    p = vetor;

    // mostra todas as posições do vetor
    for(i = 0; i < 5; i++){
        cout<< *p << endl; 
        p++;
    }

    p = vetor;
    //Mostrando o ultimo elemento do vetor
    cout<<*(p + 4)<<endl;

    /*
    p = vetor;
    cout<< *p <<endl;//Guarda o endereço de onde o vetor começa!
    p++; //Não soma um! como ele aponta para um inteiro, anda para casa seguinte do vetor, pois um inteiro ocupa um unico byte
    cout<< *p << endl;
    */

    return 0;
}