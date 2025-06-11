// LIST - Procurar na lista
/*
Faça uma função que receba em sua entrada um ponteiro para uma lista ligada
que armazena números inteiros, e um número inteiro, e retorne true se este estiver
na lista, e false caso contrário. O cabeçalho desta função deve ser:

bool encontrar(list<int> lista, int x)
Depois, faça um programa que vá lendo vários números e os inserindo na lista, e
em seguida leia o número a ser pesquisado. Este deve mostrar a mensagem "Encontrado",
se o número a ser pesquisado estiver na lista, e "Nao encontrado", caso contrário

Entrada:
A entrada consiste duas linhas.
- A primeira contém vários números inteiros, que devem ser colocados na lista. O final
  desta linha é sinalizado pelo número 0, que não deve ser inserido na lista.
- A segunda linha contém apenas um inteiro N, que é o número a ser pesquisado na lista

Saída:
Na saída, o programa deve mostrar "Encontrado" se N estiver na lista, e "Nao encontrado",
caso contrário.


Exemplo de entrada:         Exemplo de saída:
1 2 3 0                     Encontrado
2

2 -1 4 7 0                  Nao encontrado
3
*/

#include <iostream>
#include <list>
using namespace std;

bool encontrar(list<int> &lista, int x) // passagem por referencia da variavel lista
{
    list<int>::iterator p;
    bool achou = false;

    for (p = lista.begin(); p != lista.end(); ++p)
    {
        if (*p == x)
        {
            achou = true;
        }
    }

    return achou;
}

int main()
{
    list<int> lista;
    int num; // numero de inserção
    int N;   // numero que se deseja encontrar
    bool encontrou = false;

    cin >> num;
    while (num != 0)
    {
        lista.push_back(num);
        cin >> num;
    }

    cin >> N;

    encontrou = encontrar(lista, N);

    if (encontrou)
    {
        cout << "Encontrado" << endl;
    }
    else
    {
        cout << "Nao encontrado" << endl;
    }

    return 0;
}
