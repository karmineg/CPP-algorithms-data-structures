/* 6 - Fa�a um programa para realizar opera��es sobre um vetor V[5]. O programa dever� exibir um menu com as seguintes op��es:
a) Gerar vetor - o programa dever� gerar V com n�meros aleat�rios, sendo que o intervalo deve ser informado pelo
usu�rio, ou seja, ler dois n�meros inteiros X e Y, sendo que o intervalo para a gera��o dos n�meros ser� de X at� Y.
b) Mostrar vetor;
c) Multiplicar os valores pares armazenados no vetor por 3;
d) Calcular e mostrar a soma dos valores pares do vetor;
e) Mostrar o maior valor do vetor juntamente com sua posi��o.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

main()
{
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL));
    int i, p, soma = 0, menu = -1, gerou = 0, maior = 0, posicao, mini, maxi;
    int vet[5];

    do
    {
        system("cls");
        cout << "#######################MENU DE OP��ES###########################" << endl;
        cout << "# 0 - Sair                                                     #" << endl;
        cout << "# 1 - Gerar vetor                                              #" << endl;
        cout << "# 2 - Mostrar vetor                                            #" << endl;
        cout << "# 3 - Multiplicar os valores pares armazenados no vetor por 3  #" << endl;
        cout << "# 4 - Calcular e mostrar a soma dos valores pares do vetor     #" << endl;
        cout << "# 5 - Mostrar o maior valor do vetor juntamente com sua posi��o#" << endl;
        cout << "################################################################" << endl;
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
            cout << "Defina o intervalo" << endl;
            cout << "Minimo: ";
            cin >> mini;

            cout << "M�ximo: ";
            cin >> maxi;

            for(i = 0; i < 5; i++){
                vet[i] = rand() % (maxi + 1 - mini) + mini;

                if (vet[i] > maior){
                    maior = vet[i];
                    posicao = i;
                    }
            }
            cout << "Vetor gerado!" << endl;
            gerou = 1;
            getchar();
            break;
        case 2 :
            system("cls");
            if (gerou != 0) {
                cout << "Vetor: " << endl;
                for(i = 0; i < 5; i++){
                    cout << vet[i] << ", ";
                }
            }
            else
                cout << "\n� necess�rio gerar um vetor primeiro!";
            getchar();
            break;

        case 3 :
            system("cls");
            if(gerou != 0) {
                for (i = 0; i < 5; i++) {
                    cout << vet[i] * 3 << ", ";
                }
            }
            else
                cout << "\n� necess�rio gerar um vetor primeiro!";
            getchar();
            break;

        case 4 :
            system("cls");
            if(gerou != 0) {
                for (int p = 0; p < 5; p++){
                    if (vet[p] % 2 == 0)
                        soma += vet[p];
                }

            cout <<"Soma dos pares: " << soma << endl;
            }
            else
                cout << "\n� necess�rio gerar um vetor primeiro!";
            getchar();
            break;

        case 5 :
            system("cls");
            if (gerou != 0) {
                cout << "\n\nMaior valor do Vetor: " << maior << " - Posi��o: " << posicao;
            }
            else
                cout << "\n� necess�rio gerar um vetor primeiro!";
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
