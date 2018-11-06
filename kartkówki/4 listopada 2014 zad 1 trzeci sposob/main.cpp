#include <iostream>
/*
 Prosz� napisa� program, kt�ry wczytuje wprowadzany z klawiatury ci�g liczb naturalnych
zako�czonych zerem stanowi�cym wy��cznie znacznik ko�ca danych.
Program powinien wypisa� 10 co do wielko�ci warto��, jaka wyst�pi�a w ci�gu.
Na przyk�ad dla ci�gu: 1,2,3,2,3,4,5,6,7,8,9,9,11,12,13,0 powinna zosta� wypisana liczba 3.
Mo�na za�o�y�, �e w ci�gu znajduje si� wystarczaj�ca liczba element�w
*/
using namespace std;

void print_table(int tab[], int N)
{
    for (int i = 0; i < N; i++)
    {
        cout<<tab[i]<<" ";
    }
    cout<<endl;
}

void shift_right(int tab[], int N, int shift_start, int inserted_value) {
    cout<< "Shift table right"<< " starting from: " << shift_start<<" element," << "inserting value " << inserted_value<< endl;
    int to_shift;
    int to_insert = inserted_value;

    for (int i = shift_start; i < N; i++)
    {
        to_shift = tab[i];
        tab[i] = to_insert;
        to_insert = to_shift;
    }
}

void shift_left(int tab[], int N, int shift_start, int inserted_value) {
    cout<< "Shift table left"<< " starting from: " << shift_start<<" element," << "inserting value " << inserted_value << endl;
    int to_shift;
    int to_insert = inserted_value;

    for (int i = shift_start; i >= 0; i--)
    {
        to_shift = tab[i];
        tab[i] = to_insert;
        to_insert = to_shift;
    }
}

void shift_right_test(int tab[], int N)
{
    print_table(tab, N);
    shift_right(tab, N, 2,7);
    print_table(tab, N);
    shift_right(tab, N, 0,5);
    print_table(tab, N);
    shift_right(tab, N, N - 1, 0);
    print_table(tab, N);

}

void shift_left_test(int tab[], int N)
{
    shift_left(tab, N, 2,7);
    print_table(tab, N);
    shift_left(tab, N, 0,5);
    print_table(tab, N);
    shift_left(tab, N, N - 1, 3);
    print_table(tab, N);
}

int main()
{
    int N = 10;
    int tab[N] = {1,2,3,4,5,6,7,8,9,10};

    shift_right_test(tab, N);
    shift_left_test(tab, N);

    return 0;
}
