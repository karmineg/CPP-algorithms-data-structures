#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
#include<string>
using namespace std;

#include "pilha-fila-dinamica-template.hpp"

// !!! OBSERVA��O IMPORTANTE !!!
// O template unificado de pilha e fila utiliza um �nico modelo de n� tanto para fila
// quanto para pilha, sendo que para acessar ambas come�a-se pelo primeiro elemento,
// portanto, no caso da pilha, acessamos primeiro a base at� o topo!!!

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

// Verificar a nova posi��o do n� (COM uso de pilha auxiliar)
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

    // C�digo
    int codigo;
    do {
        cout << "> Informe o c�digo da pessoa: ";
        cin >> codigo;
        // TEM QUE VERIFICAR SE J� EXISTE O C�DIGO
        if(existeCodigo(*Cadastro, codigo)) cout << "!!! C�digo inserido J� pertence � cliente existente !!!\n";
        else break;
    } while(true);

    // Idade
    int idade;
    do {
        cout << "> Informe a idade da pessoa: ";
        cin >> idade;
        if(idade < 0) cout << "!!! Idade N�O pode ser negativa !!!\n";
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
    if(existeCodigo(*F, P.codigo)) cout << "!!! J� existe esta pessoa na fila " << tipo << " !!!";
    else {
        adicionar(F, P);
        cout << "!!! " << P.nome << " (C�digo: " << P.codigo << ") adicionado com sucesso na fila " << tipo << " !!!";
    }
}

void adicionarClienteFila(No<Pessoa>* Cadastro, No<Pessoa>** FP, No<Pessoa>** FN, No<Pessoa>** FD) {
    int codigo;
    cout << ">> Insira um c�digo: ";
    cin >> codigo;

    No<Pessoa>* pessoa = buscarPessoa(Cadastro, codigo);
    if(pessoa == NULL) cout << "!!! Pessoa N�O foi encontrada com c�digo inserido... :(";
    else {
        Pessoa P = pessoa->dado;
        if(P.idade >= 60) adicionarNaFila(FP, "priorit�ria", P); // Fila priorit�ria
        else {
            if(P.saldo >= 0) adicionarNaFila(FN, "n�o priorit�ria", P); // Fila N�O priorit�ria
            else adicionarNaFila(FD, "de devedores", P); // Fila de devedores
        }
    }
}

void mostrarPessoas(No<Pessoa>* P, string tipo) {
    if(P == NULL) cout << "!!! " << tipo << " est� VAZIA !!!\n\n";
    else {
        cout << ">> " << tipo << "\n";
        cout << "     Endere�o |            Nome |    C�digo |     Idade |     Saldo \n";
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
    char O; // Tipo de opera��o
    cout << "<< Fila " << tipo << " (C�digo: " << P.codigo << ", Nome: " << P.nome << ")\n\n";
    do {
        cout << ">> Insira se deseja realizar saque (S) ou dep�sito (D): ";
        cin >> O;
        O = toupper(O);
        if(O != 'S' && O != 'D') cout << "!!! Opera��o inv�lida !!!\n";
        else break;
    } while(true);

    if(O == 'S') {
        if(P.saldo < 0) cout << "!!! Seu saldo est� negativo, S� � poss�vel realizar dep�sito !!!\n";
        else {
            float S;
            do {
                cout << ">> Insira quanto voc� quer sacar (em reais): ";
                cin >> S;
                if(S > P.saldo*0.8) cout << "!!! Saque � MAIOR que " << P.saldo*0.8 << "do saldo dispon�vel !!!\n";
                else if(S <= 0) cout << "!!! Saque N�O pode ser nulo ou negativo !!!\n";
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
            if(D < 0) cout << "!!! Dep�sito N�O pode ser negativo !!!";
            break;
        } while(true);
        // Atualiza saldo direto na pilha
        cout << "!!! Dep�sito efetuado com SUCESSO... Confira a lista da pilha !!!";
        (p->dado).saldo += D;
    } getchar();
}

void atenderCliente(No<Pessoa>** FP, No<Pessoa>** FN, No<Pessoa>** FD, No<Pessoa>* Cadastro) {
    if(*FP != NULL) depositoOuSaque(FP, Cadastro, "priorit�ria");
    else {
        if(*FN != NULL) depositoOuSaque(FN, Cadastro, "n�o priorit�ria");
        else {
            if(*FD != NULL) depositoOuSaque(FD, Cadastro, "de devedores");
            else cout << "!!! N�O existe clientes nas filas !!!";
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
    if(totalC == 0) cout << "!!! N�o H� clientes armazenados !!!";
    else {
        cout << " Total de clientes                    | " << totalC << endl;
        cout << "--------------------------------------|-------\n";
        cout << " Total de clientes com saldo negativo | " << totalCN << endl;
        cout << "--------------------------------------|-------\n";
        cout << " Saldo total em reais                 | " << totalS << endl;
        cout << "--------------------------------------|-------\n";
        cout << " M�dia de saldo em reais              | " << totalS/(float)(totalC);
    }
}

main() {
    system ("color FD");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;

    No<Pessoa>** Cadastro = new No<Pessoa>*(), // Pilha de pessoas cadastradas
    ** Caux = new No<Pessoa>*(), // Pilha AUXILIAR
    ** FP = new No<Pessoa>*(), // Fila PRIORIT�RIA
    ** FN = new No<Pessoa>*(), // Fila N�O priorit�ria
    ** FD = new No<Pessoa>*(); // Fila de DEVEDORES

    do {
        system("cls");
        cout << "##########MENU DE OP��ES##########" << endl;
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
                    if(tipo != 'P' && tipo != 'F') cout << ">> Caractere inserido INV�LIDO!!!\n";
                    else break;
                } while(true);
                if(tipo == 'P') mostrarPessoas(*Cadastro, "Pilha de clientes (da base para topo)");
                else {
                    mostrarPessoas(*FP, "Fila priorit�ria");
                    mostrarPessoas(*FN, "Fila n�o priorit�ria");
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
                cout << "> Op��o inv�lida!";

        }; getchar();
    }
    while(menu != 0);
}
