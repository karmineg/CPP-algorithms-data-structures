/*11. Uma transportadora precisa de um sistema para gerenciar o carregamento de caixas nos caminhões da empresa.
Implemente um programa que atenda a necessidade da empresa, empregando uma pilha para definir a ordem do
carregamento e descarregamento das caixas em um caminhão.
O programa deve possuir um menu com as opções:
o Definir quantidade de caixa – Criar uma pilha que suporte a quantidade de caixas informada.
o Carregar caixa - empilhar
o Descarregar caixa - desempilhar
o Mostar carga – mostrar pilha
o Sair do programa*/

#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>
using namespace std;

#include "pilhaCaixa.hpp"

void adicionaCaixa(Pilha *Pcx) {
    if(!cheiaP(Pcx)) {
        // VERIFICAR CÓDIGO
        int code;
        do {
            cout << ">> Insira o código: ";
            cin >> code;
            int indB = buscaP(Pcx, code);
            if(indB >= 0) cout << "!!! Código JÁ inserido em outra caixa (no índice " << indB << ") !!!\n";
            else break;
        } while(true);
        // VERIFICAR PESO
        float peso;
        do {
            cout << ">> Insira o peso: ";
            cin >> peso;
            if(peso <= 0) cout << "!!! Peso NÃO pode ser nulo ou negativo >:( !!!\n";
            else break;
        } while(true);
        // CRIAR A CAIXA
        Caixa C = { code, peso };
        empilhaP(Pcx, C);
        cout << "Adicionado com sucesso!!!";
    } else {
        cout << "!!! Você JÁ lotou o caminhão com caixas... esvazie, por favor !!!";
    }
}

main() {
    system ("color F5");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;

    Pilha Pcx;

    do
    {
        system("cls");
        cout << "##########MENU DE OPÇÕES###########" << endl;
        cout << "# 0 - Sair                        #" << endl;
        cout << "# 1 - Definir quantidade de caixa #" << endl;
        cout << "# 2 - Carregar caixa              #" << endl;
        cout << "# 3 - Descarregar caixa           #" << endl;
        cout << "# 4 - Mostrar carga               #" << endl;
        cout << "###################################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);
        system("cls");

        switch(menu)
        {
            case 0 : // Sair
            cout << "Programa finalizado.";
            break;

            case 1: // Definir quantidade de caixa
                int tam;
                do {
                    cout << ">> Insira quantas caixas o caminhão suporta, no máximo: ";
                    cin >> tam;
                    if(tam <= 0) cout << "!!! NÃO é permitido quantidade nula ou negativa de caixas !!!\n";
                    else break;
                } while(true);
                if(verificaInicializacaoP(&Pcx)) {
                    destroiP(&Pcx);
                } inicializaP(&Pcx, tam);
                cout << "Inicializado com sucesso!! B)";
                getchar();
                break;

            case 2: // Inserir uma caixa na pilha
                if(verificaInicializacaoP(&Pcx)) {
                    adicionaCaixa(&Pcx);
                    getchar();
                } else cout << "Você precisa definir a quantidade de caixa antes!!!";
                break;

            case 3: // Eliminar última caixa da pilha
                if(verificaInicializacaoP(&Pcx)) {
                    if(!vaziaP(&Pcx)) {
                        Caixa C = desempilhaP(&Pcx);
                        cout << "Caixa RETIRADA do caminhão... confira abaixo:" << endl;
                        cout << " >> Código: " << C.codigo << endl;
                        cout << " >> Peso: " << C.peso << endl;
                    } else {
                        cout << "!!! Caminhão está VAZIO... Insira umas caixas, por favor !!!";
                    }
                }
                else cout << "Você precisa definir a quantidade de caixa antes!!!";
                break;

            case 4:
                if(verificaInicializacaoP(&Pcx)) mostraP(&Pcx, "de caixas");
                else cout << "Você precisa definir a quantidade de caixa antes!!!";
                break;

        }; getchar();
    }
    while(menu != 0);
}
