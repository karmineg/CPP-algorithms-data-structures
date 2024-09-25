/* 2 - Escreva uma fun��o que recebe as 3 notas de um aluno por par�metro e uma letra. Se a letra for A, a fun��o calcula a m�dia
aritm�tica das notas do aluno, se for P, a sua m�dia ponderada (pesos: 5, 3 e 2) e se for H, a sua m�dia harm�nica.
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
        cout << "Informe (A= aritm�tica, P=ponderada, H=harm�nica): ";
        cin >> letra;
        cout << endl;
        letra = toupper(letra);
        if(letra!='A' && letra!='P' && letra!='H')
        {
            cout << "O valor informado � inv�lido!\n";
            system("pause");
            system("cls");
        }
    }
    while(letra!='A' && letra!='P' && letra!='H');
    media = calMedia(n1, n2, n3, letra);
    cout << "O valor da m�dia " << letra << " �: " << media << endl;
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
