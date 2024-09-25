#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

main()
{
    setlocale(LC_ALL,"Portuguese");
    int nivel, horas;
    float sb, vh, sindicato, percentual;

    cout << "Informe o n�vel: ";
    cin >> nivel;
    fflush(stdin);

    while((nivel < 1) || (nivel > 4))
    {
        cout << "N�vel inv�lido.";
        getchar(); //para a tela aguardando um enter do teclado
        system("cls"); //limpa a tela
        cout << "Informe o n�vel: ";
        cin >> nivel;
        fflush(stdin);
    }

    switch(nivel)
    {
       case 1:
          vh = 12.0;
          break;
       case 2:
          vh = 17.0;
          break;
       case 3:
          vh = 24.35;
          break;
       case 4:
          vh = 29.50;
          break;
       default :
          cout << "N�vel inv�lido.";
          break;
    };

    if((nivel >= 1) && (nivel <= 4))
    {
        cout << "Informe o n�mero de horas/m�s trabalhadas: ";
        cin >> horas;
        fflush(stdin);

        cout << "Informe a sua remunera��o: ";
        cin >> sb;
        fflush(stdin);

        sindicato = vh * horas;
        percentual = ((sb - sindicato) / sb) * 100.0;

        cout << "\n\nRESULTADO: " << endl;
        cout << "Valor atual: R$ " << sb << endl;
        cout << "Valor pela tabela do sindicato: R$ " << sindicato << endl;

        if(percentual == 0.0)
            cout << "Situa��o: Valor Correto.";
        else
            cout << "Situa��o: " << percentual << " %";
    }
}
