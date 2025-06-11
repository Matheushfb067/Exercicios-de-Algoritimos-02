// Fila
#include <iostream>
#include <list>
using namespace std;

int main()
{
    // pilha é um ponteiro e só armazena numero inteiros (neste caso)
    list<int> pilha; // pilha -> NULL
    // int i;           // contador

    int x = 1;
    pilha.push_back(x); // insere x no final
    x = 2;
    pilha.push_back(x);
    x = 3;
    pilha.push_back(x);

    cout << *pilha.begin() << endl; // aponta para o primeiro elemento da pilha = 3 (FIFO - Fist In First Out)
    pilha.pop_front();              // remove o primeiro elemento.(destroi a lista)

    // Mostra o ultimo elemento tendo em vista que o 3 foi removido, portanto o topo é 2!
    cout << *pilha.begin() << endl;

    return 0;
}