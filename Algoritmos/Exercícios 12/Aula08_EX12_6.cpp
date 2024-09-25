/* 6 - Faça um programa para realizar operações sobre um vetor V[5]. O programa deverá exibir um menu com as seguintes opções:
a) Gerar vetor - o programa deverá gerar V com números aleatórios, sendo que o intervalo deve ser informado pelo
usuário, ou seja, ler dois números inteiros X e Y, sendo que o intervalo para a geração dos números será de X até Y.
b) Mostrar vetor;
c) Multiplicar os valores pares armazenados no vetor por 3;
d) Calcular e mostrar a soma dos valores pares do vetor;
e) Mostrar o maior valor do vetor juntamente com sua posição.
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
        cout << "#######################MENU DE OPÇÕES###########################" << endl;
        cout << "# 0 - Sair                                                     #" << endl;
        cout << "# 1 - Gerar vetor                                              #" << endl;
        cout << "# 2 - Mostrar vetor                                            #" << endl;
        cout << "# 3 - Multiplicar os valores pares armazenados no vetor por 3  #" << endl;
        cout << "# 4 - Calcular e mostrar a soma dos valores pares do vetor     #" << endl;
        cout << "# 5 - Mostrar o maior valor do vetor juntamente com sua posição#" << endl;
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

            cout << "Máximo: ";
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
                cout << "\nÉ necessário gerar um vetor primeiro!";
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
                cout << "\nÉ necessário gerar um vetor primeiro!";
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
                cout << "\nÉ necessário gerar um vetor primeiro!";
            getchar();
            break;

        case 5 :
            system("cls");
            if (gerou != 0) {
                cout << "\n\nMaior valor do Vetor: " << maior << " - Posição: " << posicao;
            }
            else
                cout << "\nÉ necessário gerar um vetor primeiro!";
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
