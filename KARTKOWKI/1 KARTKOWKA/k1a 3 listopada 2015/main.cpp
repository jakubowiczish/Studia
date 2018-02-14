#include <iostream>
#include <ctime>
#include <cstdlib>
/*
Prosz� napisa� program, kt�ry wype�nia tablic� t[N] pseudolosowymi liczbami nieparzystymi z zakresu [1..99],
a nast�pnie Wyznacza i wypisuje r�nic� pomi�dzy d�ugo�ci� najd�u�szego znajduj�cego si� w niej ci�gu
arytmetycznego o dodatniej r�nicy, a d�ugo�ci� najd�u�szego ci�gu arytmetycznego o ujemnej r�nicy, przy
za�o�eniu, �e kolejnymi wyrazami ci�gu s� elementy tablicy o kolejnych indeksach.
*/
using namespace std;

int main()
{
    const int N = 10;
    int tab[N];
    srand(time(NULL));
    for(int i=0; i<N; i++)
    {
        int k = rand() % 50; // liczby od 0 do 49
        k *= 2; // liczby 0,2,4,6 ... 98
        k += 1; // liczby 1,3,5, ... 99
        tab[i] = k;
    }
    int ciagodj = 1;
    int ciagdod = 1;
    int dciagu = 2;
    int roznica = tab[1] - tab[0];
    for(int i=2; i<N; i++)
    {
        if(tab[i-1] + roznica == tab[i])
        {
            dciagu++;
        }
        else
        {
            if(roznica > 0)
            {
                ciagdod = max(ciagdod,dciagu);
            }
            else if(roznica < 0)
            {
                ciagodj = max(ciagodj,dciagu);
            }
            roznica = tab[i] - tab[i-1];
            dciagu = 2;
        }
    }
    if(roznica > 0)
    {
        ciagdod = max(ciagdod,dciagu);
    }
    else if(roznica < 0)
    {
        ciagodj = max(ciagdod,dciagu);
    }
    cout<<(ciagdod - ciagodj)<<endl;
    return 0;
}
