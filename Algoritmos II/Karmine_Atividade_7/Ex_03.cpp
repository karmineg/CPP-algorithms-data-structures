/*3 – Crie um programa que manipule um vetor de 10 posições através de ponteiro. O
sistema deverá gerar os 10 valores randomicamente, sendo maior que 25 e menor que
60, o sistema deverá disponibilizar as seguintes opções no menu:
0 – Sair
1 – Gerar valores
2 – Mostrar soma dos valores
3 – Mostrar maior e menor valor
4 – Solicitar a leitura de um valor e verificar se o valor existe no vetor indicando a sua
posição.
OBS: as opções 2, 3 e 4 só poderão ser acionadas após ter sido executado a ação 1.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<string>

using namespace std;

void gerarVetor(int *V);
void mostrarSoma(int *V);
void mostrarElems(string tipo, int *ind, int qtd, int valor);
void MenorEMaior(int *V);
void lerEVerificarNumero(int *V);

main() {
    setlocale(LC_ALL, "Portuguese");
    int menu = -1, cont = 0, V[10] = {};

    do
    {
        system("cls");
        cout << "######### MENU DE OPÇÕES #########" << endl;
        cout << "# 0 - Sair                       #" << endl;
        cout << "# 1 - Gerar vetor                #" << endl;
        cout << "# 2 - Mostrar soma dos elementos #" << endl;
        cout << "# 3 - Maior e menor elemento     #" << endl;
        cout << "# 4 - Verificar elemento         #" << endl;
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
            gerarVetor(V);
            cont++;
            break;

        case 2:
            if (cont == 0)
                cout << "Nenhum vetor gerado!";
            else
                mostrarSoma(V);
            break;

        case 3:
            if (cont == 0)
                cout << "Nenhum vetor gerado!";
            else
                MenorEMaior(V);
            break;

        case 4:
            if (cont == 0)
                cout << "Nenhum vetor gerado!";
            else
                lerEVerificarNumero(V);
                getchar();
            break;

        default:
            cout << "Opção inválida!";
        }
        getchar();

    }
    while (menu != 0);
}

void gerarVetor(int *V) {
    cout << "> Vetor: \n";
    for(int i = 0; i < 10; i++) {
        int novoValor = 26 + (rand() % 34);
        V[i] = novoValor;
        cout << novoValor << ", ";
    }
}

void mostrarSoma(int *V) {
    int soma = 0;

    cout << "> Soma de todos os elementos do vetor: ";
    for(int i = 0; i < 10; i++) {
        soma += V[i];
    }
    cout << soma;
}

void mostrarElems(string tipo, int *ind, int qtd, int valor) {
    cout << "> " << tipo << " valor: " << valor << "\n";
    cout << "> Índice";
    if(qtd > 1) cout << "s";
    cout << ": ";

    for(int i = 0; i < qtd; i++) {
        cout << ind[i];
        if(i < qtd - 1) cout << ", ";
    }
    cout << endl;
}

void MenorEMaior(int *V) {
    int menor = 60, maior = 25, indm[10] = {}, indM[10] = {}, qtdm = 0, qtdM = 0;

    for(int i = 0; i < 10; i++) {
        if(menor > V[i]) {
            menor = V[i];
            indm[0] = i;
            qtdm = 1;
        }
        else if(menor == V[i]) {
            indm[qtdm] = i;
            qtdm++;
        }

        if(V[i] > maior) {
            maior = V[i];
            indM[0] = i;
            qtdM = 1;
        }
        else if(V[i] == maior) {
            indM[qtdM] = i;
            qtdM++;
        }
    }
    mostrarElems("Menor", indm, qtdm, menor);
    mostrarElems("Maior", indM, qtdM, maior);
}

void lerEVerificarNumero(int *V) {
    int num = 0;

    while(true) {
        cout << "> Informe um número entre 25 e 60: ";
        cin >> num;

        if(num <= 25)
            cout << "Valor menor ou igual a 25 é inválido!\n";

        else if(num >= 60)
            cout << "Valor maior ou igual a 60 é inválido!\n";

        else {
            int listaI[10] = {}, qtdI = 0;

            for(int i = 0; i < 10; i++) {
                if(V[i] == num) {
                    listaI[qtdI] = i;
                    qtdI++;
                }
            }

            if(qtdI == 0) {
                cout << "Valor inserido não existe!";
            }

            else {
                cout << "> Valor encontrado! Índice";
                if(qtdI != 1)
                    cout << "s";
                    cout << ": ";

                for(int j = 0; j < qtdI; j++) {
                    cout << listaI[j];

                    if(j < qtdI - 1)
                        cout << ", ";
                }
                cout << ";";
            }
            break;
        }
    }
}
