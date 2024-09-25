#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL));
    int i, aux, x, vetor[20], impar[20] = {0}, pares[20] = {0};

    cout << "Elementos do vetor: ";
    for(i = 0; i < 20; i++)
    {
        vetor[i] = rand() % 50 + 35;
        cout << vetor[i] << ", ";
    }

    cout << endl;
    cout << endl;
    for (i = 0; i < 20; i++) { //Crescente
        for (x = i + 1; x < 20; x++) {
            if (vetor[x] < vetor[i]) {
                aux = vetor[i];
                vetor[i] = vetor[x];
                vetor[x] = aux;
            }
        }

    }
    cout << "Elementos do vetor (Crescente): ";
    for (i = 0; i < 20; i++) {
        cout << vetor[i] << ", ";
    }

    cout << endl;
    cout << endl; //Ímpares e pares vetor
    for (i = 0; i < 20; i++) {
        if (vetor[i] %2 !=0){
         impar[i] = vetor[i];
        }
        else
         pares[i] = vetor[i];
    }

    // quando tem números repetidos ele acaba ignorando
    if (pares[i] > impar[i]) {
        cout << "Existe mais pares no vetor!" << endl;

        cout << "Elementos do vetor (Pares): ";
        for (i = 0; i < 20; i++) {
            if (pares[i] != 0)
            cout << pares[i] << ", ";
        }
    }
    else if (pares[i] < impar[i]) {
        cout << "Existe mais ímpares no vetor!" << endl;

        cout << "Elementos do vetor (Ímpar): ";
        for (i = 0; i < 20; i++) {
            if (impar[i] != 0)
            cout << impar[i] << ", ";
        }
    }
    else if (pares[i] == impar[i]) {
        cout << "Quantidade de pares e ímpares é igual!" << endl;

        cout << "Elementos do vetor (Pares): ";
        for (i = 0; i < 20; i++) {
            if (pares[i] != 0)
            cout << pares[i] << ", ";
        }
        cout << endl;
        cout << endl;
        cout << "Elementos do vetor (Ímpar): ";
        for (i = 0; i < 20; i++) {
            if (impar[i] != 0)
            cout << impar[i] << ", ";
        }
    }
}
