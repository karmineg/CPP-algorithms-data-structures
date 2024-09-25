#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

struct notas
{
    float n1;
    float n2;
    float n3;
};
struct alunos
{
    int mat;
    string nome;
    notas n;
};

void ler(alunos v[], int &i);
void mostra(alunos v[], int ind);

main()
{
    setlocale(LC_ALL, "Portuguese");
    alunos vet[10], aux[10];
    int menu = -1, indice = -1;
    do
    {
        system("cls");
        cout << "###MENU DE OPÇÕES###" << endl;
        cout << "# 0 - Sair         #" << endl;
        cout << "# 1 - Cadastrar    #" << endl;
        cout << "# 2 - Mostrar      #" << endl;
        cout << "####################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);
        switch(menu)
        {
        case 0:
            system("cls");
            cout << "Programa finalizado!";
            getchar();
            break;
        case 1:
            system("cls");
            ler(vet, indice);
            cout << "Aluno cadastrado com sucesso!\nPressione Enter para prosseguir";
            getchar();
            break;
        case 2:
            system("cls");
            if(indice < 0)
                cout << "Nenhum aluno cadastrado!";
            else
                mostra(vet, indice);
            getchar();
            break;
        default :
            system("cls");
            cout << "Opção inválida!";
            getchar();
        }

    }
    while (menu != 0);

}

void ler(alunos v[], int &i)
{
    i++;
    cout << "\nInforme a matricula do aluno [" << i << "]: ";
    cin >> v[i].mat;
    fflush(stdin);

    cout << "Informe o nome do aluno [" << i << "]: ";
    getline(cin, v[i].nome);
    fflush(stdin);

    cout << "Informe a nota 1 do aluno [" << i << "]: ";
    cin >> v[i].n.n1;
    fflush(stdin);

    cout << "Informe a nota 2 do aluno [" << i << "]: ";
    cin >> v[i].n.n2;
    fflush(stdin);

    cout << "Informe a nota 3 do aluno [" << i << "]: ";
    cin >> v[i].n.n3;
    fflush(stdin);
}

void mostra(alunos v[], int ind)
{
    cout << "ALUNOS CADASTRADOS: " << endl;
    for (int i = 0; i <=ind; i++)
    {
        cout << "Matrícula: " << v[i].mat << endl;
        cout << "Nome: " << v[i].nome << endl;
        cout << "Nota 1: " << v[i].n.n1 << endl;
        cout << "Nota 2: " << v[i].n.n2 << endl;
        cout << "Nota 3: " << v[i].n.n3 << endl;
        cout << "--------------------------------" << endl;
    }
}

