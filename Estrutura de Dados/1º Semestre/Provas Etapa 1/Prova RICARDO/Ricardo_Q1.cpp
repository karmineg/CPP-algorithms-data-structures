#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
#include<string>
using namespace std;

#include "filacircular.hpp"

bool busca(Fila *f, int valor) {
    bool encontrado = false;
    Fila aux;
    inicializaF(&aux, f->tam);
    while(!vaziaF(f)) {
        int x = desenfileiraF(f);
        if(x == valor) encontrado = true;
        enfileiraF(&aux, x);
    } while(!vaziaF(&aux)) enfileiraF(f, desenfileiraF(&aux));
    return encontrado;
}

void retirarRepetidos(Fila* F, Fila *Faux) {
    while(!vaziaF(F)) {
        int N = desenfileiraF(F);
        if(!busca(Faux, N)) enfileiraF(Faux, N);
    } while(!vaziaF(Faux)) enfileiraF(F, desenfileiraF(Faux));
    cout << "!!! Fila atualizada, conferir na opção de mostrar !!!";
}

main() {
    system ("color FD");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;

    Fila F, Faux;
    do {
        system("cls");
        cout << "###########MENU DE OPÇÕES###########" << endl;
        cout << "# 0 - Sair                         #" << endl;
        cout << "# 1 - Inicializar fila             #" << endl;
        cout << "# 2 - Adicionar número na fila     #" << endl;
        cout << "# 3 - Remover elementos repetidos  #" << endl;
        cout << "# 4 - Mostrar fila                 #" << endl;
        cout << "####################################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);
        system("cls");

        switch(menu)
        {
            case 0 :
                cout << "Programa finalizado.";
                break;

            case 1: {
                int S;
                do {
                    cout << ">> Qual o tamanho da fila? (Mínimo 2): ";
                    cin >> S;
                    if(S < 2) cout << "!!! Valor inserido MENOR que o mínimo necessário !!!\n";
                    else break;
                } while(true);
                destroiF(&F); // Se fila já tinha sido criada antes, ela será destruída!!
                // Inicializar filas
                inicializaF(&F, S);
                inicializaF(&Faux, S);
                cout << "!!! Pilha inicializada !!!";
                getchar();
                break;
            }

            case 2: {
                if(verificaInicializacaoF(&F)) {
                    if(!cheiaF(&F)) {
                        int num;
                        cout << ">> Insira um número: ";
                        cin >> num;
                        enfileiraF(&F, num);
                        cout << "!!! Número ADICIONADO com sucesso !!!";
                    } else cout << "!!! Fila já está cheia !!!";
                    getchar();
                } else cout << "!!! A fila NÃO foi inicializada pela primeira vez !!!";
                break;
            }

            case 3:
                if(verificaInicializacaoF(&F)) retirarRepetidos(&F, &Faux);
                else cout << "!!! A fila NÃO foi inicializada pela primeira vez !!!";
                break;

            case 4:
                mostraF(&F);
                break;

            default:
                cout << "> Opção inválida!";

        }; getchar();
    }
    while(menu != 0);
}
