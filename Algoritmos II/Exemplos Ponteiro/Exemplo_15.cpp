#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

main()
{
    int x, *p = &x;

    cout << "Informe um valor: ";
    cin >> *p;
    fflush(stdin);

    cout << "Valor na variavel x: " << x << endl;

    cout << "Endereço da variavel x " << &x << endl;
    cout << "Endereço do ponteiro p " << &p << endl;
    cout << "Endereço para onde o ponteiro aponta: " << p << endl;
    cout << "Conteudo da variavel x " << *p << endl;
    cout << "Conteudo da variavel atraves do ponteiro " << **&p << endl;
}
