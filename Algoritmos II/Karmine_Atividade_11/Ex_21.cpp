/*21 – Crie um programa que apresente um menu com as opções listadas a seguir:
0 – Sair
1 – Gerar valores para a matriz (gera valores para preencher uma matriz 8 x 8 de números inteiros)
2 – Escrever valores no arquivo texto (escreve os valores constantes na matriz em um arquivo texto chamado
matriz.txt, separando os elementos de cada linha com uma vírgula)
3 – Ler valores do arquivo e mostrar na tela no formato da matriz.
OBS: os valores gerados para a matriz devem ser menores que 100, não será permitido executar as opções 2 e 3
do menu caso não tenha sido executado a opção 1.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>

using namespace std;

void gerarM(int M[8][8]);
void escreverV(int M[8][8]);
void mostrarM(int M[8][8]);

main() {
    system ("color F5");
    setlocale(LC_ALL, "Portuguese");
    int i, M[8][8], menu = -1, cont = 0;

    do
    {
        system("cls");
        cout << "####MENU DE OPÇÕES######" << endl;
        cout << "# 0 - Sair             #" << endl;
        cout << "# 1 - Gerar matriz     #" << endl;
        cout << "# 2 - Escrever valores #" << endl;
        cout << "# 3 - Mostrar a matriz #" << endl;
        cout << "########################" << endl;
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
                cont++;
                gerarM(M);
                cout << "Matriz gerada!";
            break;

            case 2 :
               if(cont == 0)
                    cout << "Gere uma matriz primeiro!";
                else
                    escreverV(M);
                    cout << "Valores transcritos para o arquivo 'matriz.txt'!";
            break;

            case 3 :
                if(cont == 0)
                    cout << "Gere uma matriz primeiro!";
                else
                    mostrarM(M);
            break;

            default :
                cout << "Opção inválida.";
                break;
        };
        getchar();
    }
    while(menu != 0);
}

void gerarM(int M[8][8]) {
    srand(time(NULL));
        for(int l = 0; l < 8; l++){
            for(int c = 0; c < 8; c++){
                M[l][c] = rand() % 100;
            }
        }
}

void escreverV(int M[8][8]) {
    ofstream objeto("matriz.txt");
    if(objeto.is_open()){
        for(int l = 0; l < 8; l++){
            objeto << M[l][0];
            for(int c = 1; c < 8; c++)
                objeto << " " << M[l][c];
            objeto << "\n";
        }
        objeto.close();
    }
    else{
        cout << "Falha ao abrir o arquivo!";
    }
}

void mostrarM(int M[8][8]) {
    cout << "> Matriz: " << endl;
    for(int l = 0; l < 8; l++) {
        for(int c = 0; c < 8; c++) {
            int v = M[l][c];
            cout << v << "\t";
        } cout << "\n";
    }
}

