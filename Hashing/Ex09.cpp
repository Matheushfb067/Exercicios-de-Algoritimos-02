//Juntando Tudo
/*
Faça um programa que insira, remova, pesquise e liste os elementos de uma 
tabela, segundo o menu abaixo:

1: inserir

2: pesquisar

3: remover

4: listar

5: sair do programa

USE O DOUBLE HASHING PARA ESTE PROBLEMA.

Entrada:
A entrada consiste de várias linhas:
- a primeira linha irá conter o tamanho m
 da tabela (um número inteiro)

- as demais linhas podem conter um ou dois inteiros, dependendo da opção do menu escolhida:

    * se o  opção for 1 (inserir), o programa deve ler o valor da chave k e inseri-la no programa. 
    Nenhuma saída deverá ser dada neste caso.

    * se a opção for 2 (pesquisar), o programa deve ler o valor da chave k e mostrar a posição em 
    que esta está na tabela hash, ou mostrar -1, caso não esteja;

    * se a opção for 3 (remover), o programa deve ler o valor da chave k e removê-la da tabela hash. 
    Nenhuma saída deverá ser dada neste caso.

    * se a opção for 4 (listar a tabela), o programa deve mostrar os valores das chaves na tabela, 
    em uma única linha, com as chaves separadas por espaços.

    * se a opção for (sair), o programa deverá ser encerrado.

Saída:
Na saída, o programa deve efetuar a operação solicitada.


Exemplos de entrada:       Exemplos  de saída:
11                         22 -1 59 17 4 15 28 88 -1 31 10
1 10                       5
1 22                       5
1 31                       -1
1 4                        22 -1 59 17 -1 15 28 88 -1 31 10
1 15
1 28
1 17
1 88
1 59 
4
2 15
3 4
2 15
2 4
4
5	
*/

#include <iostream>
using namespace std;

struct dado{
    int k;
    int status;// 0-vazio, 1-ocupado, 2-removido
};

int h1(int k, int m){
    int h;
    
    h = k % m;
    if(h < 0)
        h = h + m;
        
    return h;
}

int h2(int k, int m){
    int h = k % (m - 1);
    if (h < 0)
        h += (m - 1);
    return 1 + h;
}

int dhash(int k, int m, int i){
    int h;
    
    h = (h1(k, m) + (i * h2(k, m))) % m;
    if(h < 0)
        h = h + m;
    
    return h;
}

int hash_insert(dado t[], int k, int m)
{
    int i;
    int j;
    
    i = 0;
    do 
    {
        j = dhash(k, m, i);
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
        j = dhash(k, m, i);
        if (t[j].k == k && t[j].status == 1) // se encontrado
            return j; // posição onde a chave foi encontrada
        i++;
    } while (t[j].status != 0 && i != m); // enquanto não encontrar a chave ou não varrer toda a tabela
    return -1; // chave não encontrada
}

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
    
    int m; //tamanho da tabela
    int op;//opção
    int k;
    dado t[100];
    
    cin>>m;
    
    // Inicializando a tabela
    for (int i = 0; i < m; i++)  
    {
        t[i].k = -1;
        t[i].status = 0; // 0:vazio
    }
    
    //cout<<"1: inserir"<<endl;
    //cout<<"2: pesquisar"<<endl;
    //cout<<"3: remover"<<endl;
    //cout<<"4: listar"<<endl;
    //cout<<"5: sair do programa"<<endl;
   
   cin>>op;
   
   while(op != 5){
       switch(op){
           
        case 1: 
            cin>>k;
            hash_insert(t, k, m);
            break; 
        case 2: 
            cin>>k;
            cout<<hash_search(t, k, m)<<endl;
            break; 
        case 3: 
            cin>>k;
            hash_remove(t, m, k);
            break; 
        case 4: 
            for (int i = 0; i < m; i++){
                if(t[i].status == 1)
                    cout << t[i].k << " ";
                else
                    cout<<-1<<" ";
            }
            cout<<endl;
            break;
        }
        cin>>op;
   }
   
    return 0;
}