//Dados dos Atletas
/*
Queremos guardar alguns dados ds atletas de uma equipe em uma tabela hash.

Os dados são:

- nome

- idade

- peso

- altura

Desta forma, podemos criar uma struct para armazenar estes dados:

struct info
{<br>    string nome;<br>    int idade;<br>    float peso;<br>    float altura; <br>};
E a struct dado ficaria assim:

struct dado
{<br>    info atleta; // nome, idade, peso e altura de cada atleta<br>    int k; // chave<br>    int status; // 0:vazio, 1:ocupado, 2:removido<br>};
Repita o problema anterior para um esquema de hashing que gere a chave a partir do nome de cada atleta.

Como no exercício anterior, a chave deve ser calculada como a soma dos valores ASCII 
de cada um de seus caracteres.

Por exemplo, "Inatel" gera uma chave k = 605.

USE O DOUBLE HASHING PARA ESTE PROBLEMA.

Entrada:
A entrada consiste de várias linhas:
- a primeira linha irá conter o tamanho m
 da tabela (um número inteiro)
- as demais linhas dependem da opção do menu escolhida:
    * se o  opção for 1 (inserir), o programa deve ler as informações a serem armazenadas para cada atleta 
    (nome, idade, peso e altura) e inseri-las na tabela. Nenhuma saída deverá ser dada neste caso.

    * se a opção for 2 (pesquisar), o programa deve ler o nome do atleta a ser pesquisado e mostrar os 
    dados deste atleta, ou mostrar a mensagem "Atleta nao cadastrado", caso não esteja;

    * se a opção for 3 (remover), o programa deve ler o nome do atleta e removê-lo da tabela hash. Nenhuma 
    saída deverá ser dada neste caso.

    * se a opção for 4 (listar a tabela), o programa deve mostrar todas as informação contidas na tabela, pulando 
    uma  linha entre cada atleta. 

    * se a opção for (sair), o programa deverá ser encerrado.

Saída:
Na saída, o programa deve efetuar a operação solicitada.

Exemplos de entrada:         Exemplos de Saída:
11                           Cassio
1                            28
Neymar Jr                    80.1
34                           1.95
63.5
1.72                         Pele nao encontrado
1
Cristiano Ronaldo            Nome: Gabigol
35                           Idade: 32
68.9                         Peso: 78.3
1.81                         Altura: 1.80
1
Mbape                        Nome: Mbape
25                           Idade: 25 
67.4                         Peso: 67.4
1.75                         Altura: 1.75
1
Cassio                       Nome: Neymar Jr 
28                           Idade: 34
80.1                         Peso: 63.5
1.95                         Altura: 1.72
1
Gabigol                      Nome: Cristiano Ronaldo
32                           Idade: 35
78.3                         Peso: 68.9
1.80                         Altura: 1.81
2
Cassio
2 Pele
3
Cassio
4
5
*/

#include <iostream>
#include <string>

using namespace std; 

struct dado{
  string info;     // informacao
  int k;           // chave
  int status;      // 0: vazio, 1:ocupado, 2:removido
};

int h1(int k, int m) {
  int h = k % m;
  if(h < 0)
    h = h + m;

  return h;
}

int h2(int k, int m) {
  int h = 1 + (k % (m - 1));
  if (h < 0) {
    h += m;
  }
  return h;
}

int dhash(int k, int m, int i) {
  return (h1(k, m) + i * h2(k, m)) % m;
}

int hash_insert(dado t[], int k, int m, string nome) {
  int i;
  int j;

  i = 0;
  do {
    j = dhash(k, m, i);
    if (t[j].status != 1) {
      t[j].k = k;
      t[j].status = 1;          // ocupado
      t[j].info = nome;
      return j;                 // posição onde a chave foi inserida
    }
    i++;
  } while (i != m);             // enquanto não encontrar a chave ou tabela cheia
  return -1;                    // tabela cheia
}

int hash_search(dado t[], int k, int m)
{
  int i = 0;
  int j;

  do {
    j = dhash(k, m, i);
    if (t[j].k == k)                         // se encontrado
      return j;                              // posição onde a chave foi encontrada
    i++;
  } while (t[j].status != 0 && i < m);       // enquanto não encontrar a chave ou não varrer toda a tabela
  return -1;                                 // chave não encontrada
}

int hash_remove(dado t[], int m, int k){
  int j = hash_search(t, k, m);

  if(j != -1){
      t[j].status = 2;
      t[j].k = -1;
      t[j].info = "vazio";
      return 0;
  }
  else
      return -1;
}

int main(){

  int m;          //tamanho da tabela
  int op;
  dado t[100];    //tabela
  int k;          //chave
  int pos = -1;   //variavel que armazena a posição
  string nome;    //variavel que armazena o nome

  cin >> m;

  // Inicializando a tabela
  for (int i = 0; i < m; i++) {
    t[i].k = -1;
    t[i].status = 0; // 0:vazio
    t[i].info = "vazio";
  }

  cin >> op;

  while(op != 5){
    switch(op){
      case 1:
        k = 0;
        getline(cin >> ws, nome);
        for (int i = 0; i < nome.size(); i++){
          k += (int)nome[i];
        }
        hash_insert(t, k, m, nome);
        break; 

      case 2: 
        k = 0;
        getline(cin >> ws, nome);
        for (int i = 0; i < nome.size(); i++){
          k += (int)nome[i];
        }
        pos = hash_search(t, k, m);
        if(pos != -1){
            cout << nome << " encontrado na posicao " << pos << endl;
        } else {
          cout << nome << " nao encontrado" << endl;
        }
        break; 

      case 3: 
        k = 0;
        getline(cin >> ws, nome);
        for (int i = 0; i < nome.size(); i++){
          k += (int)nome[i];
        }
        hash_remove(t, m, k);
        break; 

      case 4:
        for (int i = 0; i < m; i++){
          cout << t[i].info << endl;
        }
        break;
    }
    cin>>op;
  }

  return 0; 
}