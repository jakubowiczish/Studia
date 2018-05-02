#include <iostream>
/*
Mamy zdefiniowan� n-elementow� tablic� liczb ca�kowitych.
Prosz� napisa� funkcj� zwracaj�c� warto�� typu bool oznaczaj�c�,
czy w tablicy istnieje dok�adnie jeden element najmniejszy
i dok�adnie jeden element najwi�kszy (liczba element�w najmniejszych oznacza liczb� takich element�w o tej samej warto�ci).
*/
using namespace std;
const int N = 5;

bool check(int tab[],int N)
{
    int maksimum = 0;
    int minimum = INT_MAX-2;
    for(int i=0; i<N; i++)
    {
        if(tab[i] > maksimum)
            maksimum = tab[i];
        if(tab[i] < minimum)
            minimum = tab[i];
    }

    int min_counter = 0;
    int max_counter = 0;

    for(int i=0; i<N; i++)
    {
        if(tab[i] == maksimum)
            max_counter++;

        if(tab[i] == minimum)
            min_counter++;

        if(max_counter > 1 || min_counter > 1)
           return false;
    }
    return true;
}

int main()
{
    int tab[N];
    tab[0] = 5;
    tab[1] = 4;
    tab[2] = 3;
    tab[3] = 1;
    tab[4] = 1;


    cout<<check(tab,N);
    return 0;
}
