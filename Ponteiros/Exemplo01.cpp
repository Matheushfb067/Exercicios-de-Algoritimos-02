//Exemplo de aula
#include <iostream>
using namespace std;

int main()
{

    int a, b;
    int *p; /*p é um ponteiro para int/nunca armazena informação, somente o 
    endereço*/
    
    a = 2;
    b = 3;
    p = &a;  // &: operador de referencia
    *p = 5; // *: operador de referencia
    
    //b passa a ser 15
    p = &b;
    *p = 15;
    
    cout<<"a = "<< a <<endl;
    cout<<"b = "<< b <<endl;
    
    return 0;
}

