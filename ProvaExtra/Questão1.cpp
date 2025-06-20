// PROVA - LIST - MAIORES DE IDADE
/*
Um clube deseja cadastrar todos os seus sócios e contratou você para a tarefa.

No momento, ele deseja apenas saber a idade de seus sócios, pois pretende fazer
um evento no Carnaval, mas só para maiores de idade.

A sua tarefa é então ler inicialmente o número de sócios do clube (N), e depois as
idades de cada sócio.

As idades devem ser colocadas em uma lista ligada, e você deve fazer uma função que
tome um ponteiro para esta lista, e retorne o número de sócios com mais de 18 anos.

A função deve ter o seguinte cabeçalho:

int nMaiores(list <int> lista)

Entrada:
- A primeira linha consiste de um único inteiro N, que corresponde ao número de sócios
do clube.
- Na segunda linha tem-se N inteiros, que representam a idade de cada sócio.

Saída:
O programa deve imprimir o número de sócios com mais de 18 anos.


Exemplo de entrada:        Exemplo de saída:
6                          3 socios com mais de 18 anos
12 14 8 60 24 19

*/

#include <iostream>
#include <list>
using namespace std;

int nMaiores(list<int> &lista)
{                          // Passando lista por referencia - conceito de algoritimos 01
    list<int>::iterator p; // declarando ponteiro p
    int count = 0;         // contador

    for (p = lista.begin(); p != lista.end(); ++p)
    {
        if (*p > 18)
            count++;
    }
    return count;
}

int main()
{
    list<int> lista;
    int N;     // numero de socios do clube
    int idade; // idades do membros do club

    cin >> N; // leitura do numero de socios do clube

    for (int i = 0; i < N; i++)
    {
        cin >> idade;           // leitura da idade
        lista.push_back(idade); // Inserção na lista
    }

    // Saida de Dados
    cout << nMaiores(lista) << " socios com mais de 18 anos" << endl;

    return 0;
}