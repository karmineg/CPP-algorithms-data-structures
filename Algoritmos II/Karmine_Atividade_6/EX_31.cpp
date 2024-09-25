/*31 � A professora de matem�tica do IFSUL, necessita elaborar um controle para registro das
suas turmas de alunos, para cada registro � necess�rio saber o n�mero da matricula, nome,
turma, curso, m�dia e frequ�ncia.
Conforme ocorre os fechamentos dos di�rios a professora registra os resultados dos alunos no
cadastro, ap�s ela poder� usufruir dos relat�rios emitidos pelo sistema, conforme apresentados.
O sistema deve permitir as seguintes a��es:
0 - Sair
1 - Cadastrar aluno (n�o permitir cadastro com matr�cula duplicada)
2 - Listar aluno por turma (Recebe o n�mero da turma e lista todos os alunos (todos os dados)
que pertencem a referida turma, separando cada aluno com uma linha pontilhada, caso n�o
tenha alunos na turma dever� exibir uma mensagem com tal informa��o).
3 � Listar aprovados por curso (Recebe o nome do curso e lista todos os alunos pertencentes ao
curso que obtiveram m�dia igual ou superior a 6.0 e frequ�ncia igual ou superior � 75).
4 � M�dia por turma (lista a maior, menor e a m�dia das notas de cada turma, juntamente com
o n�mero da turma, separando cada turma com uma linha pontilhada)
Obs: as a��es devem funcionar para qualquer quantidade de pessoas cadastradas e ser�o no
m�ximo 50.
OBS:
- As a��es 2, 3, 4 s� poder�o ser acionadas se a op��o 1 j� foi executada.
- Ao escolher op��o inv�lida no menu dever� exibir mensagem com tal informa��o.
- Utilize struct, fun��es e passagem de par�metro para resolver este exerc�cio, n�o sendo
permitido o uso de vari�veis globais.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<string>

using namespace std;

struct registro {
    string nome, curso;
    int turma, matricula;
    float media, frequencia;
};

void leitura(registro V[], int &i, int &alunos);
void turma(registro V[], int i, int alunos);
void curso(registro V[], int i,int alunos);
void media(registro V[], int i, int alunos);

main() {
    setlocale(LC_ALL, "Portuguese");
    registro vet[50];
    int menu = -1, cont = 0, indice = -1, aluno = 0;
    do
    {
        system("cls");
        cout << "##########MENU DE OP��ES##########" << endl;
        cout << "# 0 - Sair                       #" << endl;
        cout << "# 1 - Cadastrar aluno            #" << endl;
        cout << "# 2 - Listar aluno por turma     #" << endl;
        cout << "# 3 - Listar aprovados por curso #" << endl;
        cout << "# 4 - M�dia por turma            #" << endl;
        cout << "##################################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);

        system("cls");
        switch(menu)
        {
        case 0:
            cout << "Programa finalizado!";
            break;

        case 1:
            leitura(vet, indice, aluno);
            cont++;
            break;

        case 2:
            if (cont == 0)
                cout << "Registre um aluno antes de executar est� op��o!";

            else
                turma(vet, indice, aluno);
            break;

        case 3:
            if (cont == 0)
                cout << "Registre um aluno antes de executar est� op��o!";

            else
                curso(vet, indice, aluno);
            break;

        case 4:
            if (cont == 0)
                cout << "Registre um aluno antes de executar est� op��o!";

            else
                media(vet, indice, aluno);
            break;

        default :
            system("cls");
            cout << "Op��o inv�lida!";
        }
        getchar();
    }
    while (menu != 0);
}

void leitura(registro V[], int &i, int &alunos) {
    bool jaInserido;
    int x;

    alunos++;
    i++;

    do {
        jaInserido = false;
        cout << "> Informe o n�mero da matr�cula [" << i << "]: ";
        cin >> V[i].matricula;
            for(x = 0; x < i; x++) {
                if (V[i].matricula == V[x].matricula) {
                    cout << "Esse n�mero j� foi inserido!\n\n";
                    jaInserido = true;
                    break;
                }
            }
    }while (jaInserido);

    cout << "> Informe o nome [" << i << "]: ";
    cin >> V[i].nome;

    cout << "> Informe a turma [" << i << "]: ";
    cin >> V[i].turma;

    cout << "> Informe o curso [" << i << "]: ";
    cin.ignore();
    getline(cin, V[i].curso);

    cout << "> Informe a m�dia do aluno [" << i << "]: ";
    cin >> V[i].media;

    cout << "> Informe a frequ�ncia do aluno [" << i << "]: ";
    cin >> V[i].frequencia;
    cout << "> Aluno cadastrado!";
    getchar();
}

void mostrarAluno(registro A) {
    cout.width(30);
    cout.fill('.');
    cout << "> N�mero da matr�cula " << left << " " << A.matricula << endl;

    cout.width(30);
    cout.fill('.');
    cout << "> Nome " << left << " " << A.nome << endl;

    cout.width(30);
    cout.fill('.');
    cout << "> Curso " << left << " " << A.curso << endl;

    cout.width(30);
    cout.fill('.');
    cout << "> M�dia " << left << " " << A.media << endl;

    cout.width(30);
    cout.fill('.');
    cout << "> Frequ�ncia " << left << " " << A.frequencia << endl;
    cout << "\n------------------------------------\n";
}

void iniLista() {
    cout.width(30);
    cout.fill(' ');
    cout << left << endl;
}

void turma(registro V[], int i, int alunos) {
    int n;
    bool foiEncontrado;

    cout << "Informe uma turma: ";
    cin >> n;
    iniLista();

    for (i = 0; i < alunos; i++) {
        if(V[i].turma == n) {
            foiEncontrado = true;

            mostrarAluno(V[i]);
        }
    }
    if(!foiEncontrado)
        cout << "\n > N�o foi encontrado nenhum aluno dessa turma!";
        getchar();
}

void curso(registro V[], int i, int alunos) {
    string c;
    bool foiEncontrado;
    int contAlunos = 0;

    cout << "Informe um curso: ";
    getline(cin, c);
    iniLista();

    for (i = 0; i < alunos; i++) {
        if(V[i].curso == c) {
            foiEncontrado = true;

            if(V[i].media >= 6.0 && V[i].frequencia >= 75) {
                if(contAlunos == 0)
                    cout << "Aluno(s) aprovados do curso" << V[i].curso << ": " << endl;
                    contAlunos++;
                    mostrarAluno(V[i]);
            }
        }
    }
    if(!foiEncontrado)
        cout << "\n> N�o foi encontrado nenhum aluno desse curso!";
    else {
        if(contAlunos == 0)
            cout << "\n> Todos os alunos desse curso foram reprovados!";
    }
    getchar();
}

void media(registro V[], int i, int alunos) {

    int turma[50] = {};
    float somaNotaTurmas[50] = {};
    float qtdAlunosTurma[50] = {};
    float maiorNotaTurmas[50] = {};
    float menorNotaTurmas[50] = {};
    int qtdTurmas = 0;
    for(i = 0; i < alunos; i++) {
        /* IDENTIFICAR AS TURMAS DE CADA ALUNO */
        bool turmaJaInserida = false;
        for(int j = 0; j < qtdTurmas; j++) {
            if(turma[j] == V[i].turma) { //---> Turma do aluno atual j� foi identificada antes
                turmaJaInserida = true;
                somaNotaTurmas[j] += V[i].media; // Soma a nota do aluno atual
                qtdAlunosTurma[j]++; // Adiciona mais um aluno
                if(maiorNotaTurmas[j] < V[i].media) { // se a nota atual � MAIOR que a registrada como MAIOR...
                    maiorNotaTurmas[j] = V[i].media; // ... coloca-a como a MAIOR at� agora!!!
                }
                if(menorNotaTurmas[j] > V[i].media) { // se a nota atual � MENOR que a registrada como MENOR...
                    menorNotaTurmas[j] = V[i].media; // ... coloca-a como a MENOR at� agora!!!
                }
                break;
            }
        } if(!turmaJaInserida) { //---> *** Turma do aluno identificada pela primeira vez ***
            turma[qtdTurmas] = V[i].turma; // Adiciona a turma no vetor das turmas
            somaNotaTurmas[qtdTurmas] = V[i].media; // Soma a primeira nota
            qtdAlunosTurma[qtdTurmas]++; // Adiciona o primeiro aluno

            // Coloca como maior e menor notas a nota do primeiro (ponto de partida da nossa an�lise)
            maiorNotaTurmas[qtdTurmas] = V[i].media;
            menorNotaTurmas[qtdTurmas] = V[i].media;
            qtdTurmas++;
        }
    }
    for(i = 0; i < qtdTurmas; i++) {
        cout << "> Turma " << turma[i] << ": \n";
        cout << "> M�dia das notas: " << (somaNotaTurmas[i]/qtdAlunosTurma[i]) << endl;
        cout << "> Maior nota encontrada: " << maiorNotaTurmas[i] << endl;
        cout << "> Menor nota encontrada: " << menorNotaTurmas[i] << endl;
        cout << "\n------------------------------------\n";
    }
}
