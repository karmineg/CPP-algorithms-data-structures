#include<iostream>
using namespace std;
#include "descritor-template.hpp"

ListaD<char>* InverteLD(ListaD<char>* L, int I, int J){
    ListaD<char> LD, Laux1, Laux2;
    NoD<char>* N = L->inicio;
    int tam = L->tam;
    bool encontrado = false; // k a r m i n e / I = 2 / J = 4
                             // 0 1 2 3 4 5 6
    for(int i = 0; i <= J; i++){
        if(encontrado == true){
            LD.adInicio(N->dado); // i m r
            L->removeUmVal(N->dado); // n e
        }
        if(I == i){
            encontrado = true;
            LD.adInicio(N->dado); // r
            L->removeUmVal(N->dado); // m i n e
        }
        if(encontrado == false){
            Laux1.adFim(N->dado); // k a
            L->removeUmVal(N->dado); // r m i n e
        }
        N = N->prox;
    }

    N = L->inicio;
    while (N != NULL) {
        Laux2.adFim(N->dado); // n e
        L->removeIni(); // --
        N = N->prox;
    }

    N = Laux1.inicio;
    while (N != NULL) {
        L->adFim(N->dado); // k a
        Laux1.removeIni(); // --
        N = N->prox;
    }

    N = LD.inicio;
    while (N != NULL) {
        L->adFim(N->dado); // k a i m r
        LD.removeIni(); // --
        N = N->prox;
    }

    N = Laux2.inicio;
    while (N != NULL) {
        L->adFim(N->dado); // k a i m r n e
        Laux2.removeIni(); // --
        N = N->prox;
    }

    return L;
}

ListaS<char>* InverteLS(ListaS<char>* L, int I, int J){
    ListaS<char> LS, Laux1, Laux2;
    No<char>* N = L->inicio;
    int tam = L->tam;
    bool encontrado = false; // k a r m i n e / I = 2 / J = 4
                             // 0 1 2 3 4 5 6
    for(int i = 0; i <= J; i++){
        if(encontrado == true){
            LS.adInicio(N->dado); // i m r
            L->removeIni(); // n e
        }
        if(I == i){
            encontrado = true;
            LS.adInicio(N->dado); // r
            L->removeIni(); // m i n e
        }
        if(encontrado == false){
            Laux1.adFim(N->dado); // k a
            L->removeIni(); // r m i n e
        }
        N = N->prox;
    }

    N = L->inicio;
    while (N != NULL) {
        Laux2.adFim(N->dado); // n e
        L->removeIni(); // --
        N = N->prox;
    }

    N = Laux1.inicio;
    while (N != NULL) {
        L->adFim(N->dado); // k a
        Laux1.removeIni(); // --
        N = N->prox;
    }

    N = LS.inicio;
    while (N != NULL) {
        L->adFim(N->dado); // k a i m r
        LS.removeIni(); // --
        N = N->prox;
    }

    N = Laux2.inicio;
    while (N != NULL) {
        L->adFim(N->dado); // k a i m r n e
        Laux2.removeIni(); // --
        N = N->prox;
    }

    return L;
}

main() {
    system ("color 02");
    setlocale(LC_ALL, "Portuguese");
    int menu, I, J;

    cout << "Duplamente(0) ou Simplesmente(1): ";
    cin >> menu;

    switch(menu) {
        case 0: {
            ListaD<char> L;
            string C;
            cout << "> Insira um string: ";
            cin >> C;
            for (int i = 0; i < C.length(); i++) {
                L.adFim(C[i]);
            }
            L.mostrarSimples("Lista Duplamente");
            int T = L.tam - 1;
            do {
                cout << "\n> Digite apartir de qual índice deseja realizar a inversão(I): ";
                cin >> I;
                cout << "> Digite qual índice deve ser o limite da inversão(J): ";
                cin >> J;
                if(J > T) cout << "> O índice insirido para J é maior do que a quantidade de elementos armazenados na lista!\n\n";
                else if(I >= T) cout << "> O índice insirido para I é maior ou igual do que a quantidade de elementos armazenados na lista!\n\n";
                else if(I < 0) cout << "> O índice insirido para I deve ser maior do que 0!\n\n";
                else if(I >= J) cout << "> O índice insirido para I deve ser menor do que J!\n\n";
                else break;
            } while(true);

            L = *InverteLD(&L, I, J);
            L.mostrarSimples("Lista Duplamente após inversão");

            break;
        }

        case 1: {
            ListaS<char> L;
            string C;
            cout << "> Insira um string: ";
            cin >> C;
            for (int i = 0; i < C.length(); i++) {
                L.adFim(C[i]);
            }
            L.mostrarSimples("Lista Simplesmente");
            int T = L.tam - 1;

            do {
                cout << "\n> Digite apartir de qual índice deseja realizar a inversão(I): ";
                cin >> I;
                cout << "> Digite qual índice deve ser o limite da inversão(J): ";
                cin >> J;
                if(J > T) cout << "> O índice insirido para J é maior do que a quantidade de elementos armazenados na lista!\n\n";
                else if(I >= T) cout << "> O índice insirido para I é maior ou igual do que a quantidade de elementos armazenados na lista!\n\n";
                else if(I < 0) cout << "> O índice insirido para I deve ser maior do que 0!\n\n";
                else if(I >= J) cout << "> O índice insirido para I deve ser menor do que J!\n\n";
                else break;
            } while(true);

            L = *InverteLS(&L, I, J);
            L.mostrarSimples("Lista Simplesmente após inversão");

            break;
        }

        default:
            cout << "> Opção inválida!";
            break;

    };

}
