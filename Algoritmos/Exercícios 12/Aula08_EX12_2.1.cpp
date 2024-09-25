/* 2 - Escreva uma fun��o que recebe as 3 notas de um aluno por par�metro e uma letra. Se a letra for A, a fun��o calcula a m�dia
aritm�tica das notas do aluno, se for P, a sua m�dia ponderada (pesos: 5, 3 e 2) e se for H, a sua m�dia harm�nica.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

float funcao (float n1, float n2, float n3);
char tipo;

main()
{
    setlocale(LC_ALL, "Portuguese");
    float n1, n2, n3;

    cout << "Digete a primeira nota: ";
    cin >> (n1);

    cout << "Digete a segunda nota: ";
    cin >> (n2);

    cout << "Digete a terceira nota: ";
    cin >> (n3);

    cout << "Digete o tipo de m�dia (A para aritm�tica; P para ponderada; H para harm�nica): ";
    cin >> (tipo);

    cout << "\nSua m�dia: " << funcao (n1, n2, n3);
}

float funcao (float n1, float n2, float n3)
{
   float media;

   switch (tipo){

    case 'A':
        media = (n1 + n2 + n3) / 3;
        return media;
        break;

    case 'P':
        media = ((0.5 * n1) + (0.3 * n2) + (0.2 * n3));
        return media;
        break;

    case 'H':
        media = 3 / ((1 / n1) + (1 / n2) + (1 / n3));
        return media;
        break;

    default:
        cout << "Tipo de m�dia inv�lida.";
        break;
   }

}
