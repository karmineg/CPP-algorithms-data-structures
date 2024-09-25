/*2. Considerando duas filas dinâmicas, implemente uma função para concatenar duas filas, as quais devem ser
recebidas por parâmetro. Exemplos de declaração da função:
Fila concatenaF (Fila *f1, Fila *f2);
void concatenaF (Fila *f1, Fila *f2, Fila *fConcatenada);*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>
using namespace std;

#include "filadinamica-template.hpp"

NoF<float>* concatenaF(NoF<float> *F1, NoF<float> *F2, NoF<float> *FKonk, int i, float dado){
    if(i == 1 || (i == 3 && F1 == NULL)) { // Elemento é removido em F1 ou em F2 (se F1 vazio): último elemento de FKonk será eliminado
        return removeF(FKonk);
    } else if(i == 2 || (i == 0 && F2 == NULL)) { // Elemento é adicionado em F2 ou em F1 (se F2 vazio): vai ser adicionado no FINAL de FKonk
        return adicionaF(FKonk, dado);
    } else if(i == 0) { // Elemento é adicionado em F1 (se F2 NÃO vazio): deve ser adicionado no meio de FKonk, analisar tamanho de F1
        NoF<float>* novo = new NoF<float>();
        novo->dado = dado;
        if(F1 == NULL) {
            novo->prox = FKonk;
            return novo;
        } else {
            NoF<float>* orig = FKonk;
            while(F1->prox != NULL) {
                F1 = F1->prox;
                FKonk = FKonk->prox;
            } novo->prox = FKonk->prox;
            FKonk->prox = novo;
            return orig;
        }
    } else if(i == 3) { // Elemento é removido em F2 (se F1 NÃO vazio): deve ser removido no meio de FKonk, analisar tamanho de F1
        NoF<float>* orig = FKonk;
        while(F1->prox != NULL) {
            F1 = F1->prox;
            FKonk = FKonk->prox;
        } NoF<float>* Frem = FKonk->prox;
        FKonk->prox = Frem->prox;
        delete Frem;
        return orig;
    }
}

main() {
    system ("color F2");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;
    float num1, num2;

    NoF<float>* F1 = nullptr, *F2 = nullptr, *FKonk = nullptr;

    do
    {
        system("cls");
        cout << "##########MENU DE OPÇÕES#########" << endl;
        cout << "# 0 - Sair                      #" << endl;
        cout << "# 1 - Inserir valores na fila 1 #" << endl;
        cout << "# 2 - Remover valores da fila 1 #" << endl;
        cout << "# 3 - Inserir valores na fila 2 #" << endl;
        cout << "# 4 - Remover valores da fila 2 #" << endl;
        cout << "# 5 - Mostrar filas 1, 2 e conc.#" << endl;
        cout << "#################################" << endl;
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
                cout << "Digite um número: ";
                cin >> num1;

                FKonk = concatenaF(F1, F2, FKonk, 0, num1); // Adiciona em F1 (adiciona no meio de FKonk se F2 NÃO vazia, ou no final de FKonk se F2 VAZIA)
                F1 = adicionaF(F1, num1);
                cout << "\nElemento " << num1 << " foi adicionado nos seguintes nós:" << endl;
                cout << ">> Fila um: " << F1 << endl;
                cout << ">> Fila concatenada: " << FKonk;
                getchar();
                break;

            case 2:
                if (F1 == NULL) cout << "Essa fila já está vazia!";
                else {
                    cout << "Elemento " << F1->dado << " foi removido!";
                    FKonk = concatenaF(F1, F2, FKonk, 1, NULL); // Remove em F1 (remove SEMPRE no final de FKonk)
                    F1 = removeF(F1);
                }
                break;

            case 3:
                cout << "Digite um número: ";
                cin >> num2;

                FKonk = concatenaF(F1, F2, FKonk, 2, num2); // Adiciona em F2 (adiciona SEMPRE no final de FKonk)
                F2 = adicionaF(F2, num2);
                cout << "\nElemento " << num2 << " foi adicionado nos seguintes nós:" << endl;
                cout << ">> Fila dois: " << F2 << endl;
                cout << ">> Fila concatenada: " << FKonk;
                getchar();
                break;

            case 4:
                if (F2 == NULL) cout << "Essa fila já está vazia!";
                else {
                    cout << "Elemento " << F2->dado << " foi removido!";
                    FKonk = concatenaF(F1, F2, FKonk, 3, NULL); // Remove em F2 (remove no meio de FKonk se F1 NÃO vazia ou no final de FKonk se F1 VAZIA)
                    F2 = removeF(F2);
                }
                break;

            case 5:
                mostraF(F1, "um");
                cout << endl;
                mostraF(F2, "dois");
                cout << endl;
                mostraF(FKonk, "Concatenada");
                break;

        }; getchar();
    }
    while(menu != 0);
}
