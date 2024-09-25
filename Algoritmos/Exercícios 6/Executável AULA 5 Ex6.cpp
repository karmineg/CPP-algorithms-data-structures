/* 6 - Escreva um algoritmo que receba o tempo de um atleta em uma prova de atletismo, sabendo que
serão registrados o tempo de 5 voltas no circuito, ao final apresente os seguintes dados:
- Melhor tempo e em que volta ele ocorreu;
- Média de tempo entre todas as voltas;
- Pior tempo e em que volta ele ocorreu;
- Tempo total da prova; */

#include <iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    float tempo,tmini,tmaxi,media,total;
    int mvolta,pvolta;

    cout << "Digite o tempo da volta 1: ";
    cin >> tempo;

    tmini = tempo;
    tmaxi = tempo;
    total = tempo;

    for(int x = 1; x < 5; x++){
        if(tempo <= tmini)
        {
            tmini = tempo;
            mvolta = x;
        }
        if(tempo >= tmaxi)
        {
            tmaxi = tempo;
            pvolta = x;
        }

        total += tempo;
        cout << "Digite o tempo da volta " << x+1 << ": ";
        cin >> tempo;
    }
    media = total/5;

    printf ("Melhor volta: Volta %d: %.3f segundos\n",mvolta,tmini);
    printf ("Pior volta: Volta %d: %.3f segundos\n",pvolta,tmaxi);
    printf ("Média da prova: %.3f segundos por volta\n",media);
    printf ("Tempo total da prova: %.3f segundos\n",total);
}
