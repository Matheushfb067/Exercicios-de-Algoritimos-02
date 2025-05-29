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

