/*18 – Crie um programa que apresente um menu com as seguintes opções:
0 – Sair
1 – Cadastrar
2 – Mostrar
3 – Consultar
Onde, a opção 1 permita que o usuário informe o nome completo de uma pessoa e o sistema deverá incluir este nome em
um arquivo texto chamado “cadastro.txt”, colocando cada nome em uma linha e mantendo os nomes já cadastrados.
Opção 2 deverá ler o arquivo texto e mostrar os nomes na tela.
Opção 3 deverá solicitar um nome qualquer e verificar se o nome já existe no arquivo texto. Exibindo a respectiva
informação na tela.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<bits/stdc++.h>

using namespace std;

string outSpace(string nome);
string informarNome();
void cadastrar(int *cont, string *nomes);
void gravarDados(int cont, string *nomes);
void lerDados(int cont, string *nomes);
bool consultar(int cont,  string *nomes);

main() {
    system ("color F5");
    setlocale(LC_ALL, "Portuguese");
    string *nomes = new string[50];
    int menu = -1, cont = 0;
    do
    {
        system("cls");
        cout << "######MENU DE OPÇÕES#####" << endl;
        cout << "# 0 - Sair              #" << endl;
        cout << "# 1 - Cadastrar pessoa  #" << endl;
        cout << "# 2 - Mostrar pessoa    #" << endl;
        cout << "# 3 - Consultar pessoa  #" << endl;
        cout << "#########################" << endl;
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
                cadastrar(&cont, nomes);
                gravarDados(cont, nomes);
            break;

            case 2:
                if(cont == 0)
                    cout << "É necessário cadastrar uma pessoa antes de realizar essa opção!";
                else
                    lerDados(cont, nomes);
            break;

            case 3:
                if(cont == 0)
                    cout << "É necessário cadastrar uma pessoa antes de realizar essa opção!";
                else
                    consultar(cont, nomes);
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
	int spc = 0;
	int letra = 0;
	strcpy(arr, nome.c_str());

	for(int i = 0; i < nome.length(); i++) {
		if(arr[i] == ' ') {
            if(letra && !spc) {
                N += ' ';
                spc = 1;
            }
		}
		else {
            letra = 1;
            N += arr[i];
		}
	} return N;
}

string informarNome() {
    string nome = "";
    do {
        cout << "> Informe o nome da pessoa: ";
        getline(cin, nome);
        nome = outSpace(nome);
        if(nome == "")
            cout << "\nInforme um nome!\n";
        else
            break;
    } while(true);
    return nome;
}

void cadastrar(int *cont, string *nomes) {
    string nome = informarNome();
    *(nomes + *cont) = nome;
    cout << "Nome cadastrado: " << nome;
    *cont += 1;
}

void gravarDados(int cont, string *nomes) {
    ofstream objeto;
    objeto.open("cadastro.txt");
    for(int i = 0; i < cont; i++) {
        objeto << *nomes << ";\n";
        nomes++;
    } objeto.close();
}

void lerDados(int cont, string *nomes) {
    cout << "Nomes cadastrados:\n";
    for(int i = 0; i < cont; i++) {
        cout << "> " << *nomes << "\n";
        nomes++;
    }
}

bool consultar(int cont,  string *nomes) {
    string nome = "";
    cout << "> Informe o nome da pessoa cadastrada: ";
    getline(cin, nome);
    bool encontrado = false;

    for(int i = 0; i < cont; i++) {
        if(*nomes == nome) {
            cout << "Nome cadastrado no arquivo texto!\n";
            encontrado = true;
            break;
        }
        nomes++;
    }
    if(!encontrado) {
        cout << "Nome inserido não cadastrado!" << "\n";
    }
    return encontrado;
}
