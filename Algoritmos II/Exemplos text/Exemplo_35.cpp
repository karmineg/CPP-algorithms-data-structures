#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>

using namespace std;

struct cadastro
{
    char nome[100];
    int matricula;
    float n1;
    float n2;
    float n3;
};

void leitura(cadastro v[], int *pi);
void mostra(cadastro v[], int *pi);
void mostra_vetor(cadastro v[], int *pi);
void calcular_media(cadastro v[], int *pi);

main()
{

   int menu, leu = -1, indice = -1;
   cadastro vet[30];

   do
   {
       system("cls");
       cout << "####MENU DE OPCOES####" << endl;
       cout << "# 0 - Sair           #" << endl;
       cout << "# 1 - Cadastrar      #" << endl;
       cout << "# 2 - Mostrar        #" << endl;
       cout << "# 3 - Calcular Media #" << endl;
       cout << "######################" << endl;
       cout << "Sua escolha: ";
       cin >> menu;
       fflush(stdin);
       switch(menu)
       {
           case 0 :
               system("cls");
               cout << "Programa finalizado";
               getchar();
               break;
           case 1 :
               system("cls");
               leitura(vet, &indice);
               cout << "Aluno cadastrado com sucesso.";
               getchar();
               break;
            case 2 :
               system("cls");
               mostra(vet, &indice);
               mostra_vetor(vet, &indice);
               getchar();
               break;
            case 3 :
               system("cls");
               calcular_media(vet, &indice);
               getchar();
               break;
            default :
               system("cls");
               cout << "Opcao invalida";
               getchar();
               break;

       };
   }while(menu != 0);
}

void leitura(cadastro v[], int *pi)
{
    ofstream escreve ("cadastro.txt", ios::app);
    if(escreve.good())
    {
        (*pi)++;
        escreve << ";";
        escreve << "\n";
        cout << "Informe a matricula: ";
        cin >> v[*pi].matricula;
        fflush(stdin);
        escreve << v[*pi].matricula << ";";

        cout << "Informe o nome: ";
        gets(v[*pi].nome);
        fflush(stdin);
        escreve << v[*pi].nome << ";";

        cout << "Informe a nota 1: ";
        cin >> v[*pi].n1;
        fflush(stdin);
        escreve << v[*pi].n1 << ";";

        cout << "Informe a nota 2: ";
        cin >> v[*pi].n2;
        fflush(stdin);
        escreve << v[*pi].n2 << ";";

        cout << "Informe a nota 3: ";
        cin >> v[*pi].n3;
        fflush(stdin);
        escreve << v[*pi].n3;
    }
    else
        cout << "Erro ao abrir o arquivo.";

    escreve.close();
}

void mostra(cadastro v[], int *pi)
{
    ifstream ler ("cadastro.txt", ios::in);
    char texto[100];
    if(ler.is_open())
    {
        *pi = -1;
        while(!ler.eof())
        {
            (*pi)++;
            ler.getline(texto, 100, ';');
            v[*pi].matricula = atoi(texto);
            ler.getline(texto, 100, ';');
            strcpy(v[*pi].nome, texto);
            ler.getline(texto, 100, ';');
            v[*pi].n1 = atof(texto);
            ler.getline(texto, 100, ';');
            v[*pi].n2 = atof(texto);
            ler.getline(texto, 100, ';');
            v[*pi].n3 = atof(texto);
        }
    }
    else
        cout << "Erro ao abrir o arquivo";

    ler.close();
}

void mostra_vetor(cadastro v[], int *pi)
{
    for(int i = 0; i <= *pi; i++)
    {
        cout << "Matricula: " << v[i].matricula << endl;
        cout << "Nome: " << v[i].nome << endl;
        cout << "Nota 1: " << v[i].n1 << endl;
        cout << "Nota 2: " << v[i].n2 << endl;
        cout << "Nota 3: " << v[i].n3 << endl;
        cout << "________________________________" << endl;
    }
}

void calcular_media(cadastro v[], int *pi)
{
    float soma = 0;
    cout << fixed;
    cout.precision(1);
    for(int i = 0; i <= *pi; i++)
    {
        soma = v[i].n1 + v[i].n2 + v[i].n3;
        cout << "Media do aluno: " << v[i].nome << " e: ";
        cout << soma / 3.0 << endl;
        cout << "-------------------------------" << endl;
    }
}
