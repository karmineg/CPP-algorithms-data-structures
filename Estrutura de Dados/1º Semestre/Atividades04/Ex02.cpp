/*2. Desenvolva um programa que permita gerenciar uma pista para descolagem de aviões de um aeroporto. Para o
correto funcionamento desta pista é necessário que seja implementada uma fila com as seguintes funcionalidades:
a) Nº de aviões à espera de decolar.
b) Entrada de um novo avião para decolar (incluir na fila).
c) Decolagem de um avião (retirar da fila).
d) Listar todos os aviões à espera para decolagem (mostrar fila).
e) Listar as características do próximo avião a decolar (peek).
Observação: para cada avião são necessárias as seguintes informações: código do avião, número de
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
        cout << ">> Informe a quantidade de aviões: ";
        cin >> qtd;
        if(qtd <= 0) cout << "!!! Quantidade NÃO pode ser nula ou negativa !!!";
        else break;
    } while(true);
    destroiF(F);
    inicializaF(F, qtd);
    srand(qtd);
    cout << "!!! Fila criada com SUCESSO :) !!!";
}

void adicionaAviao(Fila<Aviao> *F) {
    if(cheiaF(F)) {
        cout << "!!! A fila já está LOTADA... Faça um avião decolar antes !!!";
    } else {
        int C;
        cout << "> Digite o código do avião: ";
        cin >> C;

        int qtd;
        do {
            cout << "\n> Digite a quantidade de passageiros: ";
            cin >> qtd;
            if(qtd <= 0) cout << "!!! Quantidade NÃO pode ser nula ou negativa !!!";
            else break;
        } while(true);

        string empr;
        cout << "\n> Digite a empresa aérea do avião: ";
        cin.ignore();
        getline(cin, empr);

        Aviao A = { C, qtd, empr };
        enfileiraF(F, A);
        cout << "\n!!! Avião adicionado COM SUCESSO !!!";
    }
}

string lugares[10] = { "Sarandi", "Terra Média", "Orlais", "Alagoinha", "Khaenri'ah", "Ferelden", "Terra de OOO", "Fenda do Bikini", "Townsville", "Equestria" };

void removerAviao(Fila<Aviao> *F) {
    if(vaziaF(F)) cout << "!!! Não tem aviões na fila... Insira !!!";
    else {
        Aviao A = desenfileiraF(F);
        int *indL = new int(rand() % 10);
        cout << ">> Avião de código " << A.codigo << " da empresa " << A.empresa << " levou " << A.qtdP << " passageiros para " << lugares[*indL] << "!!!" ;
    }
}

void mostrarAv(Fila<Aviao> *f, string frase, int qtd) {
    if(vaziaF(f)) cout << "!!! Fila está VAZIA !!!\n\n";
    else {
        cout << ">> " << frase << "\n";//Fila de aviões\n";
        cout << "       Índice |       Código | Qtd. passageiros |      Empresa \n";
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
        cout << "#######################MENU DE OPÇÕES#######################" << endl;
        cout << "# 0 - Sair                                                 #" << endl;
        cout << "# 1 - Nº de aviões à espera de decolar                     #" << endl;
        cout << "# 2 - Entrada de um novo avião para decolar                #" << endl;
        cout << "# 3 - Decolagem de um avião                                #" << endl;
        cout << "# 4 - Listar todos os aviões à espera para decolagem       #" << endl;
        cout << "# 5 - Listar as características do próximo avião a decolar #" << endl;
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
                if(!verificaInicializacaoF(&F)) cout << "Primeiro defina o número de aviões antes!!!";
                else adicionaAviao(&F);
                break;

            case 3:
                if(!verificaInicializacaoF(&F)) cout << "Primeiro defina o número de aviões antes!!!";
                else removerAviao(&F);
                break;

            case 4:
                if(!verificaInicializacaoF(&F)) cout << "Primeiro defina o número de aviões antes!!!";
                else mostrarAv(&F, "Fila de aviões", F.total);
                break;

            case 5:
                if(!verificaInicializacaoF(&F)) cout << "Primeiro defina o número de aviões antes!!!";
                else mostrarAv(&F, "Próximo avião a decolar", 1);
                break;

        }; getchar();
    }
    while(menu != 0);
}
