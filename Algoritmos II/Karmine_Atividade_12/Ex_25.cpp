/*25 - Crie um programa para manipular uma agenda telefônica, o qual deverá manipular o nome da pessoa e o
número do telefone, ao iniciar o programa os dados deverão ser lidos do arquivo texto agenda.txt, o qual
contém em cada linha o nome da pessoa; o número do telefone.
Exemplo:
Pedro da Silva;54998762217;
Maria Santos;55988762199
O sistema deverá ter um menu com as seguintes opções:
0 – Sair
1 – Incluir
2 – Mostrar todos
3 – Consultar pelo nome
4 – Consultar pelo número
5 – Excluir cadastro
Os dados devem ser atualizados no arquivo texto.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>
#include <bits/stdc++.h>

using namespace std;

string outSpace(string nome);
string informarNome();
string numero(string tipo, int Min, int Max);
string informarNumero(int cont, string *n);
string informarNumeroSemVerif();
void cadastrar(int *cont, string *nomes, string *n);
void gravarD(int cont, string *nomes, string *n);
void lerD(int cont, string *nomes, string *n);
void consultar(int cont, string valor, string *tipo, string tipoTxt);
void excluir(int *cont, string *nomes, string *n);
string lower(string txt);
string *allLower(string *nomes, int cont);

main() {
    system ("color F5");
    setlocale(LC_ALL, "Portuguese");
    string *nomes = new string[50];
    string *num = new string[50];
    int menu = -1, cont = 0;
    do
    {
        system("cls");
        cout << "########MENU DE OPÇÕES#######" << endl;
        cout << "# 0 - Sair                  #" << endl;
        cout << "# 1 - Incluir               #" << endl;
        cout << "# 2 - Mostrar todos         #" << endl;
        cout << "# 3 - Consultar pelo nome   #" << endl;
        cout << "# 4 - Consultar pelo número #" << endl;
        cout << "# 5 - Excluir cadastro      #" << endl;
        cout << "#############################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);
        system("cls");
        switch(menu)
        {
            case 0:
                cout << "Programa finalizado.";
            break;

            case 1:
                cadastrar(&cont, nomes, num);
                gravarD(cont, nomes, num);
            break;

            case 2:
                if(cont == 0)
                    cout << "Cadastre uma pessoa para acessar essa opção!";
                else
                    lerD(cont, nomes, num);
            break;

            case 3:
                if(cont == 0)
                    cout << "Cadastre uma pessoa para acessar essa opção!";
                else
                    consultar(cont, lower(informarNome()), allLower(nomes, cont), "Nome");
            break;

            case 4:
                if(cont == 0) cout << "Cadastre uma pessoa para acessar essa opção!";
                else {
                    consultar(cont, informarNumeroSemVerif(), num, "Telefone");
                    getchar();
                }
            break;

            case 5:
                if(cont == 0) cout << "Cadastre uma pessoa para acessar essa opção!";
                else {
                    excluir(&cont, nomes, num);
                    getchar();
                }
            break;

            default :
                cout << "Opção inválida.";
                break;
        };
        getchar();
    }
    while(menu != 0);

}

string outSpace(string nome) {
	string N = "";
	char arr[nome.length() + 1];

	int spc = -1;
	strcpy(arr, nome.c_str());
	for(int i = 0; i < nome.length(); i++) {
		if(arr[i] == ' ') {
            if(spc == 0)
                spc = 1;
		}
		else {
            if(spc != 0) {
                if(spc == 1)
                    N += ' ';
                    spc = 0;
		    }
            N += arr[i];
		}
	} return N;
}

string informarNome() {
    string nome = "";
    do {
        cout << "> Informe o nome: ";
        getline(cin, nome);
        nome = outSpace(nome);
        if(nome == "")
            cout << "Insira um nome!\n";
        else
            break;
    } while(true);
    return nome;
}

string numero(string tipo, int Min, int Max) {
    string valor = "";
    string newValor;
    do {
        cout << "> Informe o " << tipo << ": ";
        cin >> valor;
        newValor = "";
        for(int i = 0; i < valor.length(); i++) {
            if(isdigit(valor[i]))
                newValor += valor[i];
        }
        const int Size = newValor.length();
        if(Size >= Min && Size <= Max)
            break;
        else
            cout << tipo << " inserido inválido!\n\n";
    } while(true);
    return newValor;
}

string informarNumero(int cont, string *n) {
    string DDD = "";
    string telefone = "";
    string completo = "";
    do {
        DDD = numero("DDD", 1, 3);
        telefone = numero("Telefone", 8, 8);
        completo = DDD + telefone;
        int found = 0;
        for(int i = 0; i < cont; i++) {
            if(*n == completo) {
                found = 1;
                n -= i;
                cout << "Número de telefone cadastrado com sucesso!\n\n";
                break;
            }
            n++;
        } if(!found)
            break;
    } while(true);
    return (DDD + telefone);
}

string informarNumeroSemVerif() {
    string DDD = numero("DDD", 1, 3);
    string telefone = numero("Telefone", 8, 8);
    return (DDD + telefone);
}

void cadastrar(int *cont, string *nomes, string *n) {
    string nome = informarNome();
    *(nomes + *cont) = nome;
    cout << "Nome adicionado com sucesso! -> " << nome << "\n\n";
    string telefone = informarNumero(*cont, n);
    *(n + *cont) = telefone;
    cout << "Telefone adicionado com sucesso! -> " << telefone << "\n\n";
    *cont += 1;
    getchar();
}

void gravarD(int cont, string *nomes, string *n) {
    ofstream write;
    write.open("agenda.txt");
    for(int i = 0; i < cont; i++) {
        write << *nomes << ";" << *n << ";\n";
        nomes++;
        n++;
    } write.close();
}

void lerD(int cont, string *nomes, string *n) {
    cout << "> Nomes cadastrados <\n";
    for(int i = 0; i < cont; i++) {
        cout << "> " << *nomes << "\n" << "Número de telefone: " << *n << "\n\n";
        nomes++;
        n++;
    }
}

void consultar(int cont, string valor, string *tipo, string tipoTxt) {
    for(int i = 0; i < cont; i++) {
        if(*tipo == valor) {
            cout << "\n" << tipoTxt << " cadastrado no arquivo 'agenda.txt'!";
            return;
        } tipo++;
    } cout << "\n" << tipoTxt << " não cadastrado!";
}

void excluir(int *cont, string *nomes, string *n) {
    cout << "> Para realizar a exclusão, é necessário informar o telefone!\n\n";
    string telefone = informarNumeroSemVerif();
    for(int i = 0; i < *cont; i++) {
        if(*(n + i) == telefone) {
            cout << *(nomes + i) << " deletado!";
            for(int j = i; j < *cont - 1; j++) {
                *(n + j) = *(n + j + 1);
                *(nomes + j) = *(nomes + j + 1);
            } *cont -= 1;
            gravarD(*cont, nomes, n);
            return;
        }
    } cout << "> Não foi encontrado nome pelo telefone informado (" << telefone << ")!";
}

string lower(string txt) {
    string newtxt = "";
    for(int i = 0; i < txt.length(); i++) newtxt += tolower(txt[i]);
    return newtxt;
}

string *allLower(string *nomes, int cont) {
    string *nomesLower = new string[cont];
    for(int i = 0; i < cont; i++) {
        nomesLower[i] = lower(nomes[i]);
    } return nomesLower;
}
