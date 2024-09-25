#include<iostream>
#include<cmath>
using namespace std;
#include "descritor-template.hpp"

float calcDesvioPadraoS(ListaS<float> *L) {
    No<float>* N = L->inicio;
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

    N = L->inicio;
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

float calcDesvioPadraoD(ListaD<float> *L) {
    NoD<float>* N = L->inicio;
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

    N = L->inicio;
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

    cout << "Duplamente(0) ou Simplesmente(1): ";
    cin >> menu;

    switch(menu) {
        case 0: {
            ListaD<float> L;
            L.adFim(5);
            L.adFim(2);
            L.adFim(3);
            L.adFim(4);
            L.adFim(1);
            L.mostrarSimples("Lista Duplamente");
            cout << endl << "--------------------------------------" << endl;
            float resultado = calcDesvioPadraoD(&L);
            cout << endl << "--------------------------------------" << endl;
            cout << endl << "DESVIO PADRÃO: " << (int)(resultado) << "." << ((int)(10*resultado) % 10) << ((int)(100*resultado) % 10) << endl;
            break;
        }

        case 1: {
            ListaS<float> L;
            L.adFim(5);
            L.adFim(2);
            L.adFim(3);
            L.adFim(4);
            L.adFim(1);
            L.mostrarSimples("Lista Simplesmente");
            cout << endl << "--------------------------------------" << endl;
            float resultado = calcDesvioPadraoS(&L);
            cout << endl << "--------------------------------------" << endl;
            cout << endl << "DESVIO PADRÃO: " << (int)(resultado) << "." << ((int)(10*resultado) % 10) << ((int)(100*resultado) % 10) << endl;
            break;
        }

        default:
            cout << "> Opção inválida!";
            break;

    };
}

