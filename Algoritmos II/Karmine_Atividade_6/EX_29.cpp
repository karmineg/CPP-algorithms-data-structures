/* 29 � Escreva um programa que manipule um card�pio de um restaurante, com as seguintes
estruturas:
struct prato
{
string ingredientes;
string preparo;
int calorias;
};
struct cardapio
{
int codigo;
string nome;
prato x;
float valor;
}
O sistema dever� permitir o cadastro de no m�ximo 20 itens no card�pio e dever� apresentar o
seguinte menu:
0 - Sair
1 � Incluir
2 � Mostrar card�pio (utilize um linha pontilhada entre um item e outro)
3 � Detalhar card�pio (recebe o c�digo do card�pio e mostra os dados do referido card�pio)
4 � Mostrar card�pio mais caro;
5 � Mostrar card�pio com a menor quantidade de calorias; */

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include <string>

using namespace std;

struct prato
{
    string ingredientes;
    string preparo;
    int calorias;
};
struct cardapio
{
    int codigo;
    string nome;
    prato x;
    float valor;
};

void mostrarPrato(cardapio V);
void mostrarPratoComPontinhos(cardapio V);

main() {
    setlocale(LC_ALL, "Portuguese");
    cardapio V[20];
    int menu = -1, cont = 0, i, n, I;
    float caro, menoscal;
    bool naoEncontrado;

    do
    {
        system("cls");
        cout << "################MENU DE OP��ES###############" << endl;
        cout << "## 0 - Sair                                ##" << endl;
        cout << "## 1 - Incluir                             ##" << endl;
        cout << "## 2 - Mostrar todos os itens              ##" << endl;
        cout << "## 3 - Detalhar card�pio                   ##" << endl;
        cout << "## 4 - Mostrar card�pio mais caro          ##" << endl;
        cout << "## 5 - Mostrar card�pio com menos calorias ##" << endl;
        cout << "#############################################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);
        switch(menu)
        {
        case 0:
            cout << "Programa finalizado!";
            break;

        case 1:
            if(cont == 20) cout << "Excedeu o Limite!";

            else {
                cout << "> Ingredientes: ";
                getline(cin, V[cont].x.ingredientes);

                cout << "> Modo de preparo: ";
                getline(cin, V[cont].x.preparo);

                cout << "> Calorias do prato: ";
                cin >> V[cont].x.calorias;

                cout << "> Nome do prato: ";
                cin.ignore();
                getline(cin, V[cont].nome);

                cout << "> Valor: ";
                cin >> V[cont].valor;

                cout << "> C�digo: ";
                cin >> V[cont].codigo;

                cont++;
            }
            break;

        case 2:
            if (cont == 0)
                cout << "Nenhum card�pio cadastrada no momento!";

            else {
                cout.width(30);
                cout.fill('-');
                cout << left << endl;

                for(i = 0; i < cont; i++) {
                    mostrarPratoComPontinhos(V[i]);
                    cout << "\n------------------------------------\n";
                }
            }
            break;

        case 3:
            if (cont == 0)
                cout << "Nenhum card�pio cadastrada no momento!";

            else {
                do {
                    naoEncontrado = true;
                    cout << "\nInsira c�digo do card�pio: ";
                    cin >> n;

                    for(i = 0; i < cont; i++) {
                        if(V[i].codigo == n) {
                            mostrarPrato(V[i]);
                            naoEncontrado = false;
                        }
                    }
                } while (naoEncontrado);
            }
            break;

        case 4:
            if (cont == 0)
                cout << "Nenhum card�pio cadastrada no momento!";

            else {
                caro = V[0].valor;
                I = 0; //�ndice do card�pio mais caro

                for(i = 1; i < cont; i++) {
                    if(V[i].valor > caro) {
                        caro = V[i].valor;
                        I = i;
                    }
                }
                cout << "> Prato mais caro:\n";
                mostrarPrato(V[I]);
            }
            break;

        case 5:
            if (cont == 0)
                cout << "Nenhum card�pio cadastrada no momento!";

            else {
                menoscal = V[0].x.calorias;
                I = 0; //�ndice do card�pio com menos calorias

                for(i = 1; i < cont; i++) {
                    if(V[i].x.calorias < menoscal) {
                        menoscal = V[i].x.calorias;
                        I = i;
                    }
                }
                cout << "> Prato com menos calorias:\n";
                mostrarPrato(V[I]);
            }
            break;

        default :
            cout << "Op��o inv�lida!";
        }
        fflush(stdin);
        getchar();

    }
    while (menu != 6);
}

void mostrarPrato(cardapio V) {
    cout << "> Nome: " << V.nome << endl;
    cout << "> Valor: R$ " << V.valor << endl;
    cout << "> C�digo: " << V.codigo << endl;
    cout << "> Quantidade de calorias: " << V.x.calorias << endl;
    cout << "> Ingredientes: " << V.x.ingredientes << endl;
    cout << "> Preparo: " << V.x.preparo << endl;
}

void mostrarPratoComPontinhos(cardapio V) {
    cout.width(30);
    cout.fill('.');
    cout << " > Nome " << left << " " << V.nome << endl;

    cout.width(30);
    cout.fill('.');
    cout << " > Valor " << left << " R$ " << V.valor << endl;

    cout.width(30);
    cout.fill('.');
    cout << " > C�digo " << left << " " << V.codigo << endl;
}
