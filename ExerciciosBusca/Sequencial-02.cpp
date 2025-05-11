//
/*
A Robélia, chefe das secretárias do Inatel está querendo organizar o registro acadêmico 
dos alunos, e pediu para você ajudá-la.
Ela precisa de um sistema de armazene o nome de cada aluno, bem como seu curso e número de 
matrícula. Depois ela quer digitar o nome de um aluno, e o sistema deve retornar o curso e o 
nome de matrícula deste aluno.
Será que você consegue ajudá-la?

Entrada:
A entrada consiste de várias linhas:
- a primeira irá conter um único número inteiro N (1<=N<=10000), que indica a quantidade de alunos;
- Para cada aluno, será digitadas três linhas:
  - a primeira irá conter o nome do aluno;
  - segunda, o seu curso;
  - a terceira, seu número de matrícula.

A última entrada será o nome do aluno a ser consultado.

Saída:
Na saída, o programa deve mostrar o nome do aluno, seu número de matrícula e curso do aluno. Se o 
aluno não for encontrado, seu programa deve mostrar a mensagem "Aluno nao encontrado".

DICA: armazene os dados de cada aluno em um vetor de structs.

Exemplos de Entrada:          Exemplos de Saída:
4                             Marcela Araujo
Jose Carlos                   Software
Biomedica                     112
335
Maria Antonia
Telecom
10347
Marcela Araujo
Software
112
Andre de Souza
Automacao
543
Marcela Araujo

4                              Aluno nao localizado
Jose Carlos
Biomedica
335
Maria Antonia
Telecom
10347
Marcela Araujo
Software
112
Andre de Souza
Automacao
543
Jesse Rodrigues
*/

#include <iostream>
#include <cstring>
using namespace std;

struct registro{
    string nome;
    string curso;
    int num_matricula;
};

int main(){

    registro dados[30];
    string nome;
    int n, i, j;

    do{
        cin>>n;
    }while(n < 1 || n > 30);

    cin.ignore();

    for(i = 0; i < n; i++){
        getline(cin, dados[i].nome);
        getline(cin, dados[i].curso);
        cin>>dados[i].num_matricula;
        cin.ignore();
    }

    getline(cin, nome);

    for(j = 0; j < i; j++){
        if(dados[j].nome == nome){
            cout<<dados[j].nome<<endl;
            cout<<dados[j].curso<<endl;
            cout<<dados[j].num_matricula<<endl;
            return 0;
        }
    }

    cout<<"Aluno nao localizado"<<endl;

    return 0; 
}