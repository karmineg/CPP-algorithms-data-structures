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

void ler(alunos v[]);
void mostra(alunos v[]);

main()
{
    setlocale(LC_ALL, "Portuguese");
    alunos vet[3];
    ler(vet);
    system("cls");
    mostra(vet);
}

void ler(alunos v[])
{
    for (int i = 0; i < 3; i++)
    {
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
}

void mostra(alunos v[])
{
    cout << "ALUNOS CADASTRADOS: " << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "Matrícula: " << v[i].mat << endl;
        cout << "Nome: " << v[i].nome << endl;
        cout << "Média: " << v[i].media << endl;
        cout << "--------------------------------" << endl;
    }
}







