/*5. Faça um programa que cadastre vários números em uma estrutura do tipo pilha. Ao remover um número da pilha,
este deve ser enfileirado em uma fila, conforme os critérios abaixo:
Critérios:
− Se o número for primo, na fila dos primos
− Se o número for par, na fila dos pares
− Se o número for ímpar, na fila dos ímpares
O menu deve conter as seguintes opções:
− Incluir na pilha
− Remover da pilha
− Mostrar pilha
− Mostrar as filas (Primos/Pares/Ímpares)*/


#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>
using namespace std;

#include "pilha-template.hpp"
#include "filacircular-template.hpp"

No<int>* adicionaItem(No<int>* P) {
    int num;
    cout << ">> Insira um elemento (número inteiro): ";
    cin >> num;
    cout << "!!! Número adicionado com sucesso !!!";
    return adicionaP(P, num);
}

// Adiciona número em apenas uma fila (com verificação de fila cheia)
void addFila(Fila<int> *F1, string name1, int num) {
    if(cheiaF(F1)) cout << "!!! A fila de " << name1 << " está CHEIA... Portanto, " << num << " não pode ser adicionado... :(";
    else {
        enfileiraF(F1, num);
        cout << "!!! " << num << " adicionado na fila de " << name1 << " !!!";
    }
}

// Adiciona número em duas filas (...)
void addFilas(Fila<int> *F1, Fila<int> *F2, string name1, string name2, int num) {
    if(cheiaF(F1)) {
        if(cheiaF(F2))  cout << "!!! Tanto a fila de " << name1 << " quanto a fila de " << name2 << " estão CHEIAS... Portanto, " << num << " não pode ser adicionado em ambas... :(";
        else {
            enfileiraF(F2, num);
            cout << "!!! " << num << " adicionado na fila de " << name2 << ", mas não na fila de " << name1 << " (cheia) !!!";
        }
    } else {
        enfileiraF(F1, num);
        cout << "!!! " << num << " adicionado na fila de " << name1;
        if(cheiaF(F2)) cout << ", mas não na fila de " << name2 << " (cheia) !!!";
        else {
            enfileiraF(F2, num);
            cout << " e na fila de " << name2 << " !!!";
        }
    }
}

No<int>* removeItem(No<int>* P, Fila<int>* FPa, Fila<int>* FIm, Fila<int>* FPr) {
    if(P == NULL) {
        cout << "!!! Pilha já está VAZIA... Insira itens!!!";
        return nullptr;
    } else {
        int absL = abs(P->dado);
        if(absL == 2) addFilas(FPr, FPa, "primo", "par", P->dado); // CASO ESPECIAL: 2 é o único par primo
        else if(absL == 1) addFila(FIm, "ímpar", P->dado); // CASO ESPECIAL: 1 é o único ímpar que não precisa verificar se é primo
        else {
            if(absL % 2 == 0) addFila(FPa, "par", P->dado);
            else {
                int isPrime = 1;
                for(int i = 3; i < absL; i += 2) {
                    if(absL % i == 0) {
                        isPrime = 0;
                        break;
                    }
                } if(isPrime) addFilas(FPr, FIm, "primo", "ímpar", P->dado);
                else addFila(FIm, "ímpar", P->dado);
            }
        } return removeP(P);
    }
}

main() {
    system ("color F2");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;

    Fila<int> FPr, FPa, FIm;
    No<int> *P = nullptr;

    inicializaF(&FPr, 3);
    inicializaF(&FIm, 3);
    inicializaF(&FPa, 3);
    do
    {
        system("cls");
        cout << "#####MENU DE OPÇÕES#####" << endl;
        cout << "# 0 - Sair             #" << endl;
        cout << "# 1 - Incluir na pilha #" << endl;
        cout << "# 2 - Remover na pilha #" << endl;
        cout << "# 3 - Mostrar pilha    #" << endl;
        cout << "# 4 - Mostrar as filas #" << endl;
        cout << "########################" << endl;
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
                P = adicionaItem(P);
                getchar();
                break;

            case 2:
                P = removeItem(P, &FPa, &FIm, &FPr);
                break;

            case 3:
                mostraP(P, "de números");
                break;

            case 4:
                mostraF(&FPa, "dos pares");
                mostraF(&FIm, "dos ímpares");
                mostraF(&FPr, "dos primos");
                break;

        }; getchar();
    }
    while(menu != 0);
}
