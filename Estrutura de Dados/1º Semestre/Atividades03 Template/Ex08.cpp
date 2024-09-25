#include<iostream>
#include<sstream>
using namespace std;

#include "template.hpp"

No<No<int>*> *adicionarPilha(No<No<int>*> *P) {
    No<int> *novo = nullptr;
    cout << ">> Pilha adicionada com SUCESSO!!";
    return adicionar(P, novo);
}

void mostrarPilhas(No<No<int>*> *P) {
    if(P == NULL) {
        cout << "!!! NENHUMA pilha inserida !!!";
        return;
    } while(P != NULL) {
        ostringstream S;
        S << P;
        mostrar(P->dado, "de endereço " + S.str());
        P = P->prox;
    }
}

void addNum(No<No<int>*> *P) {
    int num;
    cout << ">> Insira um número: ";
    cin >> num;
    (P->dado) = adicionar(P->dado, num);
    cout << "!!! Número adicionado com SUCESSO !!!";
}

void removeNum(No<No<int>*> *P) {
    if(P->dado == NULL) cout << "!!! Esta pilha JÁ ESTÁ vazia... Insira números !!!";
    else {
        cout << "!!! Seguinte número foi removido da pilha: " << (P->dado)->dado << " !!!";
        (P->dado) = remover(P->dado);
    }
}

void searchNum(No<No<int>*> *P) {
    int num;
    cout << ">> Insira um número: ";
    cin >> num;
    No<int>* p = P->dado;
    while(p != NULL) {
        if(p->dado == num) {
            cout << "!!! Número ENCONTRADO no endereço " << p << " !!!";
            return;
        } p = p->prox;
    } cout << "!!! Número inserido NÃO ESTÁ na pilha selecionada !!!";
    //(P->dado) = adicionar(P->dado, num);
    //cout << "!!! Número adicionado com SUCESSO !!!";
}

void funcEndr(No<No<int>*> *P, void (*funcao)(No<No<int>*>*)) {
    string endr = "";
    cout << ">> Insira o endereço: ";
    cin >> endr;
    while(P != NULL) {
        ostringstream S;
        S << P;
        if(S.str() == endr) {
            funcao(P);
            return;
        } P = P->prox;
    } cout << "!!! NÃO EXISTE pilha com endereço inserido !!!";
}

int main() {
    system("color 5F");
    setlocale(LC_ALL, "Portuguese");

    No<No<int>*> *P = nullptr;
    int menu = -1;
    do
    {
        system("cls");
        cout << "######### MENU DE OPÇÕES #########" << endl;
        cout << "# 0 - Sair do programa           #" << endl;
        cout << "# 1 - Adicionar nova pilha       #" << endl;
        cout << "# 2 - Remover última pilha       #" << endl;
        cout << "# 3 - Adicionar número em pilha  #" << endl;
        cout << "# 4 - Remover número em pilha    #" << endl;
        cout << "# 5 - Buscar número em pilha     #" << endl;
        cout << "# 6 - Mostrar pilhas             #" << endl;
        cout << "##################################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);
        system("cls");

        switch(menu)
        {
            case 0 :
                cout << "Programa encerrado!!";
                menu = 0;
            break;

            case 1:
                P = adicionarPilha(P);
            break;

            case 2:
                if(P == NULL) cout << "!!! Pilha completamente VAZIA !!!";
                else {
                    cout << ">> Pilha de endereço " << P << " removido com SUCESSO!!";
                    P->dado = destruir(P->dado);
                    P = remover(P);
                }
            break;

            case 3:
                if(P == NULL) cout << "!!! Pilha completamente VAZIA !!!";
                else funcEndr(P, addNum);
                getchar();
            break;

            case 4:
                if(P == NULL) cout << "!!! Pilha completamente VAZIA !!!";
                else funcEndr(P, removeNum);
                getchar();
            break;

            case 5:
                if(P == NULL) cout << "!!! Pilha completamente VAZIA !!!";
                else funcEndr(P, searchNum);
                getchar();
            break;

            case 6:
                mostrarPilhas(P);
            break;

            default :
                cout << "Opção inválida.";
                break;
        }; getchar();
    }
    while(menu != 0);
}
