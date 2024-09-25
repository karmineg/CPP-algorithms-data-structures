/*5. Uma transportadora precisa de um sistema para gerenciar o carregamento de caixas nos caminhões da empresa.
Implemente um programa que atenda a necessidade da empresa, empregando uma pilha definir a ordem do
carregamento e descarregamento de caixas de um caminhão.
• O programa deve possuir um menu com as opções:
o Carregar caixa - empilhar
o Descarregar caixa - desempilhar
o Mostrar carga – mostrar pilha
o Mostrar peso total da carga – criar uma função em Pilha.hpp para realizar a soma do peso de
todas as caixas armazenadas na pilha.
o Mostrar a quantidade de caixas – criar uma função em Pilha.hpp para contar a quantidade de
caixas na pilha.
o Sair do programa
• Cada caixa possui um código e peso;
struct Caixa
{
 int codigo;
 float peso;
};
• Na estrutura Nó, a variável “dado” deve ser alterada para o tipo Caixa;
• Alterar as demais funções de Pilha.hpp para o tipo Caixa.
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

/* FUNÇÕES ESPECÍFICAS PARA O PROBLEMA DAS CAIXAS */
template<typename T> void mostrarCaixas(No<T> *P) {
    if(P == NULL) cout << "!!! Pilha está VAZIA !!!\n\n";
    else {
        cout << ">> PILHAS DAS CAIXAS\n";
        No<T> *atual = P;
        cout << " Endereço " << setfill(' ') << std::setw(6) << " | ";
        cout << " Código " << setfill(' ') << std::setw(8) << " | ";
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
    cout << ">> Insira o código: ";
    cin >> code;
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
                getchar();
                break;

            case 2: // Inserir uma caixa na pilha
                Pcx = adicionaCaixa(Pcx);
                getchar();
                break;

            case 3: // Eliminar última caixa da pilha
                if(Pcx == NULL) cout << "!!! A carga do caminhão está VAZIA !!!";
                else {
                    Pcx = remover<Caixa>(Pcx);
                    cout << "!!! Última caixa removida com sucesso !!!";
                } break;

            case 4:
                mostrarCaixas<Caixa>(Pcx);
                break;

            case 5:
                if(Pcx == NULL) cout << "!!! A carga do caminhão está VAZIA !!!";
                else {
                    cout << ">> Peso total: " << pesoTotal(Pcx);
                }
                break;

            default:
                cout << ">> Opção inválida!!!";

        }; getchar();
    }
    while(menu != 0);
}
