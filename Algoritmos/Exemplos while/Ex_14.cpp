#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

main()
{
    setlocale(LC_ALL,"Portuguese");
    int menu = -1, num, leu = 0;

    do
    {
        system("cls");
        cout << "####MENU DE OP��ES####" << endl;
        cout << "# 0 - Sair           #" << endl;
        cout << "# 1 - Ler n�mero     #" << endl;
        cout << "# 2 - Tabuada        #" << endl;
        cout << "######################" << endl;
        cout << "Sua Escolha: ";
        cin >> menu;
        fflush(stdin);

        switch(menu)
        {
        case 0 :
            system("cls");
            cout << "Programa finalizado com sucesso!";
            getchar();
            break;
        case 1 :
            system("cls");
            cout << "Informe um n�mero: ";
            cin >> num;
            fflush(stdin);
            leu = 1;
            cout << "N�mero registrado com sucesso.";
            getchar();
            break;
        case 2 :
            system("cls");
            if(leu == 0)
            {
                cout << "Para acessar esta rotina � necess�rio ler um valor.";
            }
            else
            {
                cout << "Tabuada do " << num << endl;
                int x = 1;
                while(x <= 10)
                {
                    cout << x << " * " << num << " = " << x * num << endl;
                    x++;
                }
            }
            getchar();
            break;
        default :
            system("cls");
            cout << "Op��o inv�lida.";
            getchar();
            break;
        };


    }
    while(menu != 0);

}
