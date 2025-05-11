//Controle de acesso
/*
Com o avanço da tecnologia, muitos empresas adotaram o método do cartão magnético para controle de acesso aos 
seus ambientes. Você deve construir um programa verifica se uma ID( identificação) tem acesso ao ambiente. Antes 
de ser informado a ID, será informado a lista de IDS que possuem acesso ao ambiente.
Obs: A verificação de acesso deve ser rápida. Portanto, use busca binária

Entrada: 
A entrada consiste em vários números inteiros, que devem ser inseridos no vetor. O final da entrada é sinalizado 
pelo número -1, que não deve ser inserido no vetor. Considere que não haverá mais do que 20 elementos. Após o número 
-1, será informado a ID que deseja verificar se tem acesso ou não.

Saída: 
Na saída, o programa deve mostrar "Possui acesso" caso a ID esteja na lista de IDS autorizadas ou "Nao possui acesso", caso não tenha acesso.

Exemplo de entrada:              Exemplo de saída: 
1 3 5 7 10 13 -1 9               Nao possui acesso
1 3 5 7 10 13 -1 3               Possui acesso
*/

#include <iostream>
using namespace std;

int binaria(int vetor[], int tamanho, int x){
    
    bool achou; //var aux para busca
    int baixo, meio, alto; //var aux
    
    baixo = 0;
    alto = tamanho - 1;
    achou = false; 
    
    while((baixo <= alto) && (achou == false)){
        meio = (baixo + alto) / 2;
        if(x < vetor[meio])
            alto = meio - 1;
        else{
            if(x > vetor[meio])
                baixo = meio + 1;
                
        else 
            achou = true;
        }
        
    }
    if(achou)
        return meio;
    else
        return -1;
}

int main (){
    
    //Declare Variables: 
    int vetor[10], id, i, resultado = 0;
    
    //Data input: 
    cout<<"Entre com os IDs: ";
    for(i = 0; i < 20; i++){
        cin>>id;
        if(id != -1)
            vetor[i] = id;
        else 
            break;
    }
    
    cout<<"Qual id você deseja achar: ";
    cin>>id;
    
    resultado = binaria(vetor, i, id);
    
    if(resultado != -1)
        cout<<"Possui acesso"<<endl;
    else
        cout<<"não possui acesso"<<endl;
    
    return 0;
}