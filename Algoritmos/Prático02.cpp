#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese");
    srand(time(NULL));

    int V[20], x, aux, somap = 0, somai = 0;

    cout << "\n- Elementos do vetor V: ";

    for(int x = 0;x<20;x++)
    {
        V[x] = rand() % 51 + 35 ;
        if (V[x]%2==0)
        somap++;
        else
        somai++;
    }

    for (int i = 0;i<20;i++)
    {
        if(i<19)
        cout<<V[i]<<", ";
        else
        cout<<V[i]<<endl;
    }

    for (x = 0; x < 20; x++)
    {
        for (int i = x + 1; i < 20; i++)
        {
            if (V[i] < V[x])
            {
                aux = V[x];
                V[x] = V[i];
                V[i] = aux;
            }
        }
    }

    cout << "\n- Elementos do vetor V(Crescente): ";

    for (x = 0; x < 20; x++)
    {
        if(x<19)
        cout<<V[x]<<", ";
        else
        cout<<V[x]<<endl;
    }

    if(somap>somai)
    cout<<"\n- A maior parte de elementos é par!\n- Contagem: "<<somap<<endl;
    else if (somap<somai)
    cout<<"\n- A maior parte de elementos é ímpar!\n- Contagem: "<<somai<<endl;
    else
    cout<<"\nA quantidade de ímpares e pares é igual!\n- Contagem ímpar: "<<somai<<"\n- Contagem par: "<<somap<<endl;

}
