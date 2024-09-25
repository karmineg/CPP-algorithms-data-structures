/*20 � Crie um programa que manipule um arquivo texto contendo em cada linha um n�mero inteiro qualquer, o
programa dever� ler todos os n�meros e apresentar os seguintes dados:
- Maior valor existente no arquivo
- Menor valor existente no arquivo
- M�dia aritm�tica dos valores no arquivo
- Quantidade de n�meros pares e �mpares existentes no arquivo*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>

using namespace std;

main() {
    system ("color F5");
    setlocale(LC_ALL, "Portuguese");
    ifstream objeto("text_int.txt");
    int V[20] = {}, cont = 0, maior, menor, impar;
    float soma = 0, media = 0;

    objeto >> V[0];
    maior = V[0];
    menor = V[0];
    soma = V[0];
    impar = (V[0] % 2);
    cout << V[0];

    for(int i = 1; i < 10; i++) {
        objeto >> V[i];
        cout << "; " << V[i];
        soma += V[i];
        if(V[i] > maior){
            maior = V[i];
        }
         if(V[i] < menor){
            menor = V[i];
        }

        impar += (V[i] % 2);

    } cout << ";";

    media = soma / 10;
    cout << "\nM�dia: " << media;
    cout << "\nMaior valor: " << maior;
    cout << "\nMenor valor: " << menor;
    cout << "\nQuantidade de pares: " << (10 - impar);
    cout << "\nQuantidade de �mpares: " << impar;
    objeto.close();
}
