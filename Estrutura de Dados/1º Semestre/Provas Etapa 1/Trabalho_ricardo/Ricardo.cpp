#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
#include<string>
using namespace std;

#include "pilha-fila-dinamica-template.hpp"

// !!! OBSERVAÇÃO IMPORTANTE !!!
// O template unificado de pilha e fila utiliza um único modelo de nó tanto para fila
// quanto para pilha, sendo que para acessar ambas começa-se pelo primeiro elemento,
// portanto, no caso da pilha, acessamos primeiro a base até o topo!!!

struct Pessoa {
    string nome;
    int codigo;
    int idade;
    float saldo;
};

int existeCodigo(No<Pessoa>* Cadastro, int codigo) {
    while(Cadastro != NULL) {
        if((Cadastro->dado).codigo == codigo) return 1;
        Cadastro = Cadastro->prox;
    } return 0;
}

No<Pessoa>* buscarPessoa(No<Pessoa>* Cadastro, int codigo) {
    while(Cadastro != NULL) {
        if((Cadastro->dado).codigo == codigo) return Cadastro;
        Cadastro = Cadastro->prox;
    } return nullptr;
}

// Verificar a nova posição do nó (COM uso de pilha auxiliar)
void adicionarEmOrdemAlf(No<Pessoa>** Cadastro, No<Pessoa>** Caux, Pessoa P) {
    int add = 0;
    while(*Cadastro != NULL) {
        Pessoa p = removeP(Cadastro);
        if(p.nome[0] >= P.nome[0]) {
            adicionar(Cadastro, p);
            adicionar(Cadastro, P);
            add = 1;
            break;
        } else adicionar(Caux, p);
    }
    if(!add) adicionar(Cadastro, P);

    while(*Caux != NULL) {
        adicionar(Cadastro, removeP(Caux));
    }
}

// Adicionar novo cliente
void adicionarNovoCliente(No<Pessoa>** Cadastro, No<Pessoa>** Caux) {
    // Nome
    string nome;
    cout << "> Informe o nome da pessoa: ";
    getline(cin, nome);

    // Código
    int codigo;
    do {
        cout << "> Informe o código da pessoa: ";
        cin >> codigo;
        // TEM QUE VERIFICAR SE JÁ EXISTE O CÓDIGO
        if(existeCodigo(*Cadastro, codigo)) cout << "!!! Código inserido JÁ pertence à cliente existente !!!\n";
        else break;
    } while(true);

    // Idade
    int idade;
    do {
        cout << "> Informe a idade da pessoa: ";
        cin >> idade;
        if(idade < 0) cout << "!!! Idade NÃO pode ser negativa !!!\n";
        else break;
    } while(true);

    // Saldo
    float saldo;
    cout << "> Informe o saldo, em reais: ";
    cin >> saldo;

    Pessoa P = { nome, codigo, idade, saldo };
    adicionarEmOrdemAlf(Cadastro, Caux, P);
    cout << "!!! Novo cliente adicionado com sucesso !!!";
}

void adicionarNaFila(No<Pessoa>** F, string tipo, Pessoa P) {
    if(existeCodigo(*F, P.codigo)) cout << "!!! JÁ existe esta pessoa na fila " << tipo << " !!!";
    else {
        adicionar(F, P);
        cout << "!!! " << P.nome << " (Código: " << P.codigo << ") adicionado com sucesso na fila " << tipo << " !!!";
    }
}

void adicionarClienteFila(No<Pessoa>* Cadastro, No<Pessoa>** FP, No<Pessoa>** FN, No<Pessoa>** FD) {
    int codigo;
    cout << ">> Insira um código: ";
    cin >> codigo;

    No<Pessoa>* pessoa = buscarPessoa(Cadastro, codigo);
    if(pessoa == NULL) cout << "!!! Pessoa NÃO foi encontrada com código inserido... :(";
    else {
        Pessoa P = pessoa->dado;
        if(P.idade >= 60) adicionarNaFila(FP, "prioritária", P); // Fila prioritária
        else {
            if(P.saldo >= 0) adicionarNaFila(FN, "não prioritária", P); // Fila NÃO prioritária
            else adicionarNaFila(FD, "de devedores", P); // Fila de devedores
        }
    }
}

void mostrarPessoas(No<Pessoa>* P, string tipo) {
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

void depositoOuSaque(No<Pessoa>** F, No<Pessoa>* Cadastro, string tipo) {
    Pessoa P = removeF(F);
    No<Pessoa>* p = buscarPessoa(Cadastro, P.codigo);
    char O; // Tipo de operação
    cout << "<< Fila " << tipo << " (Código: " << P.codigo << ", Nome: " << P.nome << ")\n\n";
    do {
        cout << ">> Insira se deseja realizar saque (S) ou depósito (D): ";
        cin >> O;
        O = toupper(O);
        if(O != 'S' && O != 'D') cout << "!!! Operação inválida !!!\n";
        else break;
    } while(true);

    if(O == 'S') {
        if(P.saldo < 0) cout << "!!! Seu saldo está negativo, SÓ é possível realizar depósito !!!\n";
        else {
            float S;
            do {
                cout << ">> Insira quanto você quer sacar (em reais): ";
                cin >> S;
                if(S > P.saldo*0.8) cout << "!!! Saque é MAIOR que " << P.saldo*0.8 << "do saldo disponível !!!\n";
                else if(S <= 0) cout << "!!! Saque NÃO pode ser nulo ou negativo !!!\n";
                else break;
            } while(true);
            // Atualiza saldo direto na pilha
            cout << "!!! Saque efetuado com SUCESSO... Confira a lista !!!";
            (p->dado).saldo -= S;
        }
    } else {
        float D;
        do {
            cout << ">> Deposite uma determinada quantia: ";
            cin >> D;
            if(D < 0) cout << "!!! Depósito NÃO pode ser negativo !!!";
            break;
        } while(true);
        // Atualiza saldo direto na pilha
        cout << "!!! Depósito efetuado com SUCESSO... Confira a lista da pilha !!!";
        (p->dado).saldo += D;
    } getchar();
}

void atenderCliente(No<Pessoa>** FP, No<Pessoa>** FN, No<Pessoa>** FD, No<Pessoa>* Cadastro) {
    if(*FP != NULL) depositoOuSaque(FP, Cadastro, "prioritária");
    else {
        if(*FN != NULL) depositoOuSaque(FN, Cadastro, "não prioritária");
        else {
            if(*FD != NULL) depositoOuSaque(FD, Cadastro, "de devedores");
            else cout << "!!! NÃO existe clientes nas filas !!!";
        }
    }
}

void mostrarDados(No<Pessoa>* Cadastro) {
    int totalC = 0; // Total de clientes
    int totalCN = 0; // Total de clientes com saldo negativo
    float totalS = 0; // Total de saldo
    while(Cadastro != NULL) {
        float saldo = (Cadastro->dado).saldo;
        totalC++;
        if(saldo < 0) totalCN++;
        totalS += saldo;
        Cadastro = Cadastro->prox;
    }
    if(totalC == 0) cout << "!!! Não HÁ clientes armazenados !!!";
    else {
        cout << " Total de clientes                    | " << totalC << endl;
        cout << "--------------------------------------|-------\n";
        cout << " Total de clientes com saldo negativo | " << totalCN << endl;
        cout << "--------------------------------------|-------\n";
        cout << " Saldo total em reais                 | " << totalS << endl;
        cout << "--------------------------------------|-------\n";
        cout << " Média de saldo em reais              | " << totalS/(float)(totalC);
    }
}

main() {
    system ("color FD");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;

    No<Pessoa>** Cadastro = new No<Pessoa>*(), // Pilha de pessoas cadastradas
    ** Caux = new No<Pessoa>*(), // Pilha AUXILIAR
    ** FP = new No<Pessoa>*(), // Fila PRIORITÁRIA
    ** FN = new No<Pessoa>*(), // Fila NÃO prioritária
    ** FD = new No<Pessoa>*(); // Fila de DEVEDORES

    do {
        system("cls");
        cout << "##########MENU DE OPÇÕES##########" << endl;
        cout << "# 0 - Sair                       #" << endl;
        cout << "# 1 - Cadastrar cliente          #" << endl;
        cout << "# 2 - Adicionar cliente na fila  #" << endl;
        cout << "# 3 - Mostrar clientes           #" << endl;
        cout << "# 4 - Atender cliente da fila    #" << endl;
        cout << "# 5 - Mostrar dados do banco     #" << endl;
        cout << "##################################" << endl;
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
                adicionarNovoCliente(Cadastro, Caux);
                getchar();
                break;

            case 2:
                adicionarClienteFila(*Cadastro, FP, FN, FD);
                getchar();
                break;

            case 3: {
                char tipo;
                do {
                    cout << ">> Informe se deseja mostrar pilha (P) ou filas (F): ";
                    cin >> tipo;
                    tipo = toupper(tipo);
                    if(tipo != 'P' && tipo != 'F') cout << ">> Caractere inserido INVÁLIDO!!!\n";
                    else break;
                } while(true);
                if(tipo == 'P') mostrarPessoas(*Cadastro, "Pilha de clientes (da base para topo)");
                else {
                    mostrarPessoas(*FP, "Fila prioritária");
                    mostrarPessoas(*FN, "Fila não prioritária");
                    mostrarPessoas(*FD, "Fila devedora");
                } getchar();
                break;
            }

            case 4:
                atenderCliente(FP, FN, FD, *Cadastro);
                break;

            case 5:
                mostrarDados(*Cadastro);
                break;

            default:
                cout << "> Opção inválida!";

        }; getchar();
    }
    while(menu != 0);
}
