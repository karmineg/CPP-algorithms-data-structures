#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

main()
{
    int *tam = new int;
    int *psoma = new int(0);
    cout << "Informe a quantidade de numeros: ";
    cin >> *tam;
    fflush(stdin);

    int *pvet = new int[*tam];

    srand(time(NULL));
    cout << "Endereco do ponteiro: " << pvet << endl;
    int *i = new int;
    for (*i = 0; *i < *tam; (*i)++)
    {
        *(pvet + *i) = rand() % 100;
    }

    cout << "\nEndereco do ponteiro: " << pvet << endl;

    for (*i = 0; *i < *tam; (*i)++)
    {
        cout << *pvet << ", ";
        if(*pvet % 2 == 0)
            *psoma += *pvet;
        pvet++;
    }


    cout << "\nEndereco do ponteiro apos aritmetica: " << pvet << endl;
    cout << "Soma dos pares: " << *psoma << endl;
    delete i;
    delete []pvet;
    delete psoma;
}
