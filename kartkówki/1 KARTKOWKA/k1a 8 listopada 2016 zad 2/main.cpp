#include <iostream>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <algorithm>
/*
Prosz� napisa� program, kt�ry wype�nia tablic� int tab[MAX] liczbami pseudolosowymi
z zakresu [1 .. 1000], a nast�pnie wyznacza i wypisuje sum� 10 najwi�kszych element�w
z tablicy.
Uwagi:
- tablica tab zajmuje ponad po�ow� dost�pnej pami�ci na dane i nie mo�e ulec zmianie
*/
using namespace std;

int main()
{
    const int MAX = 20;
    int tab[MAX];
    srand(time(NULL));
    for(int i=0; i<MAX; i++)
    {
        tab[i] = (rand() % 1000) + 1;
    }
    int licznik = 10;
    sort(tab,tab+20);
    for(int i=0; i<MAX; i++)
        cout<<tab[i]<<" ";
    long suma = 0;
    for(int i=MAX/2; i<MAX; i++)
    {
        suma += tab[i];
    }
    cout<<suma<<endl;


    return 0;
}
