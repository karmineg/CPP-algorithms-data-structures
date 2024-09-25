#include<iostream>
using namespace std;

#include "fila-dinamica.hpp"
#include "pilha-dinamica.hpp"

NoF<char>* InverterF(NoF<char>* F, int I, int J) {
    No<char> *Paux = nullptr;
    NoF<char> *Faux = nullptr;

    int cont = 0;
    int total = quantosItens(F);

    if(I != 0){
    while(F != NULL) {
            Faux = adicionaF(Faux, F->dado);
            F = removeF(F);
            cont++;
            if(cont == I) break;
        }
    }

    cont = 0;
    if(I != 0){
        if(J == total - 1) {
            while(F != NULL) {
                Paux = adicionaP(Paux, F->dado);
                F = removeF(F);
            }
        }
        else {
            if(total % 2 == 0) {
                while(F != NULL) {
                    Paux = adicionaP(Paux, F->dado);
                    F = removeF(F);
                    cont++;
                    if(cont == J - 1) break;
                }
            }
            else {
                while(F != NULL) {
                    Paux = adicionaP(Paux, F->dado);
                    F = removeF(F);
                    cont++;
                    if(cont == J - I) break;
                }
            }
        }
    }

    if(I == 0){
        if(J == total - 1) {
            while(F != NULL) {
                Paux = adicionaP(Paux, F->dado);
                F = removeF(F);
            }
        }
        else{
            while(F != NULL) {
                Paux = adicionaP(Paux, F->dado);
                F = removeF(F);
                cont++;
                if(cont == J + 1) break;
            }
        }
    }

    while(F != NULL) {
            Faux = adicionaF(Faux, F->dado);
            F = removeF(F);
        }

    cont = 0;
    if(I != 0){
    while(Faux != NULL) {
            F = adicionaF(F, Faux->dado);
            Faux = removeF(Faux);
            cont++;
            if(cont == I) break;
        }
    }

    while(Paux != NULL) {
           F = adicionaF(F, Paux->dado);
            Paux = removeP(Paux);
        }

    while(Faux != NULL) {
            F = adicionaF(F, Faux->dado);
            Faux = removeF(Faux);
        }

    getchar();
    return F;

}

main() {
    system ("color F2");
    setlocale(LC_ALL, "Portuguese");
    int menu = -1;
    NoF<char>* F = nullptr;

    do
    {
        system("cls");
        cout << "###########MENU DE OPÇÕES#########" << endl;
        cout << "# 0 - Sair                       #" << endl;
        cout << "# 1 - Inserir valores na fila    #" << endl;
        cout << "# 2 - Inverter elementos da fila #" << endl;
        cout << "# 3 - Mostrar fila               #" << endl;
        cout << "# 4 - Destruir fila              #" << endl;
        cout << "##################################" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);
        system("cls");

        switch(menu)
        {
            case 0 :
            cout << "Programa finalizado.";
            break;

            case 1:{
                string C;
                cout << "> Insira um string: ";
                cin >> C;
                cout << "> String " << C << " adicionado!";
                 for (int i = 0; i < C.length(); i++) {
                    F = adicionaF(F, C[i]);
                }
                getchar();
                break;
            }
            case 2: {
                int I;
                int J;
                int T = quantosItens(F);
                do {
                    cout << "> Digite apartir de qual valor deseja realizar a inversão(I): ";
                    cin >> I;
                    cout << "> Digite qual valor deve ser o limite da inversão(J): ";
                    cin >> J;
                    if(J >= T) cout << "> O valor insirido para J é maior ou igual do que a quantidade de elementos armazenados na fila!\n\n";
                    else if(I >= T) cout << "> O valor insirido para I é maior ou igual do que a quantidade de elementos armazenados na fila!\n\n";
                    else if(I < 0) cout << "> O valor insirido para I deve ser maior do que 0!\n\n";
                    else if(I >= J) cout << "> O valor insirido para I deve ser menor do que J!\n\n";
                    else break;
                } while(true);

                F = InverterF(F, I, J);
                cout << "\nFila invertida com sucesso!";

                break;}

            case 3:
                mostraF(F, "de caracteres");
                break;

            case 4:
                F = destroiF(F);
                cout << "Fila destruída com sucesso!";
                break;

            default:
                cout << "> Opção inválida!";
                break;

        }; getchar();
    }
    while(menu != 0);
}
