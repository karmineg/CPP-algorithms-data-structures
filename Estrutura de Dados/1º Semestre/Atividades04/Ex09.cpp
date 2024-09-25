/*9. Faça uma função para contar os elementos de uma fila.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>
using namespace std;

#include "filacircular-template.hpp"

void adicionaF(Fila<float> *F) {
    if(cheiaF(F)) {
        cout << "!!! A fila está cheia... Remova um elemento antes !!!";
    } else {
        float num;
        cout << "> Digite um elemento: ";
        cin >> num;
        enfileiraF(F, num);
        cout << "Elemento adicionado na fila!!!";
    }
}

void removeF(Fila<float> *F) {
    if(vaziaF(F)) cout << "!!! A fila está vazia... Insira um elemento antes !!!";
    else {
        float num = desenfileiraF(F);
        cout << "Elemento " << num << " foi removido !!!" ;
    }
}

void mostraSoma(Fila<float> *f) {
    float soma = 0;
    int idx = f->inicio;
    for(int i = 0; i < f->total; i++) {
        soma += f->dados[idx];
        idx++;
        if(idx >= f->tam) idx = 0;
    } cout << ">> Soma total: " << soma;
}

void mostraQtd(Fila<float> *F) {
    if(F->total == 0) cout << ">> Fila está VAZIA... Sem elementos :(";
    else {
        cout << ">> A fila está preenchida com " << F->total << " elemento";
        if(F->total > 1) cout << "s";
        cout << "!!!";
    }
}

main() {
    system ("color F2");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1, qtd;

    Fila<float> F;

    do {
    cout << ">> Informe o tamanho da fila: ";
        cin >> qtd;
        if(qtd <= 0) cout << "!!! Quantidade NÃO pode ser nula ou negativa !!!\n";
        else break;
    } while(true);
    inicializaF(&F, qtd);

    do
    {
        system("cls");
        cout << "###############MENU DE OPÇÕES#############" << endl;
        cout << "# 0 - Sair                               #" << endl;
        cout << "# 1 - Incluir na fila                    #" << endl;
        cout << "# 2 - Remover na fila                    #" << endl;
        cout << "# 3 - Mostrar fila                       #" << endl;
        cout << "# 4 - Mostrar soma dos elementos da fila #" << endl;
        cout << "# 5 - Contar elementos da fila           #" << endl;
        cout << "##########################################" << endl;
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
                mostraF(&F, "de números");
                break;

            case 4:
                mostraSoma(&F);
                break;

            case 5:
                mostraQtd(&F);
                break;

        }; getchar();
    }
    while(menu != 0);
}
