/*Fa�a uma fun��o que inverta a ordem dos elementos da fila.
Dica: Use uma pilha auxiliar na implementa��o.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>
using namespace std;

#include "filacircular-template.hpp"
#include "pilha-template.hpp"

void adicionaF(Fila<float> *F) {
    if(cheiaF(F)) {
        cout << "!!! A fila est� cheia... Remova um elemento antes !!!";
    } else {
        float num;
        cout << "> Digite um elemento: ";
        cin >> num;
        enfileiraF(F, num);
        cout << "Elemento adicionado na fila!!!";
    }
}

void removeF(Fila<float> *F) {
    if(vaziaF(F)) cout << "!!! A fila est� vazia... Insira um elemento antes !!!";
    else {
        float num = desenfileiraF(F);
        cout << "Elemento " << num << " foi removido !!!" ;
    }
}

void InverteF(Fila<float> *F) {
    int iniO = F->inicio; // Primeiro �ndice original, que ser� CONSERVADO
    No<float> *P = nullptr;
    while(!vaziaF(F)) { // Enquanto a fila n�o estiver vazia, remove os itens da mesma adicionando-as na pilha
        float item = desenfileiraF(F);
        P = adicionaP(P, item);
    }
    // Quando esvaziar a fila, tanto o in�cio quanto o fim v�o para o primeiro �ndice original (iniO)
    F->inicio = iniO;
    F->fim = iniO;
    while(P != NULL) { // Enquanto a pilha n�o estiver vazia, remove os itens da mesma adicionando-as na fila
        enfileiraF(F, P->dado);
        P = removeP(P);
    }
    cout << "!!! Fila invertida com SUCESSO (confira na op��o 'Mostrar') !!!";
}

main() {
    system ("color F2");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1, qtd;

    Fila<float> F;

    do {
    cout << ">> Informe o tamanho da fila: ";
        cin >> qtd;
        if(qtd <= 0) cout << "!!! Quantidade N�O pode ser nula ou negativa !!!\n";
        else break;
    } while(true);
    inicializaF(&F, qtd);

    do
    {
        system("cls");
        cout << "#########MENU DE OP��ES#######" << endl;
        cout << "# 0 - Sair                   #" << endl;
        cout << "# 1 - Incluir na fila        #" << endl;
        cout << "# 2 - Remover na fila        #" << endl;
        cout << "# 3 - Mostrar fila           #" << endl;
        cout << "# 4 - Inverter ordem da fila #" << endl;
        cout << "##############################" << endl;
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
                adicionaF(&F);
                getchar();
                break;

            case 2:
                removeF(&F);
                break;

            case 3:
                mostraF(&F, "de n�meros");
                break;

            case 4:
                InverteF(&F);
                break;

        }; getchar();
    }
    while(menu != 0);
}
