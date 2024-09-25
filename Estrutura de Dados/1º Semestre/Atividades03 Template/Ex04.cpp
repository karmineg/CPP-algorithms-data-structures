#include<iostream>
using namespace std;

#include "template.hpp"

No<int> *adicionaItem(No<int> *P, string num) {
    int elem;
    cout << ">> Insira um valor para pilha " << num << ": ";
    cin >> elem;
    return adicionar(P, elem);
}

void contarPares(No<int> *P, string num) {
    if(P == NULL) {
        cout << ">> NÃO HÁ ITENS na pilha " << num << "!!! :,(";
        return;
    }
    int cont = 0;
    while(P != NULL) {
        cont += 1 - abs((P->dado) % 2);
        P = P->prox;
    }

    if(cont == 0) cout << ">> NÃO tem números pares na pilha " << num << "!!! >:(";
    else if(cont == 1) cout << ">> Há apenas um número par na pilha " << num << "... :(";
    else cout << ">> Há " << cont << " números pares na pilha " << num << "... :)";
}

void analisaP(No<int> *P1, No<int> *P2) {
    string erro = "";
    // Endereços originais
    No<int> *p1 = P1;
    No<int> *p2 = P2;

    if(P1 == NULL && P2 != NULL) erro = "a pilha 1 está VAZIA... Insira itens!!";
    else if(P1 != NULL && P2 == NULL) erro = "a pilha 2 está VAZIA... Insira itens!!";
    else if(P1 == NULL && P2 == NULL) erro = "ambas as pilhas estão VAZIAS... Insira itens!!";
    while(erro == "") {
        if(P1->dado == P2->dado) {
            if(P1->prox == NULL && P2->prox == NULL) { // A análise chegou ao final de ambas as pilhas simultaneamente, logo é IGUAL
                break;
            } else if(P1->prox != NULL && P2->prox != NULL) { // Se ainda não chegamos ao final de uma das pilhas, CONTINUAR a análise
                // Passando para o próximo
                P1 = P1->prox;
                P2 = P2->prox;
            } else erro = "NÃO possuem o mesmo tamanho"; // Se chegamos ao final de uma das pilhas, AUTOMATICAMENTE as pilhas NÃO são iguais
        } else erro = "ao percorrer a partir do topo, dois correspondentes não são iguais";
    } if(erro == "") cout << "Ambas as pilhas são IGUAIS!!\n\n";
    else cout << "As pilhas NÃO são iguais, pois " << erro << "... :(\n\n";
    mostrar(p1, "1");
    cout << endl;
    mostrar(p2, "2");
}

main() {
    system ("color F2");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;

    No<int> *P1 = nullptr;
    No<int> *P2 = nullptr;

    do
    {
        system("cls");
        cout << "################MENU DE OPÇÕES#################" << endl;
        cout << "# 0 - Sair                                    #" << endl;
        cout << "# 1 - Inserir elementos na pilha um           #" << endl;
        cout << "# 2 - Inserir elementos na pilha dois         #" << endl;
        cout << "# 3 - Ver se as pilhas são iguais             #" << endl;
        cout << "# 4 - Conferir quantidade de pares nas pilhas #" << endl;
        cout << "###############################################" << endl;
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
                P1 = adicionaItem(P1, "1");
                break;

            case 2:
                P2 = adicionaItem(P2, "2");
                break;

            case 3:
                analisaP(P1, P2);
                break;

            case 4:
                contarPares(P1, "1");
                cout << endl;
                contarPares(P2, "2");
                break;

        }; getchar();
    }
    while(menu != 0);
}
