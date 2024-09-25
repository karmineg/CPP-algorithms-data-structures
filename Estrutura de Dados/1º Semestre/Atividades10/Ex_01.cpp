#include<iostream>
#include<fstream>
using namespace std;

#include "descritor-template.hpp"

struct Animal {
    int codigo, idade;
    string nome;
    float peso;
};

ostream& operator << (ostream &o, Animal &a) {
    return o << a.codigo << " |" << setfill(' ') << setw(12) << a.nome << " |" <<
                setfill(' ') << setw(8) << a.idade << " |" << setfill(' ') << setw(7) << a.peso;
}

bool operator==(const Animal &a, const int &c) {
    return (a.codigo == c);
}

void CriarAnimal(ListaD<Animal> *L, int *cont) {
    string nome;
    cout << "> Insira o nome do animal Nº " << *cont << ": ";
    cin >> nome;

    int idade;
    do {
        cout << "> Insira a idade do animal Nº " << *cont << ": ";
        cin >> idade;
        if(idade < 0) cout << "> Idade inserida inválida!\n";
        else break;
    } while(true);

    float peso;
    do {
        cout << "> Insira o peso do animal Nº " << *cont << ": ";
        cin >> peso;
        if(peso <= 0) cout << "> Peso inserido inválido!\n";
        else break;
    } while(true);

    cout << "> Animal adicionado na lista! O código atribuído é " << *cont;
    getchar();
    Animal A = { *cont, idade, nome, peso };
    L->adFim(A);
    *cont += 1;
}

void RemoverAnimal(ListaD<Animal> *L, string col) {
    int codigo;
    cout << "> Insira o código do animal: ";
    cin >> codigo;

    Animal *Arem = L->removeUmVal(codigo);
    if(Arem != nullptr) {
        cout << ">> Seguinte animal foi removido com sucesso: " << endl << endl;
        cout << col << endl;
        string barra = "";
        for(int i = 0; i < col.length(); i++) {
            if(col[i] == '|') barra += '|';
            else barra += '-';
        } cout << barra << "--" << endl;
        cout << setfill(' ') << setw(9) << *Arem << endl;
        delete Arem;
    } else cout << "!!! O código inserido não pertence a nenhum animal da lista !!!";
}

void miniMenu(string tit, string opt1, string opt2, ListaD<Animal> *L, string col, void(*funcao)(ListaD<Animal>*, int, string)) {
    // Mostrar menu
    int l1 = opt1.length(), l2 = opt2.length();
    int i;
    // Se a string de opção 1 for maior que a string de opção 2, adicionar espaços na opção 2 para igualar o tamanho
    if(l1 > l2) for(i = l2 + 1; i <= l1; i++) opt2 += " ";
    // Contrário de cima (adiciona espaços em opção 1 para igualar tamanho)
    else if(l1 < l2) for(i = l1 + 1; i <= l2; i++) opt1 += " ";
    string base = "";
    for(i = 0; i < opt1.length() + 8; i++) base += "#";

    cout << tit << endl << base << endl;
    cout << "# 0 - " << opt1 << " #" << endl;
    cout << "# 1 - " << opt2 << " #" << endl << base << endl << endl;

    // Inserir opção
    int opt;
    do {
        cout << ">> Insira uma das opções acima: ";
        cin >> opt;
        if(opt < 0 || opt > 1) cout << "!!! Opção inserida INVÁLIDA !!!\n";
        else {
            system("cls");
            funcao(L, opt, col);
            getchar();
            break;
        }
    } while(true);
}

void funcMostrar(ListaD<Animal> *L, int opt, string col) {
    if(opt == 0) L->mostrar("Lista de todos os animais" , col, 2, 'T');
    else L->mostrarTresUlt("Lista dos três últimos animais" , col, 2);
}

int SepararLista(ListaD<Animal> *L, string col) {
    ListaD<Animal> L1, L2;

    NoD<Animal> *N = L->inicio;
    while(N != NULL){
        Animal A = N->dado;
        if(A.peso <= 50) L1.adFim(A); // Adicionar animais leves em L1
        else L2.adFim(A); // Adicionar animais pesados em L2
        N = N->prox;
    }

    L1.mostrar("Lista de animais com 50kg OU MENOS", col, 2, 'T');
    cout << endl;
    L2.mostrar("Lista de animais com MAIS de 50kg", col, 2, 'T');

    L1.destruir();
    L2.destruir();
}

int main () {
    system ("color F2");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1, cont = 1;
    string col = "   Código |        Nome |   Idade |   Peso";

    ListaD<Animal> L;

    do
    {
        system("cls");
        cout << "#########MENU DE OPÇÕES##########" << endl;
        cout << "# 0 - Sair                      #" << endl;
        cout << "# 1 - Adicionar animal na lista #" << endl;
        cout << "# 2 - Remover animal da lista   #" << endl;
        cout << "# 3 - Mostrar animais           #" << endl;
        cout << "# 4 - Separar lista             #" << endl;
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
                CriarAnimal(&L, &cont);
                break;

            case 2:
                RemoverAnimal(&L, col);
                getchar();
                break;

            case 3:
                miniMenu("Mostrar...", "Todos os animais em ordem de chegada", "Os três últimos animais da lista", &L, col, funcMostrar);
                break;

            case 4:
                SepararLista(&L, col);
                break;

        }; getchar();
    }
    while(menu != 0);
}

