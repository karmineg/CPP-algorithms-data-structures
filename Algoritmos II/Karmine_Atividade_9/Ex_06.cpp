/* 6 – Escreva um programa para manipular um vetor de 10 posições de números inteiros, o sistema deve
permitir as seguintes opções:
0 – Sair
1 – Gerar valores para o vetor entre 25 e 50
2 – Mostrar os valores do vetor, separando cada elemento com uma vírgula
3 – Mostrar o percentual de números pares no vetor
4 – Mostrar os números ímpares no vetor
5 – Mostrar a média dos elementos do vetor com uma casa decimal
OBS: este exercício deve ser resolvido usando alocação dinâmica de memória, ponteiros e aritmética de
ponteiro */

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<iomanip>

using namespace std;

void gerarVetor(int *p);
void mostrarVetor(int *p);
void mostrarPercentual(int *p);
void mostrarImpar(int *p);
void mostrarMedia(int *p);

main(){
    setlocale(LC_ALL, "Portuguese");
    int *menu = new int(-1);
    int *cont = new int(0);
    int *pv = new int[10];
    do
    {
        system("cls");
        cout << "######MENU DE OPÇÕES#######" << endl;
        cout << "# 0 - Sair                #" << endl;
        cout << "# 1 - Gerar vetor         #" << endl;
        cout << "# 2 - Mostrar vetor       #" << endl;
        cout << "# 3 - Percentual de pares #" << endl;
        cout << "# 4 - Ímpares do vetor    #" << endl;
        cout << "# 5 - Média do vetor      #" << endl;
        cout << "###########################" << endl;
        cout << "Sua escolha: ";
        cin >> *menu;
        fflush(stdin);

        system("cls");
        switch(*menu)
        {
        case 0:
            cout << "Programa finalizado!";
            break;

        case 1:
            *cont += 1;
            gerarVetor(pv);
            cout << "Vetor gerado!";
            break;

        case 2:
            if (*cont == 0)
                cout << "Essa opção necessita de um vetor já gerado!";

            else
            mostrarVetor(pv);
            break;

        case 3:
            if (*cont == 0)
                cout << "Essa opção necessita de um vetor já gerado!";

            else
            mostrarPercentual(pv);
            break;

        case 4:
            if (*cont == 0)
                cout << "Essa opção necessita de um vetor já gerado!";

            else
                mostrarImpar(pv);
            break;

        case 5:
            if (*cont == 0)
                cout << "Essa opção necessita de um vetor já gerado!";

            else
                mostrarMedia(pv);
            break;

        default :
            system("cls");
            cout << "Opção inválida!";
        }
        getchar();
    }
    while (*menu != 0);
}

void gerarVetor(int *p) {
    // a (menor) = 25
    // b (maior) = 50
    // Fórmula: a + (rand() % (b - a + 1))
    for(int i = 0; i < 10; i++) {
        *p = 25 + (rand() % 26);
        p++;
    }
}

void mostrarVetor(int *p) {
    cout << "Vetor gerado: ";
    for(int i = 0; i < 10; i++) {
        cout << *p;
        p++;
        if(i < 9)
            cout << ", ";
    } cout << ";";
}

void mostrarPercentual(int *p) {
    float *par = new float(0);
    float *percent = new float(0);

    for(int i = 0; i < 10; i++) {
        if (*p % 2 == 0) {
            *par += 1;
        }
        p++;
    }
    *percent = (*par)*10;
    cout << fixed << setprecision(1) << "Percentual de pares: " << *percent << "%";
}

void mostrarImpar(int *p) {
    cout << "Valores Ímpares do Vetor: ";
    bool jaEncontrado = false;
    for(int i = 0; i < 10; i++) {
        if (*p % 2 != 0) {
            if(!jaEncontrado) {
                jaEncontrado = true;
            }
            else {
                cout << ", ";
            }
            cout << *p;
        }
        p++;
    } cout << ";";
}

void mostrarMedia(int *p) {
    float *soma = new float(0);
    float *media = new float(0);

    for(int i = 0; i < 10; i++) {
        *soma += *p;
        p++;
    }
    *media = (*soma) / 10;
    cout << fixed << setprecision(1) << "Média do vetor: " << *media;
}
