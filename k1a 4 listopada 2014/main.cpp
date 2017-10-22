#include <iostream>
#include <algorithm>
#include <vector>
/*
Prosz� napisa� program, kt�ry wczytuje wprowadzany z klawiatury ci�g liczb naturalnych
zako�czonych zerem stanowi�cym wy��cznie znacznik ko�ca danych.
Program powinien wypisa� 10 co do wielko�ci warto��, jaka wyst�pi�a w ci�gu.
Na przyk�ad dla ci�gu: 1,2,3,2,3,4,5,6,7,8,9,9,11,12,13,0 powinna zosta� wypisana liczba 3.
Mo�na za�o�y�, �e w ci�gu znajduje si� wystarczaj�ca liczba element�w.
*/
using namespace std;

int main()
{
    vector <int> liczby;
    int liczba;
    cin>>liczba;
    while(liczba != 0)
    {
        cin>>liczba;
        liczby.push_back(liczba);
        sort(liczby.begin(),liczby.end());
    }
    int index = liczby.size()-1;

        for(int i = 0; i < 9; i++)
        {
            int liczbaTemp = liczby[index];
            index--;
            while(liczbaTemp == liczby[index])
            {
                 index--;
            }
        }

    for(unsigned int i=0; i<liczby.size(); i++)
        cout<<liczby.at(i)<<" ";
    cout<<endl;
    cout<<liczby[index]<<endl;
    cout<<index<<endl;

    return 0;
}
