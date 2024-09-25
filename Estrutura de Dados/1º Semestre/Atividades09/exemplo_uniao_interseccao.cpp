#include "descritor-template.hpp"

main() {
    system ("color F2");
    setlocale(LC_ALL, "Portuguese");

    ListaD<int> L1;
    L1.adFim(30);
    L1.adFim(40);
    L1.adFim(50);
    L1.adInicio(20);
    L1.adInicio(10);
    L1.adFim(10);
    L1.adFim(10);

    ListaD<int> L2;
    L2.adInicio(10);
    L2.adInicio(10);
    L2.adFim(30);
    L2.adFim(50);
    L2.adFim(70);

    L1.mostrar("Lista #1", "  Número", 0, 'T');
    cout << endl;
    L2.mostrar("Lista #2", "  Número", 0, 'T');
    cout << endl;
    L1.unirLista(L2).mostrar("Lista concatenada", "  Número", 0, 'T');
    cout << endl;
    L2.intersectLista(L1).mostrar("Lista intersectada", "  Número", 0, 'T');
    return 0;
}
