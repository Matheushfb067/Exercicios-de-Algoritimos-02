//HASH - REMOVER TODAS DOUBLE HASHING
/*
Faça um programa que leia o tamanho desejado m para uma tabela hash 
e insira várias chaves k nesta.

Depois, o programa deve ler uma outra chave R, e remover todas as 
ocorrências desta na tabela.

Finalmente, o programa deve mostrar a tabela depois das remoções. 

Use double hashing como mecanismo de sondagem para este problema.

Entrada:
A entrada consiste de três linhas:
- a primeira linha irá conter o tamanho m da tabela (um número inteiro)
- a segunda linha consiste de vários inteiros positivos, correspondentes 
aos valores das chaves a serem inseridas. Esta linha termina com o número 0, 
que não deve ser inserido na tabela.

- a última linha tem um único inteiro, que corresponde à chave R que queremos 
remover.

Saída:
Na saída, o programa deve mostrar a tabela depois das remoções de todas as ocorrências 
de R. Os valores vazios da tabela devem ser mostrados com o valor -1

Exemplo de entrada:                	  Exemplo  de saída:
13                                    88 -1 15 28 4 31 17 59 -1 22 -1 -1 -1
10 22 10 31 4 15 28 17 10 88 59 0
10
*/

#include <iostream> 
using namespace std;

struct dado{
    int k;
    int status;
};

int hash_aux(int k, int m){
    int h; 
    
    h = k % m;
    
    if(h < 0)
        h += m;
        
    return h;
}

int hash2(int k, int m){
    int h;
        
    h = 1 + (k % (m - 1));

    return h;
}

int dhash(int k, int m, int i){
    int h; 

    h = (hash_aux(k, m) + i * hash2(k, m)) % m;

    if(h < 0)
        h += m;

    return h;
}

int hash_insert(dado t[], int m, int k)
{
    int j, i = 0;//contadores

    do
    {
        j = dhash(k, m, i);
        if (t[j].status != 1)
        {
            t[j].k = k;
            t[j].status = 1;
            return j;
        }
        else
            i = i + 1;
    }while (i != m);

    return -1;
}

int hash_search(dado t[], int m, int k){

    int i = 0; 
    int j;

    do{
        j = dhash(k, m, i);
        if(t[j].k == k)
            return j;
        i += 1;
    }while(t[j].status != 0 && i < m);

    return -1;
}

int hash_remove(dado t[], int m, int k){
    int j; 

    j = hash_search(t, m, k);
    if(j != -1){
        t[j].status = 2;
        t[j].k = -1;
        return 0; //Conseguiu remover
    }
    else 
        return -1; //k não está na tabela;
}

int main(){
    
    dado T[100];
    int k, r, m; //chaves, tamanho da tabela
    
    cin >> m;
    
    //Inicialização de todas as posições do vetor de structs T[] com 0
    for(int i = 0; i < m; i++){
        T[i].status = 0;
        T[i].k = -1;
    }
    
    cin >> k; 

    while(k != 0){
        hash_insert(T, m, k);
        cin >> k;
    }
    
    //lê a chave a ser removida
    cin >> r;
    
    //Varre o vetor para encontrar r e remover da tabela
    while(hash_remove(T, m, r) == 0);
    
    for(int i = 0; i < m; i++){
        if(T[i].status != 1)
            cout << "-1 ";
        else
            cout << T[i].k << " ";  
    }
    cout << endl;  

    return 0;
}