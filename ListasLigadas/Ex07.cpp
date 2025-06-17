// LIST - União
/*
Faça um programa que leia os dados de duas listas ligadas cujos elementos estão em ordem crescente, crie e
mostre uma terceira lista ligada, formada pela união dos elementos das duas listas originais, também
ordenada em ordem crescente.

Entrada:
A entrada consiste duas linhas:
- A primeira contém vários números inteiros, que devem ser colocados na lista 1. O final desta linha é sinalizado
pelo número 0, que não deve ser inserido na lista 1.

- A segunda também contém vários números inteiros, que devem ser colocados na lista 2. O final desta linha é sinalizado
pelo número 0, que não deve ser inserido na lista 2.


Saída:
Na saída, o programa deve mostrar os elementos da lista 3, formada pela união dos elementos das duas listas, ordenados
em ordem crescente.


Exemplo de entrada:     Exemplo de saída:
1 2 3 5 0               1 2 3 5 7
1 3 5 7 0
*/

#include <iostream>
#include <list>
using namespace std;

int main()
{

    // Declare variables:
    list<int> list1;
    list<int> list2;
    list<int> list3;
    list<int>::iterator lts1; // Ponteiro lista 1
    list<int>::iterator lts2; // Ponteiro lista 2
    list<int>::iterator lts3; // Ponteiro lista 3
    int num;

    // Data input:

    cin >> num;
    while (num != 0)
    {
        list1.push_back(num); // Entrada de dados na lista 1
        cin >> num;
    }

    cin >> num;
    while (num != 0)
    {
        list2.push_back(num); // Entrada de dados na lista 2
        cin >> num;
    }

    // Operation:
    lts1 = list1.begin(); // seta lts1 para o inicio da lista 1
    lts2 = list2.begin(); // seta lts1 para o inicio da lista 2
    int ultimo = 9999999; // para evitar numeros duplicados na lista 3

    while (lts1 != list1.end() && lts2 != list2.end())
    {

        if (*lts1 <= *lts2)
        {
            // Verificação se o numero foi duplicado
            if (*lts1 != ultimo)
            {
                list3.push_back(*lts1); // insere lts1 na lista
                ultimo = *lts1;
            }
            lts1++; // itera a posição de lts1
        }
        else
        {
            // Verificação se o numero foi duplicado
            if (*lts2 != ultimo)
            {
                list3.push_back(*lts2); // insere lts2 na lista
                ultimo = *lts2;
            }
            lts2++; // itera a posição de lts2
        }
    }

    // Add mais elementos caso haja
    while (lts1 != list1.end())
    {
        // Verificação se o numero foi duplicado
        if (*lts1 != ultimo)
        {
            list3.push_back(*lts1); // insere lts1 na lista
            ultimo = *lts1;         // variavel ultimo recebe o valor de lts1
        }
        lts1++; // itera a posição de lts1
    }

    // Add mais elementos caso haja
    while (lts2 != list2.end())
    {
        // Verificação se o numero foi duplicado
        if (*lts2 != ultimo)
        {
            list3.push_back(*lts2); // insere lts2 na lista
            ultimo = *lts2;         // variavel ultimo recebe o valor de lts2
        }
        lts2++; // itera a posição de lts2
    }

    for (lts3 = list3.begin(); lts3 != list3.end(); ++lts3)
    {
        cout << *lts3 << " "; // mostra os elementos da lista com um espaço no final
    }

    return 0;
}