/* 2 - Escreva uma função que recebe as 3 notas de um aluno por parâmetro e uma letra. Se a letra for A, a função calcula a média
aritmética das notas do aluno, se for P, a sua média ponderada (pesos: 5, 3 e 2) e se for H, a sua média harmônica.
*/

#include <iostream>
#include <ctime>
using namespace std;
float calMedia(float n1, float n2, float n3, char tipo);

int main()
{
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL));
    float n1, n2, n3, media;
    char letra;
    cout << "Informe a nota 1: ";
    cin >> n1;
    cout << endl;
    cout << "Informe a nota 2: ";
    cin >> n2;
    cout << endl;
    cout << "Informe a nota 3: ";
    cin >> n3;
    cout << endl;

    do
    {
        cout << "Informe (A= aritmética, P=ponderada, H=harmônica): ";
        cin >> letra;
        cout << endl;
        letra = toupper(letra);
        if(letra!='A' && letra!='P' && letra!='H')
        {
            cout << "O valor informado é inválido!\n";
            system("pause");
            system("cls");
        }
    }
    while(letra!='A' && letra!='P' && letra!='H');
    media = calMedia(n1, n2, n3, letra);
    cout << "O valor da média " << letra << " é: " << media << endl;
    return EXIT_SUCCESS;
}
float calMedia(float n1, float n2, float n3, char tipo)
{
    float media = 0;
    if(tipo=='A')
        media = (n1+n2+n3) / 3.0;
    else if(tipo=='P')
        media = (n1*5 + n2*3 + n3*2) / 10.0;
    else if(tipo=='H')
        media = 3.0 / (1.0/n1 + 1.0/n2 + 1.0/n3);
    return media;
}
