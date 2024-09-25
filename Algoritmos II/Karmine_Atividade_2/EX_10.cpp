/*10 � Crie um programa que ao ser iniciado dever� ser informado uma palavra chave
(uma palavra qualquer informada pelo usu�rio), em seguida o programa deve solicitar
que o usu�rio digite palavras, a cada palavra digitada dever� ser verificado se ele
acertou a palavra chave, caso tenha acertado o programa deve apresentar uma
mensagem e finalizar o teste, juntamente com o n�mero de tentativas que foram
necess�rias. Caso o usu�rio n�o acertar e mesmo assim queira encerrar o programa
dever� digitar a palavra Fim.
OBS: o sistema n�o deve fazer distin��o entre letras mai�sculas e min�sculas e n�o
dever� ser utilizado acentua��o e cedilha. A palavra Fim n�o pode ser utilizada como
palavra chave.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

int main()
{
    setlocale(LC_ALL,"portuguese");
    string chave, text, fim = "fim";
    int falhas = 1;

    cout << "Informe uma palavra-chave: ";
    getline(cin, chave);

    for(int i = 0; i <= chave.size(); i++){
        chave[i] = tolower(chave[i]);}

    cout << "\nAgora, adivinhe qual a palavra-chave: ";
    getline(cin, text);

    for(int i = 0; i <= text.size(); i++){
        text[i] = tolower(text[i]);}

    while (chave != text){
        cout << "\nErrou! Tente novamente ou encerre o programa(Fim): " ;
        getline(cin, text);

        for(int i = 0; i <= text.size(); i++){
            text[i] = tolower(text[i]);}

        if(text == fim){
            cout << "\nPrograma encerrado!";
            break;
        }

        falhas++;
    }

    if (chave == text) {
         cout << "\nParab�ns! Voc� acertou a palavra-chave!\nVoc� obteve o total de " << falhas << " tentiva(s)...";
    }

}
