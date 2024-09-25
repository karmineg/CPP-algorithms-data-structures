/*31 – A professora de matemática do IFSUL, necessita elaborar um controle para registro das
suas turmas de alunos, para cada registro é necessário saber o número da matricula, nome,
turma, curso, média e frequência.
Conforme ocorre os fechamentos dos diários a professora registra os resultados dos alunos no
cadastro, após ela poderá usufruir dos relatórios emitidos pelo sistema, conforme apresentados.
O sistema deve permitir as seguintes ações:
0 - Sair
1 - Cadastrar aluno (não permitir cadastro com matrícula duplicada)
2 - Listar aluno por turma (Recebe o número da turma e lista todos os alunos (todos os dados)
que pertencem a referida turma, separando cada aluno com uma linha pontilhada, caso não
tenha alunos na turma deverá exibir uma mensagem com tal informação).
3 – Listar aprovados por curso (Recebe o nome do curso e lista todos os alunos pertencentes ao
curso que obtiveram média igual ou superior a 6.0 e frequência igual ou superior à 75).
4 – Média por turma (lista a maior, menor e a média das notas de cada turma, juntamente com
o número da turma, separando cada turma com uma linha pontilhada)
Obs: as ações devem funcionar para qualquer quantidade de pessoas cadastradas e serão no
máximo 50.
OBS:
- As ações 2, 3, 4 só poderão ser acionadas se a opção 1 já foi executada.
- Ao escolher opção inválida no menu deverá exibir mensagem com tal informação.
- Utilize struct, funções e passagem de parâmetro para resolver este exercício, não sendo
permitido o uso de variáveis globais.*/

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
        cout << "##########MENU DE OPÇÕES##########" << endl;
        cout << "# 0 - Sair                       #" << endl;
        cout << "# 1 - Cadastrar aluno            #" << endl;
        cout << "# 2 - Listar aluno por turma     #" << endl;
        cout << "# 3 - Listar aprovados por curso #" << endl;
        cout << "# 4 - Média por turma            #" << endl;
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
                cout << "Registre um aluno antes de executar está opção!";

            else
                turma(vet, indice, aluno);
            break;

        case 3:
            if (cont == 0)
                cout << "Registre um aluno antes de executar está opção!";

            else
                curso(vet, indice, aluno);
            break;

        case 4:
            if (cont == 0)
                cout << "Registre um aluno antes de executar está opção!";

            else
                media(vet, indice, aluno);
            break;

        default :
            system("cls");
            cout << "Opção inválida!";
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
        cout << "> Informe o número da matrícula [" << i << "]: ";
        cin >> V[i].matricula;
            for(x = 0; x < i; x++) {
                if (V[i].matricula == V[x].matricula) {
                    cout << "Esse número já foi inserido!\n\n";
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

    cout << "> Informe a média do aluno [" << i << "]: ";
    cin >> V[i].media;

    cout << "> Informe a frequência do aluno [" << i << "]: ";
    cin >> V[i].frequencia;
    cout << "> Aluno cadastrado!";
    getchar();
}

void mostrarAluno(registro A) {
    cout.width(30);
    cout.fill('.');
    cout << "> Número da matrícula " << left << " " << A.matricula << endl;

    cout.width(30);
    cout.fill('.');
    cout << "> Nome " << left << " " << A.nome << endl;

    cout.width(30);
    cout.fill('.');
    cout << "> Curso " << left << " " << A.curso << endl;

    cout.width(30);
    cout.fill('.');
    cout << "> Média " << left << " " << A.media << endl;

    cout.width(30);
    cout.fill('.');
    cout << "> Frequência " << left << " " << A.frequencia << endl;
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
        cout << "\n > Não foi encontrado nenhum aluno dessa turma!";
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
        cout << "\n> Não foi encontrado nenhum aluno desse curso!";
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
            if(turma[j] == V[i].turma) { //---> Turma do aluno atual já foi identificada antes
                turmaJaInserida = true;
                somaNotaTurmas[j] += V[i].media; // Soma a nota do aluno atual
                qtdAlunosTurma[j]++; // Adiciona mais um aluno
                if(maiorNotaTurmas[j] < V[i].media) { // se a nota atual é MAIOR que a registrada como MAIOR...
                    maiorNotaTurmas[j] = V[i].media; // ... coloca-a como a MAIOR até agora!!!
                }
                if(menorNotaTurmas[j] > V[i].media) { // se a nota atual é MENOR que a registrada como MENOR...
                    menorNotaTurmas[j] = V[i].media; // ... coloca-a como a MENOR até agora!!!
                }
                break;
            }
        } if(!turmaJaInserida) { //---> *** Turma do aluno identificada pela primeira vez ***
            turma[qtdTurmas] = V[i].turma; // Adiciona a turma no vetor das turmas
            somaNotaTurmas[qtdTurmas] = V[i].media; // Soma a primeira nota
            qtdAlunosTurma[qtdTurmas]++; // Adiciona o primeiro aluno

            // Coloca como maior e menor notas a nota do primeiro (ponto de partida da nossa análise)
            maiorNotaTurmas[qtdTurmas] = V[i].media;
            menorNotaTurmas[qtdTurmas] = V[i].media;
            qtdTurmas++;
        }
    }
    for(i = 0; i < qtdTurmas; i++) {
        cout << "> Turma " << turma[i] << ": \n";
        cout << "> Média das notas: " << (somaNotaTurmas[i]/qtdAlunosTurma[i]) << endl;
        cout << "> Maior nota encontrada: " << maiorNotaTurmas[i] << endl;
        cout << "> Menor nota encontrada: " << menorNotaTurmas[i] << endl;
        cout << "\n------------------------------------\n";
    }
}
