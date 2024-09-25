/* 6 - A Federação Gaúcha de Futebol contratou você para escrever um programa para fazer uma estatística
do resultado de vários GRENAIS. Escreva um programa para ler o número de gols marcados pelo Inter
e pelo Grêmio em um GRENAL. Logo após escrever a mensagem "Novo grenal (S-sim N-nao)" e solicitar
uma resposta. Se a resposta for ‘S’, o algoritmo deve ser executado novamente solicitando o número
de gols marcados pelos times em uma nova partida, caso contrário deve ser encerrado mostrando:

● Quantos GRENAIS fizeram parte da estatística.
● O percentual de vitórias do Grêmio em relação ao total.
● O número de vitórias do Inter.
● O número de vitórias do Grêmio.
● O número de Empates.
● A média de gols por partida.
● Uma mensagem indicando qual o time que venceu o maior número de GRENAIS (ou
"Nao houve vencedor", caso termine empatado).
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int gol_inter, gol_gremio, vitorias_inter = 0, vitorias_gremio = 0, empates = 0, total = 0, flag = 1;
    float porcent, media;

    while (flag == 1){
        total++;
        cout << "Escreva o número de gols do Inter: ";
        cin >> (gol_inter);

        cout << "Escreva o número de gols do Grêmio: ";
        cin >> (gol_gremio);

        if (gol_inter > gol_gremio)
            vitorias_inter++;
        else if (gol_gremio > gol_inter)
            vitorias_gremio++;
        else
            empates++;

        cout << "Novo Grenal? (1- sim, 2-não): ";
        cin >> (flag);
        getchar();
        system("cls");

        while((flag !=1) and (flag !=2)){
            cout << "Novo Grenal? (1- sim, 2-não): ";
            cin >> (flag);
        }
    }

        cout << "Houve " << total << " partidas!" << endl;

		cout << "Houve " << vitorias_gremio << " vitórias do Grêmio!" << endl;

		cout << "Houve " << vitorias_inter << " vitórias do Inter!" << endl;

		cout << "Houve " << empates << " empates!" << endl;

		if (vitorias_inter > vitorias_gremio){
            cout << "Inter venceu mais!";
		}
		else if (vitorias_gremio > vitorias_inter){
            cout << "Gremio venceu mais!";
		}
		else{
            cout << "Nao houve vencedor! Foi um Emapate!";
		};

}
