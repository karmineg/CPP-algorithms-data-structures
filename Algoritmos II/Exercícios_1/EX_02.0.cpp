/* 2 - O cardápio de uma lancheria contém os seguintes itens:

Descrição           Código    Valor   R$
Cachorro quente     10          15.00
Bauru simples       11          18.50
Bauru com ovo       12          22.00
Hambúrger           13          26.00
Cheeseburguer       14          22.00
Torrada             15          10.00
Refrigerante        1           7.50
Suco Natural        2           10.00
Água                3           5.00

Escreva um programa que auxilie o dono da lancheria a realizar os pedidos dos clientes, o
programa deve possibilitar que o atendente informe o código do item e a quantidade solicitada,
sendo possível incluir vários itens no mesmo pedido, para tanto a cada item solicitado o sistema
deverá apresentar as seguintes possibilidades:
1 – Incluir mais um item
2 – Encerrar o pedido
Se a opção for incluir mais um item (1) permite informar o código e a quantidade do próximo
item, caso a opção seja encerrar o pedido (2) deverá exibir os itens do pedido, com as
respectivas quantidades, o valor do item e ao final o valor total do pedido, como no exemplo:
Descrição       QTD     Valor do Item
Bauru Simples   1       18.50
Torrada         2       20.00
Suco Natural    1       10.00
Total do Pedido:....................................................48.50
OBS:
- Validar para aceitar somente itens pertencentes ao cardápio.
- Exibir o pedido com os alinhamentos e os valores numéricos formatados conforme no exemplo. */

#include <iostream>
#include <ctime>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "portuguese");

    const int tam = 9, espaco = 15, espacoNum = 25;
    const char *produto[] = {"Cachorro quente", "Bauru simples", "Bauru com ovo", "Hambúrger", "Cheeseburguer", "Torrada", "Refrigerante", "Suco Natural", "Água"};
    const float valor[tam] = {15.00, 18.50, 22.00, 26.00, 22.00, 10.00, 7.50, 10.00, 5.00};

    int codigo, pedido[tam] = {}, incluir, quant;
    float total = 0.00;

    cout << fixed;
    cout.precision(2);

    do {
        cout << "Informe o código do item que deseja adicionar ao pedido: ";
        cin >> codigo;

        cout << "Informe a quantidade desejada: ";
        cin >> quant;

        switch(codigo) {
        case 10:
            pedido[0] = pedido[0] + quant;
            break;
        case 11:
            pedido[1] = pedido[1] + quant;
            break;
        case 12:
            pedido[2] = pedido[2] + quant;
            break;
        case 13:
            pedido[3] = pedido[3] + quant;
            break;
        case 14:
            pedido[4] = pedido[4] + quant;
            break;
        case 15:
            pedido[5] = pedido[5] + quant;
            break;
        case 1:
            pedido[6] = pedido[6] + quant;
            break;
        case 2:
            pedido[7] = pedido[7] + quant;
            break;
        case 3:
            pedido[8] = pedido[8] + quant;
            break;
        default:
            cout << "\nCódigo Inválido!\n";
        }

        cout << "\n1 - Incluir mais um item\n2 - Encerrar o pedido\n";
        cin >> incluir;
        system("cls");

    }
    while (incluir == 1);

    for(int i = 0; i < tam; i++) {
        total = total + (pedido[i] * valor[i]);
    }

    cout.width(42);
    cout  << left << "Descrição";

    cout.width(espacoNum);
    cout << "Quantidade";

    cout.width(espaco);
    cout << right << "Valor do item\n";

    for (int i=0; i<tam; i++) {
        if (pedido[i] != 0) {
            cout.width(43);
            cout << left << produto[i];
            cout.width(espacoNum);
            cout << pedido[i];
            cout.width(espaco-2);
            cout << right << valor[i] << "$" << endl;
        }
    }

    cout  << "\nTotal do pedido:";

    cout.width(espaco*4.35);
    cout.fill('.');
    cout << total << "$";

    return EXIT_SUCCESS;
}
