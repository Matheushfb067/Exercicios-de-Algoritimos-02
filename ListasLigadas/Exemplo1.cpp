// Pilha
#include <iostream>
#include <list>
using namespace std;

int main()
{
    // pilha é um ponteiro e só armazena numero inteiros (neste caso)
    list<int> pilha; // pilha -> NULL
    // int i;           // contador
    int x = 1;
    pilha.push_front(x); // insere x no inicio
    x = 2;
    pilha.push_front(x);
    x = 3;
    pilha.push_front(x);

    cout << *pilha.begin() << endl; // aponta para o primeiro elemento da pilha = 3 (LIFO - Last In First Out)
    pilha.pop_front();              // remove o primeiro elemento.

    // Mostra o ultimo elemento tendo em vista que o 3 foi removido, portanto o topo é 2!
    cout << *pilha.begin() << endl;

    return 0;
}