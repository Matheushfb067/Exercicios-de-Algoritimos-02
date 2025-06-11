// LIST - Fila
/*
Faça um programa que leia 4 valores inteiros e os insira no final de uma lista
ligada (veja que estamos implementando uma fila).

Depois o programa deve ir removendo os elementos da lista e mostrando-os na tela.

Entrada:
A entrada consiste de 4 números inteiros.

Saída:
Na saída, o programa deve mostrar os elementos inseridos.

Exemplo de entrada:           Exemplo de saída:
40 32 51 70	                  40 32 51 70
*/

#include <iostream>
#include <list>
using namespace std;

int main()
{

    list<int> fila;
    int x;

    for (int i = 0; i < 4; i++)
    {
        cin >> x;
        fila.push_back(x);
    }

    for (int i = 0; i < 4; i++)
    {
        cout << *fila.begin() << " ";
        fila.pop_front();
    }

    return 0;
}
