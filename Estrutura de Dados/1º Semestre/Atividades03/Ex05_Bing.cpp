/*5. Uma transportadora precisa de um sistema para gerenciar o carregamento de caixas nos caminh�es da empresa.
Implemente um programa que atenda a necessidade da empresa, empregando uma pilha definir a ordem do
carregamento e descarregamento de caixas de um caminh�o.
� O programa deve possuir um menu com as op��es:
o Carregar caixa - empilhar
o Descarregar caixa - desempilhar
o Mostrar carga � mostrar pilha
o Mostrar peso total da carga � criar uma fun��o em Pilha.hpp para realizar a soma do peso de
todas as caixas armazenadas na pilha.
o Mostrar a quantidade de caixas � criar uma fun��o em Pilha.hpp para contar a quantidade de
caixas na pilha.
o Sair do programa
� Cada caixa possui um c�digo e peso;
struct Caixa
{
 int codigo;
 float peso;
};
� Na estrutura N�, a vari�vel �dado� deve ser alterada para o tipo Caixa;
� Alterar as demais fun��es de Pilha.hpp para o tipo Caixa.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>
using namespace std;

struct Caixa {
    int codigo;
    float peso;
};

#include "template.hpp"

/* FUN��ES ESPEC�FICAS PARA O PROBLEMA DAS CAIXAS */
template<typename T> void mostrarCaixas(No<T> *P) {
    if(P == NULL) cout << "!!! Pilha est� VAZIA !!!\n\n";
    else {
        cout << ">> PILHAS DAS CAIXAS\n";
        No<T> *atual = P;
        cout << " Endere�o " << setfill(' ') << std::setw(6) << " | ";
        cout << " C�digo " << setfill(' ') << std::setw(8) << " | ";
        cout << " Peso" << endl;
        while(atual != NULL) {
            cout << setfill(' ') << std::setw(13) << atual << " | ";
            cout << setfill(' ') << std::setw(13) << (atual->dado).codigo << " | ";
            cout << setfill(' ') << std::setw(13) << (atual->dado).peso << endl;
            atual = atual->prox;
        } cout << endl;
    }
}

template<typename T> int pesoTotal(No<T> *P) {
    int peso = 0;
    while(P != NULL) {
        peso += (P->dado).peso;
        P = P->prox;
    } return peso;
}

No<Caixa> *adicionaCaixa(No<Caixa> *Pcx) {
    int code;
    cout << ">> Insira o c�digo: ";
    cin >> code;
    // VERIFICAR PESO
    float peso;
    do {
        cout << ">> Insira o peso: ";
        cin >> peso;
        if(peso <= 0) cout << "!!! Peso N�O pode ser nulo ou negativo >:( !!!\n";
        else break;
    } while(true);
    // CRIAR A CAIXA
    Caixa C = { code, peso };
    cout << "Adicionado com sucesso!!!";
    return adicionar<Caixa>(Pcx, C);
}

main() {
    system ("color F2");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;

    No<Caixa> *Pcx = nullptr; // Iniciando uma pilha de caixa como nulo (ou seja, SEM itens)

    do
    {
        system("cls");
        // Op��es 3 e 5 ser�o executadas apenas se a pilha N�O for nula
        cout << "###########MENU DE OP��ES#############" << endl;
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
                getchar();
                break;

            case 2: // Inserir uma caixa na pilha
                Pcx = adicionaCaixa(Pcx);
                getchar();
                break;

            case 3: // Eliminar �ltima caixa da pilha
                if(Pcx == NULL) cout << "!!! A carga do caminh�o est� VAZIA !!!";
                else {
                    Pcx = remover<Caixa>(Pcx);
                    cout << "!!! �ltima caixa removida com sucesso !!!";
                } break;

            case 4:
                mostrarCaixas<Caixa>(Pcx);
                break;

            case 5:
                if(Pcx == NULL) cout << "!!! A carga do caminh�o est� VAZIA !!!";
                else {
                    cout << ">> Peso total: " << pesoTotal(Pcx);
                }
                break;

            default:
                cout << ">> Op��o inv�lida!!!";

        }; getchar();
    }
    while(menu != 0);
}
