// Leia 5 numeros e insira na lista:

#include <iostream>
#include <list>
using namespace std;

int main()
{
    // pilha é um ponteiro e só armazena numero inteiros (neste caso)
    list<int> lista; // pilha -> NULL
    int x;
    list<int>::iterator p; // ponteiro iterador!

    for (int i = 0; i < 5; i++)
    {
        cin >> x;
        lista.push_back(x);
    }

    // for para varrer a lista
    // for = INICIALIZAÇÃO // TESTE DE PARADA // INCREMENTO
    for (p = lista.begin(); p != lista.end(); p++) // lista.end() aponta para o o espaço de memoria após o ultimo elemento da lista
    {
        cout << *p << endl;
    }

    return 0;
}