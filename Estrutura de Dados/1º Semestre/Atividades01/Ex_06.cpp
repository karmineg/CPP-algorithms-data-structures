/*6) Crie uma função para calcular a soma de duas matrizes MxN de números reais alocadas
dinamicamente. A função deve retornar a matriz com a soma realizada. A implementação
deste programa deve considerar as dimensões fornecidas pelo usuário. Além disso, antes
de finalizar o programa, deve-se liberar a área de memória alocada*/


#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<fstream>
#include<string>

using namespace std;

main() {
    system ("color F5");
    setlocale(LC_ALL, "Portuguese");
    int l, c;

    cout << "Informe a quantidade de linhas: ";
    cin >> l;

    cout << "Informe a quantidade de colunas: ";
    cin >> c;

    int qtd = l*c;
    int **M1 = new int*[l];
    int **M2 = new int*[l];
    int **MR = new int*[l];

    for(int i = 0; i < l; i++) {
        M1[i] = new int[c];
        M2[i] = new int[c];
        MR[i] = new int[c];
    }

    for(int i = 0; i < l; i++) {
        for(int j = 0; j < c; j++) {
            int V1 = rand() % qtd, V2 = rand() % qtd;
            M1[i][j] = V1;
            M2[i][j] = V2;
            MR[i][j] = V1 + V2;
        }
    }

    cout << endl;
    for(int i = 0; i < l; i++) {
        // Mostrando primeira matriz
        for(int j = 0; j < c; j++) {
            if(M1[i][j] < 10) cout << "0";
            cout << M1[i][j] << "  ";
        } if(i == floor(l/2)) cout << " +  ";
        else cout << "    ";

        // Mostrando segunda matriz
        for(int j = 0; j < c; j++) {
            if(M2[i][j] < 10) cout << "0";
            cout << M2[i][j] << "  ";
        } if(i == floor(l/2)) cout << " =  ";
        else cout << "    ";

        // Mostrando matriz resultante
        for(int j = 0; j < c; j++) {
            if(MR[i][j] < 10) cout << "0";
            cout << MR[i][j] << "  ";
        } cout << endl;
    }

    // Liberar memória
    delete[] M1;
    delete[] M2;
    delete[] MR;

    cout << "\n > Liberado a memória!\n";
}
