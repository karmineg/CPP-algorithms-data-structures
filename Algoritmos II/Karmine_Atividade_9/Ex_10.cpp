/*10 � Fa�a um programa para manipular um vetor de n linhas (usu�rio informa a quantidade de linhas),
onde dever� ser armazenado o n�mero da matr�cula e as 3 notas de n alunos, sabendo que a nota 1 tem
peso 3, a nota 2 tem peso 4 e a nota 3 tem peso 3, o sistema deve permitir o cadastrado das notas com
valores do tipo float entre 0 � 10 (validar esta entrada), o sistema deve apresentar um menu com as
seguintes op��es:
- Cadastrar aluno
- Mostrar alunos cadastrados (separar um registro do outro com uma linha pontilhada)
- Mostrar a maior e a menor m�dia ponderada, juntamente com a matr�cula do aluno
- Mostrar quantos alunos possuem m�dia ponderada igual ou superior a 6 e inferior a 6
- Consultar aluno pela matr�cula.
Utilize aloca��o din�mica de mem�ria, fun��es e ponteiros para resolver este exerc�cio.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

void adicionarNota(string ord, float *nota);
void cadastrarAluno(float *pm[4], int *indice, int *qtd);
void mostrarAluno(float *pm[4], int *i);
void mostrarTodosAlunos(float *pm[4], int *indice);
float *media(float *pm[4], int *i);
void mostrarMatricula(int *alunos, int *qtd);
void maiorEMenorMedia(float *pm[4], int *indice);
void qtdAprovReprov(float *pm[4], int *indice);
void mostrarAlunoMatricula(float *pm[4], int *indice);

main() {
    setlocale(LC_ALL, "Portuguese");

    int *menu = new int(-1);
    int *indice = new int(-1);
    int *qtd = new int;
    cout << "Informe quantidade de alunos: ";
    cin >> *qtd;
    if(*qtd < 1) *qtd = 1;

    float *pm[4]; // 4 linhas e a quantidade de colunas informada pelo usu�rio
    // 0 (primeira): N�mero da matr�cula
    // 1: Primeira nota
    // 2: Segunda nota
    // 3: Terceira nota
    do
    {
        system("cls");
        cout << "################ MENU DE OP��ES ##############" << endl;
        cout << "# 0 - Cadastrar aluno                        #" << endl;
        cout << "# 1 - Mostrar alunos cadastrados             #" << endl;
        cout << "# 2 - Maior e menor m�dia                    #" << endl;
        cout << "# 3 - Alunos aprovados e reprovados          #" << endl;
        cout << "# 4 - Consultar aluno pela matr�cula         #" << endl;
        cout << "# 5 - Sair                                   #" << endl;
        cout << "##############################################" << endl;
        cout << "Sua escolha: ";
        cin >> *menu;
        fflush(stdin);

        system("cls");
        switch(*menu)
        {
        case 0:
            cadastrarAluno(pm, indice, qtd);
            break;

        case 1:
            if(*indice < 0) cout << "Registre um aluno antes de executar est� op��o!";
            else mostrarTodosAlunos(pm, indice);
            break;

        case 2:
            if(*indice < 0) cout << "Registre um aluno antes de executar est� op��o!";
            else maiorEMenorMedia(pm, indice);
            break;

        case 3:
            if(*indice < 0) cout << "Registre um aluno antes de executar est� op��o!";
            else qtdAprovReprov(pm, indice);
            break;

        case 4:
            if(*indice < 0) cout << "Registre um aluno antes de executar est� op��o!";
            else mostrarAlunoMatricula(pm, indice);
            break;

        case 5:
            cout << "Programa finalizado!";
            break;

        default :
            system("cls");
            cout << "Op��o inv�lida!";
        }
        getchar();
    }
    while (*menu != 5);
}

void adicionarNota(string ord, float *nota) {
    do {
        cout << "\n> Informe a " << ord << " nota do aluno: ";
        cin >> *nota;
        if(*nota < 0) cout << "Valor inv�lido! (negativo)\n";
        else if(*nota > 10) cout << "Valor inv�lido! (> 10)\n";
        else break;
    } while(true);
}

void cadastrarAluno(float *pm[4], int *indice, int *qtd) {
    if(*indice + 1 == *qtd) {
        cout << "Voc� j� alcan�ou o n�mero m�ximo de alunos registrados!";
        return;
    }
    if(*indice < 0) { // Criar os ponteiros de vetores dentro do vetor geral (matriz)
        for(int j = 0; j < 4; j++) {
            pm[j] = new float[*qtd];
        }
    }

    int *jaInserido = new int;
    *indice += 1;
    do {
        *jaInserido = 0;
        cout << "> Informe o n�mero da matr�cula [" << *indice << "]: ";
        cin >> pm[0][*indice];
        for(int x = 0; x < *indice; x++) {
            if(*(*pm + *indice) == *(*pm + x)) {
                cout << "Esse n�mero de matr�cula j� foi inserido!\n\n";
                *jaInserido = 1;
                break;
            }
        }
    } while(*jaInserido);

    adicionarNota("primeira", &pm[1][*indice]);
    adicionarNota("segunda", &pm[2][*indice]);
    adicionarNota("terceira", &pm[3][*indice]);
}

void mostrarAluno(float *pm[4], int *i) {
    cout << "> Aluno n� " << (*i + 1) << endl;
    cout << " > N�mero da matr�cula: " << *(*pm + *i) << endl;
    cout << " > Primeira nota: " << *(*(pm + 1) + *i) << endl;
    cout << " > Segunda nota: " << *(*(pm + 2) + *i) << endl;
    cout << " > Terceira nota: " << *(*(pm + 3) + *i) << endl;
}

void mostrarTodosAlunos(float *pm[4], int *indice) {
    int *i = new int;
    for(*i = 0; *i < *indice; *i += 1) {
        mostrarAluno(pm, i);
        cout << "---------------------------\n";
    } mostrarAluno(pm, indice);
}

float *media(float *pm[4], int *i) {
    return new float((3*(pm[1][*i] + pm[3][*i]) + 4*pm[2][*i])/10);
}

void mostrarMatricula(int *alunos, int *qtd) {
    if(*qtd == 1) {
        cout << " > Matr�cula: " << *alunos;
    } else {
        cout << " > Matr�culas: ";
        for(int j = 0; j < *qtd - 1; j++) {
            cout << *alunos << ", ";
            alunos++;
        } cout << *alunos;
    } cout << ";" << endl;
}

void maiorEMenorMedia(float *pm[4], int *indice) {
    float *menor = new float(10);
    float *maior = new float(0);
    int *alunosm = new int[*indice];
    int *alunosM = new int[*indice];
    int *qtdm = new int(0);
    int *qtdM = new int(0);

    int *i = new int;
    for(*i = 0; *i <= *indice; *i += 1) {
        float *M = media(pm, i);
        // Menor m�dia
        if(*menor >= *M) {
            if(*menor > *M) {
                *qtdm = 0;
                *menor = *M;
            } alunosm[*qtdm] = pm[0][*i];
            *qtdm += 1;
        }
        // Maior m�dia
        if(*maior <= *M) {
            if(*maior < *M) {
                *qtdM = 0;
                *maior = *M;
            } alunosM[*qtdM] = pm[0][*i];
            *qtdM += 1;
        }
    }

    cout << "> Maior m�dia: " << *maior << endl;
    mostrarMatricula(alunosM, qtdM);
    cout << "\n> Menor m�dia: " << *menor << endl;
    mostrarMatricula(alunosm, qtdm);
}

void qtdAprovReprov(float *pm[4], int *indice) {
    int *aprov = new int(0);
    int *i = new int;
    for(*i = 0; *i <= *indice; *i += 1) {
        float *M = media(pm, i);
        *aprov += (*M >= 6);
    } cout << "> Quantidade de aprovados: " << *aprov << endl;
    cout << "> Quantidade de reprovados: " << (*indice + 1 - *aprov) << endl;
}

void mostrarAlunoMatricula(float *pm[4], int *indice) {
    int *matric = new int;
    int *i = new int;
    cout << "> Informe um n�mero de matr�cula: ";
    cin >> *matric;
    cout << endl;
    for(*i = 0; *i <= *indice; *i += 1) {
        if(pm[0][*i] == *matric) {
            mostrarAluno(pm, i);
            getchar();
            return;
        }
    } cout << "Aluno n�o encontrado!";
    getchar();
}

