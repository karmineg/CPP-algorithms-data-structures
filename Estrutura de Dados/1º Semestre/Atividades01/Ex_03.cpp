/*3) Construa um programa que apresente um menu com as seguintes op��es:
a. Gerar vetor - alocar dinamicamente um vetor de 10 posi��es com valores aleat�rios
no intervalor de 20 a 50;
b. Mostrar vetor � mostrar os elementos do vetor;
c. Sair do programa.
Observa��es:
� Antes de apresentar o menu, inicialize o vetor como NULL (int *vetor =
NULL;)
� Para gerar um novo vetor, caso o vetor j� tenha sido alocado, deve-se
liberar mem�ria antes de alocar um novo:
If (vetor != NULL)
 // liberar mem�ria...
� Na op��o mostrar vetor, o vetor n�o pode ser nulo*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>
using namespace std;

main() {
    system ("color F5");
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    int menu = -1, *pv = NULL;

    do
    {
        system("cls");
        cout << "####MENU DE OP��ES###" << endl;
        cout << "# 0 - Sair          #" << endl;
        cout << "# 1 - Gerar vetor   #" << endl;
        cout << "# 2 - Mostrar vetor #" << endl;
        cout << "#####################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);
        system("cls");

        switch(menu)
        {
            case 0 :
            cout << "Programa finalizado.";
            break;

            case 1 :
                if(pv != NULL) delete[] pv;
                else pv = new int[10];
                for(int i = 0; i < 10; i++) {
                    *pv = 20 + (rand() % 31);
                    pv++;
                } pv -= 10;
                cout << "Vetor gerado!";

            break;

            case 2 :
                if(pv != NULL) {
                    cout << "Vetor: ";
                    for(int i = 0; i < 9; i++) {
                        cout << *pv << ", ";
                        pv++;
                    } cout << *pv << ";";
                    pv -= 9;
                } else {
                    cout << "Gere primeiramente um vetor!";
                }

            break;

            default :
                cout << "Op��o inv�lida.";
                break;
        }; getchar();
    }
    while(menu != 0);
}
