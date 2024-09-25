/* 28 - O IBGE realizou uma pesquisa entre 50 habitantes de uma cidade. De cada habitante foram
coletados os dados: idade, sexo(M - Masculino, F- Feminino), salário e número de filhos. Crie a
estrutura de dados adequada para armazenar estas informações e faça uma função que
armazene as informações digitadas pelo usuário na estrutura de dados criada.
O programa deverá possibilitar a exibição dos seguintes dados a qualquer momento:
- Média de salário das pessoas do sexo Masculino;
- Média de salário das pessoas do sexo Feminino;
- Sexo e salário da pessoa com a maior idade;
- Sexo e salário da pessoa com menor idade;
- Salário da pessoa com o maior número de filhos;
Crie as opções necessárias no menu. */

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

struct ibge {
    int idade, salario, filhos;
    char sexo;
};

void leitura(ibge V[]);
void media(ibge V[], char C);
int maiorOuMenor(ibge V[], int N);
void mostrarSS(ibge V[], int N);
int sal(ibge V[]);

main() {
    setlocale(LC_ALL, "Portuguese");
    ibge P[50];
    int menu = -1, cont = 0;

    do
    {
        system("cls");
        cout << "####################MENU DE OPÇÕES####################" << endl;
        cout << "# 0 - Sair                                           #" << endl;
        cout << "# 1 - Realizar entrevista                            #" << endl;
        cout << "# 2 - Média de salário das pessoas do sexo Masculino #" << endl;
        cout << "# 3 - Média de salário das pessoas do sexo Feminino  #" << endl;
        cout << "# 4 - Sexo e salário da pessoa com a maior idade     #" << endl;
        cout << "# 5 - Sexo e salário da pessoa com menor idade       #" << endl;
        cout << "# 6 - Salário da pessoa com o maior número de filhos #" << endl;
        cout << "######################################################" << endl;
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
            leitura(P);
            cont++;
            break;
        case 2:
            if (cont == 0)
                cout << "Nenhuma entrevista realizada!";
            else
                media(P, 'M');
            break;
        case 3:
            if (cont == 0)
                cout << "Nenhuma entrevista realizada!";
            else
                media(P, 'F');
            break;
        case 4:
            if (cont == 0)
                cout << "Nenhuma entrevista realizada!";
            else
                mostrarSS(P, 1);
            break;
        case 5:
            if (cont == 0)
                cout << "Nenhuma entrevista realizada!";
            else
                mostrarSS(P, 0);
            break;
        case 6:
            if (cont == 0)
                cout << "Nenhuma entrevista realizada!";
            else
                sal(P);
            break;
        default :
            cout << "Opção inválida!";
        }
        getchar();

    }
    while (menu != 0);
}

void leitura(ibge V[]) {
    int i;

    for (int i = 0; i < 50; i++) {
        cout << "\nInformações da " << i + 1 << "º pessoa: \n  > Idade: ";
        cin >> V[i].idade;

        do {
            cout << "\n  > Sexo: ";
            cin >> V[i].sexo;
        } while (V[i].sexo != 'M' && V[i].sexo != 'F' && V[i].sexo != 'm' && V[i].sexo != 'f');

        cout << "\n  > Salário: ";
        cin >> V[i].salario;

        cout << "\n  > Número de filhos: ";
        cin >> V[i].filhos;
    }
}

void media(ibge V[], char C) {
    int i, contC = 0, soma = 0;

    for (i = 0; i < 50; i++) {
        if (V[i].sexo == C) {
            contC++;
            soma += V[i].salario;
        }
    }
    if (contC == 0)
        cout << "Não há registro de pessoas do sexo " << C;

    else {
        cout << "Média do salário de pessoas do sexo " << C << ": R$ " << (soma/contC);
    }
}

int maiorOuMenor(ibge V[], int N) {
    int idade = V[0].idade, aux = 0, i;

    for(i = 1; i < 50; i++) {
        if((V[i].idade > idade) == N) {
            aux = i;
            idade = V[i].idade;
        }
    } return aux;
}

void mostrarSS(ibge V[], int N) {
    int indice = maiorOuMenor(V, N);

    cout << "Salário da pessoa: " << V[indice].salario;
    cout << "\nSexo da pessoa: " << V[indice].sexo;
}

int sal(ibge V[]) {
    int filhos = V[0].filhos, I = 0, i;

    for(i = 1; i < 50; i++) {
        if (V[i].filhos > filhos) {
            I = i; //índice da pessoa com mais filhos
            filhos = V[i].filhos;
        }
    } cout << "Salário da pessoa com mais filhos: R$ " << V[I].salario;
}

