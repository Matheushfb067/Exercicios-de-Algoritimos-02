// LIST - Soma dos nós
/*
Faça uma função que receba em sua entrada um ponteiro para uma lista ligada,
e retorne a soma dos nós nesta lista. O cabeçalho desta função deve ser:

int soma(list<int> lista)

Depois, faça um programa que vá lendo vários números e os inserindo na lista,
e em seguida mostre a soma dos nós desta lista.

Entrada:
A entrada consiste vários números inteiros, que devem ser colocados na lista.
O final da entrada é sinalizado pelo número 0, que não deve ser inserido na lista.
Saída:
Na saída, o programa deve mostrar a soma dos campos info dos nós que foram inseridos
na lista.


Exemplo de entrada:       Exemplo de saída:
1 2 3 0                   6
2 -1 4 7 0                12
*/

#include <iostream>
#include <list>
using namespace std;

int soma(list<int> &lista)
{
    list<int>::iterator p;
    int soma = 0;

    for (p = lista.begin(); p != lista.end(); ++p)
    {
        soma += *p;
    }

    return soma;
}

int main()
{

    list<int> lista;
    int x;

    cin >> x;
    while (x != 0)
    {
        lista.push_back(x); // insere x no final da lista
        cin >> x;
    }

    cout << soma(lista) << endl;

    return 0;
}