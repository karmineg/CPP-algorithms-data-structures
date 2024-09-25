/*11. Uma transportadora precisa de um sistema para gerenciar o carregamento de caixas nos caminh�es da empresa.
Implemente um programa que atenda a necessidade da empresa, empregando uma pilha para definir a ordem do
carregamento e descarregamento das caixas em um caminh�o.
O programa deve possuir um menu com as op��es:
o Definir quantidade de caixa � Criar uma pilha que suporte a quantidade de caixas informada.
o Carregar caixa - empilhar
o Descarregar caixa - desempilhar
o Mostar carga � mostrar pilha
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
        // VERIFICAR C�DIGO
        int code;
        do {
            cout << ">> Insira o c�digo: ";
            cin >> code;
            int indB = buscaP(Pcx, code);
            if(indB >= 0) cout << "!!! C�digo J� inserido em outra caixa (no �ndice " << indB << ") !!!\n";
            else break;
        } while(true);
        // VERIFICAR PESO
        float peso;
        do {
            cout << ">> Insira o peso: ";
            cin >> peso;
            if(peso <= 0) cout << "!!! Peso N�O pode ser nulo ou negativo >:( !!!\n";
            else break;
        } while(true);
        // CRIAR A CAIXA
        Caixa C = { code, peso };
        empilhaP(Pcx, C);
        cout << "Adicionado com sucesso!!!";
    } else {
        cout << "!!! Voc� J� lotou o caminh�o com caixas... esvazie, por favor !!!";
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
        cout << "##########MENU DE OP��ES###########" << endl;
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
                    cout << ">> Insira quantas caixas o caminh�o suporta, no m�ximo: ";
                    cin >> tam;
                    if(tam <= 0) cout << "!!! N�O � permitido quantidade nula ou negativa de caixas !!!\n";
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
                } else cout << "Voc� precisa definir a quantidade de caixa antes!!!";
                break;

            case 3: // Eliminar �ltima caixa da pilha
                if(verificaInicializacaoP(&Pcx)) {
                    if(!vaziaP(&Pcx)) {
                        Caixa C = desempilhaP(&Pcx);
                        cout << "Caixa RETIRADA do caminh�o... confira abaixo:" << endl;
                        cout << " >> C�digo: " << C.codigo << endl;
                        cout << " >> Peso: " << C.peso << endl;
                    } else {
                        cout << "!!! Caminh�o est� VAZIO... Insira umas caixas, por favor !!!";
                    }
                }
                else cout << "Voc� precisa definir a quantidade de caixa antes!!!";
                break;

            case 4:
                if(verificaInicializacaoP(&Pcx)) mostraP(&Pcx, "de caixas");
                else cout << "Voc� precisa definir a quantidade de caixa antes!!!";
                break;

        }; getchar();
    }
    while(menu != 0);
}
