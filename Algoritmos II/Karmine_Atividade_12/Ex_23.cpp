/*23 - Crie um programa que manipule um vetor de dimensão variável (o usuário informa o tamanho do vetor) os
valores para preenche o vetor devem ser gerados dinamicamente, não sendo permitido números duplicados e
devem ser menores que a 500.
Após os valores do vetor devem ser escritos em um arquivo texto chamado “valores.txt” separando cada valor
por uma virgula e colocando os valores em ordem crescente.
O programa deve permitir:
Excluir valores do vetor (o usuário informa o valor se existir no vetor deve ser eliminado, ajustando os
elementos na ordem novamente)
Mostrar vetor na tela.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<fstream>

using namespace std;

void gerarV(int *V, int q);
int *vCrescente(int *VX, int Q);
void escreverV(int *V, int q);
void excluirV(int *V, int *num);
void mostrarV(int *V, int q);

main() {
    system ("color F5");
    setlocale(LC_ALL, "Portuguese");
    int i, num, menu = -1, cont = 0;

    cout << "> Insira um valor para o tamanho do vetor: ";
    cin >> num;
    int V[num];

    do
    {
        system("cls");
        cout << "#####MENU DE OPÇÕES#####" << endl;
        cout << "# 0 - Sair             #" << endl;
        cout << "# 1 - Gerar vetor      #" << endl;
        cout << "# 2 - Escrever valores #" << endl;
        cout << "# 3 - Excluir valores  #" << endl;
        cout << "# 4 - Mostrar vetor    #" << endl;
        cout << "########################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);
        system("cls");
        switch(menu)
        {
            case 0 :
                cout << "Programa finalizado.";
            break;

            case 1 :
                cont++;
                gerarV(V, num);
                cout << "Vetor gerado!";
            break;

            case 2 :
                if(cont == 0)
                    cout << "Gere um vetor primeiro!";
                else
                    escreverV(vCrescente(V, num), num);

                cout << "Valores transcritos para o arquivo 'vetor.txt'!";
            break;

            case 3 :
                if(cont == 0)
                    cout << "Gere um vetor primeiro!";
                else {
                    excluirV(V, &num);
                    getchar();
                }
            break;

            case 4 :
                if(cont == 0)
                    cout << "Gere um vetor primeiro!";
                else
                    mostrarV(vCrescente(V, num), num);
            break;

            default :
                cout << "Opção inválida.";
                break;
        };
        getchar();
    }
    while(menu != 0);
}

void gerarV(int *V, int q) {
    for(int i = 0; i < q; i++) {
        int Rand;
        int qtd;
        do {
            qtd = 0;
            Rand = (rand() % 500);
            for(int j = 0; j < i; j++) {
                if(Rand == *(V + j)) {
                    qtd = 1;
                    break;
                }
            }
        } while(qtd);
        *(V + i) = Rand;
    }
}

int *vCrescente(int *VX, int Q) {
    int *X = new int[Q];
    for(int x = 0; x < Q; x++) {
        *X = *VX;
        X++;
        VX++;
    } X -= Q;
    VX -= Q;
    for(int x = 0; x < Q - 1; x++) {
        for(int i = x + 1; i < Q; i++) {
            if(*(X + i) < *(X + x)) {
                int aux = *(X + x);
                *(X + x) = *(X + i);
                *(X + i) = aux;
            }
        }
    } return X;
}

void escreverV(int *V, int q) {
    ofstream objeto("vetor.txt", ios::out);
    if(objeto.is_open()){
        for(int i = 0; i < q; i++) {
            if(*V < 10)
                objeto << "  ";
            else if(*V < 100)
                objeto << " ";
            objeto << *V << ";";

            if((i + 1) % 10 == 0)
                objeto << "\n";
            else
                objeto << " ";
            V++;
        }
        objeto.close();
    }
    else{
        cout << "Falha ao abrir o arquivo.";
    }
}

void excluirV(int *V, int *num) {
    int N;
    cout << "\n> Insira um valor entre 0 e 499: ";
    cin >> N;
    if(N < 0 || N >= 500) {
        cout << "Valor inválido!";
        return;
    }
    for(int i = 0; i < *num; i++) {
        if(N == *(V + i)) {
            cout << "> Valor deletado com sucesso!";
            for(int j = i; j < *num - 1; j++) {
                *(V + j) = *(V + j + 1);
            } *num -= 1;
        }
    }
    escreverV(vCrescente(V, *num), *num);
}

void mostrarV(int *V, int q) {
    cout << "Vetor: \n\n";
    for(int i = 0; i < q - 1; i++) {
        cout << *V << ", ";
        V++;
    } cout << *V << ";";
}
