#include<iostream>
using namespace std;
#include "descritor-template.hpp"

typedef string* pointS;
struct Comida {
    int id;
    string nome, tipo;
};

// !!! IMPORTANTE: Overloading para MOSTRAR comidas !!!
ostream& operator<<(ostream &o, Comida &C) {
    return o << C.id << " |" << setfill(' ') << setw(15) << C.nome << " |"
             << setfill(' ') << setw(15) << C.tipo;
}

// !!! IMPORTANTE: Overloading para buscar comida pelo TIPO usando STRING (OBRIGATÓRIO USAR OPERADOR "==")
bool operator==(const Comida &C, const string &tipo) {
    return (C.tipo == tipo);
}

// !!! IMPORTANTE: Overloading para buscar comida pelo NOME usando PONTEIRO DE STRING (OBRIGATÓRIO USAR OPERADOR "==")
bool operator==(const Comida &C, const pointS &nome) {
    return (C.nome == *nome);
}

// O QUE O CÓDIGO FAZ???
// Armazena comidas em uma lista, e BUSCAS são realizados pelo nome ou tipo das comidas!!
main() {
    setlocale(LC_ALL, "Portuguese");

    ListaS<Comida> L;
    string col = " Código |        Nome |        Tipo";

    // ADICIONANDO COMIDAS
    Comida C = { 1, "Abacaxi", "Fruta"};
    L.adInicio(C);

    C = { 2, "Picanha", "Carne" };
    L.adInicio(C);

    C = { 3, "Banana", "Fruta" };
    L.adInicio(C);

    C = { 4, "Tomate", "Fruta" };
    L.adInicio(C);

    C = { 5, "Feijão", "Grão" };
    L.adInicio(C);


    // BUSCAR SE EXISTE UMA DETERMINADA COMIDA (existeVal, usa OVERLOAD do ponteiro)
    string* comidaP = new string("Batata");
    bool existeBatata = L.existeVal(comidaP);
    if(existeBatata) {
        cout << "> Existe batata na lista!!! :D\n\n";
    } else {
        cout << "> NÃO tem batata... :(\n\n";
    }

    *comidaP = "Tomate";
    if(L.existeVal(comidaP)) {
        cout << "> Tem um tomate na lista!!! :D\n\n";
    } else {
        cout << "> Cadê o tomate??? :|\n\n";
    }


    // PEGAR ENDEREÇO DE UMA COMIDA DE UM NOME (existeNo, usa OVERLOAD do ponteiro)
    *comidaP = "Feijão";
    No<Comida>* Feijao = L.existeNo(comidaP);
    cout << "> O endereço do nó onde está Feijão é " << Feijao << "!!\n\n";


    // BUSCAR QUANTAS COMIDAS DE UM TIPO TEM!!! (qtdD, usa OVERLOAD de string)
    int qtdFruta = L.qtdD("Fruta");
    cout << "> Há " << qtdFruta << " frutas na lista!!\n\n";

    int qtdLegume = L.qtdD("Legume");
    cout << "> Quantidade de legumes: " << qtdLegume << ";\n\n";

    cout << endl;
}
