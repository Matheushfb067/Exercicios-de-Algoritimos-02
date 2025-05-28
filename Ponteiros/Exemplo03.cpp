//Exemplo em sala: alocação dinamica
#include <iostream>
using namespace std;

struct dados {
    int idade;
    float altura;
};

int main (){

    dados *pessoa = NULL;/*boa pratica apontar o ponteiro para NULL 
    quando não se sabe para onde se quer apontar.*/
    cout<< pessoa << endl;

    pessoa = new dados; //alocando memoria.
    cout << pessoa << endl; // aloca um endereço de memoria para a variavel pessoa.

    pessoa->idade = 20;
    pessoa->altura = 1.75;

    cout<<pessoa->idade<<endl;
    cout<<pessoa->altura<<endl;

    /*No c++ não existe um Garbage Colector, portanto a alocação dinamica com o 
    comando new é como um virus, já que ele consome aproximadamente 10bytes de 
    memoria ram e ela fica marcada como usada pelo sistema operacionao e nunca 
    mais é acessada. Por isso usamos o comando "delete"*/
    //Sempre que o new for usado o delete deve vir no final do codigo!

    delete pessoa; 

    return 0; 
}