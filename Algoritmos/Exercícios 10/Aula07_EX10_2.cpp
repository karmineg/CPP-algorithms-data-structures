/*2 - Faça um programa para gerenciar as hospedagens de um hotel, contendo 12 quartos disponíveis.
Para gerenciar os quartos, crie um vetor de inteiros V[12] e atribua zero para todas as posições (todos
os quartos vagos).
O programa deverá apresentar um menu com as seguintes opções:
a) Efetuar reserva:
- O programa deverá ler o número n do quarto e a quantidade q de hóspedes.
- Armazenar a reserva no vetor: V[n] = q;
b) Listar todos os quartos
- Percorrer o vetor e mostrar a quantidade de hóspedes de cada quarto.
c) Listar os quartos vagos
- Percorrer o vetor e mostrar o número dos quartos em que a quantidade de hóspedes é zero.
d) Mostrar o total de pessoas hospedadas no hotel
- Efetuar a soma de todos os elementos do vetor.
e) Efetuar saída:
- O programa deverá ler o número n do quarto.
- Atribuir zero para quantidade de hóspedes do quarto n: V[n] = 0;
f) Listar quartos ocupados cujo número de hóspedes seja maior ou igual a um valor inteiro “x”, sendo
que esse valor deve ser informado pelo usuário.
Observações:
- Para sair do menu (encerrar o programa) pergunte para o usuário se ele deseja sair do programa.
- Ao efetuar uma reserva de um quarto já ocupado o programa deverá emitir uma mensagem de
erro.
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL));
    int x, n, q, aux, V[12] = {0}, menu, soma = 0;
    char sair = 'N';

    do {
        system("cls");
        cout << "####################MENU DE OPÇÕES###################" << endl;
        cout << "# 0 - Sair                                          #" << endl;
        cout << "# 1 - Efetuar reserva                               #" << endl;
        cout << "# 2 - Listar todos os quartos                       #" << endl;
        cout << "# 3 - Listar os quartos vagos                       #" << endl;
        cout << "# 4 - Mostrar o total de pessoas hospedadas no hotel#" << endl;
        cout << "# 5 - Efetuar saída                                 #" << endl;
        cout << "# 6 - Listar quartos ocupados                       #" << endl;
        cout << "# 7 - Listar quartos com oxupação superior a x      #" << endl;
        cout << "#####################################################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);

        switch(menu) {

        case 0 :
            system("cls");
            break;

        case 1 :
            system("cls");
            cout << "Qual quarto deseja fazer a reserva? (1 a 12): " << endl;
            cin >> n;

            if (n < 1 || n > 12) {
            cout << "Número inválido";
            menu = 1;
            }
            else{
                if (V[n-1] != 0)
                    cout << "Quarto ocupado!" << endl;

                  else {
                    cout << "Digite a quantidade de hóspedes: " << endl;
                    cin >> q;
                    V[n-1] = q;

                    cout << "Reserva feita!" << endl;
                    soma = soma + q;
                    }
                }
              getchar();
            break;
            case 2 :
              system("cls");
               cout<<"#Lista de Quartos#\n";

              for (int i = 0; i < 12; i++) {
                cout << "Quarto "<< i+1 << ": "<< V[i] << endl;
              }
              getchar();
              break;
            case 3 :
              system("cls");
              cout << "#Lista de Quartos Vagos#\n";
              for (int i = 0; i < 12; i++) {
                if (V[i]==0)
                cout << "Quarto " << i+1 << ": " << V[i] << endl;
              }
              getchar();
              break;
            case 4 :
              system("cls");
              cout << "A quantidade de pessoas hospedadas é: " << soma << endl;
              getchar();
              break;
            case 5 :
              system("cls");
              do {
                cout << "Digite o número de seu quarto: ";
                cin >> n;
                if (V[n] != 0) {
                  V[n] = 0;
                  cout << "Saída efetuada. ";
                }
                else{
                  cout << "Não há ninguém no quarto!\n";
                }
              }
              while (n < 1 || n > 12);
              getchar();
              break;
            case 6 :
              system("cls");
              cout << "#Lista de Quartos Ocupados#\n";
              for (int i = 0; i < 12; i++) {
                if (V[i] != 0)
                cout << "Quarto " << i+1 << ": " << V[i] << endl;
              }
              getchar();
              break;
            case 7 :
              system("cls");
              cout << "Número minimo de hospedes: ";
              cin >> x;
              cout << "#Lista de Quartos com ocupação maior que " << x << "#\n";
              for (int i = 0; i < 12; i++) {
                if (V[i] >= x)
                cout << "Quarto " << i+1 << ": " << V[i] << endl;
              }
              getchar();
              break;
            default :
              system("cls");
              cout << "Opção inválida. ";
              getchar();
              break;
        };
        do
        {
        cout << "Deseja sair do menu?\nDigite S(Sim) ou N(Não): ";
        cin >> sair;

        if (sair == 'S') {
          cout << "Programa finalizado." << endl;
          menu = 0;
        }
        else if (sair == 'N')
          menu = 1;
        else
          cout << "Opção inválida! " << endl;
        }while(sair != 'N' && sair != 'S');
    }
    while(menu != 0);
}
