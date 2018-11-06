#include <iostream>
#include <vector>
/*
 Prosz� napisa� program, kt�ry wczytuje wprowadzany z klawiatury ci�g liczb naturalnych
zako�czonych zerem stanowi�cym wy��cznie znacznik ko�ca danych.
Program powinien wypisa� te elementy ci�gu kt�re s� r�wne �redniej arytmetycznej z 4 najbli�szych
s�siad�w. Na przyk�ad dla ci�gu: 2,3,2,7,1,2,4,8,5,2,2,4,3,9,5,4,0 powinny zosta� wypisane
podkre�lone liczby. Mo�na za�o�y�, �e w ci�gu znajduje si� co najmniej 5 element�w.
*/
using namespace std;

int main()
{
    vector<int> liczby;
    int liczba;
    while(true)
    {
        cin>>liczba;
        if(liczba == 0)
            break;
        liczby.push_back(liczba);
    }
    for(int i=0; i<liczby.size(); i++)
    {
        if((i >= 2 && i<= liczby.size() - 3) && liczby[i] == (liczby[i-2] + liczby [i-1] + liczby[i+1] + liczby[i+2]) / 4.0 ) // standardowy przyklad
           {
               cout<<liczby[i]<<" ";
           }

        if((i == 1) && liczby[i] == (liczby[i-1] + liczby [i+1] + liczby[i+2] + liczby[i+3]) / 4.0) // liczba nr 2
           {
               cout<<liczby[i]<<" ";
           }

        if((i == liczby.size() - 2) && liczby[i] == (liczby[i-3] + liczby [i-2] + liczby[i-1] + liczby[i+1]) / 4.0)  // przedostatnia
           {
               cout<<liczby[i]<<" ";
           }
        if((i == liczby.size() -1) && liczby[i] == (liczby[i-4] + liczby [i-3] + liczby[i-2] + liczby[i-1]) / 4.0) // ostatnia
           {
               cout<<liczby[i]<<" ";
           }

        if((i == 0) && liczby[i] == (liczby[i+1] + liczby [i+2] + liczby[i+3] + liczby[i+4]) / 4.0)  // pierwsza
           {
               cout<<liczby[i]<<" ";
           }
    }
    return 0;
}
