//Remoção
/*Remoção de um elemento inserido atraves do hashing
exemplo dados em aula, sem enunciado, apenas explicação e 
resolução do professor!*/

#include <iostream>
using namespace std;

struct dados
{
    int k; // chave
    int status; // 0:vazio, 1:ocupado, 2:removido
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

int hash_insert(dados t[], int k, int m)
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

int hash_search(dados t[], int k, int m)
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

int main()
{
    int m = 9; // tamanho da tabela
    dados T[100]; // tabela de hash
    int i; // contador
    int pos; // posição onde a chave foi encontrada

    // Inicializando a tabela
    for (i = 0; i < m; i++)  
    {
        T[i].k = -1;
        T[i].status = 0; // 0:vazio
    }

    // Inserindo chaves na tabela
    hash_insert(T, 22, m);
    hash_insert(T, 31, m);    
    
    //-------------------------------------//-------------------------------------//
    
    //Removendo o 22
    pos = hash_search(T, 22, m);
    T[pos].status = 2;
    T[pos].k = -1;

    cout<<"pos = "<<pos<<endl;

    //PROBLEMA procurando pelo 31
    pos = hash_search(T, 31, m);
    if(pos == -1)
        cout<<"Chave não encontrada"<<endl;
    else
        cout<<"Chave encontrada na posicao "<<pos<<endl;
        
    //-------------------------------------//-------------------------------------//
    
    // Exibindo a tabela
    for (i = 0; i < m; i++)
        cout << T[i].k << " ";
    cout << endl;

    return 0;
}