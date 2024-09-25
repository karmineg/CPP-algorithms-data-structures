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
        mostrar(P->dado, "de endere�o " + S.str());
        P = P->prox;
    }
}

void addNum(No<No<int>*> *P) {
    int num;
    cout << ">> Insira um n�mero: ";
    cin >> num;
    (P->dado) = adicionar(P->dado, num);
    cout << "!!! N�mero adicionado com SUCESSO !!!";
}

void removeNum(No<No<int>*> *P) {
    if(P->dado == NULL) cout << "!!! Esta pilha J� EST� vazia... Insira n�meros !!!";
    else {
        cout << "!!! Seguinte n�mero foi removido da pilha: " << (P->dado)->dado << " !!!";
        (P->dado) = remover(P->dado);
    }
}

void searchNum(No<No<int>*> *P) {
    int num;
    cout << ">> Insira um n�mero: ";
    cin >> num;
    No<int>* p = P->dado;
    while(p != NULL) {
        if(p->dado == num) {
            cout << "!!! N�mero ENCONTRADO no endere�o " << p << " !!!";
            return;
        } p = p->prox;
    } cout << "!!! N�mero inserido N�O EST� na pilha selecionada !!!";
    //(P->dado) = adicionar(P->dado, num);
    //cout << "!!! N�mero adicionado com SUCESSO !!!";
}

void funcEndr(No<No<int>*> *P, void (*funcao)(No<No<int>*>*)) {
    string endr = "";
    cout << ">> Insira o endere�o: ";
    cin >> endr;
    while(P != NULL) {
        ostringstream S;
        S << P;
        if(S.str() == endr) {
            funcao(P);
            return;
        } P = P->prox;
    } cout << "!!! N�O EXISTE pilha com endere�o inserido !!!";
}

int main() {
    system("color 5F");
    setlocale(LC_ALL, "Portuguese");

    No<No<int>*> *P = nullptr;
    int menu = -1;
    do
    {
        system("cls");
        cout << "######### MENU DE OP��ES #########" << endl;
        cout << "# 0 - Sair do programa           #" << endl;
        cout << "# 1 - Adicionar nova pilha       #" << endl;
        cout << "# 2 - Remover �ltima pilha       #" << endl;
        cout << "# 3 - Adicionar n�mero em pilha  #" << endl;
        cout << "# 4 - Remover n�mero em pilha    #" << endl;
        cout << "# 5 - Buscar n�mero em pilha     #" << endl;
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
                    cout << ">> Pilha de endere�o " << P << " removido com SUCESSO!!";
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
                cout << "Op��o inv�lida.";
                break;
        }; getchar();
    }
    while(menu != 0);
}
