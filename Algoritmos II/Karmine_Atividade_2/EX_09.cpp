/*9 - Escreva um programa que leia 3 strings quaisquer em seguida verifique, em relação
ao número de caracteres, qual é a maior string, a menor string e a do meio, apresente
as string em ordem crescente em relação ao número de caracteres que possuem e com
todos os caracteres em maiúsculo.*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

int main()
{
    string text1, text2, text3;
    int t1, t2, t3;

    cout << "Digite um texto qualquer: ";
    getline(cin, text1);
    t1 = text1.size();

    cout << "\nDigite outro texto qualquer: ";
    getline(cin, text2);
    t2 = text2.size();

    cout << "\nDigite mais um texto qualquer: ";
    getline(cin, text3);
    t3 = text3.size();


    if ((t1 >= t2) and (t1 >= t3) and (t2 >= t3)) {
        for (int i = 0; i <= t3; i++){
            text3[i] = toupper(text3[i]);}
            cout << "\nMenor: " << text3;

         for (int i = 0; i <= t2; i++){
            text2[i] = toupper(text2[i]);}
            cout << "\nMeio: " << text2;

         for (int i = 0; i <= t1; i++){
            text1[i] = toupper(text1[i]);}
            cout << "\nMaior: " << text1;
    }

    else if ((t2 >= t1) and (t2 >= t3) and (t1 >= t3)) {
        for (int i = 0; i <= t3; i++){
            text3[i] = toupper(text3[i]);}
            cout << "\nMenor: " << text3;

         for (int i = 0; i <= t1; i++){
            text1[i] = toupper(text1[i]);}
            cout << "\nMeio: " << text1;

         for (int i = 0; i <= t2; i++){
            text2[i] = toupper(text2[i]);}
            cout << "\nMaior: " << text2;
    }

    else if ((t3 >= t1) and (t3 >= t2) and (t1 >= t2)) {
        for (int i = 0; i <= t2; i++){
            text2[i] = toupper(text2[i]);}
            cout << "\nMenor: " << text2;

         for (int i = 0; i <= t1; i++){
            text1[i] = toupper(text1[i]);}
            cout << "\nMeio: " << text1;

         for (int i = 0; i <= t3; i++){
            text3[i] = toupper(text3[i]);}
            cout << "\nMaior: " << text3;
    }

    else if ((t1 >= t2) and (t1 >= t3) and (t3 >= t2)) {
        for (int i = 0; i <= t2; i++){
            text2[i] = toupper(text2[i]);}
            cout << "\nMenor: " << text2;

         for (int i = 0; i <= t3; i++){
            text3[i] = toupper(text3[i]);}
            cout << "\nMeio: " << text3;

         for (int i = 0; i <= t1; i++){
            text1[i] = toupper(text1[i]);}
            cout << "\nMaior: " << text1;
    }

    else if ((t2 >= t1) and (t2 >= t3) and (t3 >= t1)) {
        for (int i = 0; i <= t1; i++){
            text1[i] = toupper(text1[i]);}
            cout << "\nMenor: " << text1;

         for (int i = 0; i <= t3; i++){
            text3[i] = toupper(text3[i]);}
            cout << "\nMeio: " << text3;

         for (int i = 0; i <= t2; i++){
            text2[i] = toupper(text2[i]);}
            cout << "\nMaior: " << text2;
    }

    else if ((t3 > t1) and (t3 > t2) and (t2 > t1)) {
        for (int i = 0; i <= t1; i++){
            text1[i] = toupper(text1[i]);}
            cout << "\nMenor: " << text1;

         for (int i = 0; i <= t2; i++){
            text2[i] = toupper(text2[i]);}
            cout << "\nMeio: " << text2;

         for (int i = 0; i <= t3; i++){
            text3[i] = toupper(text3[i]);}
            cout << "\nMaior: " << text3;
    }
}
