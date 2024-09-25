/*5 - Escrever um algoritmo que leia um vetor A[20] de caracteres. Mostrar o vetor lido. Trocar a seguir
o 1o elemento com o 11o, o 2o com o 12o e, assim, sucessivamente até o 10o com o 20o. Mostrar o
vetor modificado.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int i;
    char A[20], aux;

    for(i = 0; i < 20; i++){
        cout << "Digite um caractere: ";
        cin >> A[i];
    }
    cout << "Elementos do A: ";
    for(i = 0; i < 20; i++){
        cout << A[i] << ", ";
    }

    i = 0;
    for(int x = 0; x < 10; x++){
    aux = A[i];
    A[i] = A[i+10];
    A[i+10] = aux;
    i++;
    }

    cout << endl;

    cout << "Elementos do A Inverso: ";
    for(i = 0; i < 20; i++){
        cout << A[i] << ", ";
    }

}
