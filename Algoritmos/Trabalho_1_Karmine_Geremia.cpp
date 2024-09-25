/* 1 � O sindicato das escolas da rede particular de ensino orienta os diretores que fazem o pagamento
de seus professores por hora/aula que devem seguir a tabela aprovada em assembleia do sindicado,
conforme apresentada abaixo:
Professor N�vel 1 R$ 12.00 por hora/aula
Professor N�vel 2 R$ 17.00 por hora/aula
Professor N�vel 3 R$ 24.35 por hora/aula
Professor N�vel 4 R$ 29.50 por hora/aula
Fa�a um algoritmo que receba o n�vel que o professor se encontra na carreira (o sistema n�o deve aceitar
informar n�vel diferente dos n�veis apresentados acima), o n�mero de horas que ele trabalha no m�s e o valor do
sal�rio base que ele recebe. A seguir calcule se o valor est� correto em rela��o a tabela do sindicato e apresente
os seguintes resultados:
Valor atual:
Valor pela tabela do sindicato:
Situa��o: (deve exibir o percentual que ele recebe a mais ou a menos em rela��o a tabela do sindicato), caso
esteja igual deve exibir a mensagem dizendo �valor correto�; */

#include <iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int niv_car, num_h_mensais;
    float salario_base, hora_valor, remun, porcent;
    cout << fixed;
    cout.precision (2);

    cout << "Informe seu n�vel de carreira: ";
    cin >> (niv_car);

    cout << "Informe suas horas trabalhadas: ";
    cin >> (num_h_mensais);

    cout << "Informe sua remunera��o: ";
    cin >> (remun);

    switch (niv_car){

case 1:
    hora_valor = 12.00;
    salario_base = num_h_mensais * hora_valor;

    if (remun == salario_base){
        cout << "Situa��o: Valor correto!" << endl;
    }
    else if (remun > salario_base){
        porcent = (remun / salario_base - 1) * 100.0;
        cout << "Situa��o: Valor incorreto. Voc� ganha " << porcent << "% a mais do sal�rio correto (" << salario_base << "R$)." << endl;
    }
    else {
        porcent = (salario_base / remun - 1) * 100.0;
        cout << "Situa��o: Valor incorreto. Voc� ganha " << porcent << "% a menos do sal�rio correto (" << salario_base << "R$)." << endl;
    };
break;

case 2:
    hora_valor = 17.00;
    salario_base = num_h_mensais * hora_valor;

    if (remun == salario_base){
        cout << "Situa��o: Valor correto!" << endl;
    }
    else if (remun > salario_base){
        porcent = (remun / salario_base - 1) * 100.0;
        cout << "Situa��o: Valor incorreto. Voc� ganha " << porcent << "% a mais do sal�rio correto (" << salario_base << "R$)." << endl;
    }
    else {
        porcent = (salario_base / remun - 1) * 100.0;
        cout << "Situa��o: Valor incorreto. Voc� ganha " << porcent << "% a menos do sal�rio correto (" << salario_base << "R$)." << endl;
    };
break;

case 3:
    hora_valor = 24.35;
    salario_base = num_h_mensais * hora_valor;

    if (remun == salario_base){
        cout << "Situa��o: Valor correto!";
    }
    else if (remun > salario_base){
        porcent = (remun / salario_base - 1) * 100.0;
        cout << "Situa��o: Valor incorreto. Voc� ganha " << porcent << "% a mais do sal�rio correto (" << salario_base << "R$)." << endl;
    }
    else {
        porcent = (salario_base / remun - 1) * 100.0;
        cout << "Situa��o: Valor incorreto. Voc� ganha " << porcent << "% a menos do sal�rio correto (" << salario_base << "R$)." << endl;
    }
break;

case 4:
    hora_valor = 29.50;
    salario_base = num_h_mensais * hora_valor;

    if (remun == salario_base){
        cout << "Situa��o: Valor correto!";
    }
    else if (remun > salario_base){
        porcent = (remun / salario_base - 1) * 100.0;
        cout << "Situa��o: Valor incorreto. Voc� ganha " << porcent << "% a mais do sal�rio correto (" << salario_base << "R$)." << endl;
    }
    else {
        porcent = (salario_base / remun - 1) * 100.0;
        cout << "Situa��o: Valor incorreto. Voc� ganha " << porcent << "% a menos do sal�rio correto (" << salario_base << "R$)." << endl;
    }
break;

default:
    cout << "N�vel Inv�lido";
break;

    };

}
