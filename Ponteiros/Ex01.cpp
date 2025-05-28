//PONT - Alocação dinâmica de memória
/*
Defina uma struct que armazene quatro notas de uma pessoa e a média destas notas.
Depois faça um programa que use um ponteiro para alocar memória para esta struct, 
leia 4 notas, armazenando-as na struct alocada.

Por fim, o programa deve calcular a média das notas, armazená-la na struct e mostrar 
a média calculada, com 2 casas decimais.

IMPORTANTE: não se esqueça de desalocar a memória ocupada pela struct ao final do 
programa!  

Entrada:
A entrada consiste de 4 números inteiros, que correspondem às notas do aluno.

Saída:
Na saída, o programa deve mostrar a média das notas, com 2 casas decimais.

Exemplo de entrada:           Exemplo de saída:
40 32 51 70	                  48.25
*/

#include <iostream>
#include <iomanip>
using namespace std; 
 
struct dado {
    double nota1, nota2, nota3, nota4;
    double md;
};

int main(){
    
    dado *nts = NULL;
    
    nts = new dado;
    
    cin >> nts->nota1 >> nts->nota2 >> nts->nota3 >> nts->nota4;
    
    nts->md = (nts->nota1 + nts->nota2 + nts->nota3 + nts->nota4)/4.0;
    
    cout << fixed << setprecision(2) << nts->md << endl;
    
    return 0; 
}