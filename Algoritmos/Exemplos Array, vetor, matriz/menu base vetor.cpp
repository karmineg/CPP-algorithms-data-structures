#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL));
    int i, V[12], menu = -1;

    do
    {
        system("cls");
        cout << "####################MENU DE OPÇÕES###################" << endl;
        cout << "# 0 - Sair                                          #" << endl;
        cout << "# 1 - Efetuar reserva                               #" << endl;
        cout << "# 2 - Listar todos os quartos                       #" << endl;
        cout << "# 3 - Listar os quartos vagos                       #" << endl;
        cout << "# 4 - Mostrar o total de pessoas hospedadas no hotel#" << endl;
        cout << "# 5 - Efetuar saída:                                #" << endl;
        cout << "# 6 - Listar quartos ocupados                       #" << endl;
        cout << "#####################################################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);

        switch(menu)
        {
            case 0 :
            system("cls");
            cout << "Programa finalizado.";
            getchar();
            break;

            case 1 :
            system("cls");

            getchar();
            break;

            case 2 :
            system("cls");

            getchar();
            break;

            case 3 :
            system("cls");

            getchar();
            break;

            case 4 :
            system("cls");

            getchar();
            break;

            case 5 :
            system("cls");

            getchar();
            break;

            case 6 :
            system("cls");

            getchar();
            break;

            default :
                system("cls");

                cout << "Opção inválida.";
                getchar();
                break;
        };

    }
    while(menu != 0);
}
