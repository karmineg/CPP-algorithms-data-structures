/*11 – Implemente um programa que manipule uma matriz, onde o número de linhas deve ser alocado
dinamicamente (usuário informa quantas linhas) no máximo 20 e com 5 colunas, após preencha a matriz
com valores randômicos menores que 100, o programa deverá ter um menu com as seguintes opções:
0 – Sair
1 – Gerar matriz (nesta opção deverá ser informado o número de linhas)
2 – Mostrar a matriz
3 – Soma das diagonais (deverá mostrar os elementos da diagonal principal e secundária, juntamente
com as respectivas somas)
4 – Mostrar a matriz de forma invertida (a primeira linha passa a ser a última e a última linha a primeira e
assim sucessivamente)
OBS: as opções 2, 3 e 4 só poderão ser acionadas após a execução da opção 1 (mostrar mensagem com
tratamento deste erro), tratar opção inválida no menu.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

void gerarMatriz(int *pm[5], int *L);
void mostrarMatriz(int *pm[5], int *L, int *C);
void somaDiagonais(int *pm[5], int *L);

main(){
    setlocale(LC_ALL, "Portuguese");
    int *menu = new int(-1);
    int *cont = new int(0);
    int *L = new int(0);
    int *pm[5];
    do
    {
        system("cls");
        cout << "######MENU DE OPÇÕES######" << endl;
        cout << "# 0 - Sair               #" << endl;
        cout << "# 1 - Gerar matriz       #" << endl;
        cout << "# 2 - Mostrar matriz     #" << endl;
        cout << "# 3 - Soma das diagonais #" << endl;
        cout << "# 4 - Matriz invertida   #" << endl;
        cout << "##########################" << endl;
        cout << "Sua escolha: ";
        cin >> *menu;
        fflush(stdin);

        system("cls");
        switch(*menu)
        {
        case 0:
            cout << "Programa finalizado!";
            break;

        case 1:
            *cont += 1;
            gerarMatriz(pm, L);
            cout << "Matriz gerada!";
            getchar();
            break;

        case 2:
            if(*cont == 0)
                cout << "Essa opção necessita de uma matriz já gerada!";
            else
                mostrarMatriz(pm, L, new int(1));
            break;

        case 3:
            if(*cont == 0)
                cout << "Essa opção necessita de uma matriz já gerada!";
            else
                somaDiagonais(pm, L);
            break;

        case 4:
            if(*cont == 0)
                cout << "Essa opção necessita de uma matriz já gerada!";
            else
                mostrarMatriz(pm, L, new int(0));
            break;

        default :
            system("cls");
            cout << "Opção inválida!";
        }
        getchar();
    }
    while(*menu != 0);
}

void gerarMatriz(int *pm[5], int *L) {
    do {
        cout << "Informe a quantidade de linhas: ";
        cin >> *L;

        if(*L < 1)
            cout << "Valor inválido!( < 1)\n";

        else if(*L > 20)
            cout << "Valor inválido! ( > 20)\n";

        else
            break;
    } while(true);

    for(int j = 0; j < 5; j++) {
        pm[j] = new int[*L];
    }

    for(int i = 0; i < *L; i++) {
        for(int j = 0; j < 5; j++) {
            //As linhas dos ponteiros de matriz são interpretadas como suas colunas, assim como suas colunas são interpretadas como linhas.
            pm[j][i] = (rand() % 100);
        }
    }
}

void mostrarMatriz(int *pm[5], int *L, int *C) {
    cout << "Matriz gerada:\n";

    for(int i = 0; i < *L; i++) {
        for(int j = 0; j < 5; j++) {
            cout << pm[j][i*(*C) + (*L - 1 - i)*!(*C)] << "\t";
        }
        cout << "\n";
    }
}

void somaDiagonais(int *pm[5], int *L) {
    int *dP = new int(0);
    int *dS = new int(0);
    int *tam = new int((*L) + (5 - (*L))*((*L) > 5));

    for(int i = 0; i < *tam; i++) {
        *dP += pm[i][i];
        *dS += pm[i][(*tam) - 1 - i];
    }
    cout << "Soma da diagonal principal: " << (*dP) << endl;
    cout << "Soma da diagonal secundária: " << (*dS);
}
