#include "descritor-template.hpp"

void excluirVal(ListaS<int>* L, int num) {
    No<int> *N = L->inicio;
    int C = 0;
    // In�cio
    while(N != NULL) {
        cout << N->dado << endl;
        if(N->dado == num) {
            No<int> *atual = N;
            L->inicio = N->prox;
            N = N->prox;
            delete atual;
        } else break;
    }
    // Ap�s o in�cio
    while(N->prox != NULL && C < 20) {
        C++;
        No<int> *prox = N->prox;
        cout << N->dado << endl;
        if(prox->dado == num) {
            N->prox = prox->prox;
            delete prox;
        } else N = N->prox;
    }
}

struct Otario {
    float altura;
    int idade;
    string nome;
};

/*ostream& operator<<(ostream& os, const Otario o) {
    os << o.altura << " |" << setfill(' ') << setw(6) << o.idade << " |" << setfill(' ') << setw(10) << o.nome;
    return os;
}

bool operator==(const Otario &o1, const int &alt) {
    return (o1.altura == alt);
}*/


main() {
    /*system ("color F2");
    setlocale(LC_ALL, "Portuguese");

    ListaS<Otario> L1;
    Otario K = { 0.5, 12, "Karmoine" };
    Otario R = { 2, 17, "Rodolfo" };

    L1.adFim(K);
    L1.adFim(R);

    L1.mostrar("Lista de OT�RIOS", "  Altura | Idade |      Nome", 2, 'T');
    L1.removeVariosVal(2);
    //L1.removeVariosVal(i);
    L1.mostrar("Lista NOVA de ot�rios", "  Altura | Idade |      Nome", 2, 'T');*/

    ListaD<int> L1;
    L1.adFim(10);
    L1.adFim(10);
    L1.adFim(10);
    L1.adFim(20);
    L1.adFim(10);
    L1.adFim(30);
    L1.adFim(40);
    L1.adFim(10);
    L1.adFim(10);
    L1.adFim(10);
    L1.adFim(50);
    L1.adFim(60);
    L1.mostrar("Lista de n�meros", " N�meros", 0, 'T');

    L1.removeUmVal(10);
    L1.removeUmVal(20);
    L1.removeUmVal(40);
    //L1.removeVariosVal(10);

    L1.mostrar("Lista atualizada", " N�meros", 0, 'T');
    cout << endl;

    //L1.mostrarDesdeFim("Lista atualizada INVERTIDA", " N�meros", 0);*/
    return 0;
}
