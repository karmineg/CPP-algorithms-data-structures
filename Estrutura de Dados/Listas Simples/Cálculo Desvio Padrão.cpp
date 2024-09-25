#include<iostream>
#include<cmath>
using namespace std;
#include "lista-template.hpp"

float calcDesvioPadraoS(ListaS<float> *L) {
    No<float>* N = L->dado;
    float num = 0;
    float dif = 0;
    float soma = 0;
    while(N != NULL){
        num = (num + N->dado);
        N = N->prox;
    }
    cout << "Soma dos elementos da lista: " << num << endl;
    cout << "Tamanho da Lista: " << L->tam << endl;

    float media = num / L->tam;
    cout << "Média: " << media << endl;

    N = L->dado;
    while(N != NULL){
        dif = (N->dado - media);
        dif = dif * dif;
        soma += dif;
        N = N->prox;
    }
    cout << "Soma do passo 2: " << soma << endl;

    float div = soma / L->tam;
    cout << "Divisão do passo 3: " << div << endl;

    float resultado = sqrt(div);
    cout << "Raiz do passo 4: " << resultado << endl;
    return resultado;
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    int menu;

    No<int>** L = new No<int>*();
    adicionarFim(L, 8);
    adicionarFim(L, 2);
    adicionarFim(L, 3);
    adicionarFim(L, 4);
    adicionarFim(L, 1);
    mostrar(*L, "Lista de números", "    Número", 0);
    cout << endl << "--------------------------------------" << endl;
    float resultado = calcDesvioPadraoS(&L);
    cout << endl << "--------------------------------------" << endl;
    cout << endl << "DESVIO PADRÃO: " << (int)(resultado) << "." << ((int)(10*resultado) % 10) << ((int)(100*resultado) % 10) << endl;
    break;
}

