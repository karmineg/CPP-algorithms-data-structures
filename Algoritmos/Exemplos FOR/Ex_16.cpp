#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

main()
{
    int i, soma = 0, num;
    for(i = 1; i <= 10; i++)
    {
        cout << "Informe um valor qualquer: ";
        cin >> num;
        fflush(stdin);
        soma += num;
        if(soma >= 100)
            break;
    }

    cout << "Soma: " << soma;

}
