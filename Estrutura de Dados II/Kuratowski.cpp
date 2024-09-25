#include <iostream>
#include <boost/graph/boyer_myrvold_planar_test.hpp>
#include <boost/graph/is_kuratowski_subgraph.hpp>
#include <iomanip>

#define YELLOW  "\033[33m"
#define WHITE   "\033[37m"
#define BOLDRED     "\033[1m\033[31m"
#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDYELLOW  "\033[1m\033[33m"
#define BOLDBLUE    "\033[1m\033[34m"

using namespace std;

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS, //Define a estrutura do grafo, não direcionado
    boost::property<boost::vertex_index_t, int>, boost::property<boost::edge_index_t, int>> grafo; // e o tipo de variavel que vai ser add no grafo, nesse caso um inteiro

typedef boost::adjacency_list<boost::listS, boost::vecS, boost::directedS, //Define a estrutura do dígrafo, direcionado
    boost::property<boost::vertex_index_t, int>, boost::property<boost::edge_index_t, int>> digrafo; // e o tipo de variavel que vai ser add no grafo, nesse caso um inteiro

// Função para criar um grafo de Petersen (contém subdivisão de subgrafo K3,3)
grafo gerarPetersen() {
    grafo g(10);
    boost::add_edge(0, 1, g);
    boost::add_edge(0, 4, g);
    boost::add_edge(0, 5, g);
    boost::add_edge(1, 2, g);
    boost::add_edge(1, 6, g);
    boost::add_edge(2, 3, g);
    boost::add_edge(2, 7, g);
    boost::add_edge(3, 4, g);
    boost::add_edge(3, 8, g);
    boost::add_edge(4, 9, g);
    boost::add_edge(5, 7, g);
    boost::add_edge(5, 8, g);
    boost::add_edge(6, 8, g);
    boost::add_edge(6, 9, g);
    boost::add_edge(7, 9, g);
    return g;
}

// Função para criar um grafo completo K5
grafo gerarK5() {
    grafo g(5);
    boost::add_edge(0, 1, g);
    boost::add_edge(0, 2, g);
    boost::add_edge(0, 3, g);
    boost::add_edge(0, 4, g);
    boost::add_edge(1, 2, g);
    boost::add_edge(1, 3, g);
    boost::add_edge(1, 4, g);
    boost::add_edge(2, 3, g);
    boost::add_edge(2, 4, g);
    boost::add_edge(3, 4, g);
    return g;
}

// Função para criar um grafo bipartido K3,3
grafo gerarK33() {
    grafo g(6);
    boost::add_edge(0, 3, g);
    boost::add_edge(0, 4, g);
    boost::add_edge(0, 5, g);
    boost::add_edge(1, 3, g);
    boost::add_edge(1, 4, g);
    boost::add_edge(1, 5, g);
    boost::add_edge(2, 3, g);
    boost::add_edge(2, 4, g);
    boost::add_edge(2, 5, g);
    return g;
}

// Função para criar um grafo completo K4
grafo gerarPlanar() {
    grafo g(4);
    boost::add_edge(0, 1, g);
    boost::add_edge(0, 2, g);
    boost::add_edge(0, 3, g);
    boost::add_edge(1, 2, g);
    boost::add_edge(1, 3, g);
    boost::add_edge(2, 3, g);
    return g;
}

// Função para criar um dígrafo não planar com subgrafo K5 com arestas paralelas
digrafo gerarDigrafo() {
     digrafo g(5);

    // Adiciona as arestas do grafo completo K5
    boost::add_edge(0, 1, g);
    boost::add_edge(0, 2, g);
    boost::add_edge(0, 3, g);
    boost::add_edge(0, 4, g);
    boost::add_edge(1, 2, g);
    boost::add_edge(1, 3, g);
    boost::add_edge(1, 4, g);
    boost::add_edge(2, 3, g);
    boost::add_edge(2, 4, g);
    boost::add_edge(3, 4, g);

    boost::add_edge(1, 0, g);
    boost::add_edge(2, 0, g);
    boost::add_edge(3, 0, g);
    boost::add_edge(4, 0, g);
    boost::add_edge(2, 1, g);
    boost::add_edge(3, 1, g);
    boost::add_edge(4, 1, g);
    boost::add_edge(3, 2, g);
    boost::add_edge(4, 2, g);
    boost::add_edge(4, 3, g);

    return g;
}

// Função para criar um grafo não planar com subgrafo K3,3 com laços
grafo gerarLacos() {
    grafo g(6);
    boost::add_edge(0, 3, g);
    boost::add_edge(0, 4, g);
    boost::add_edge(0, 5, g);
    boost::add_edge(1, 3, g);
    boost::add_edge(1, 4, g);
    boost::add_edge(1, 5, g);
    boost::add_edge(2, 3, g);
    boost::add_edge(2, 4, g);
    boost::add_edge(2, 5, g);
    boost::add_edge(2, 2, g);
    boost::add_edge(5, 5, g);
    boost::add_edge(4, 4, g);
    boost::add_edge(3, 3, g);
    boost::add_edge(1, 1, g);
    boost::add_edge(0, 0, g);
    return g;
}

void mostrar_grafo(const grafo& g) {
    int t = boost::num_vertices(g);

    cout << BOLDYELLOW << "\nGrafo:" << endl;
    cout << "    ";
    for (int c = 0; c < t; c++) {
        cout << YELLOW << setw(2) << c << " ";
    }
    cout << endl << endl;

    for (int i = 0; i < t; i++) {
        cout << YELLOW << setw(2) << i << "  ";
        for (int j = 0; j < t; j++) {
            cout << WHITE << setw(2) << boost::edge(i, j, g).second << " ";
        }
        cout << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    //grafo g = gerarK5();
    //grafo g = gerarK33();
    //grafo g = gerarPetersen();
    //grafo g = gerarPlanar();
    //grafo g = gerarLacos();
    digrafo g = gerarDigrafo();

    //mostrar_grafo(g);

    // Inicialize o índice da aresta
    auto indice_aresta = boost::get(boost::edge_index, g);
    auto aresta_cont = 0;

    // Atribuição de índices às arestas do grafo
    grafo::edge_iterator aresta_ini, aresta_final;
    for (boost::tie(aresta_ini, aresta_final) = boost::edges(g); aresta_ini != aresta_final; ++aresta_ini)
        boost::put(indice_aresta, *aresta_ini, aresta_cont++);

    // Declaração para o teste de planaridade
    typedef vector<grafo::edge_descriptor> kuratowski_edges_t; // criado um iterador para armazenar as arestas que formam um subgrafo de kuratowski
    kuratowski_edges_t kuratowski_edges;

    // Teste de planaridade do grafo
    if (boost::boyer_myrvold_planarity_test(boost::boyer_myrvold_params::graph = g, // testar a planaridade do grafo
        boost::boyer_myrvold_params::kuratowski_subgraph // Define o iterador onde as arestas do subgrafo de Kuratowski serão armazenadas, se o grafo não for planar.
        = back_inserter(kuratowski_edges)))
        cout << BOLDGREEN << "\nO grafo é planar!\n" << endl;
    else
    {
        cout << BOLDRED << "\nO grafo não é planar!\n" << endl;

        // Verificação de subgrafo de Kuratowski
        cout << BOLDYELLOW << "Arestas do subgrafo de Kuratowski: ";
        for (auto ki = kuratowski_edges.begin(); ki != kuratowski_edges.end(); ++ki)
        {
            cout << WHITE << *ki << " ";
        }
        cout << endl;

    }

    cout << BOLDGREEN;

    return 0;
}
