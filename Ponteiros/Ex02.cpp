//PONT - Alocação dinâmica de memória 2
/*
Defina uma struct que armazene quatro notas de uma pessoa e a média destas notas.
Depois faça um programa que use um ponteiro para alocar memória para um vetor desta 
struct, leia 4 notas de várias, e as armazene no vetor alocado.

Por fim, o programa deve calcular a média das notas de cada um, armazená-la na struct 
e mostrar a média da turma, com 2 casas decimais.

IMPORTANTE: não se esqueça de desalocar a memória ocupada pela struct ao final do programa!  

Entrada:
A entrada consiste de várias linhas:
- a primeira consiste de um único inteiro N, que corresponde ao número de alunos
- seguem -se N linhas, cada uma com 4 números inteiros, que correspondem às notas de cada 
aluno.

Saída:
Na saída, o programa deve mostrar a média das médias dos alunos, com 2 casas decimais.


Exemplo de entrada:        Exemplo de saída:
2                          68.25
40 32 51 70
78 95 80 100	
*/

#include <iostream>
#include <iomanip>
using namespace std; 

struct dado{
    int n1, n2, n3, n4; 
    double md;//media
};

int main(){

    dado *v = NULL;//ponteiro
    int n; //Numero de alunos
    int i; // contador
    int soma = 0;
    
    cin >> n;
    
    v = new dado [n];//alocação 
    
    for(i = 0; i < n; i++){
        cin >> v[i].n1 >> v[i].n2 >> v[i].n3 >> v[i].n4;
        soma += v[i].n1 + v[i].n2 + v[i].n3 + v[i].n4;
    }
    
    v -> md = (double)soma / (n * 4); //Casting variavel soma
    
    cout<<fixed<<setprecision(2);
    cout <<  v->md << endl;
    
    delete v;
    
    return 0;
}