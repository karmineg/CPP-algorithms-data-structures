/*3. Implemente uma função para dividir uma fila dinâmica de valoresinteiros. A função deve receber como parâmetro
uma fila F1 com os valores inteiros, uma fila vazia F2 e um valor inteiro N. A função deve dividir a fila F1 em duas,
de tal forma que F2 comece no primeiro nó (elemento) logo após a primeira ocorrência de N na fila original.
a) Exemplo de declaração da função:
void separaF (int N, Fila *F1, Fila *F2);
a) Exemplo de separação:
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
            if(prox == NULL) cout << "Valor inserido está na última posição de F1, portanto F2 está VAZIA!!";
            else {
                F1->prox = nullptr; // Dividimos a fila aqui (colocando o próximo como nulo)
                cout << "Fila F1 foi dividida (encerrando no endereço " << F1 << ")!\nConfira na opção 'Menu'!";
            } return prox; // Retornamos o endereço do próximo antigo
        }
        F1 = F1->prox; // Passamos para o próximo endereço se o atual dado NÃO for N
    } // Se, após analisar todo F1, o dado NÃO for encontrado, F2 será VAZIO!! (Retornar nulo)
    cout << "Valor inserido NÃO foi encontrado em F1... :(";
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
        cout << "#####MENU DE OPÇÕES####" << endl;
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
                cout << "Digite um número: ";
                cin >> num;

                F1 = adicionaF(F1, num);
                cout << "Elemento " << num << " foi adicionado no nó " << F1;
                getchar();
                break;

            case 2:
                if (F1 == NULL) cout << "Essa fila já está vazia!";
                else {
                    cout << "Elemento " << F1->dado << " foi removido!";
                    F1 = removeF(F1);
                }
                break;

            case 3:
                cout << "> Informe um número qualquer: ";
                cin >> N;

                F2 = destroiF(F2); // Antes de separarmos a fila F1, DESTRUIMOS a antiga F2
                F2 = separaF(N, F1); // Realizamos a separação AQUI!
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
