// PROVA - LIST - Soma com critério
/*
Faça uma função que receba uma lista ligada cujo campo info dos nós armazena
números inteiros.

Depois leia uma descrição, que pode ser PAR ou IMPAR, e retorne a soma dos elementos
pares ou ímpares desta lista.

O cabeçalho da função deve ser:

int calcSoma(list<int> lista, string tipo)
Depois, escreva um programa que leia inicialmente vários números inteiros e os armazene
em uma lista ligada. Finalmente, o programa deve fazer uso da função implementada para
mostrar a soma dos elementos pares ou ímpares desta lista.

Entrada:
A entrada consiste de duas linhas
- a primeira irá conter vários números inteiros. Esta linha termina com a entrada 0, que não
deve ser inserida na lista.
- a segunda linha contém uma única palavra, que pode ser PAR ou IMPAR.

Saída:
- a saída, o programa deve mostrar os elementos inseridos na lista e a soma dos elementos pares
ou ímpares, conforme o exemplo abaixo.

Exemplo de entrada:             Exemplos de saída:
2 1 4 3 0                       Elementos inseridos: 2 1 4 3
PAR                             soma = 6

-3 1 5 7 9 2 0                  Elementos inseridos: -3 1 5 7 9 2
IMPAR                           soma = 19
*/

#include <iostream>
#include <string>
#include <list>
using namespace std;

int calcSoma(list<int> &lista, string tipo)
{ // Passagem da lista por referencia - conceito algoritimos 01
    list<int>::iterator p;
    int soma = 0;

    for (p = lista.begin(); p != lista.end(); ++p)
    {
        if (tipo == "PAR" && *p % 2 == 0)
        {
            soma += *p;
        }
        else if (tipo == "IMPAR" && *p % 2 != 0)
        {
            soma += *p;
        }
    }
    return soma;
}

int main()
{
    list<int> lista;
    int num;   // Numeros de entrada
    string op; // Opção = PAR ou IMPAR - equivalente a variavel "tipo" da função!
    list<int>::iterator p;

    cin >> num; // entra com os numeros
    while (num != 0)
    {
        lista.push_back(num); // insere na lista
        cin >> num;
    }

    cin.ignore();
    while (op != "PAR" && op != "IMPAR")
    {
        getline(cin, op); // Escolhe a opção desejada, se é impar ou par
    }

    cout << "Elementos inseridos:";
    for (p = lista.begin(); p != lista.end(); ++p)
    {
        cout << " " << *p;
    }
    cout << endl;

    cout << "soma = " << calcSoma(lista, op); // retorna a soma dos elementos inseridos

    return 0;
}