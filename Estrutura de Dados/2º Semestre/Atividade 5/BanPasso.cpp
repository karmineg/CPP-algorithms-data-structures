#include<iostream>
using namespace std;
#include"pilha-dinamica.hpp"

struct Pessoa {
    string nome;
    int codigo;
    int idade;
    float saldo;
};

bool operator<(const Pessoa &P1, const Pessoa &P2) {
    return (P1.nome < P2.nome);
}

bool operator==(const Pessoa &C, const int &codigo) {
    return (codigo == C.codigo);
}

void mostrarPessoasP(No<Pessoa>* P, string tipo) {
    if(P == NULL) cout << "!!! " << tipo << " está VAZIA !!!\n\n";
    else {
        cout << ">> " << tipo << "\n";
        cout << "     Endereço |            Nome |    Código |     Idade |     Saldo \n";
        cout << "--------------|-----------------|-----------|-----------|-----------\n";
        while(P != NULL) {
            Pessoa p = P->dado;
            cout << setfill(' ') << std::setw(13) << P << " |";
            cout << setfill(' ') << std::setw(16) << p.nome << " |";
            cout << setfill(' ') << std::setw(10) << p.codigo << " |";
            cout << setfill(' ') << std::setw(10) << p.idade << " |";
            cout << setfill(' ') << std::setw(10) << p.saldo << endl;
            P = P->prox;
        } cout << endl;
    }
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;

    No<Pessoa>* Cadastro = nullptr;

    do {
        system("cls");
        cout << "#####MENU DE OPÇÕES######" << endl;
        cout << "# 0 - Sair              #" << endl;
        cout << "# 1 - Cadastrar cliente #" << endl;
        cout << "# 2 - Mostrar clientes  #" << endl;
        cout << "#########################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);
        system("cls");

        switch(menu)
        {
            case 0 :
                cout << "Programa finalizado.";
                break;

            case 1: {
                // Nome
                string nome;
                cout << "> Informe o nome da pessoa: ";
                getline(cin, nome);

                // Código
                int codigo;
                do {
                    cout << "> Informe o código da pessoa: ";
                    cin >> codigo;
                    if(buscaSTRUCT(Cadastro, codigo)) cout << "> Código inserido já pertence à um cliente existente!\n";
                    else break;
                } while(true);

                // Idade
                int idade;
                do {
                    cout << "> Informe a idade da pessoa: ";
                    cin >> idade;
                    if(idade < 0) cout << "> Idade não pode ser negativa!\n";
                    else break;
                } while(true);

                // Saldo
                float saldo;
                cout << "> Informe o saldo(R$): ";
                cin >> saldo;

                Pessoa P = { nome, codigo, idade, saldo };
                Cadastro = adicionaOrdenado(Cadastro, P, false);
                cout << "\n> Novo cliente adicionado com sucesso!";
                getchar();
                break;

            } case 2: {
                mostrarPessoasP(Cadastro, "Pilha de clientes (da base para topo)");
                break;

            } default:
                cout << "> Opção inválida!";

        }; getchar();
    }
    while(menu != 0);
}
