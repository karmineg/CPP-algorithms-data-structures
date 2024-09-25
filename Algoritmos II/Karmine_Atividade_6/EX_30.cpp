/*30 - Em diferentes modalidades esportivas a tecnologia está sendo utilizada para monitorar o
desempenho dos atletas, no futebol não tem sido diferente, a maioria dos grandes clubes utiliza
de uma espécie de colete ou cinta que os jogadores utilizam embaixo da camiseta, este colete
está equipado com sensores e um dispositivo de GPS, capaz de coletar as seguintes
informações:
Tempo da atividade (em horas), Distância percorrida (em km), Frequência cardíaca.
Tudo isso é um “prato cheio” para os departamentos de análises científicas dos clubes, que, em
uma integração com o departamento médico, de fisiologia e técnico, conseguem saber qual
atleta está melhor em vários aspectos.
Para facilitar a análise dos dados você foi contratado para desenvolver um programa
informatizado, que poderá receber os dados mencionados acima de cada um dos jogadores,
cada jogador é identificado pelo número da sua camisa e deve ter a informação da sua idade e
seu peso corporal também.
O sistema deverá realizar e exibir os seguintes cálculos:
- Velocidade média de cada jogador
- Distância percorrida por cada jogador em ordem decrescente
- Jogador que consumiu o maior e o menor número de calorias, o cálculo do consumo de
calorias deverá seguir conforme este exemplo: um indivíduo de 78 Kg, correndo à uma
velocidade média de 8 Km/h estará gastando: 8 x 78 x 0,0175 = 10,92 Calorias por minuto.
Uma corrida de uma hora nesta velocidade terá, portanto, gastado 10,92 x 60 min = 655,2
Calorias.
O sistema deverá apresentar um menu com as seguintes alternativas:
0 – Sair
1 – Cadastrar atleta (O sistema deve funcionar com qualquer quantidade de atletas
cadastrados)
2 – Mostrar todos os cadastrados (exibir todos os dados separando cada atleta por uma linha
pontilhada)
3 – Velocidade média de cada jogador
4 – Distância percorrida em ordem decrescente
5 – Maior e menor consumo de calorias

OBS:
- As ações 2, 3, 4 e 5 só poderão ser acionadas se a opção 1 já foi executada.
- Ao escolher opção inválida no menu deverá exibir mensagem com tal informação.
- Utilize struct, funções e passagem de parâmetro para resolver este exercício, não sendo
permitido o uso de variáveis globais.*/

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
        cout << "#################MENU DE OPÇÕES##################" << endl;
        cout << "# 0 - Sair                                      #" << endl;
        cout << "# 1 - Cadastrar atleta                          #" << endl;
        cout << "# 2 - Mostrar todos os cadastrados              #" << endl;
        cout << "# 3 - Velocidade média de cada jogador          #" << endl;
        cout << "# 4 - Distância percorrida em ordem decrescente #" << endl;
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
                cout << "Cadastre um atleta antes de executar esta opção!";
                getchar();
            }
            else
                mostra(vet, indice, X);

            break;

        case 3:
            if (cont == 0) {
                cout << "Cadastre um atleta antes de executar esta opção!";
                getchar();
            }
            else
                media(vet, indice, X);

            break;

        case 4:
            if (cont == 0) {
                cout << "Cadastre um atleta antes de executar esta opção!";
                getchar();
            }
            else
                decrescente(vet, indice, X);

            break;

        case 5:
            if (cont == 0) {
                cout << "Cadastre um atleta antes de executar esta opção!";
            }
            else
                calorias(vet, indice, X);
            break;

        default :
            cout << "Opção inválida!";
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
        cout << "> Informe o número do jogador [" << i << "]: ";
        cin >> V[i].num;
            for(x = 0; x < i; x++) {
                if (V[i].num == V[x].num) {
                    cout << "Esse número já foi inserido!\n\n";
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

    cout << "> Informe a distância(km) percorrida do jogador [" << i << "]: ";
    cin >> V[i].dist;
}

void mostra(registro V[], int i, int atletas) {

    cout.width(20);
    cout.fill('-');
    cout << left << endl;

    for(i = 0; i < atletas; i++) {
        cout.width(20);
        cout.fill('.');
        cout << "> Altleta número " << left << " " << V[i].num << endl;

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
        cout << "> Distância(km) " << left << " " << V[i].dist << endl;
        cout << "\n------------------------------------\n";
    }
}

void media(registro V[], int i, int atletas) {
    float K;

    for(i = 0; i < atletas; i++) {
        K = V[i].dist / V[i].tempo;
        cout << "Velocidade Média do atleta [" << i << "] é " << K << endl;
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
    cout << "> Distância percorrida de cada jogador em ordem decrescente: ";
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
