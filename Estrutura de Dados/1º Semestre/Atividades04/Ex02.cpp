/*2. Desenvolva um programa que permita gerenciar uma pista para descolagem de avi�es de um aeroporto. Para o
correto funcionamento desta pista � necess�rio que seja implementada uma fila com as seguintes funcionalidades:
a) N� de avi�es � espera de decolar.
b) Entrada de um novo avi�o para decolar (incluir na fila).
c) Decolagem de um avi�o (retirar da fila).
d) Listar todos os avi�es � espera para decolagem (mostrar fila).
e) Listar as caracter�sticas do pr�ximo avi�o a decolar (peek).
Observa��o: para cada avi�o s�o necess�rias as seguintes informa��es: c�digo do avi�o, n�mero de
passageiros, empresa.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>
using namespace std;

struct Aviao {
    int codigo;
    int qtdP;
    string empresa;
};

#include "filacircular-template.hpp"

void criarFila(Fila<Aviao> *F) {
    int qtd;
    do {
        cout << ">> Informe a quantidade de avi�es: ";
        cin >> qtd;
        if(qtd <= 0) cout << "!!! Quantidade N�O pode ser nula ou negativa !!!";
        else break;
    } while(true);
    destroiF(F);
    inicializaF(F, qtd);
    srand(qtd);
    cout << "!!! Fila criada com SUCESSO :) !!!";
}

void adicionaAviao(Fila<Aviao> *F) {
    if(cheiaF(F)) {
        cout << "!!! A fila j� est� LOTADA... Fa�a um avi�o decolar antes !!!";
    } else {
        int C;
        cout << "> Digite o c�digo do avi�o: ";
        cin >> C;

        int qtd;
        do {
            cout << "\n> Digite a quantidade de passageiros: ";
            cin >> qtd;
            if(qtd <= 0) cout << "!!! Quantidade N�O pode ser nula ou negativa !!!";
            else break;
        } while(true);

        string empr;
        cout << "\n> Digite a empresa a�rea do avi�o: ";
        cin.ignore();
        getline(cin, empr);

        Aviao A = { C, qtd, empr };
        enfileiraF(F, A);
        cout << "\n!!! Avi�o adicionado COM SUCESSO !!!";
    }
}

string lugares[10] = { "Sarandi", "Terra M�dia", "Orlais", "Alagoinha", "Khaenri'ah", "Ferelden", "Terra de OOO", "Fenda do Bikini", "Townsville", "Equestria" };

void removerAviao(Fila<Aviao> *F) {
    if(vaziaF(F)) cout << "!!! N�o tem avi�es na fila... Insira !!!";
    else {
        Aviao A = desenfileiraF(F);
        int *indL = new int(rand() % 10);
        cout << ">> Avi�o de c�digo " << A.codigo << " da empresa " << A.empresa << " levou " << A.qtdP << " passageiros para " << lugares[*indL] << "!!!" ;
    }
}

void mostrarAv(Fila<Aviao> *f, string frase, int qtd) {
    if(vaziaF(f)) cout << "!!! Fila est� VAZIA !!!\n\n";
    else {
        cout << ">> " << frase << "\n";//Fila de avi�es\n";
        cout << "       �ndice |       C�digo | Qtd. passageiros |      Empresa \n";
        cout << "--------------|--------------|------------------|--------------\n";
        int idx = f->inicio;
        for(int i = 0; i < qtd; i++)
        {
            Aviao a = f->dados[idx];
            cout << setfill(' ') << std::setw(13) << idx << " |";
            cout << setfill(' ') << std::setw(13) << a.codigo << " |";
            cout << setfill(' ') << std::setw(17) << a.qtdP << " |";
            cout << setfill(' ') << std::setw(13) << a.empresa << endl;
            idx++;
            if(idx >= f->tam) idx=0;
        }
    }
}

main() {
    system ("color F2");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;

    Fila<Aviao> F;

    do
    {
        system("cls");
        cout << "#######################MENU DE OP��ES#######################" << endl;
        cout << "# 0 - Sair                                                 #" << endl;
        cout << "# 1 - N� de avi�es � espera de decolar                     #" << endl;
        cout << "# 2 - Entrada de um novo avi�o para decolar                #" << endl;
        cout << "# 3 - Decolagem de um avi�o                                #" << endl;
        cout << "# 4 - Listar todos os avi�es � espera para decolagem       #" << endl;
        cout << "# 5 - Listar as caracter�sticas do pr�ximo avi�o a decolar #" << endl;
        cout << "############################################################" << endl;
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
                criarFila(&F);
                getchar();
                break;

            case 2:
                if(!verificaInicializacaoF(&F)) cout << "Primeiro defina o n�mero de avi�es antes!!!";
                else adicionaAviao(&F);
                break;

            case 3:
                if(!verificaInicializacaoF(&F)) cout << "Primeiro defina o n�mero de avi�es antes!!!";
                else removerAviao(&F);
                break;

            case 4:
                if(!verificaInicializacaoF(&F)) cout << "Primeiro defina o n�mero de avi�es antes!!!";
                else mostrarAv(&F, "Fila de avi�es", F.total);
                break;

            case 5:
                if(!verificaInicializacaoF(&F)) cout << "Primeiro defina o n�mero de avi�es antes!!!";
                else mostrarAv(&F, "Pr�ximo avi�o a decolar", 1);
                break;

        }; getchar();
    }
    while(menu != 0);
}
