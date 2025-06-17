// Fila
/*
Armazena os elementos como filas de pessoas
As inserções são realizadas no final, e as remoções são feitas do primeiro para o último

pilha.push_back(x);    // insere no final
pilha.pop_front();     // remove do início
*/

#include <iostream>
#include <list>
using namespace std;

int main()
{
    // pilha é um ponteiro e só armazena numero inteiros (neste caso)
    list<int> fila; // pilha -> NULL
    // int i;           // contador

    int x = 1;
    fila.push_back(x); // insere x no final
    x = 2;
    fila.push_back(x); // insere o valor 2 depois do 1
    x = 3;
    fila.push_back(x); // 1 -> 2 -> 3

    cout << *fila.begin() << endl; // aponta para o primeiro elemento da fila = 1 (FIFO - Fist In First Out)
    fila.pop_front();              // remove o primeiro elemento.(destroi a lista)

    // Mostra o ultimo elemento tendo em vista que o 1 foi removido, portanto o topo é 2!
    cout << *fila.begin() << endl;

    return 0;
}