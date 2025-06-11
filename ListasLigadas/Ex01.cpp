// LIST - Pilha
/*
Faça um programa que leia 4 valores inteiros e os insira em uma pilha. Depois o
programa deve ir removendo os elementos da pilha e mostrando-os na tela.

Entrada:
A entrada consiste de 4 números inteiros.

Saída:
Na saída, o programa deve mostrar os elementos inseridos.


Exemplo de entrada:              Exemplo de saída:
40 32 51 70	                     70 51 32 40
*/

#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> lista;
    int x;

    for (int i = 0; i < 4; i++)
    {
        cin >> x;
        lista.push_front(x); // insere os elementos
    }

    for (int i = 0; i < 4; i++)
    {
        cout << *lista.begin() << " "; // Mostrar antes p/ não aparecer o 0;
        lista.pop_front();             // remove os elementos da lista
    }

    return 0;
}
