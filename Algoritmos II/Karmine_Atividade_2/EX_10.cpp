/*10 – Crie um programa que ao ser iniciado deverá ser informado uma palavra chave
(uma palavra qualquer informada pelo usuário), em seguida o programa deve solicitar
que o usuário digite palavras, a cada palavra digitada deverá ser verificado se ele
acertou a palavra chave, caso tenha acertado o programa deve apresentar uma
mensagem e finalizar o teste, juntamente com o número de tentativas que foram
necessárias. Caso o usuário não acertar e mesmo assim queira encerrar o programa
deverá digitar a palavra Fim.
OBS: o sistema não deve fazer distinção entre letras maiúsculas e minúsculas e não
deverá ser utilizado acentuação e cedilha. A palavra Fim não pode ser utilizada como
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
         cout << "\nParabéns! Você acertou a palavra-chave!\nVocê obteve o total de " << falhas << " tentiva(s)...";
    }

}
