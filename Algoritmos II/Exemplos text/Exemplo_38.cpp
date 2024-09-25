#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;

struct cadastro
{
    char nome[100];
    int idade;
    float salario;
};

void carregar_dados (cadastro x[], int &i);
void ler (cadastro x[], int &i);
void mostra (cadastro x[], int i);
float media (cadastro x[], int i);
void gravar_dados (cadastro x[], int &i);

main()
{
    cadastro cad[30];
    int menu = -1, indice = -1;
    carregar_dados(cad, indice);

    do
    {
        system("cls");
        cout << "MENU DE OPCOES" << endl;
        cout << "0 - Sair" << endl;
        cout << "1 - Cadastrar" << endl;
        cout << "2 - Mostrar" << endl;
        cout << "3 - Media de idade" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);

        switch(menu)
        {
        case 0:
            gravar_dados(cad, indice);
            cout << "DADOS ATUALIZADOS NO ARQUIVO TEXTO!";
            cout << "PROGRAMA FINALIZADO!";
            getchar();
            break;
        case 1:
            system("cls");
            ler(cad, indice);
            gravar_dados(cad, indice);
            break;
        case 2:
            system("cls");
            if(indice < 0)
                cout << "NAO EXISTE NENHUM CADASTRO ATUALMENTE!";
            else
                mostra(cad, indice);
            getchar();
            break;
        case 3:
            system("cls");
            if(indice < 0)
                cout << "NAO EXISTE NENHUM CADASTRO ATUALMENTE!";
            else
                cout << "MEDIA DAS IDADES: " << media(cad, indice);
            getchar();
            break;
        };
    }
    while(menu != 0);
}

void carregar_dados (cadastro x[], int &i)
{
    char aux[100];
    int cont = 0;
    ifstream ler("exemplo_46.txt");
    if(ler.is_open())
    {
        ler.getline(aux, 100, ';');
        while(!ler.fail())
        {
            if(cont == 0)
               i++;
            cont++;
            if(cont == 1)
            {
                strcpy(x[i].nome, aux);
            }
            else if(cont == 2)
            {
                x[i].idade = atoi(aux);
            }
            else if(cont == 3)
            {
                x[i].salario = atof(aux);
                cont = 0;
            }
            ler.getline(aux, 100, ';');
        }
    }
    ler.close();
}

void gravar_dados (cadastro x[], int &i)
{
    ofstream escreve;
    escreve.open("exemplo_46.txt", ios::out);
    if(escreve.is_open())
    {
        for(int j = 0; j <= i; j++)
        {
            escreve << x[j].nome << ";" << x[j].idade << ";" << x[j].salario << ";";
        }
    }
    escreve.close();
}

void ler (cadastro x[], int &i)
{
    i++;
    cout << "Informe o nome: ";
    gets(x[i].nome);
    fflush(stdin);

    cout << "Digite a idade: ";
    cin >> x[i].idade;
    fflush(stdin);

    cout << "Digite o salario: ";
    cin >> x[i].salario;
    fflush(stdin);
}

void mostra (cadastro x[], int i)
{
    cout << "DADOS INFORMADOS: " << endl;
    for(int j = 0; j <= i; j++)
    {
        cout << "Nome: " << x[j].nome << endl;
        cout << "Idade: " << x[j].idade << endl;
        cout << "Salario: " << x[j].salario << endl;
        cout << "..................................." << endl;
    }
}

float media (cadastro x[], int i)
{
    float soma = 0;
    for(int j = 0; j <= i; j++)
    {
        soma += x[j].idade;
    }
    return (float) (soma / (i + 1));
}
