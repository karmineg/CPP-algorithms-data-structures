#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<iomanip>

using namespace std;

main(){
    setlocale(LC_ALL, "Portuguese");
    int *menu = new int(-1);
    int *cont = new int(0);
    int *cont2 = new int(0);
    int *E = new int(0);

    do {
        cout << "Informe a quantidade de posições do vetor: ";
        cin >> *E;
        if(*E > 50 )
            cout << "Valor inválido! Insira um valor menor ou igual a 50!" << endl << endl;
        else if(*E < 5 )
            cout << "Valor inválido! Insira um valor maior ou igual a 5!" << endl << endl;
        else
            break;
    } while(true);

    int *pv = new int[*E];
    int *ps = new int;

    do
    {
        system("cls");
        cout << "#######MENU DE OPÇÕES#######" << endl;
        cout << "# 0 - Sair                 #" << endl;
        cout << "# 1 - Gerar vetor          #" << endl;
        cout << "# 2 - Localizar valor      #" << endl;
        cout << "# 3 - Mostrar vetor        #" << endl;
        cout << "# 4 - Mostrar vetor 'sobra'#" << endl;
        cout << "############################" << endl;
        cout << "Sua escolha: ";
        cin >> *menu;
        fflush(stdin);

        system("cls");
        switch(*menu)
        {
        case 0:
            cout << "Programa finalizado!";
            break;

        case 1:
            *cont += 1;
            for(int i = 0; i < *E; i++) {
            int *Rand = new int;
            int *qtd = new int;

            do {
                *Rand = 1 + (rand() % 50);
                *qtd = 0;
                for(int j = 0; j < i; j++) {
                    if(*Rand == *pv) {
                        break;
                    }
                    *qtd += 1;
                    pv++;
                }
                pv -= *qtd;
            } while(*qtd != i);
            pv += i;
            *pv = *Rand;
            pv -= i;
            }
            cout << "Vetor gerado!";
            break;

        case 2:
            if (*cont == 0)
                cout << "Essa opção necessita de um vetor já gerado!";

            else {
                *cont2 += 1;
                int *num = new int(0);

                cout << "> Informe um número para localizar no vetor: ";
                cin >> *num;

                for(int i = 0; i < *E; i++) {
                    if(*pv == *num) {
                        cout << "Valor " << *num << " Pertence ao vetor e está no endereço de memória " << pv;
                        fflush(stdin);
                        pv -= i;
                        break;
                    }
                    else if((*pv != *num)and(i == *E- 1)) {
                        cout << "Valor inserido não existe no vetor! Adicionado no vetor 'sobra'";
                        *ps = *num;
                        ps++;
                        fflush(stdin);
                        ps -= i;
                        pv -= i;
                        break;
                    }
                    pv++;
                    }
                }

            break;

        case 3:
            if (*cont == 0)
                cout << "Essa opção necessita de um vetor já gerado!";

            else {
                *cont += 1;
                cout << "Vetor: " << endl;
                for(int i = 0; i < *E; i++) {
                pv += i;
                cout << *pv;
                pv -= i;
                if(i < *E) cout << ", ";
                }
            }
            break;

        case 4:
            if (*cont2 == 0)
                cout << "Execute a opção '2' antes!";

            else {
                cout << "Vetor 'sobra': " << endl;
                for(int i = 0; i < *E; i++) {
                ps += i;
                cout << *ps;
                ps -= i;
                if(i < *E) cout << ", ";
                }
            }

            break;

        default :
            system("cls");
            cout << "Opção inválida!";

        }
        getchar();
    }
    while (*menu != 0);
}

