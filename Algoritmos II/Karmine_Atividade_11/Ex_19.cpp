/*19 � Crie um programa que leia um arquivo texto chamado �n�meros.txt�, o qual cont�m uma s�rie de n�meros separados
por ponto e v�rgula, o sistema dever� ler os n�meros necess�rios para preencher uma matriz 5 x 5 de n�meros inteiros.
Ap�s ler os dados o sistema dever� exibir um menu com as seguintes a��es:
1 � Mostrar elementos da diagonal principal
2 � Mostrar os elementos da diagonal secund�ria
3 � Mostrar a matriz e a soma dos elementos acima e abaixo da diagonal principal.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>

using namespace std;

void showElemt(int num, string virg) {
    cout << num << virg;
}

/*void diagonal(string tipo, int n, int M[5][5]) {
    // n = 0 ---> s = 1
    // n = 1 ---> s = -1
    // s = 1 - 2*n
    int s = 1 - 2*n;
    cout << "Diagonal " << tipo << ": ";
    for(int i = 0; i < 4; i++) showElemt(M[4*n + s*i][i], ", ");
    showElemt(M[4 - 4*n][4], ";");
}*/

main() {
    system ("color F5");
    setlocale(LC_ALL, "Portuguese");
    ifstream objeto("n�meros.txt");
    int i, M[5][5], menu = -1, soma = 0;

    if(objeto.is_open()) {
        for(int l = 0; l < 5; l++) {
            for(int c = 0; c < 5; c++) objeto >> M[l][c];
        }
        objeto.close();
    }

    do
    {
        system("cls");
        cout << "###################################MENU DE OP��ES###################################" << endl;
        cout << "# 0 - Sair                                                                         #" << endl;
        cout << "# 1 - Mostrar elementos da diagonal principal                                      #" << endl;
        cout << "# 2 - Mostrar elementos da diagonal secund�ria                                     #" << endl;
        cout << "# 3 - Mostrar a matriz e a soma dos elementos acima e abaixo da diagonal principal #" << endl;
        cout << "####################################################################################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);
        system("cls");
        switch(menu)
        {
            case 0 :
            cout << "Programa finalizado.";

            break;

            case 1 :
                //diagonal("principal", 0, M);
                cout << "Diagonal principal: ";
                for(int i = 0; i < 4; i++)
                    showElemt(M[i][i], ", ");
                    showElemt(M[4][4], ";");
            break;

            case 2 :
                //diagonal("secund�ria", 1, M);
                cout << "Diagonal secund�ria: ";
                for(int i = 0; i < 4; i++)
                    showElemt(M[4 - i][i], ", ");
                    showElemt(M[0][4], ";");
            break;

            case 3 : {
                int acima = 0;
                int abaixo = 0;
                cout << "Matriz: " << endl;
                    for(int l = 0; l < 5; l++) {
                        for(int c = 0; c < 5; c++) {
                            int v = M[l][c];
                            cout << v << "\t";
                            if(c > l)
                                acima += v;
                            else if(c < l)
                                abaixo += v;

                        }
                        cout << "\n";
                    }
                    cout << "\n> Soma dos valores acima da diagonal principal: " << acima;
                    cout << "\n> Soma dos valores abaixo da diagonal principal: " << abaixo;
                    cout << "\n> Soma dos valores total (exceto a diagonal principal): " << (acima + abaixo);

            break;
            }
            default :
                cout << "Op��o inv�lida.";
                break;
        };
        getchar();
    }
    while(menu != 0);
}
