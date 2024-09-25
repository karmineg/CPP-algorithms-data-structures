/*2. Crie as seguintes fun��es:*/

#include<iostream>
using namespace std;

#include "lista-template.hpp"

string saoIguais(No<int>* L1, No<int>* L2) {
    int ind = 0;
    while(L1 != NULL) {
        if(L2 == NULL) return "Lista 1 � MAIOR que lista 2, logo N�O s�o iguais!!";
        if(L1->dado != L2->dado) return ("Dados no �ndice " + to_string(ind) + " N�O s�o iguais, logo as listas tamb�m n�o!!");
        L1 = L1->prox;
        L2 = L2->prox;
        ind++;
    } if(L2 != NULL) return "Lista 2 � MAIOR que lista 1, logo N�O s�o iguais!!";
    return "Ambas as listas S�O iguais!!";
}

void escolherLista(No<int>** L1, No<int>** L2, string acao, void(*funcao)(No<int>**, No<int>**, int)) {
    do {
        int N;
        cout << "> Em qual lista voc� deseja " << acao << "? (1 ou 2) ";
        cin >> N;
        if(N == 1 || N == 2) {
            funcao(L1, L2, N);
            break;
        } else cout << "!!! ERRO: N�mero inserido para lista inexiste !!!\n";
    } while(true);
    getchar();
}

void adicionarItem(No<int>** L1, No<int>** L2, int N) {
    int num;
    cout << "> Digite um valor para adicionar na lista: ";
    cin >> num;

    if(N == 1) adicionarFim(L1, num);
    else adicionarFim(L2, num);
    cout << "> Valor adicionado na lista com sucesso!";
}

void removerDoFim(No<int>** L1, No<int>** L2, int N) {
    int num = NULL;
    if(N == 1 && *L1 != NULL) num = removeFim(L1);
    else if(N == 2 && *L2 != NULL) num = removeFim(L2);
    if(num != NULL) cout << "> Valor " << num << " removido da lista com sucesso!";
    else cout << "!!! Lista " << N << " J� EST� VAZIA !!!";
}

void buscarPos(No<int>** L1, No<int>** L2, int N) {
    bool vazio = ((N == 1 && *L1 == NULL) || (N == 2 && *L2 == NULL));
    if(vazio) cout << "> Lista " << N << " est� vazia, imposs�vel fazer uma busca!";
    else {
        int P;
        cout << "> Insira um �ndice para buscar dado: ";
        cin >> P;

        int dado = NULL;
        if(N == 1) dado = buscarPosicao(*L1, P);
        else dado = buscarPosicao(*L2, P);
        if(dado != NULL) cout << "> N�mero ENCONTRADO: " << dado;
    }
}

void mostrarFim(No<int>* L, int n) {
    int fim = lerFim(L);
    if(fim == NULL) cout << "> N�o h� itens na lista " << n << endl;
    else cout << "> Valor no final da lista 1: " << fim << endl;
}

No<int>* novoPont(No<int>* L, No<int>** Lconc, No<int>* atual) {
    No<int>* novo = new No<int>();
    novo->dado = L->dado;
    if(*Lconc == NULL) *Lconc = novo;
    else atual->prox = novo;
    return novo;
}

void concatenar(No<int>* L1, No<int>* L2, No<int>** Lconc) {
    if(*Lconc != NULL) destruir(Lconc);
    else {
        No<int>* atual = nullptr;
        while(L1 != NULL) {
            atual = novoPont(L1, Lconc, atual);
            L1 = L1->prox;
        } while(L2 != NULL) {
            atual = novoPont(L2, Lconc, atual);
            L2 = L2->prox;
        }
    }
}

main() {
    system ("color F2");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;

    //No<>** nome = new No<>*(); -> Declara��o padr�o para criar uma lista
    No<int>** L1 = new No<int>*(),
    ** L2 = new No<int>*(),
    ** Lconc = new No<int>*();

    do
    {
        system("cls");
        cout << "###########MENU DE OP��ES############" << endl;
        cout << "# 0 - Sair                          #" << endl;
        cout << "# 1 - Inserir valor na lista        #" << endl; // Escolher
        cout << "# 2 - Verifica total elementos      #" << endl;
        cout << "# 3 - Verifica se listas s�o iguais #" << endl;
        cout << "# 4 - Ler valor do final            #" << endl;
        cout << "# 5 - Remover valor do final        #" << endl; // Escolher
        cout << "# 6 - Ler posi��o de um valor       #" << endl; // Escolher
        cout << "# 7 - Mostrar filas                 #" << endl;
        cout << "# 8 - Unir filas e mostrar          #" << endl;
        cout << "#####################################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);
        system("cls");

        switch(menu) {
            case 0 :
            cout << "Programa finalizado.";
            break;

            case 1:
                escolherLista(L1, L2, "adicionar", adicionarItem);
                break;

            case 2:
                cout << "> Total de elementos na lista 1: " << quantosItens(*L1) << endl;
                cout << "> Total de elementos na lista 2: " << quantosItens(*L2);
                break;

            case 3:
                cout << saoIguais(*L1, *L2);
                break;

            case 4:
                mostrarFim(*L1, 1);
                mostrarFim(*L2, 2);
                break;

            case 5:
                escolherLista(L1, L2, "remover", removerDoFim);
                break;

            case 6:
                escolherLista(L1, L2, "buscar", buscarPos);
                break;

            case 7:
                mostrar(*L1, "Lista 1");
                cout << endl;
                mostrar(*L2, "Lista 2");
                cout << endl;
                break;

            case 8:
                concatenar(*L1, *L2, Lconc);
                mostrar(*Lconc, "Lista concatenada");
                break;

            default:
                cout << "!!! Op��o inv�lida !!!";
        } getchar();
    } while(menu != 0);
}
