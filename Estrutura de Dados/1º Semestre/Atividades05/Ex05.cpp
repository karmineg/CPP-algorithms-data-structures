/*5. O Despachante Passo Fundo � especializado em requerimentos e encaminhamentos na documenta��o de
ve�culos. Quando um cliente chega na empresa, ele deve informar os seguintes dados para a cria��o de uma ficha de
atendimento: nome, idade, sexo, cidade e placa do ve�culo.
Ap�s o preenchido dos dados da ficha, o funcion�rio guarda a ficha em uma pilha, sendo que a ficha cuja a
cidade � Passo Fundo s�o empilhadas em PILHAPF e as fichas de outras cidades s�o empilhadas na pilha PILHAGERAL.
Agora voc� deve escrever um programa que implementa o sistema para controlar tudo que foi descrito:
f) Criar ficha de atendimento - o usu�rio deve informar os dados da ficha de atendimento e, em seguida, a ficha
deve ser empilhada na pilha correspondente;
g) Mostrar os dados das fichas de atendimento de todos os clientes (das duas as pilhas).
h) Listar as fichas da pilha PILHAPF na ordem em que eles foram preenchidas(imprimir a pilha na ordem inversa);
i) Mostrar informa��es dos clientes da pilha PILHAGERAL: n�meros de clientes de cada sexo e m�dia aritm�tica
da idade dos clientes.
j) Mostrar a placa do ve�culo da pessoa mais velha (os dados est�o armazenados nas pilhas PILHAPF e
PILHAGERAL).*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>
using namespace std;

#include "pilha-fila-dinamica-template.hpp"

struct AtendPF {
    string nome;
    int idade;
    char sexo;
    string placa;
};

struct AtendGeral {
    string cidade;
    AtendPF X; //---> Herdando atributos de AtendPF
};

struct Velho {
    string nome;
    string placa;
};

void criarFicha(No<AtendPF>** PF, No<AtendGeral>** Geral) {
    // Nome
    string nome;
    cout << "!!! Dados para ficha !!!\n>> Informe o nome: ";
    getline(cin, nome);
    // Idade
    int idade;
    do {
        cout << ">> Informe a idade: ";
        cin >> idade;
        if(idade < 0) cout << "!!! N�O existe idade nula !!!\n";
        else if(idade > 122) cout << "!!! At� agora, nenhuma pessoa viveu mais que 122 anos !!!\n";
        else break;
    } while(true);
    // Sexo
    char S;
    do {
        cout << ">> Informe o sexo - masculino (M), feminino (F) ou intersexo (I): ";
        cin >> S;
        S = toupper(S);
        if(S != 'M' && S != 'F' && S != 'I') cout << "!!! Op��o inserida INV�LIDA !!!\n";
        else break;
    } while(true);
    // Placa
    string placa;
    do {
        cout << ">> Insira a placa do ve�culo: ";
        cin.ignore();
        getline(cin, placa);
        if(placa.length() != 7) cout << "!!! Valor inserido N�O corresponde ao de uma placa !!!\n";
        else break;
    } while(true);
    // Cidade
    char pf;
    do {
        cout << ">> O cliente mora em Passo Fundo? (Digite 'S' caso sim, digite 'N' pra n�o) ";
        cin >> pf;
        if(pf != 'S' && pf != 'N' && pf != 's' && pf != 'n') cout << "!!! Op��o inv�lida !!!\n";
        else break;
    } while(true);
    AtendPF novoPF = { nome, idade, S, placa };
    if(pf == 'S' || pf == 's') {
        adicionar(PF, novoPF);
        cout << "!!! Adicionado na lista de Passo Fundo !!!";
    } else {
        string cidade;
        cout << ">> Qual a cidade? \n";
        cin.ignore();
        getline(cin, cidade);
        AtendGeral novoG = { cidade, novoPF };
        adicionar(Geral, novoG);
        cout << "!!! Adicionado na lista GERAL !!!";
    }
}

void mostrarAtendPF(AtendPF X) {
    cout << setfill(' ') << std::setw(16) << X.nome << " |";
    cout << setfill(' ') << std::setw(10) << X.idade << " |";
    cout << setfill(' ') << std::setw(10) << X.sexo << " |";
    cout << setfill(' ') << std::setw(10) << X.placa << endl;
}

void mostrarPF(No<AtendPF>* PF) {
    if(PF == NULL) cout << "!!! Lista de Passo Fundo est� VAZIA !!!\n\n";
    else {
        cout << ">> Lista de Passo Fundo\n";
        cout << "     Endere�o |            Nome |     Idade |      Sexo |     Placa \n";
        cout << "--------------|-----------------|-----------|-----------|-----------\n";
        while(PF != NULL) {
            AtendPF atual = PF->dado;
            cout << setfill(' ') << std::setw(13) << PF << " |";
            mostrarAtendPF(atual);
            PF = PF->prox;
        } cout << endl;
    }
}

// OBSERVA��O: as pilhas est�o sendo mostradas a partir do primeiro elemento inserido, portanto na fun��o seguinte (mostrar a pilha geral invertida),
// a pilha ser� mostrada a partir do �LTIMO!!
void mostrarPilhas(No<AtendPF>* PF, No<AtendGeral>* Geral) {
    // Mostrar lista de Passo Fundo
    mostrarPF(PF);

    // Mostrar lista das outras cidades
    if(Geral == NULL) cout << "!!! Lista Geral est� VAZIA !!!\n\n";
    else {
        cout << ">> Lista Geral\n";
        cout << "     Endere�o |          Cidade |            Nome |     Idade |      Sexo |     Placa \n";
        cout << "--------------|-----------------|-----------------|-----------|-----------|-----------\n";
        while(Geral != NULL) {
            AtendGeral atual = Geral->dado;
            cout << setfill(' ') << std::setw(13) << Geral << " |";
            cout << setfill(' ') << std::setw(16) << atual.cidade << " |";
            mostrarAtendPF(atual.X);
            Geral = Geral->prox;
        } cout << endl;
    }
}

void pilhaInvertida(No<AtendPF>** PF) {
    // Inverter a pilha em uma pilha auxiliar
    No<AtendPF>** PFinv = new No<AtendPF>*();
    while(*PF != NULL) adicionar(PFinv, removeP(PF));

    // Mostrar ap�s o processo
    mostrarPF(*PFinv);

    // Retornar � pilha original
    while(*PFinv != NULL) adicionar(PF, removeP(PFinv));
}

void informGeral(No<AtendGeral>* Geral) {
    if(Geral == NULL) cout << "!!! Lista geral est� VAZIA... Insira itens !!!";
    else {
        float soma = 0;
        float qtd = 0;
        int qtdM = 0, qtdF = 0;
        while(Geral != NULL) {
            AtendPF D = (Geral->dado).X;
            soma += D.idade;
            qtd++;
            if(D.sexo == 'M') qtdM++;
            else if(D.sexo == 'F') qtdF++;
            Geral = Geral->prox;
        } cout << ">> M�dia aritm�tica da idade: " << (soma/qtd) << endl;
        cout << ">> Quantidades de pessoas do sexo: " << endl;
        cout << " ** Masculino: " << qtdM << endl;
        cout << " ** Feminino: " << qtdF << endl;
        cout << " ** Intersexo: " << (qtd - (qtdM + qtdF));
    }
}

void adicionarVelho(AtendPF atual, No<Velho>** V, int* maior) {
    if(atual.idade >= *maior) {
        if(atual.idade > *maior) { // Se a atual idade � MAIOR do que a maior (at� agora), substituimos o valor de maior E destruimos a pilha dos velhos!!
            *maior = atual.idade;
            destruir(V);
        } Velho novo = { atual.nome, atual.placa };
        adicionar(V, novo); // Adicionando o novo velho na pilha
    }
}

void placaDoMaisVelho(No<AtendPF>* PF, No<AtendGeral>* Geral) {
    if(PF == NULL && Geral == NULL) cout << "!!! N�O H� itens em nenhuma das listas... Insira itens !!!";
    else {
        No<Velho>** V = new No<Velho>*();
        int *maior = new int(0); // Maior idade registrada at� ent�o...
        while(PF != NULL) {
            adicionarVelho(PF->dado, V, maior);
            PF = PF->prox;
        } while(Geral != NULL) {
            adicionarVelho((Geral->dado).X, V, maior);
            Geral = Geral->prox;
        }

        cout << ">> Pessoa(s) mais velha(s)\n";
        cout << "            Nome |           Placa \n";
        cout << "-----------------|-----------------\n";
        while(*V != NULL) {
            Velho atual = (*V)->dado;
            cout << setfill(' ') << std::setw(16) << atual.nome << " |";
            cout << setfill(' ') << std::setw(16) << atual.placa << endl;
            *V = (*V)->prox;
        }
    }
}

main() {
    system ("color F2");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;

    No<AtendPF> **PF = new No<AtendPF>*(); // Fichas de Passo Fundo
    No<AtendGeral> **Geral = new No<AtendGeral>*(); // Fichas de outras cidades
    string cidade;

    do
    {
        system("cls");
        cout << "#####################MENU DE OP��ES#########################" << endl;
        cout << "# 0 - Sair                                                 #" << endl;
        cout << "# 1 - Criar ficha de atendimento                           #" << endl;
        cout << "# 2 - Mostrar os dados das fichas de atendimento           #" << endl;
        cout << "# 3 - Listar as fichas da pilha PILHAPF                    #" << endl;
        cout << "# 4 - Mostrar informa��es dos clientes da pilha PILHAGERAL #" << endl;
        cout << "# 5 - Mostrar a placa do ve�culo da pessoa mais velha      #" << endl;
        cout << "############################################################" << endl;
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
                criarFicha(PF, Geral);
                break;

            case 2:
                mostrarPilhas(*PF, *Geral);
                break;

            case 3:
                pilhaInvertida(PF);
                break;

            case 4:
                informGeral(*Geral);
                break;

            case 5:
                placaDoMaisVelho(*PF, *Geral);
                break;

        }; getchar();
    }
    while(menu != 0);
}
