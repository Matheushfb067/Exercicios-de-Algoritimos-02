// Pilha
/*
Armazena os números em sequência, como uma pilha de livros
Insere no final e remove do final também

push_front: colocar na frente
pop_front: remover da frente
*/

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
    pilha.push_front(x); // inserir o valor 2 antes do 1
    x = 3;
    pilha.push_front(x); // 3 -> 2 -> 1

    cout << *pilha.begin() << endl; // aponta para o primeiro elemento da pilha = 3 (LIFO - Last In First Out)
    pilha.pop_front();              // remove o primeiro elemento.
    // O pilha.begin() já aponta para o 2 automaticamente após o comando pilha.pop_front() uma vez que ele passa a ser o topo da pilha

    // Mostra o ultimo elemento tendo em vista que o 3 foi removido, portanto o topo é 2!
    cout << *pilha.begin() << endl;

    return 0;
}