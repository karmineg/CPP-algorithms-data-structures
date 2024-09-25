
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

main()
{
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL)); //inicializando o randômico
    int i, x, aux, menu = -1, gerou = 0;
    int vet[5];

    do
    {
        system("cls");
        cout << "#####MENU DE OPÇÕES#####" << endl;
        cout << "# 0 - Sair             #" << endl;
        cout << "# 1 - Gerar vetor      #" << endl;
        cout << "# 2 - Ordem crescente  #" << endl;
        cout << "# 3 - Ordem decrescente#" << endl;
        cout << "########################" << endl;
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
            cout << "VETOR GERADO: " << endl;
            for(i = 0; i < 5; i++)
            {
                vet[i] = rand() % 10;
                cout << vet[i] << ", ";
            }
            gerou = 1;
            getchar();
            break;
        case 2 :
            system("cls");
            if(gerou != 0)
            {
                for(i = 0; i < 4; i++)
                {
                    for(x = i + 1; x < 5; x++)
                    {
                        if(vet[i] > vet[x])
                        {
                            aux = vet[i];
                            vet[i] = vet[x];
                            vet[x] = aux;
                        }
                    }
                }

                cout << "\n\nVETOR ORDENADO EM ORDEM CRESCENTE: " << endl;
                for(i = 0; i < 5; i++)
                {
                    cout << vet[i] << ", ";
                }
            }
            else
                cout << "\nÉ NECESSÁRIO GERAR O VETOR PRIMEIRO";
            getchar();
            break;
        case 3 :
            system("cls");
            if(gerou != 0)
            {
                for(i = 0; i < 4; i++)
                {
                    for(x = i + 1; x < 5; x++)
                    {
                        if(vet[i] < vet[x])
                        {
                            aux = vet[i];
                            vet[i] = vet[x];
                            vet[x] = aux;
                        }
                    }
                }

                cout << "\n\nVETOR ORDENADO EM ORDEM DECRESCENTE: " << endl;
                for(i = 0; i < 5; i++)
                {
                    cout << vet[i] << ", ";
                }
            }
            else
                cout << "\nÉ NECESSÁRIO GERAR O VETOR PRIMEIRO";
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
