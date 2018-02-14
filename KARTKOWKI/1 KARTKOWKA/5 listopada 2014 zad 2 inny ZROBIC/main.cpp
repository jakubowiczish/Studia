#include <iostream>
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
    srand(time(NULL));
    const int N = 5;
    const int M = 10 * N;
    int tab1[10][N];
    int tab2[M];
    // wypelnienie tablicy
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<N; j++)
        {
            tab1[i][j] = rand () % 1000 + 1;
            cout<<tab1[i][j]<<"\t";
        }
        cout<<endl<<endl;
    }
    int k = 0;
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<N; j++)
        {
            tab2[k++] = tab1[i][j];
        }
    }

    int tab3[10*N];
    int p = 0, r = 0;
    for(int i=0; i<10*N; i++)
    {
        for(int m=i+1; m<10*N-1; m++)
        {
            if(tab2[i] == tab2[m])
            {
                tab3[p++] = 0;
            }
            else
            {
                tab3[r++] = tab2[i];
            }
        }
    }

cout<<endl<<endl<<endl;
    for(int i=0; i<10*N; i++)
    {
        cout<<tab3[i]<<" ";
    }
    return 0;
}
