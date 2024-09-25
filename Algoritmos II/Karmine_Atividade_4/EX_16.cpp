/*16 - Crie um programa que manipule uma matriz de inteiros m[7][7]. Utilizando funções o
programa deverá apresentar um menu para acionar as seguintes funcionalidades:
1 – Gerar valores para preencher a matriz, não sendo permitido números duplicados e devem
ser menores que 100.
2 – Mostrar a matriz na tela
3 - Encontrar o maior elemento de cada linha e passá-lo para a posição da diagonal principal na
linha e o elemento que estava na diagonal principal para o local do número, exibir a matriz
original e depois modificada.
4 – Verificar se a Matriz é uma matriz simétrica
5 – Mostrar os elementos acima e abaixo da diagonal principal*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

void matriz(int M[][7]);
void mostra(int M[][7]);
void troca(int M[][7]);
void simetrica(int M[][7]);
void elements(int M[][7]);

int main()
{
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL));
    int menu = -1, matrix[7][7], cont = 0;

    do
    {
        system("cls");
        cout << "#########################MENU DE OPÇÕES#########################" << endl;
        cout << "# 0 - Sair                                                     #" << endl;
        cout << "# 1 - Gerar matriz                                             #" << endl;
        cout << "# 2 - Mostrar matriz                                           #" << endl;
        cout << "# 3 - Trocar linhas                                            #" << endl;
        cout << "# 4 - Vereficar se é simétrica                                 #" << endl;
        cout << "# 5 - Mostrar os elementos acima e abaixo da diagonal principal#" << endl;
        cout << "################################################################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);

        switch(menu)
        {
            case 0 :
            system("cls");
            cout << "Programa finalizado.";
            getchar();
            break;

            case 1 :
            system("cls");
            matriz(matrix);
            cont ++;
            cout << "Matriz gerada!";

            fflush(stdin);
            getchar();
            break;

            case 2 :
            system("cls");
            if (cont == 0){
                cout << "Gere uma matriz primeiro!";
            }
            else {
                mostra(matrix);
            }
            fflush(stdin);
            getchar();
            break;

            case 3 :
            system("cls");
            if (cont == 0){
                cout << "Gere uma matriz primeiro!";
            }
            else {
                troca(matrix);
            }
            fflush(stdin);
            getchar();
            break;

            case 4 :
            system("cls");
            if (cont == 0){
                cout << "Gere uma matriz primeiro!";
            }
            else {
                simetrica(matrix);
            }
            fflush(stdin);
            getchar();
            break;

            case 5 :
            system("cls");
            if (cont == 0){
                cout << "Gere uma matriz primeiro!";
            }
            else {
                elements(matrix);
            }
            fflush(stdin);
            getchar();
            break;

            default :
                system("cls");

                cout << "Opção inválida.";
                getchar();
                break;
        };

    }
    while(menu != 0);
}

void matriz(int M[][7]) {
    int i, aux, y, x, V[49], l, c;

    srand(time(NULL));
    for (i = 0; i < 49; i++) {
        for (i = 0; i < 49; i++) {
        aux = rand() % 100;

        if (i == 0) {
            V[i] = aux;
        }

        else {
            y = 0;
            for (x = 0; x < i; x++) {
                if(V[x] == aux) {
                    y++;
                    break;
                }
            }

            if (y == 0) {
                V[i] = aux;
            }

            else
                i--;
            }
        }
       M[0][0] = V[0];M[0][1] = V[1];M[0][2] = V[2];M[0][3] = V[3];M[0][4] = V[4];M[0][5] = V[5];M[0][6] = V[6];M[1][0] = V[7];M[1][1] = V[8];M[1][2] = V[9];M[1][3] = V[10];M[1][4] = V[11];
       M[1][5] = V[12];M[1][6] = V[13];M[2][0] = V[14];M[2][1] = V[15];M[2][2] = V[16];M[2][3] = V[17];M[2][4] = V[18]; M[2][5] = V[19];M[2][6] = V[20];M[3][0] = V[21];M[3][1] = V[22];M[3][2] = V[23];M[3][3] = V[24];
       M[3][4] = V[25];M[3][5] = V[26];M[3][6] = V[27];M[4][0] = V[28];M[4][1] = V[29];M[4][2] = V[30];M[4][3] = V[31];M[4][4] = V[32];M[4][5] = V[33];M[4][6] = V[34];
       M[5][0] = V[35];M[5][1] = V[36];M[5][2] = V[37];M[5][3] = V[38];M[5][4] = V[39];M[5][5] = V[40];M[5][6] = V[41];M[6][0] = V[42];M[6][1] = V[43];M[6][2] = V[44];M[6][3] = V[45];M[6][4] = V[46];M[6][5] = V[47];M[6][6] = V[48];
    }
}

void mostra(int M[][7]) {
    int l, c;

    for (l = 0; l < 7; l++) {
        for (c = 0; c < 7; c++) {
            cout << M[l][c] << "\t";
        }
        cout << "\n";
    }

    cout << endl;
}
void troca(int M[][7]) {
    int l, c, aux, auxl, auxc;

    cout << "Matriz original: \n";
    for (l = 0; l < 7; l++) {
        for (c = 0; c < 7; c++) {
            cout << M[l][c] << "\t";
        }
        cout << "\n";
    }
    cout << endl;

    cout << "Matriz modificada: \n";
    for (l = 0; l < 7; l++)
    {
        for (c = 0; c < 7; c++)
        {
            if (c == 0) {
                aux = M[l][c];
                auxl = l;
                auxc = c;
            }
            else if (M[l][c] > aux) {
                aux = M[l][c];
                auxl = l;
                auxc = c;
            }

        }
       M[auxl][auxc] = M[l][l];
       M[l][l] = aux;

    }

    for (l = 0; l < 7; l++) {
        for (c = 0; c < 7; c++) {
            cout << M[l][c] << "\t";
        }
        cout << "\n";
    }
    cout << endl;
}

void simetrica(int M[][7]) {
    int yex = 1, l, c;

    for (l = 0; ( l < 7 ) && (yex == 1); l++) {
        for (c = 0; (c < l) && (yex == 1); c++) {
            if (M[l][c] != M[c][l])
                yex = 0;
            }
    }
  if (yex == 1)
     cout << "A matriz é simétrica!";

  else
    cout << "A matriz não é simétrica!";
}

void elements(int M[][7]) {
    int l, c;

    cout << "\nElementos acima da diagonal principal: ";
    for (l = 0; l < 7; l++) {
        for (c = 0; c < 7; c++) {
            if (l < c)
                cout << M[l][c] << ", ";
        }
    }

    cout << "\nElementos da abaixo da diagonal principal: ";
    for (l = 0; l < 7; l++) {
        for (c = 0; c < 7; c++) {
            if (l > c)
                cout << M[l][c] << ", ";
        }
    }
}
