/*7 – Crie uma função que receba como parâmetros dois vetores de inteiros: x1 e x2. A função deverá
alocar um terceiro vetor, x3, alocado dinamicamente, contendo a união de x1 e x2 e deverá apresentar:
- Os elementos do vetor x3.
- Os elementos do vetor x3 em ordem crescente.
- O maior e o menor elemento do vetor x3.
OBS: este exercício deve ser resolvido usando alocação dinâmica de memória, ponteiros e aritmética de
ponteiro*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<bits/stdc++.h>

using namespace std;

void adicionarVparaV(int *V, int *pv3, int *A, int *B, int *ind);
void mostrarV3(int *pv3, string message);
int V3Crescente(int *pv3);
void maiorEMenorV3(int *pv3);

main(){
    setlocale(LC_ALL, "Portuguese");
    int *pv1 = new int[5];
    int *pv2 = new int[5];
    int *pv3 = new int[10];

    adicionarVparaV(pv1, pv3, new int(0), new int(9), new int(0)); // adicionar valores aleatórios no primeiro vetor (v1)
    adicionarVparaV(pv2, pv3, new int(10), new int(20), new int(1)); // adicionar valores aleatórios no segundo vetor (v2)
    // conforme vai adicionando os valores nos vetores v1 e v2, v3 já vai sendo preenchido também

    mostrarV3(pv3, ""); // mostrar v3 original
    V3Crescente(pv3); // colocar elementos de v3 em ordem crescente, alterando assim o vetor
    mostrarV3(pv3, " em ordem crescente"); // mostrar v3 recém modificado
    maiorEMenorV3(pv3); // mostrar menor e maior elementos de v3 (respectivamente, primeiro e último elementos do atual v3)
}

void adicionarVparaV(int *V, int *pv3, int *A, int *B, int *ind) {
    int *dist = new int(*B - *A + 1);
    pv3 += 5*(*ind);
    cout << "Vetor " << (*ind + 1) << ": " << endl;
    for(int i = 0; i < 5; i++) {
        //int *jaExiste = new int;
        int *Rand = new int;
        int *qtd = new int;
        do {
            //*jaExiste = 0; //---> Começa como falso
            *Rand = *A + (rand() % *dist);
            *qtd = 0;
            for(int j = 0; j < i; j++) {
                if(*Rand == *V) { //---> Valor aleatório já foi adicionado!!!
                    //cout << "Já existe " << *Rand << " em " << j;
                    //*jaExiste = 1; //---> Se for encontrado o valor, mudar para "1" para fazer o laço se repetir
                    break;
                }
                *qtd += 1;
                V++;
            }
            V -= *qtd;
        } while(*qtd != i);
        V += i;
        *V = *Rand;
        *pv3 = *Rand;
        pv3++;
        cout << *V;
        V -= i;
        if(i < 4) cout << ", ";
    } cout << ";" << endl << endl;
    //cout << "primeiro valor: " << *V << endl << endl;
}

void mostrarV3(int *pv3, string message) {
    cout << "Vetor 1 + Vetor 2" << message << ":\n";
    for(int i = 0; i < 10; i++) {
        cout << *pv3;
        pv3++;
        if(i < 9) cout << ", ";
    } cout << ";" << endl << endl;
}

int V3Crescente(int *pv3) {
    for(int x = 0; x < 9; x++) {
        /* PRIMEIRO CÓDIGO PARA ORDENAÇÃO CRESCENTE COM ARITMÉTICA

        for(int i = x + 1; i < 10; i++) {
            pv3 += x; //pv3 + x
            int *pvX = new int(*pv3);
            pv3 += i - x; //pv3 + i
            int *pvI = new int(*pv3);
            if(*pvI < *pvX) {
                *pv3 = *pvX; // pv3 + i
                pv3 += x - i; // pv3 + x
                *pv3 = *pvI;
                pv3 -= x; // pv3
            } else {
                pv3 -= i; // pv3
            }
        }*/

        /* SEGUNDO CÓDIGO PARA ORDENAÇÃO CRESCENTE COM ARITMÉTICA

        for(int i = 1; i <= 9 - x; i++) {
            int *pvX = new int(*pv3);
            pv3 += i; //pv3 + i
            int *pvI = new int(*pv3);
            if(*pvI < *pvX) {
                *pv3 = *pvX; // subtitui v[i] pelo antigo v[x]
                pv3 -= i; // pv3 + x
                *pv3 = *pvI; // subtitui v[x] pelo antigo v[i]
            } else {
                pv3 -= i;
            } cout << *pvX << " - " << *pvI << endl;
        } pv3++;*/

        /* TERCEIRO CÓDIGO PARA ORDENAÇÃO CRESCENTE SEM ARITMÉTICA

        int *pvX = new int(*pv3);
        for(int i = 1; i <= 9 - x; i++) {
            int *pvI = new int(*(pv3 + i));
            if(*pvI < *pvX) {
                *(pv3 + i) = *pvX; // subtitui v[i] pelo antigo v[x]
                *pvX = *pvI; // subtitui v[x] pelo antigo v[i]
            }
        } *pv3 = *pvX;
        pv3++;*/

        // COM ARITMÉTICA
        int *pvX = new int(*pv3); // estabelece auxiliar de v[x]
        for(int i = 1; i <= 9 - x; i++) { // laço "for" para todos os elementos "v" com índice maior que "x"
            pv3++;
            int *pvI = new int(*pv3);
            if(*pvI < *pvX) {
                *pv3 = *pvX; // subtitui v[i] pelo antigo v[x]
                *pvX = *pvI; // subtitui auxiliar de v[x] pelo antigo v[i]
            }
        } pv3 -= 9 - x; // voltando ao índice "x"
        *pv3 = *pvX; // substitui v[x] pelo seu auxiliar, atualizando-o
        pv3++; // avança para o próximo índice "x" (adicionando mais um)
    }
}

void maiorEMenorV3(int *pv3) {
    cout << "Menor valor: " << *pv3 << ";\n";
    cout << "Maior valor: " << *(pv3 + 9) << ";";
}
