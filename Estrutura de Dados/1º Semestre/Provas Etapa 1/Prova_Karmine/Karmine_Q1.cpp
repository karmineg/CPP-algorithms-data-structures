#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>
using namespace std;

#include "filacircular.hpp"

bool busca(Fila *F, int valor){
    bool encontrado = false;
    Fila Faux;
    inicializaF(&Faux, F-> tam);
    while(!vaziaF(F)) {
        int x = desenfileiraF(F);
        if( x == valor) encontrado = true;
        enfileiraF(&Faux, x);
    }
    while(!vaziaF(&Faux)){
        enfileiraF(F, desenfileiraF(&Faux));
    }
    return encontrado;
}

void removeRepetidos(Fila *F, Fila *aux) {
    while(!vaziaF(F)){
        int N = desenfileiraF(F);
        while(!busca(aux, N)) enfileiraF(aux, N);
    } while(!vaziaF(aux))
        enfileiraF(F, desenfileiraF(aux));
    cout << "> Elementos repetidos foram removidos!";
}

main() {
    system ("color F2");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1, T;
    Fila F;
    Fila aux;

    do {
        cout << "Qual o tamanho que você deseja definir para a sua fila?\n";
        cin >> T;
        if (T < 2 ) cout << "Tamanho menor do que o mínimo necessário!\n";
        else break;
    }while(true);

    inicializaF(&F, T);
    inicializaF(&aux, T);
    cout << "> Filas inicializadas com sucesso!";
    do
    {
        system("cls");
        cout << "###########MENU DE OPÇÕES##########" << endl;
        cout << "# 0 - Sair                        #" << endl;
        cout << "# 1 - Incluir na fila             #" << endl;
        cout << "# 2 - Remover elementos repetidos #" << endl;
        cout << "# 3 - Mostrar a fila              #" << endl;
        cout << "###################################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);
        system("cls");

        switch(menu)
        {
            case 0 :
            cout << "Programa finalizado.";
            break;

            case 1:
                if(!cheiaF(&F)){
                    int num;
                    cout << "Insira um número inteiro: ";
                    cin >> num;
                    enfileiraF(&F, num);
                    cout << "> Valor adicionado na fila com sucesso!";
                    getchar();
                } else cout << "> Fila está cheia!";

                break;

            case 2:
                removeRepetidos(&F, &aux);
                break;

            case 3:
                mostraF(&F);
                break;

            default:
                cout << "> Opção inválida!";
                break;

        }; getchar();
    }
    while(menu != 0);
}
