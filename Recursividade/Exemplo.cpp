#include <iostream>
using namespace std;

//Inprevisibilidade do uso de memoria - por conta da entrada ser imprevisivel WARNING!!!
int fatorial(int n){
    if(n == 0)//Condição de parada
        return 1;
    else//Chamada recursiva
        return n*fatorial(n-1);
}


int main(){

    int n;

    cin>>n;

    cout<<fatorial(n)<<endl; 

    return 0;
}