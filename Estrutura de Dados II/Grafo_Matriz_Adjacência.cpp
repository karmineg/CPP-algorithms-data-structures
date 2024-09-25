#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
using namespace std;

void remover(int grafo[20][20], int v1, int v2) {
    grafo[v1][v2] = 0;
    grafo[v2][v1] = 0;
}

void inserir(int grafo[20][20], int v1, int v2) {
    if (v1 >= 0 && v1 < 20 && v2 >= 0 && v2 < 20) {
        grafo[v1][v2] = 1;
        grafo[v2][v1] = 1;
    } else {
        cout << "Vértice inválido!";
    }
}

void mostrar_matriz(int grafo[20][20], int indice) {
    cout << "Matriz de adjacência:" << endl;
    cout << "  ";
    for (int c = 0; c <= indice; c++) {
        cout << c << " ";
    }
    cout << endl;

    for (int i = 0; i <= indice; i++) {
        cout << i << " ";
        for (int j = 0; j <= indice; j++) {
            cout << grafo[i][j] << " ";
        }
        cout << endl;
    }
}

void consultar_adjacentes(int grafo[20][20], int vertice, int indice) {
    cout << "> Vértices adjacentes do vértice " << vertice << ": ";
    for (int i = 0; i < indice; i++) {
        if (grafo[vertice][i] == 1) {
            cout << i << ", ";
        }
    }
    cout << endl;
}

void consultar_grau(int grafo[20][20], int vertice, int indice) {
    int grau = 0;
    for (int i = 0; i < indice; i++) {
        if (grafo[vertice][i] == 1) {
            grau++;
        }
    }
    cout << "> Grau do vértice " << vertice << ": " << grau << endl;
}

main() {
    system ("color 05");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1, indice = 0, v1, v2, num;
    bool inserido = false;

    int grafo[20][20] = {0};

     do
    {
        system("cls");
        cout << "############MENU DE OPÇÕES###########" << endl;
        cout << "# 0 - Sair                          #" << endl;
        cout << "# 1 - Incluir aresta                #" << endl;
        cout << "# 2 - Mostrar matriz                #" << endl;
        cout << "# 3 - Remover aresta                #" << endl;
        cout << "# 4 - Consultar vértices adjacentes #" << endl;
        cout << "# 5 - Consultar grau de vértice     #" << endl;
        cout << "#####################################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);
        system("cls");

        switch(menu)
        {
            case 0 :
                cout << "> Programa finalizado.";
            break;

            case 1:
                if(indice == 20) cout << "> Matriz está cheia! Remova uma aresta.";
                else {
                    cout << "> Digite o vértice inicial: ";
                    cin >> v1;

                    cout << "> Digite o vértice final: ";
                    cin >> v2;

                    inserir(grafo, v1, v2);
                    cout << "> Aresta adicionada com sucesso!";
                    inserido = true;
                    indice++;
                    fflush(stdin);
                }
                break;

            case 2:
                if(inserido == false) cout << "> Primeiro é necessário inserir uma aresta!";
                else {
                    mostrar_matriz(grafo, indice);
                }

                break;

            case 3:
                if(inserido == false) cout << "> Primeiro é necessário inserir uma aresta!";
                else {
                    cout << "> Digite o vértice inicial: ";
                    cin >> v1;

                    cout << "> Digite o vértice final: ";
                    cin >> v2;
                    remover(grafo, v1, v2);
                    cout << "> Aresta (" << v1 << ", " << v2 << ") removida com sucesso!";
                }

                break;

            case 4:
                if(inserido == false) cout << "> Primeiro é necessário inserir uma aresta!";
                else {
                    cout << "Insira o índice do vértice que deseja consultar: ";
                    cin >> num;

                    if(num <= indice) {
                        consultar_adjacentes(grafo, num, indice);
                        fflush(stdin);
                    }
                    else cout << "> Vértice inválido!";
                    fflush(stdin);
                }

                break;

            case 5:
                if(inserido == false) cout << "> Primeiro é necessário inserir uma aresta!";
                else {
                    cout << "Insira o índice do vértice que deseja consultar: ";
                    cin >> num;

                    if(num <= indice) {
                        consultar_grau(grafo, num, indice);
                        fflush(stdin);
                    }
                    else cout << "> Vértice inválido!";
                    fflush(stdin);
                }

                break;

            default:
                    cout << "> Opção inválida!";

                break;

        }; getchar();
    } while(menu != 0);
}
