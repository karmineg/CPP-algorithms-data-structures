#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

#include "descritor-template.hpp"

float calcDesvioParao(ListaS<float> *L) {
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

main() {
    system ("color F5");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;

    ListaS<float> L;
    L.adFim(5); // ADD VALORES NA LISTAAAA
    L.adFim(2);
    L.adFim(3);
    L.adFim(4);
    L.adFim(1);
    L.mostrarSimples("Lista bonita");
    cout << endl << "--------------------------------------" << endl;
    float resultado = calcDesvioParao(&L);
    cout << endl << "--------------------------------------" << endl;
    cout << endl << "DESVIO PADRÃO: " << (int)(resultado) << "." << ((int)(10*resultado) % 10) << ((int)(100*resultado) % 10) << endl;

}
