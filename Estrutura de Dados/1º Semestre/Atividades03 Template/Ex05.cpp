#include<iostream>
using namespace std;

struct Caixa {
    int codigo;
    float peso;
};

#include "template.hpp"

/* FUNÇÕES ESPECÍFICAS PARA O PROBLEMA DAS CAIXAS */
void mostrarCaixas(No<Caixa> *P) {
    if(P == NULL) cout << "!!! Pilha está VAZIA !!!\n\n";
    else {
        No<Caixa> *atual = P;
        cout << ">> Pilha das caixas\n";
        cout << "     Endereço |       Código |         Peso\n";
        cout << "--------------|--------------|--------------\n";
        while(atual != NULL) {
            cout << setfill(' ') << std::setw(13) << atual << " |";
            cout << setfill(' ') << std::setw(13) << (atual->dado).codigo << " |";
            cout << setfill(' ') << std::setw(13) << (atual->dado).peso << endl;
            atual = atual->prox;
        } cout << endl;
    }
}

int pesoTotal(No<Caixa> *P) {
    int peso = 0;
    while(P != NULL) {
        peso += (P->dado).peso;
        P = P->prox;
    } return peso;
}

bool existeItem(No<Caixa> *Pcx, int cod) {
    while(Pcx != NULL) {
        if((Pcx->dado).codigo == cod) return true;
        Pcx = Pcx->prox;
    } return false;
}

No<Caixa> *adicionaCaixa(No<Caixa> *Pcx) {
    int code;
    do {
        cout << ">> Insira o código: ";
        cin >> code;
        if(existeItem(Pcx, code)) cout << "!!! Código informado JÁ existe !!!\n";
        else break;
    } while(true);
    // VERIFICAR PESO
    float peso;
    do {
        cout << ">> Insira o peso: ";
        cin >> peso;
        if(peso <= 0) cout << "!!! Peso NÃO pode ser nulo ou negativo >:( !!!\n";
        else break;
    } while(true);
    // CRIAR A CAIXA
    Caixa C = { code, peso };
    cout << "Adicionado com sucesso!!!";
    return adicionar(Pcx, C);
}

main() {
    system ("color F2");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;

    No<Caixa> *Pcx = nullptr; // Iniciando uma pilha de caixa como nulo (ou seja, SEM itens)

    do
    {
        system("cls");
        // Opções 3 e 5 serão executadas apenas se a pilha NÃO for nula
        cout << "###########MENU DE OPÇÕES#############" << endl;
        cout << "# 0 - Sair                           #" << endl;
        cout << "# 1 - Mostrar a quantidade de caixas #" << endl;
        cout << "# 2 - Carregar caixa                 #" << endl;
        cout << "# 3 - Descarregar caixa              #" << endl;
        cout << "# 4 - Mostrar carga                  #" << endl;
        cout << "# 5 - Mostrar peso total da carga    #" << endl;
        cout << "######################################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);
        system("cls");

        switch(menu)
        {
            case 0 : // Sair
            cout << "Programa finalizado.";
            break;

            case 1:
                cout << ">> Quantidade de caixas: " << quantosItens(Pcx);
                break;

            case 2: // Inserir uma caixa na pilha
                Pcx = adicionaCaixa(Pcx);
                break;

            case 3: // Eliminar última caixa da pilha
                if(Pcx == NULL) cout << "!!! A carga do caminhão está VAZIA !!!";
                else {
                    cout << "!!! Caixa de código " << (Pcx->dado).codigo << " removida!!!";
                    Pcx = remover(Pcx);
                } break;

            case 4:
                mostrarCaixas(Pcx);
                break;

            case 5:
                if(Pcx == NULL) cout << "!!! A carga do caminhão está VAZIA !!!";
                else cout << ">> Peso total: " << pesoTotal(Pcx);
                break;

            default:
                cout << ">> Opção inválida!!!";

        }; getchar();
    }
    while(menu != 0);
}
