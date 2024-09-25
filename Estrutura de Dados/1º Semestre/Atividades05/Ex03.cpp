/*3. Implemente uma fun��o para dividir uma fila din�mica de valoresinteiros. A fun��o deve receber como par�metro
uma fila F1 com os valores inteiros, uma fila vazia F2 e um valor inteiro N. A fun��o deve dividir a fila F1 em duas,
de tal forma que F2 comece no primeiro n� (elemento) logo ap�s a primeira ocorr�ncia de N na fila original.
a) Exemplo de declara��o da fun��o:
void separaF (int N, Fila *F1, Fila *F2);
a) Exemplo de separa��o:
F1[1, 2, 3, 4, 5, 6, 7, 8, 9]
F2[]
separaF (5, &F1, &F2);
F1[1, 2, 3, 4, 5]
F2[6, 7, 8, 9]*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<string>
using namespace std;

#include "filadinamica-template.hpp"

NoF<float>* separaF(float N, NoF<float> *F1){
    while(F1 != NULL) {
        if(F1->dado == N) {
            NoF<float>* prox = F1->prox;
            if(prox == NULL) cout << "Valor inserido est� na �ltima posi��o de F1, portanto F2 est� VAZIA!!";
            else {
                F1->prox = nullptr; // Dividimos a fila aqui (colocando o pr�ximo como nulo)
                cout << "Fila F1 foi dividida (encerrando no endere�o " << F1 << ")!\nConfira na op��o 'Menu'!";
            } return prox; // Retornamos o endere�o do pr�ximo antigo
        }
        F1 = F1->prox; // Passamos para o pr�ximo endere�o se o atual dado N�O for N
    } // Se, ap�s analisar todo F1, o dado N�O for encontrado, F2 ser� VAZIO!! (Retornar nulo)
    cout << "Valor inserido N�O foi encontrado em F1... :(";
    return nullptr;
}

main() {
    system ("color F2");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;
    float num, N;

    NoF<float>* F1 = nullptr, *F2 = nullptr;

    do
    {
        system("cls");
        cout << "#####MENU DE OP��ES####" << endl;
        cout << "# 0 - Sair            #" << endl;
        cout << "# 1 - Incluir na fila #" << endl;
        cout << "# 2 - Remover da fila #" << endl;
        cout << "# 3 - Dividir fila    #" << endl;
        cout << "# 4 - Mostrar filas   #" << endl;
        cout << "#######################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);
        system("cls");

        switch(menu)
        {
            case 0 :
            cout << "Programa finalizado.";
            break;

            case 1:
                cout << "Digite um n�mero: ";
                cin >> num;

                F1 = adicionaF(F1, num);
                cout << "Elemento " << num << " foi adicionado no n� " << F1;
                getchar();
                break;

            case 2:
                if (F1 == NULL) cout << "Essa fila j� est� vazia!";
                else {
                    cout << "Elemento " << F1->dado << " foi removido!";
                    F1 = removeF(F1);
                }
                break;

            case 3:
                cout << "> Informe um n�mero qualquer: ";
                cin >> N;

                F2 = destroiF(F2); // Antes de separarmos a fila F1, DESTRUIMOS a antiga F2
                F2 = separaF(N, F1); // Realizamos a separa��o AQUI!
                getchar();
                break;

            case 4:
                mostraF(F1, "original");
                cout << endl;
                mostraF(F2, "dividida");

                break;

        }; getchar();
    }
    while(menu != 0);
}
