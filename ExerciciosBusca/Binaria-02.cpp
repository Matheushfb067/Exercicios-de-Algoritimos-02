//Onde está o estudante?
/*
Na cidade de Morangoleste, existe um dormitório enorme. Acredita-se que existem cerca de 10.000 
estudantes morando ali. Imagine se eles fossem procurar um estudante de forma sequencial, gastariam 
muito tempo. Então, o responsável pelo dormitório teve uma ideia: armazenar os números de matrícula em um sistema, 
e a posição em que a matrícula ficasse seria o número do corredor em que o estudante deveria ficar.

Entrada: 

A entrada consiste de 3 linhas:
- a primeira irá conter um único número inteiro N (1<=N<=10000), que indica a quantidade de alunos;

- a segunda linha tem N inteiros, que correspondem aos números de matrículas de cada aluno. Estas serão inseridas em ordem crescente.

- a terceira linha terá apenas um inteiro X, referente à matrículado que do aluno o qual se quer saber o corredor em que irá ficar.

Saída:
Na saída, o programa deve mostrar "Corredor Y",em que Y é o corredor que está o estudante. Caso não seja encontrado o mesmo, deve-se mostrar "Nao localizado".


Exemplo de entrada:                  Exemplo de saída:
4
567 1011 1241 9932                   Corredor 0
567	

6
963 1552 1562 2135 2883 3060         Nao localizado
1526	  
*/

#include <iostream> 
using namespace std;

int binaria(int vetor[], int tamanho, int x){
    bool achou;
    int baixo, meio, alto;

    baixo = 0;
    alto = tamanho - 1;
    achou = false; 

    while((baixo <= alto) && (achou == false)){
        meio = (baixo + alto) / 2;
        if(x < vetor[meio]) {
          alto = meio - 1;
        }
        else{
            if(x > vetor[meio]) {
              baixo = meio + 1;
            }
            else {
              achou = true;
            }
        }
    }
    if(achou) {
      return meio;
    }
    else {
      return -1;
    }
}

int main(){
    
    //Declare Variables: 
    int matricula[10], num_alunos, x;
    int resultado = -1;
    
    //Data input: 
    do{
        //cout<<"Entre com o numero de alunos: ";
        cin>>num_alunos;
    }while(num_alunos > 20);
    
    //cout<<"Entre com as matriculas: ";
    for(int i = 0; i < num_alunos; i++)
        cin>>matricula[i];
    
    //cout<<"Entre com a matricula que se quer encontrar: ";
    cin>>x;
    
    //Operation:
    resultado = binaria(matricula, num_alunos, x);
    
    if(resultado != -1)
        cout<<"Corredor "<<resultado<<endl;
    else
        cout<<"Nao localizado";
        
            
    return 0; 
}

