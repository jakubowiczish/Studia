#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
/*
 Dane s� dwie tablice mog�ce pomie�ci� tak� sam� liczb� element�w:
 int t1[10][N];
 int t2[M]; // M = 10*N
W ka�dym wierszu tablicy t1 znajduj� si� uporz�dkowane rosn�co (w obr�bie wiersza) liczby
naturalne.
Prosz� napisa� fragment programu przepisuj�cy wszystkie singletony (liczby wyst�puj�ce dok�adnie
raz) z tablicy t1 do t2, tak aby liczby w tablicy t2 by�y uporz�dkowane rosn�co. Pozosta�e elementy
tablicy t2 powinny zawiera� zera.
*/
using namespace std;

int main()
{
    const int N = 20;
    int tab1[10][N];
    int tab2[10*N];

    srand(time(NULL));
    for(int i=0;i<10; i++) // wypelnienie tablicy na wlasne potrzeby
    {
        for(int j=0; j<N; j++)
        {
            tab1[i][j] = rand() % 200 + 1;
            cout<<tab1[i][j]<<" ";
        }
    }
    cout<<endl<<endl<<endl;
    int k = 0;
    for(int i=0; i<10; i++) // przypisanie do tablicy jednowymiarowej
    {
        for(int j=0; j<N; j++)
        {
            tab2[k++] = tab1[i][j];
        }
    }
    int wynik = 0;
    for(int m=0; m<10*N; m++)
    {
        wynik = count(tab2, tab2 + 10*N, m); // zliczanie wystapien poszczegolnych liczb
        if(wynik == 1)                       // jesli wystepuja raz wyswietlamy je
        {
            cout<< m <<" ";
        }
        else
        {
            tab2[m] = 0;                    // jesli nie, zamiast liczby wyswietlamy 0
        }
    }

    cout<<endl<<endl;
    for(int i=0; i<10*N; i++)               // pokazanie tablicy na wlasne potrzeby
    {
        cout<<tab2[i]<<" ";
    }
    return 0;
}
