/* Sabendo-se que 100 quilowatts de energia custa um quinto do salário mínimo, fazer um algoritmo
que receba o valor do salário mínimo e a quantidade de quilowatts gasta por uma residência.
Calcule e mostre:
− O valor em reais de cada quilowatt
− O valor em reais a ser pago
− O novo valor a ser pago por essa residência com um desconto de 10%. */

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

main()
{
  setlocale(LC_ALL,"Portuguese");
  float salario_min, quant_qlw, valor_qlw, valor_pago, valor_desc;

  cout << "Digite o salário mínimo: ";
  cin >> (salario_min);

  cout << "Digite a quantidade de quillowatts: ";
  cin >> (quant_qlw);

  valor_qlw = (salario_min /7) /100;
  valor_pago = quant_qlw * valor_qlw;
  valor_desc = valor_pago * 0.1;

  cout << "O valor de cada quillowatt é: " << valor_qlw << endl;
  cout << "O valor a ser pago é: " << valor_pago << "\n";
  cout << "O valor com desconto é: " << valor_desc << "\n";

}
