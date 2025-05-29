//PONT - Acima da média
/*
Faça um programa que leia inicialmente o tamanho N de um vetor de inteiros, 
que deve ser alocado dinamicamente.

Depois, o programa deve ler N números inteiros e os inseri-los no vetor.

Finalmente, varra o vetor usando um ponteiro, e mostre quantos elementos 
deste vetor são iguais ou maiores que a média. 

IMPORTANTE: Esta é uma questão que tem por objetivo avaliar se você sabe 
mexer com ponteiros. Desta forma, você deve obrigatoriamente fazer alocação 
dinâmica de memória e usar ponteiros para fazer a verificação da quantidade 
de elementos maiores ou iguais à média, caso contrário, sua solução não será 
aceita.

Entrada:
A entrada consiste de 2 linhas:
- a primeira linha contém apenas um inteiro N, que corresponde ao tamanho do vetor
- na segunda linha, tem-se N inteiros, separados por um espaço em branco.

Saída:
Na saída, o programa deve mostrar a quantidade de elementos com valor igual ou maior 
que a média dos elementos inseridos no vetor, como no exemplo abaixo.


Exemplo de entrada:         Exemplo de saída:
4                           2 elementos iguais ou maiores que a media
40 32 51 70	
*/

#include <iostream>
using namespace std; 

int main(){
    
    int n; //tamanho do vetor
    int *v = NULL; //poteiro vetor
    int *p = NULL; //Ponteiro varredura
    int i; //contador
    double media;
    
    cin >> n; 
    
    v = new int[n]; //alocação dinamica
    
    double soma = 0;
    
    p = v;//coloca 'p' na primeira posição do vetor
    
    for(i = 0; i < n; i++){
        cin >> *p;
        soma += *p;
        p++;
    }
    
    media = soma / n;
  
    //reatribiu 'p' `a primeira posição do vetor
    p = v;
    
    int cont = 0;  //variavel contadorá
    
    //Conta quantos elementos são maiores que a média e incrementa o vetor
    for(i = 0; i < n; i++){
        if(*p >= media)
            cont++;
        p++;    
    }
    
    cout << cont << " elementos iguais ou maiores que a media" <<endl;
    
    delete [] v;
    
    return 0;
}