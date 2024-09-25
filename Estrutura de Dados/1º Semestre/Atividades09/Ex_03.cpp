#include<iostream>
#include<fstream>
using namespace std;

#include "descritor-template.hpp"

//typedef string tipoP;
typedef string* pointS;

struct Veiculo {
    string placa;
    int ano;
    string fabric, modelo;
};

bool operator==(const Veiculo &v, const string &p) {
    return (v.placa == p);
}

bool operator==(const Veiculo &v, const pointS &m) {
    return (v.fabric == *m);
}

// "Overloading" para mostrar struct DIRETO pelo m�todo "cout"
ostream& operator << (ostream &o, Veiculo &v) {
    return o << v.placa << " |" << setfill(' ') << setw(6) << v.ano << " |" <<
                setfill(' ') << setw(13) << v.fabric << " |" << setfill(' ') << setw(10) << v.modelo;
}

bool anoMenor(Veiculo N, Veiculo M) { return (N.ano < M.ano); }
bool modeloMenor(Veiculo N, Veiculo M) { return (N.modelo < M.modelo); }

void lerArquivo(ListaS<Veiculo> *L) {
    string nome;
    cout << ">> Insira o nome de um arquivo de texto: ";
    cin >> nome;
    ifstream leitor;
    leitor.open(nome, ios_base::in);
    if(!leitor) cout << "!!! N�o EXISTE arquivo com nome inserido !!!";
    else {
        L->destruir();
        int cont = 0;
        while(!leitor.eof()) {
            Veiculo V;
            string ano;
            if(getline(leitor, V.placa, '#') &&
            getline(leitor, ano, '#') &&
            getline(leitor, V.fabric, '#') &&
            getline(leitor, V.modelo)) {
                V.ano = stoi(ano);
                L->adFim(V);
                cont++;
            }
        } if(cont == 0) cout << "!!! NENHUM ve�culo foi encontrado !!!";
        else if(cont == 1) cout << "!!! Encontrado APENAS UM ve�culo !!!";
        else cout << "!!! Um total de " << cont << " ve�culos foram encontrados !!!";
    }
}

void miniMenu(string tit, string opt1, string opt2, ListaS<Veiculo> *L, void(*funcao)(ListaS<Veiculo>*, int)) {
    // Mostrar menu
    int l1 = opt1.length(), l2 = opt2.length();
    int i;
    if(l1 > l2) for(i = l2 + 1; i <= l1; i++) opt2 += " ";
    else if(l1 < l2) for(i = l1 + 1; i <= l2; i++) opt1 += " ";
    string base = "";
    for(i = 0; i < opt1.length() + 8; i++) base += "#";

    cout << tit << endl << base << endl;
    cout << "# 0 - " << opt1 << " #" << endl;
    cout << "# 1 - " << opt2 << " #" << endl << base << endl << endl;

    // Inserir op��o
    int opt;
    do {
        cout << ">> Insira uma das op��es acima: ";
        cin >> opt;
        if(opt < 0 || opt > 1) cout << "!!! Op��o inserida INV�LIDA !!!\n";
        else {
            system("cls");
            funcao(L, opt);
            getchar();
            break;
        }
    } while(true);
}

void funcMostrar(ListaS<Veiculo> *L, int opt) {
    if(opt == 0) L->mostrar("Lista de todos os ve�culos", "   Placa |   Ano |   Fabricante |    Modelo", 2, 'T');
    else {
        string fabric;
        cout << ">> Insira um nome de fabricante: ";
        cin >> fabric;

        bool encontrado = false;
        No<Veiculo> *N = L->inicio;
        while(N != NULL) {
            Veiculo V = N->dado;
            if(V.fabric == fabric) { // Se for encontrado carro com fabricante informado
                if(!encontrado) { // Foi encontrado, pelo menos, um
                    cout << "*** Placas encontradas: " << V.placa;
                    encontrado = true;
                } cout << ", " << V.placa;
            } N = N->prox;
        }
        if(!encontrado) cout << "!!! N�O H� carros com fabricante informado !!!";
        else cout << ";";
    }
}

void funcOrdenar(ListaS<Veiculo> *L, int opt) {
    if(opt == 0) L->ordenar(anoMenor);
    else L->ordenar(modeloMenor);
}

void funcRemover(ListaS<Veiculo> *L, int opt) {
    if(opt == 0) {
        string P;
        cout << ">> Informe a placa do ve�culo: ";
        cin >> P;
        bool excl = L->removeUmVal(P);
        if(excl) cout << "!!! Encontrado e REMOVIDO... Confira na op��o 'Mostrar' !!!";
        else cout << "!!! N�O foi encontrado carro com placa informada... :( !!!";
    } else {
        string *M = new string();
        cout << ">> Informe o fabricante: ";
        cin >> *M;
        int qtd = L->removeVariosVal(M);
        if(qtd == 0) cout << "!!! N�O foi encontrado carros com fabricante informado... :( !!!";
        else {
            if(qtd == 1) cout << "!!! Apenas um carro foi exclu�do... ";
            else cout << "!!! " << qtd << " carros foram exclu�dos... ";
            cout << " Confira na op��o 'Mostrar' !!!";
        }
    }
}

int main () {
    system ("color F2");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;

    ListaS<Veiculo> L;

    do
    {
        system("cls");
        cout << "################MENU DE OP��ES#################" << endl;
        cout << "# 0 - Sair                                    #" << endl;
        cout << "# 1 - Ler informa��es de ve�culos             #" << endl;
        cout << "# 2 - Mostrar lista de ve�culos               #" << endl;
        cout << "# 3 - Ordenar lista de ve�culos               #" << endl;
        cout << "# 4 - Remover ve�culo(s)                      #" << endl;
        cout << "###############################################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);
        system("cls");

        switch(menu)
        {
            case 0 :
            cout << "Programa finalizado.";
            break;

            case 1:
                lerArquivo(&L);
                getchar();
                break;

            case 2:
                miniMenu("Mostrar...", "Todos os ve�culos", "Ve�culos pelo nome do fabricante", &L, funcMostrar);
                break;

            case 3:
                miniMenu("Ordenar por...", "Ano de lan�amento", "Modelo do ve�culo", &L, funcOrdenar);
                break;

            case 4: // Remover ve�culo pela placa informada
                miniMenu("Remover pelo...", "Placa do ve�culo", "Fabricante", &L, funcRemover);
                break;

            /*case 5: {// Remover ve�culos com base no fabricante
                string fabric;
                cout << ">> Informe o fabricante: ";
                cin >> fabric;
                int qtd = L1->removeVal(fabric);
                if(qtd == 0) cout << "!!! N�O foi encontrado carros com fabricante informado !!!";
                else cout << ""
                break;
            }*/

        }; getchar();
    }
    while(menu != 0);
}

