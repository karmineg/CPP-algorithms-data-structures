/* 2 - O card�pio de uma lancheria cont�m os seguintes itens:

Descri��o           C�digo    Valor   R$
Cachorro quente     10          15.00
Bauru simples       11          18.50
Bauru com ovo       12          22.00
Hamb�rger           13          26.00
Cheeseburguer       14          22.00
Torrada             15          10.00
Refrigerante        1           7.50
Suco Natural        2           10.00
�gua                3           5.00

Escreva um programa que auxilie o dono da lancheria a realizar os pedidos dos clientes, o
programa deve possibilitar que o atendente informe o c�digo do item e a quantidade solicitada,
sendo poss�vel incluir v�rios itens no mesmo pedido, para tanto a cada item solicitado o sistema
dever� apresentar as seguintes possibilidades:
1 � Incluir mais um item
2 � Encerrar o pedido
Se a op��o for incluir mais um item (1) permite informar o c�digo e a quantidade do pr�ximo
item, caso a op��o seja encerrar o pedido (2) dever� exibir os itens do pedido, com as
respectivas quantidades, o valor do item e ao final o valor total do pedido, como no exemplo:
Descri��o       QTD     Valor do Item
Bauru Simples   1       18.50
Torrada         2       20.00
Suco Natural    1       10.00
Total do Pedido:....................................................48.50
OBS:
- Validar para aceitar somente itens pertencentes ao card�pio.
- Exibir o pedido com os alinhamentos e os valores num�ricos formatados conforme no exemplo. */

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int menu = -1, codigo, sair = 1, quant, ch = 0, bs = 0, bo = 0, h = 0, cb = 0, tr = 0, rf = 0, sn = 0, a = 0;
    float valor, total;

    do
    {
        system("cls");
        cout << "###################CARD�PIO#################" << endl;
        cout << "# Descri��o           C�digo       Valor R$#" << endl;
        cout << "#Cachorro quente       10          15.00   #" << endl;
        cout << "#Bauru simples         11          18.50   #" << endl;
        cout << "#Bauru com ovo         12          22.00   #" << endl;
        cout << "#Hamb�rger             13          26.00   #" << endl;
        cout << "#Cheeseburguer         14          22.00   #" << endl;
        cout << "#Torrada               15          10.00   #" << endl;
        cout << "#Refrigerante          1           7.50    #" << endl;
        cout << "#Suco Natural          2           10.00   #" << endl;
        cout << "#�gua                  3           5.00    #" << endl;
        cout << "############################################" << endl;
        cout << "Digite o c�digo: ";
        cin >> menu;
        fflush(stdin);

        switch(menu)
        {
            case 0 :
            system("cls");
            getchar();
            break;

            case 10 :
            cout << "\nDigite a quantidade desejada: ";
            cin >> quant;
            ch+= quant;

            fflush(stdin);
            getchar();
            break;

            case 11 :
            cout << "\nDigite a quantidade desejada: ";
            cin >> quant
            bs+= quant;

            fflush(stdin);
            getchar();
            break;

            case 12 :
            cout << "\nDigite a quantidade desejada: ";
            cin >> quant;
            bo+= quant;

            fflush(stdin);
            getchar();
            break;

            case 13 :
            cout << "\nDigite a quantidade desejada: ";
            cin >> quant;
            h+= quant;

            fflush(stdin);
            getchar();
            break;

            case 14 :
            cout << "\nDigite a quantidade desejada: ";
            cin >> quant;
            cb+= quant;

            fflush(stdin);
            getchar();
            break;

            case 15 :
            cout << "\nDigite a quantidade desejada: ";
            cin >> quant;
            tr+= quant;

            fflush(stdin);
            getchar();
            break;

            case 1 :
            cout << "\nDigite a quantidade desejada: ";
            cin >> quant;
            rf+= quant;

            fflush(stdin);
            getchar();
            break;

            case 2 :
            cout << "\nDigite a quantidade desejada: ";
            cin >> quant;
            sn+= quant;

            fflush(stdin);
            getchar();
            break;

            case 3 :
            cout << "\nDigite a quantidade desejada: ";
            cin >> quant;
            a += quant;

            fflush(stdin);
            getchar();
            break;

            default :
                system("cls");

                cout << "Op��o inv�lida.";
                getchar();
                break;
        };
        do
            {
            cout << "Deseja encerrar o pedido?\nDigite 1 para N�O ou 2 para SIM: ";
            cin >> sair;

            if (sair == 2) {
            cout << "Pedido Finalizado." << endl;

            cout.width ( 52 );
            cout.fill('.');
            cout << left << "Total do Pedido:" << total << "R$" << endl;
            menu = 0;
            }
            else if (sair == 1)
                menu = 1;
            else
            cout << "Op��o inv�lida! " << endl;
        }
        while(sair != 1 && sair != 2);
    }
    while(menu != 0);
}

