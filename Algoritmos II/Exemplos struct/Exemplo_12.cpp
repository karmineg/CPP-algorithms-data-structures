#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

struct alunos
{
    int mat;
    string nome;
    float nota[3];
    float media;
};

void ler(alunos v[], int &i);
void mostra(alunos v[], int ind);
void remover(alunos v[], int &ind, alunos a[]);

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
        cout << "# 3 - Remover      #" << endl;
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
        case 3:
            system("cls");
            if(indice < 0)
                cout << "Nenhum aluno cadastrado!";
            else
            {
                remover(vet, indice, aux);
            }
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

    float s = 0;
    for (int x = 0; x < 3; x++)
    {
        cout << "Informe a nota "<< x + 1 << " do aluno [" << i << "]: ";
        cin >> v[i].nota[x];
        fflush(stdin);
        s += v[i].nota[x];
    }
    v[i].media = s / 3.0;

}

void mostra(alunos v[], int ind)
{
    cout << "ALUNOS CADASTRADOS: " << endl;
    for (int i = 0; i <=ind; i++)
    {
        cout << "Matrícula: " << v[i].mat << endl;
        cout << "Nome: " << v[i].nome << endl;
        cout << "Média: " << v[i].media << endl;
        cout << "--------------------------------" << endl;
    }
}

void remover(alunos v[], int &ind, alunos a[])
{
    int cont = 0, m, j = -1;
    cout << "Informe a matrícula do aluno que deseja remover: ";
    cin >> m;
    fflush(stdin);
    for (int i = 0; i <=ind; i++)
    {
        if(m != v[i].mat)
        {
            j++;
            a[j].mat = v[i].mat;
            a[j].nome = v[i].nome;
            a[j].nota[0] = v[i].nota[0];
            a[j].nota[1] = v[i].nota[1];
            a[j].nota[2] = v[i].nota[2];
            a[j].media = v[i].media;
        }
        else
            cont++;
    }
    if(cont != 0)
    {
        ind--;
        j = -1;
        for (int i = 0; i <= ind; i++)
        {
           j++;
           v[j].mat = a[i].mat;
           v[j].nome = a[i].nome;
           v[j].nota[0] = a[i].nome[0];
           v[j].nota[1] = a[i].nome[1];
           v[j].nota[2] = a[i].nome[2];
           v[j].media = a[i].media;
        }
        cout << "\nAluno Removido com sucesso.";
    }
    else
    {
        cout << "Matrícula não cadastrada.";
    }
}







