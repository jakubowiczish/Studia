#include <iostream>
/*
Prosz� napisa� program czytaj�cy z wej�cia liczby typu integer i wypisuj�cy na wyj�ciu te z nich,
kt�re s� wi�ksze od przynajmniej trzech poprzednich. Prosz� rozwa�y� przypadki dla ci�gu
wej�ciowego o dowolnej d�ugo�ci.
*/

using namespace std;

int main()
{
    int liczba;
    cin>>liczba;
    int tab[4];
    tab[0] = liczba;
    while(true)
    {
        cin>>liczba;
        if(liczba == 0)
            break;

        tab[3] = tab[2];
        tab[2] = tab[1];
        tab[1] = tab[0];

        tab[0] = liczba;

        if(tab[0] > tab[1] && tab[0] > tab[2] && tab[0] > tab[3])
            cout<<tab[0]<<" ";


    }
    return 0;
}
