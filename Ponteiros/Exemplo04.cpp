////Exemplo em sala: alocação dinamica
#include <iostream>
using namespace std;

int main (){

    int *v = NULL;
    int N; //tamanho
    int i; //comtador
    int *p = NULL; //ponteiro

    cin >> N;
    v = new int[N]; /*criação de um valor de tamanho infinito a partir de uma entrada
    alocada de forma dinamica*/

    for (i = 0; i < N; i++){//entrando com o vetor
        cin >> v[i];
    }

    p = v;

    for (i = 0; i < N; i++){//mostrando o vetor
        //cout<<v[i]<<endl;
        cout << *p << endl; /*mostra os elementos do vetor, se que varrendo o ponteiro 
        e não o proprio vetor.*/ 
        p++;
    }

    delete [] v;

    return 0; 
}