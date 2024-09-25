#include<iostream>
using namespace std;
#include "descritor-template.hpp"

struct Carro {
    int ID;
    string modelo, marca;
};

// !!! IMPORTANTE: Overloading para MOSTRAR carros !!!
ostream& operator<<(ostream &o, Carro &P) {
    return o << P.ID << " |" << setfill(' ') << setw(15) << P.modelo << " |"
             << setfill(' ') << setw(15) << P.marca;
}

// !!! IMPORTANTE: Overloading para remover carro pelo MODELO (OBRIGATÓRIA USAR OPERADOR "==")
bool operator==(const Carro &C1, const string &marcaParam) {
    return (C1.modelo == marcaParam);
}

// O QUE O CÓDIGO FAZ???
// Armazena carros em uma lista, e remove carros de um determinado MODELO (UM POR VEZ ou TODOS DE UMA VEZ)!!!
main() {
    setlocale(LC_ALL, "Portuguese");

    ListaS<Carro> L;
    string col = " Código |         Modelo |          Marca";

    // ADICIONANDO CARROS
    Carro C = { 1, "Fusca", "Volkswagem" };
    L.adFim(C);

    C = { 2, "Willys", "Jeep" };
    L.adFim(C);

    C = { 3, "Fusca", "Volkswagem" };
    L.adFim(C);

    C = { 4, "Fusca", "Volkswagem" };
    L.adFim(C);

    C = { 5, "Kombi", "Volkswagem" };
    L.adFim(C);

    C = { 6, "458", "Ferrari" };
    L.adFim(C);

    C = { 7, "DMC-12", "Delorean" };
    L.adFim(C);

    C = { 8, "Fusca", "Volkswagem" };
    L.adFim(C);

    L.mostrar("Lista de carros", col, 2, 'T');

    // REMOVER APENAS UM FUSCA E MOSTRAR
    Carro* Crem = L.removeUmVal("Fusca");
    cout << "\n\n\n> Um veículo foi removido, de código " << Crem->ID << "!!";

    // REMOVER TODOS OS 'FUSCAS' DA LISTA E MOSTRAR
    cout << "\n\n\n> Removido " << L.removeVariosVal("Fusca") << " Fuscas!\n\n\n";
    L.mostrar("Lista de carros sem Fuscinha... :(", col, 2, 'T');

    //cout << endl << endl;
    //L.mostrarDesdeFim("Lista de carros sem Fuscinha... :(", col, 2);

    cout << endl;
}
