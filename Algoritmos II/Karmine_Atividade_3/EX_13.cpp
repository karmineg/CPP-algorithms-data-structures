/*13 - Escreva um programa que exiba um menu com as op��es apresentadas abaixo e quanto
acionada deve executar as a��es descritas:
0 � Sair - Encerra o programa
1 � Ler um valor qualquer � Aciona uma fun��o para ler um n�mero via entrada padr�o
2 � Verifica primo - Aciona uma fun��o que recebe o n�mero por par�metro e exibe a
informa��o se o n�mero � primo ou n�o, os n�meros 0 e 1 por defini��o n�o s�o primos.
3 � Soma algarismo - Aciona uma fun��o que soma os algarismos que comp�em o n�mero, por
exemplo:
se o n�mero informado foi 528 a fun��o deve retornar 15 pois 5 + 2 + 8 = 15
Obs: executar as valida��es apresentadas:
- Escolha de op��o inv�lida no menu exibir mensagem de alerta.
- As op��es 2 e 3 s� podem ser acionadas ap�s ter sido executado a op��o 1.
- A op��o 3 s� pode ser acionado se o n�mero for maior que zero e menor ou igual a 999.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

void leitura(int &n);
void primo(int n);
void algarismo(int n);

int main()
{
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL));
    int menu = -1, num, cont = 0;

    do
    {
        system("cls");
        cout << "#######MENU DE OP��ES########" << endl;
        cout << "# 0 - Sair                  #" << endl;
        cout << "# 1 - Ler um valor qualquer #" << endl;
        cout << "# 2 - Verifica primo        #" << endl;
        cout << "# 3 - Soma algarismo        #" << endl;
        cout << "#############################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);

        switch(menu)
        {
            case 0 :
            system("cls");
            cout << "Programa finalizado.";
            getchar();
            break;

            case 1 :
            system("cls");
            leitura(num);
            cont ++;

            fflush(stdin);
            getchar();
            break;

            case 2 :
            system("cls");
            if (cont == 0){
                cout << "Leia um n�mero primeiro!";
            }

            else {
                primo(num);
            }

            fflush(stdin);
            getchar();
            break;

            case 3 :
            system("cls");
            if (cont == 0){
                cout << "Leia um n�mero primeiro!";
            }
            else if ((num < 0) or (num > 999)){
                cout << "Digite um n�mero maior do que 0 ou menor ou igual a 999!";
            }

            else {
                algarismo(num);
            }

            fflush(stdin);
            getchar();
            break;

            default :
                system("cls");

                cout << "Op��o inv�lida.";
                getchar();
                break;
        };

    }
    while(menu != 0);
}

void leitura(int &n) {
    setlocale(LC_ALL, "Portuguese");

    cout << "Digite um n�mero qualquer: ";
    cin >> n;

}

void primo(int n) {
    setlocale(LC_ALL, "Portuguese");
    int i, div = 0;

    for (i = 2; i <= n/2; i++) {
        if (n % i == 0) {
        div ++;
        break;
        }
    }
    if(div == 0)
        cout << "� primo!" << endl;

    else
        cout << "N�o � primo!" << endl;
}

void algarismo(int n) {
    setlocale(LC_ALL, "Portuguese");
    int soma = 0;

    while (n != 0) {
        soma   += n % 10;
        n  = n / 10;
    }

    cout << "A soma �: " << soma << endl;


}
