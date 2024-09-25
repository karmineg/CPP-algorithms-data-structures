/* 2 - Escreva uma função que recebe as 3 notas de um aluno por parâmetro e uma letra. Se a letra for A, a função calcula a média
aritmética das notas do aluno, se for P, a sua média ponderada (pesos: 5, 3 e 2) e se for H, a sua média harmônica.
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

    cout << "Digete o tipo de média (A para aritmética; P para ponderada; H para harmônica): ";
    cin >> (tipo);

    cout << "\nSua média: " << funcao (n1, n2, n3);
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
        cout << "Tipo de média inválida.";
        break;
   }

}
