//EXEMPLO EM SALA:
#include <iostream>

using namespace std;

int main (){
    
    int vetor[5];
    int x;
    int i;
    int pos;
    
    for(i = 0; i < 5; i++)
        cin>>vetor[i];
    
    cin>>x;
    
    //Faça um programa que verifique se x está no vetor
    pos = -1;
    
    for(i = 0; i < 5; i++)
        if(vetor[i] == x)
            pos = i;
    
    if(pos != -1)
        cout<<"x encontrado na posição "<<pos<<endl;
    else
        cout<<"X não encontrado"<<endl;
    
    return 0;
}