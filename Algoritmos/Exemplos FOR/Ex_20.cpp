#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

main()
{
    setlocale(LC_ALL,"Portuguese");
    int i, tab, v;
    do
    {
        system("cls");
        cout << "Informe o valor para calcular a tabuada: ";
        cin >> v;
        fflush(stdin);
        if(v < 1 or v > 10)
        {
            system("cls");
            cout << "\nValor inválido.";
            getchar();
        }
    }
    while(v < 1 or v > 10);

    cout << "TABUADA DO " << v << endl;
    for(int i = 1; i <= 10; i++)
    {
        tab = v * i;
        cout << i << " * " << v << " = " << tab << endl;
    }
}
