#include <iostream>
using namespace std;

#include <cstring>


#include "lista_funcionario.hpp"
#include "lista_descritor.hpp"

int main(void)
{
    setlocale(LC_ALL, "Portuguese");


    ListaFunc *listaF = new ListaFunc();
    Lista *listaProd = new Lista();

    insereOrdenado(listaF, Funcionario(0, "Pedro", 'F'));
    insereOrdenado(listaF, Funcionario(10, "Maria", 'F'));
    insereOrdenado(listaF, Funcionario(5, "Joao", 'F'));
    insereOrdenado(listaF, Funcionario(2, "Ana", 'F'));
    cout << "L[" << listaF->tamanho << "]:{" << listaF << "}" << endl; //mostra a lista


    insereInicioL(listaProd, 1);
    insereInicioL(listaProd, 2);
    insereInicioL(listaProd, 3);
    insereInicioL(listaProd, 80);
    cout << "L[" << listaProd->tamanho << "]:{" << listaProd << "}" << endl; //mostra a lista


    delete(listaF);
    delete(listaProd);
    return EXIT_SUCCESS;
}
