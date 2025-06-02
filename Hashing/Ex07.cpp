//Remoção Exercicio
/*
A remoção de elementos de uma tabela hash cria problemas na busca, pois posições que 
foram removidas interrompem a sequência de sondagem.

Uma forma de evitar é este problema é criar um sinalizador de status de cada posição. Assim, 
a tabela hash irá armazenar em cada posição, não só a chave, mas também o seu status.

Para remover um elemento da tabela, basta fazer a busca e, se este for encontrado, basta alterar 
o status dele para 2, como mostrado no pseudocódigo abaixo:

HASH_REMOVE(T,m,k)
    j = HASH_SEARCH(T,m,k)
    if(j != -1)
       T[j].status = 2
       T[j].k = -1
       return 0 // consegui remover
    else
       return -1 // k nao esta na tabela
A função de remoção deve ter o seguinte cabeçalho:

int hash_remove(dado t[], int m, int k)
Sua tarefa é então implementar a função hash_remove(). 

Faça então um programa que leia o tamanho da tabela e insira várias chaves nela. Depois, o programa 
deve ler a chave que deve ser removida, e mostrar a tabela depois da remoção.

Entrada:
A entrada consiste de três linhas:

- a primeira linha irá conter o tamanho m da tabela (um número inteiro)
- a segunda linha consiste de vários inteiros positivos, correspondentes aos valores das chaves a 
serem inseridas. Esta linha termina com o número 0, que não deve ser inserido na tabela.
- a última linha tem um único inteiro, que corresponde à chave que queremos remover.

Saída:
Na saída, o programa deve a tabela depois da remoção da chave.

Exemplos de entrada:            Exemplos de Saída:
11                              22 88 -1 -1 4 -1 28 17 59 31 10
10 22 31 4 15 28 17 88 59 0 
15	
11                              22 88 -1 -1 4 15 28 17 59 31 10
10 22 31 4 15 28 17 88 59 0
20	
*/

#include <iostream>
using namespace std;

struct dado{
    int k;
    int status;// 0-vazio, 1-ocupado, 2-removido
};

int hash_aux(int k, int m)
{
    int h;
    h =  k % m; 
    if (h < 0)
        h = h + m; // se negativo, ajusta para o intervalo [0, m-1]
    return h;
}

int hash1(int k, int i, int m)
{
    return (hash_aux(k, m) + i) % m; // função hash primitiva
}

int hash_insert(dado t[], int k, int m)
{
    int i;
    int j;
    
    i = 0;
    do 
    {
        j = hash1(k, i, m);
        if (t[j].status != 1) 
        {
            t[j].k = k;
            t[j].status = 1; // ocupado
            return j; // posição onde a chave foi inserida
        }
        i++;
    } while (i != m); // enquanto não encontrar a chave ou tabela cheia
    return -1; // tabela cheia
}

int hash_search(dado t[], int k, int m)
{
    int i;
    int j;
    
    i = 0;
    do 
    {
        j = hash1(k, i, m);
        if (t[j].k == k && t[j].status == 1) // se encontrado
            return j; // posição onde a chave foi encontrada
        i++;
    } while (t[j].status != 0 && i != m); // enquanto não encontrar a chave ou não varrer toda a tabela
    return -1; // chave não encontrada
}

//--------------------------------------//------------------------------------//

int hash_remove(dado T[], int m, int k){
    int j = hash_search(T, k, m);
    
    if(j != -1){
        T[j].status = 2;
        T[j].k = -1;
        return 0;
    }
    else
        return -1;
}

int main(){
    
    int k, m; // tamanho da tabela
    dado T[100]; // tabela de hash
    int i; // contador
    int pos; // posição onde a chave foi encontrada
    int x;//chave que queremos remover
    
    cin>>m; 

     // Inicializando a tabela
    for (i = 0; i < m; i++)  
    {
        T[i].k = -1;
        T[i].status = 0; // 0:vazio
    }

    cin>>k;
    while(k != 0)
    {
        hash_insert(T, k, m);
        cin>>k;
    }
    
    cin>>x;
    
    hash_remove(T, m, x);
    
    for (i = 0; i < m; i++)
        cout << T[i].k << " ";
    cout << endl;
    
    return 0;
}