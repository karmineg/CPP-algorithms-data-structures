/*30 - Em diferentes modalidades esportivas a tecnologia est� sendo utilizada para monitorar o
desempenho dos atletas, no futebol n�o tem sido diferente, a maioria dos grandes clubes utiliza
de uma esp�cie de colete ou cinta que os jogadores utilizam embaixo da camiseta, este colete
est� equipado com sensores e um dispositivo de GPS, capaz de coletar as seguintes
informa��es:
Tempo da atividade (em horas), Dist�ncia percorrida (em km), Frequ�ncia card�aca.
Tudo isso � um �prato cheio� para os departamentos de an�lises cient�ficas dos clubes, que, em
uma integra��o com o departamento m�dico, de fisiologia e t�cnico, conseguem saber qual
atleta est� melhor em v�rios aspectos.
Para facilitar a an�lise dos dados voc� foi contratado para desenvolver um programa
informatizado, que poder� receber os dados mencionados acima de cada um dos jogadores,
cada jogador � identificado pelo n�mero da sua camisa e deve ter a informa��o da sua idade e
seu peso corporal tamb�m.
O sistema dever� realizar e exibir os seguintes c�lculos:
- Velocidade m�dia de cada jogador
- Dist�ncia percorrida por cada jogador em ordem decrescente
- Jogador que consumiu o maior e o menor n�mero de calorias, o c�lculo do consumo de
calorias dever� seguir conforme este exemplo: um indiv�duo de 78 Kg, correndo � uma
velocidade m�dia de 8 Km/h estar� gastando: 8 x 78 x 0,0175 = 10,92 Calorias por minuto.
Uma corrida de uma hora nesta velocidade ter�, portanto, gastado 10,92 x 60 min = 655,2
Calorias.
O sistema dever� apresentar um menu com as seguintes alternativas:
0 � Sair
1 � Cadastrar atleta (O sistema deve funcionar com qualquer quantidade de atletas
cadastrados)
2 � Mostrar todos os cadastrados (exibir todos os dados separando cada atleta por uma linha
pontilhada)
3 � Velocidade m�dia de cada jogador
4 � Dist�ncia percorrida em ordem decrescente
5 � Maior e menor consumo de calorias

OBS:
- As a��es 2, 3, 4 e 5 s� poder�o ser acionadas se a op��o 1 j� foi executada.
- Ao escolher op��o inv�lida no menu dever� exibir mensagem com tal informa��o.
- Utilize struct, fun��es e passagem de par�metro para resolver este exerc�cio, n�o sendo
permitido o uso de vari�veis globais.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include <string>

using namespace std;

struct registro {
    int num, idade, peso, dist, tempo;
    float media;
};

void leitura(registro V[], int &i, int &atletas);
void mostra(registro V[], int i, int atletas);
void media(registro V[], int i, int atletas);
void decrescente(registro V[], int i, int atletas);
void calorias(registro V[], int i, int atletas);

main() {
    setlocale(LC_ALL, "Portuguese");
    registro vet[100];
    int menu = -1, cont = 0, indice = -1, X = 0;
    do
    {
        system("cls");
        cout << "#################MENU DE OP��ES##################" << endl;
        cout << "# 0 - Sair                                      #" << endl;
        cout << "# 1 - Cadastrar atleta                          #" << endl;
        cout << "# 2 - Mostrar todos os cadastrados              #" << endl;
        cout << "# 3 - Velocidade m�dia de cada jogador          #" << endl;
        cout << "# 4 - Dist�ncia percorrida em ordem decrescente #" << endl;
        cout << "# 5 - Maior e menor consumo de calorias         #" << endl;
        cout << "#################################################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);

        system("cls");
        switch(menu)
        {
        case 0:
            cout << "Programa finalizado!";
            getchar();
            break;

        case 1:
            leitura(vet, indice, X);
            cont++;
            break;

        case 2:
            if (cont == 0) {
                cout << "Cadastre um atleta antes de executar esta op��o!";
                getchar();
            }
            else
                mostra(vet, indice, X);

            break;

        case 3:
            if (cont == 0) {
                cout << "Cadastre um atleta antes de executar esta op��o!";
                getchar();
            }
            else
                media(vet, indice, X);

            break;

        case 4:
            if (cont == 0) {
                cout << "Cadastre um atleta antes de executar esta op��o!";
                getchar();
            }
            else
                decrescente(vet, indice, X);

            break;

        case 5:
            if (cont == 0) {
                cout << "Cadastre um atleta antes de executar esta op��o!";
            }
            else
                calorias(vet, indice, X);
            break;

        default :
            cout << "Op��o inv�lida!";
        }
        getchar();
    }
    while (menu != 0);
}

void leitura(registro V[], int &i, int &atletas) {
    bool jaInserido;
    int x;

    atletas++;
    i++;

    do {
        jaInserido = false;
        cout << "> Informe o n�mero do jogador [" << i << "]: ";
        cin >> V[i].num;
            for(x = 0; x < i; x++) {
                if (V[i].num == V[x].num) {
                    cout << "Esse n�mero j� foi inserido!\n\n";
                    jaInserido = true;
                    break;
                }
            }
    }while (jaInserido);

    cout << "> Informe a idade do jogador [" << i << "]: ";
    cin >> V[i].idade;

    cout << "> Informe o peso(kg) do jogador [" << i << "]: ";
    cin >> V[i].peso;

    cout << "> Informe o tempo(horas) de atividade do jogador [" << i << "]: ";
    cin >> V[i].tempo;

    cout << "> Informe a dist�ncia(km) percorrida do jogador [" << i << "]: ";
    cin >> V[i].dist;
}

void mostra(registro V[], int i, int atletas) {

    cout.width(20);
    cout.fill('-');
    cout << left << endl;

    for(i = 0; i < atletas; i++) {
        cout.width(20);
        cout.fill('.');
        cout << "> Altleta n�mero " << left << " " << V[i].num << endl;

        cout.width(20);
        cout.fill('.');
        cout << "> idade " << left << " " << V[i].idade << endl;

        cout.width(20);
        cout.fill('.');
        cout << "> Peso(kg) " << left << " " << V[i].peso << endl;

        cout.width(20);
        cout.fill('.');
        cout << "> tempo(horas) " << left << " " << V[i].tempo << endl;

        cout.width(20);
        cout.fill('.');
        cout << "> Dist�ncia(km) " << left << " " << V[i].dist << endl;
        cout << "\n------------------------------------\n";
    }
}

void media(registro V[], int i, int atletas) {
    float K;

    for(i = 0; i < atletas; i++) {
        K = V[i].dist / V[i].tempo;
        cout << "Velocidade M�dia do atleta [" << i << "] � " << K << endl;
        cout << "\n------------------------------------\n";
    }
}

void decrescente(registro V[], int i, int atletas) {
    int x, aux;

    for(i = 0; i < atletas - 1; i++) {
        for(x = i + 1; x < atletas; x++) {
            if(V[i].dist < V[x].dist) {
                aux = V[i].dist;
                V[i].dist = V[x].dist;
                V[x].dist = aux;
            }
        }
    }
    cout << "> Dist�ncia percorrida de cada jogador em ordem decrescente: ";
    for(i = 0; i < atletas; i++) {
        cout << V[i].dist << ", ";
    }
}

float caloria(registro V) {
    return V.peso * (float)(V.dist)/(float)(V.tempo) * 1.05; // 60 * 0.0175
}

void calorias(registro V[], int i, int atletas) {

    float CalMaior = caloria(V[0]),
    CalMenor = CalMaior;
    int x, y;

    for(i = 1; i < atletas; i++) {
        float cal = caloria(V[i]);
        if(cal > CalMaior) {
            CalMaior = cal;
        }
        else if(cal < CalMenor) {
            CalMenor = cal;
        }
    }
    cout << "> Maior quantidade de calorias: " << CalMaior << " calorias" << endl;
    cout << "> Menor quantidade de calorias: " << CalMenor << " calorias";
}
