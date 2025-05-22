//Guardando Nomes
/*
Repita o problema anterior para um esquema de hashing que gere a chave a partir da informação a ser armazenada.
A informação vai ser uma string de até 50 caracteres, e a chave deve ser calculada como a soma dos valores ASCII 
de cada um de seus caracteres.
Por exemplo, "Inatel" gera uma chave k = 605.

A struct para armazenar os dados deve ser modificada para:

struct dado
{<br>    string info; // informacao<br>    int k; // chave<br>    int status; // 0: vazio, 1:ocupado, 2:removido<br>};

USE O DOUBLE HASHING PARA ESTE PROBLEMA.

Entrada:

A entrada consiste de várias linhas:

- a primeira linha irá conter o tamanho m
 da tabela (um número inteiro)
- as demais linhas dependem da opção do menu escolhida:

    * se o  opção for 1 (inserir), o programa deve ler a informação a ser armazenada (uma string) e inseri-la no programa. 
    Nenhuma saída deverá ser dada neste caso.
    * se a opção for 2 (pesquisar), o programa deve ler a informação a ser pesquisada e mostrar a posição em que esta está 
    na tabela hash, ou mostrar -1, caso não esteja;
    * se a opção for 3 (remover), o programa deve ler a informação a ser removida e removê-la da tabela hash. Nenhuma saída 
    deverá ser dada neste caso.
    * se a opção for 4 (listar a tabela), o programa deve mostrar todas as informação contidas na tabela, uma por linha. 
    * se a opção for (sair), o programa deverá ser encerrado.

Saída:
Na saída, o programa deve efetuar a operação solicitada.

Exemplos de entrada:          Exemplos de Saída:
11                            gol.mp4 nao encontrado
1                             documento.doc encontrado na posicao 2
www.inatel.br                 www.inatel.br
1                             imagem.jpg
imagem.jpg                    vazio
1                             vazio
filme1.mov                    vazio
1                             vazio
documento.                    vazio
2                             vazio
gol.mp4                       vazio
2                             vazio
documento.doc                 filme1.mov
3
documento.doc
4
5
*/

#include <iostream>
using namespace std; 

struct dado{
    string info; // informacao
    int k; // chave
    int status; // 0: vazio, 1:ocupado, 2:removido
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
    
    int m;//tamanho da tabela
    int op;
    dado t[100];//tabela
    int i;
    int k; //chave
    int pos = -1;//variavel que armazena a posição
    
    cin>>m;
    
    // Inicializando a tabela
    for (int i = 0; i < m; i++)  
    {
        t[i].k = -1;
        t[i].status = 0; // 0:vazio
    }
    
    cin>>op;
   
    while(op != 5){
       switch(op){
           
        case 1: 
            getline(cin, t[i].info);
            hash_insert(t, k, m);
            break; 
            
        case 2: 
            cin>>k;
            if(pos != -1){
                pos = hash_search(t, k, m);
                cout<<k<<"econtrado na posição "<<pos<<endl;
            }
            else 
                cout<<pos<<endl;
                
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