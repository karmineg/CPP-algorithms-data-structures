#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

struct data
{
    int dia;
    string mes;
    int ano;
};

struct venda
{
    int pecas;
    float valor;
    data dia_venda;
};

main()
{
    setlocale(LC_ALL, "Portuguese");
    venda a = {22, 154.80, {11, "Maio", 2022}};
    cout << "Quantidade de peças: " << a.pecas << endl;
    cout << "Valor das vendas: " << a.valor << endl;
    cout << "Data: " << a.dia_venda.dia << " de ";
    cout << a.dia_venda.mes << " de " << a.dia_venda.ano;
}
