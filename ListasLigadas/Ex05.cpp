// LIST - Contar nós
/*
Faça uma função que receba em sua entrada um ponteiro para uma lista ligada,
e retorne o número de nós nesta lista. Esta função deve ter o seguinte cabeçalho:

int contar(list<int> lista)
Depois, faça um programa que vá lendo vários números e os inserindo na lista,
e em seguida mostre o número de nós desta lista.

Entrada:
A entrada consiste vários números inteiros, que devem ser colocados na lista.
O final da entrada é sinalizado pelo número 0, que não deve ser inserido na lista.

Saída:
Na saída, o programa deve mostrar o número de nós que foram inseridos na lista.

Exemplo de entrada:         Exemplo de saída:
1 4 2 6 5 4 7 0             7
2 -1 4 7 3 0                5
*/

#include <iostream>
#include <list>
using namespace std;

int contar(list<int> &lista)
{
    list<int>::iterator p;
    int contador = 0;

    for (p = lista.begin(); p != lista.end(); ++p)
    {
        contador++;
    }

    return contador;
}

int main()
{

    list<int> lista;
    int x;

    cin >> x;
    while (x != 0)
    {
        lista.push_back(x);
        cin >> x;
    }

    cout << contar(lista) << endl;

    return 0;
}