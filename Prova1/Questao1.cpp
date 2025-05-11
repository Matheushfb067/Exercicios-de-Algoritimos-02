// BUSCA- SEQUENCIAL 2

/*
O ISBN é um número único atribuído a um livro pela Biblioteca Nacional. 

O bibliotecário do Inatel pediu então que você fizesse um programa que registrasse os livros e depois pudesse consultar o ISBN de um livro qualquer.

Armazene os dados de cada livro em um vetor de structs da forma:

struct dado
{
    string nome;
    string isbn;
};
Altere a função de pesquisa sequencial mostrada abaixo para que ela tenha como entrada o nome do livro, e retorne o seu ISBN. 

int sequencial(int vetor[], int tamanho, int x)
{
    bool achou = false; // var aux p/ busca
    int i = 0; // contador
    while (achou == false && i < tamanho)
    {
	if (vetor[i] == x)
            achou = true;
	i++;
    }
    if (achou == true)
	return (i - 1);
    else
	return -1;
}

Faça então um programa que leia o nome de vários livros bem como seus ISBN e os armazene em um vetor de structs. 

Depois, o programa deve ler o nome de um livro X e fazer uso da função modificada para verificar se X está ou não no vetor. Se X for encontrado no vetor, o programa deve retornar o ISBN. Se não, deve retornar o número -1.

Entrada
A entrada consiste de várias linhas:
- a primeira linha contém o nome do primeiro livro;

- a segunda linha tem o ISBN desse livro;

- as linhas a seguir seguirão o mesmo padrão: nome do livro e ISBN;

- a entrada destes dados termina quando for digitado a palavra "fim";

- na última linha será informado o nome X do livro a ser procurado.

Saída
Na saída, o programa deve mostrar o ISBN do livro X, se este for encontrado no vetor, ou uma mensagem dizendo que X não foi encontrado, caso contrário.


Exemplo de entrada:                    Exemplo de saída:
O nome da rosa                         8525056006
8501115827
O velho e o mar
8501115827
O pequeno principe
8595081514
Crime e castigo
8573266465
Admiravel mundo novo
fim
O pequeno principe	8595081514
 
O nome da rosa                         Livro nao encontrado
8501115827
O velho e o mar
8501115827
O pequeno principe
8595081514
Crime e castigo
8573266465
Admiravel mundo novo
8525056006
fim
Marcelo, marmelo, martelo	

*/

//FAZER ESSA QUESTÃO EM CASA - UNICA NÂO FEITA NA PROVA

#include <iostream>
#include <cstring>
using namespace std;

struct dado{
    string nome;
    string isbn;
}; 

int sequencial(string vetor[], int tamanho, string x){
    bool achou = false; // var aux p/ busca
    int i = 0; // contador
    while (achou == false && i < tamanho){	
        if (vetor[i] == x)
            achou = true;	
        i++;
    }
    if (achou == true)	
        return (i - 1);
    else	
        return -1;
} 

int main(){
    
    dado registro[20];
    int i = 0;
    char x;
    
    getline(cin, registro[i].nome);
    getline(cin, registro[i].isbn); 
    
    while(registro[i].nome != "fim"){
        
        getline(cin, registro[i].nome);
        getline(cin, registro[i].isbn);
        i++; 
    }
    
    cin>>x;
    
 //   sequencial(registro, i, x);
    
    return 0;
}