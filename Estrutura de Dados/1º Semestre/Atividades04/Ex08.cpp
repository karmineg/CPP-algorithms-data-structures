/*8. Faça uma função para intercalar filas: a função recebe as duas filas e retorna a fila com
os elementos das duas filas intercalados, mantendo a ordem relativa dos elementos.*/

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

void intercalaF(Fila<float> *F1, Fila<float> *F2, int qtd) {
    Fila<float> F3;
    Fila<float>* Fmax;
    inicializaF(&F3, 2*qtd);
    // Índice inicial das filas 1 e 2, que será conservado após a intercalação
    int iniO1 = F1->inicio;
    int iniO2 = F2->inicio;
    int qtd1 = F1->total; // Quantidade de elementos em F1
    int qtd2 = F2->total; // Quantidade de elementos em F2
    int qtdm, qtdM;
    if(qtd1 >= qtd2) {
        qtdm = qtd2;
        qtdM = qtd1;
        Fmax = F1;
    } else {
        qtdm = qtd1;
        qtdM = qtd2;
        Fmax = F2;
    }
    int i;
    for(i = 0; i < qtdm; i++) { // Desenfileira de F1 e F2 até a quantidade menor de elementos
        enfileiraF(&F3, desenfileiraF(F1));
        enfileiraF(&F3, desenfileiraF(F2));
    } for(i = qtdm; i < qtdM; i++) enfileiraF(&F3, desenfileiraF(Fmax)); // Com a fila MENOR totalmente vazia, finalmente se esvazia o que sobrou da fila MAIOR

    // Mostrar fila intercalada
    mostraF(&F3, "intercalada");

    // Retornar novamente as filas antes do processo
    F1->inicio = iniO1;
    F1->fim = iniO2;
    F2->inicio = iniO2;
    F2->fim = iniO2;
    for(i = 0; i < qtdm; i++) {
        enfileiraF(F1, desenfileiraF(&F3));
        enfileiraF(F2, desenfileiraF(&F3));
    } for(i = qtdm; i < qtdM; i++) enfileiraF(Fmax, desenfileiraF(&F3)); // Com a fila MENOR totalmente vazia, finalmente se esvazia o que sobrou da fila MAIOR
}

main() {
    system ("color F2");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1, qtd;

    Fila<float> F1, F2;

    do {
    cout << ">> Informe o tamanho da fila: ";
        cin >> qtd;
        if(qtd <= 0) cout << "!!! Quantidade NÃO pode ser nula ou negativa !!!\n";
        else break;
    } while(true);
    inicializaF(&F1, qtd);
    inicializaF(&F2, qtd);
    do
    {
        system("cls");
        cout << "##########MENU DE OPÇÕES##########" << endl;
        cout << "# 0 - Sair                       #" << endl;
        cout << "# 1 - Incluir na fila 1          #" << endl;
        cout << "# 2 - Remover na fila 2          #" << endl;
        cout << "# 3 - Incluir na fila 1          #" << endl;
        cout << "# 4 - Remover na fila 2          #" << endl;
        cout << "# 5 - Mostrar filas              #" << endl;
        cout << "# 6 - Intercalar filas e mostrar #" << endl;
        cout << "##################################" << endl;
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
                adicionaF(&F1);
                getchar();
                break;

            case 2:
                removeF(&F1);
                break;

            case 3:
                adicionaF(&F2);
                getchar();
                break;

            case 4:
                removeF(&F2);
                break;

            case 5:
                mostraF(&F1, "1");
                mostraF(&F2, "2");
                break;

            case 6:
                intercalaF(&F1, &F2, qtd);
                break;

        }; getchar();
    }
    while(menu != 0);
}
