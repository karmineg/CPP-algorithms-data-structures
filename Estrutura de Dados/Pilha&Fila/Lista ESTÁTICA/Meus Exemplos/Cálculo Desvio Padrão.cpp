#include<iostream>
#include<cmath>
using namespace std;
#include"pilha-estatica.hpp"
#include"fila-circular.hpp"

float calcDesvioPadraoP(Pilha<float> *P) {
    Pilha<float>* aux = new Pilha<float>();
    inicializaP(aux, P->tam);
    float num = 0;
    float dif = 0;
    float soma = 0;
    while(!vaziaP(P)) {
        num = num + espiaP(P);
        empilhaP(aux, desempilhaP(P));
    }
    cout << "\n> Soma dos elementos da pilha: " << num;
    cout << "\n> Tamanho da pilha: " << aux->tam;

    float media = num / aux->tam;
    cout << "\n> Média: " << media;

    while(!vaziaP(aux)) {
        dif = espiaP(aux) - media;
        dif = dif * dif;
        soma += dif;
        empilhaP(P, desempilhaP(aux));
    }
    cout << "\n> Soma do passo 2: " << soma;

    float div = soma / P->tam;
    cout << "\n> Divisão do passo 3: " << div;

    float resultado = sqrt(div);
    cout << "\n> Raiz do passo 4: " << resultado;
    return resultado;
}

float calcDesvioPadraoF(Fila<float> *F) {
    Fila<float>* aux = new Fila<float>();
    inicializaF(aux, F->tam);
    float num = 0;
    float dif = 0;
    float soma = 0;
    while(!vaziaF(F)) {
        num = num + espiaF(F);
        enfileiraF(aux, desenfileiraF(F));
    }
    cout << "\n> Soma dos elementos da fila: " << num;
    cout << "\n> Tamanho da fila: " << aux->tam;

    float media = num / aux->tam;
    cout << "\n> Média: " << media;

    while(!vaziaF(aux)) {
        dif = espiaF(aux) - media;
        dif = dif * dif;
        soma += dif;
        enfileiraF(F, desenfileiraF(aux));
    }
    cout << "\n> Soma do passo 2: " << soma;

    float div = soma / F->tam;
    cout << "\n> Divisão do passo 3: " << div;

    float resultado = sqrt(div);
    cout << "\n> Raiz do passo 4: " << resultado;
    return resultado;
}

float calcDesvioPadraoPF(Fila<float> *F) {
    Pilha<float>* auxP = new Pilha<float>();
    Fila<float>* auxF = new Fila<float>();
    inicializaP(auxP, F->tam);
    inicializaF(auxF, F->tam);
    float num = 0;
    float dif = 0;
    float soma = 0;
    int n = F->tam;
    while(!vaziaF(F)) {
        num = num + espiaF(F);
        empilhaP(auxP, desenfileiraF(F));
    }
    cout << "\n> Soma dos elementos da fila: " << num;
    cout << "\n> Número total de elementos: " << n;

    float media = num / n;
    cout << "\n> Média: " << media;

    while(!vaziaP(auxP)) {
        dif = espiaP(auxP) - media;
        dif = dif * dif;
        soma += dif;
        enfileiraF(auxF, desempilhaP(auxP));
    }
    cout << "\n> Soma do passo 2: " << soma;

    float div = soma / n;
    cout << "\n> Divisão do passo 3: " << div;

    float resultado = sqrt(div);
    cout << "\n> Raiz do passo 4: " << resultado;

    while(!vaziaF(auxF)) { enfileiraF(F, desenfileiraF(auxF)); }

    return resultado;
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");

    Pilha<float>* P = new Pilha<float>();
    inicializaP(P, 10);
    Fila<float>* F = new Fila<float>();
    inicializaF(F, 10);

    empilhaP(P, 10.5F);
    empilhaP(P, 20.3F);
    empilhaP(P, 30.7F);
    empilhaP(P, 40.1F);
    empilhaP(P, 50.9F);
    mostraP(P, "de valores");
    cout << endl;

    enfileiraF(F, 15.4F);
    enfileiraF(F, 25.2F);
    enfileiraF(F, 35.6F);
    enfileiraF(F, 45.8F);
    enfileiraF(F, 55.1F);
    mostraF(F, "de valores");

    float desvioP = calcDesvioPadraoP(P);
    cout << fixed << setprecision(2);
    cout << "\n\n> O desvio padrão da pilha é: " << desvioP;

    cout << endl;
    float desvioF = calcDesvioPadraoF(F);
    cout << fixed << setprecision(2);
    cout << "\n\n> O desvio padrão da fila é: " << desvioF;

    cout << endl;
    float desvioPF = calcDesvioPadraoPF(F);
    cout << fixed << setprecision(2);
    cout << "\n\n> O desvio padrão da fila usando uma pilha auxiliar é: " << desvioPF;

    destroiP(P);
    destroiF(F);

}

