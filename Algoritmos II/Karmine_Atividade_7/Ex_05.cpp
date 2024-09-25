/*5 – Crie um programa que manipule através de ponteiros e funções um vetor de 50
Elementos inteiros, o sistema deverá disponibilizar um menu com as seguintes opções:
0 – Sair
1 – Gerar valores (não permitir dados duplicados e devem ser menores que 100)
2 – Mostrar vetor (exibe os elementos do vetor na tela mostrando 10 elementos por
linha)
3 – Média, maior e menor (calcular a média dos elementos, o maior e o menor elemento
do vetor)
4 – Percentual (exibe o percentual de números pares e ímpares no vetor)
OBS: as opções 2, 3 e 4 só poderão ser acionadas após a opção 1, opção inválida no
menu deve exibir mensagem com esta informação.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<string>

using namespace std;

void analisarElement(int novoElem, int *pV, int i);
void gerarValorPVetor(int *pV);
void mostrar(int *pV);
void calculaValores(int *pV);
void percentual(int *pV);

main() {
    setlocale(LC_ALL, "Portuguese");
    int menu = -1, cont = 0, V[50];

    do
    {
        system("cls");
        cout << "#######MENU DE OPÇÕES########" << endl;
        cout << "# 0 - Sair                  #" << endl;
        cout << "# 1 - Gerar vetor           #" << endl;
        cout << "# 2 - Mostrar               #" << endl;
        cout << "# 3 - Média, maior e menor  #" << endl;
        cout << "# 4 - Porcentual            #" << endl;
        cout << "#############################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);

        system("cls");
        switch(menu)
        {
        case 0:
            cout << "Programa finalizado!";
            break;

        case 1:
            gerarValorPVetor(V);
            cont++;
            cout << "Vetor gerado!";
            break;

        case 2:
            if (cont == 0)
                cout << "Nenhum vetor gerado!";
            else
                mostrar(V);
            break;

        case 3:
            if (cont == 0)
                cout << "Nenhum vetor gerado!";
            else
                calculaValores(V);
            break;

        case 4:
            if (cont == 0)
                cout << "Nenhum vetor gerado!";
            else
                percentual(V);
            break;

        default :
            cout << "Opção inválida!";
        }
        getchar();

    }
    while (menu != 0);
}

void analisarElement(int novoElem, int *pV, int i) {
    for(int x = 0; x < i; x++) {
        if(novoElem == pV[x]) {
            analisarElement(rand() % 100, pV, i);
            return;
        }
    }
    *(pV + i) = novoElem;
}

void gerarValorPVetor(int *pV) {
    for(int i = 0; i < 50; i++) {
        analisarElement(rand() % 100, pV, i);
    }
}

void mostrar(int *pV) {
    cout << "> Vetor: \n";
    for(int i = 0; i < 50; i++) {
        cout << *(pV + i);

        if(i < 49)
            cout << ", ";

        if((i + 1) % 10 == 0)
            cout << endl;
    }
}

void calculaValores(int *pV) {
    int maior = 0, menor = 99, indM = 0, indm = 0, V;
    float media = 0;

    for(int i = 0; i < 50; i++) {
        V = *(pV + i);
        media += V;

        if(V > maior) {
            maior = V;
            indM = i;
        }

        if(V < menor) {
            menor = V;
            indm = i;
        }

    }
    cout << "> Média dos valores: " << (media/50) << endl;
    cout << "> Maior valor: " << maior << " (Índice: " << indM << ")" << endl;
    cout << "> Menor valor: " << menor << " (Índice: " << indm << ")";
}

void percentual(int *pV) {
    int V;
    float quantI = 0;

    for(int i = 0; i < 50; i++) {
        V = *(pV + i);
        quantI += (V % 2);
    }
    cout << "> Quantidade de ímpares: " << (quantI * 100 / 50) << "%" << endl;
    cout << "> Quantidade de pares: " << ((50 - quantI)* 100 / 50) << "%";
}


