// LIST - Supermercado
/*
Um gerente de supermercado possui duas listas, sendo a primeira com os códigos de produtos que estão
no estoque, e a segunda com os códigos dos produtos que já estão disponíveis para venda.
Sempre que um produto novo chega, primeiro ele é adicionado no estoque, e depois é movido para venda,
à medida em que os produtos vão sendo vendidos.

Ele precisa de alguém para gerenciar essas listas e contratou você para o serviço.

Entrada:
A primeira linha contém um único inteiro N, que corresponde ao número de operações.
Depois seguem-se N linhas, sendo que cada linha corresponde a uma operação.
Se o primeiro número da linha  for 1, você deverá ler o código do produto e colocá-lo no estoque;
Se for 2, você deverá pegar um elemento do estoque e colocá-lo para venda.

Saída:
A saída deverá mostrar quais elementos estão no estoque e quais estão disponíveis para venda.

Exemplo de entrada:    Exemplo de saída:
5                      Estoque: 33
1 15                   Venda: 19 15
1 19
2
1 33
2
*/

#include <iostream>
#include <list>
using namespace std;

int main()
{

    // Declare varibles:
    list<int> estoque; // FIFO (Fist In First Out) - Estoque
    list<int> venda;   // LIFO (Last In First Out) - venda
    int N, op;         // Operações
    int cod;           // codigo do produto
    int prod;          // produto
    int retirado;      // guarda o estado do produto, se está no estoque ou se foi retirado
    list<int>::iterator p;

    // Data input:
    cin >> N; // N° de operações

    for (int i = 0; i < N; i++)
    {
        cin >> op;

        switch (op)
        {
        case 1:
            cin >> cod;
            estoque.push_back(cod); // add ao estoque;
            break;

        case 2:
            retirado = *estoque.begin();
            estoque.pop_front();
            venda.push_front(retirado);
            break;
        }
    }

    // Output:
    cout << "Estoque:";
    for (p = estoque.begin(); p != estoque.end(); p++)
    {
        cout << " " << *p;
    }

    cout << " " << endl;

    cout << "Venda:";
    for (p = venda.begin(); p != venda.end(); p++)
    {
        cout << " " << *p;
    }

    cout << " " << endl;

    return 0;
}