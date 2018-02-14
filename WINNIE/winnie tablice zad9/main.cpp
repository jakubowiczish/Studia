#include <iostream>
#include <cstdlib>
#include <ctime>
/*
Dane s� definicje:
const
max1 = 100; max2 = 200;
type
wiersz = array[1..max2] of integer;
table = array[1..max1] of wiersz;
Typ table opisuje tablic� zawieraj�c� max1 wierszy po max2 element�w. Prosz� napisa�
funkcj�, kt�ra dla zmiennej typu table zwraca ilo�� wierszy, w kt�rych warto�ci element�w
stanowi� ci�gi arytmetyczne.
*/
using namespace std;
const int N = 3;

int number_of_lines(int tab[N][N])
{
    // roznica ciagu
    int counter = 1; // stanowi dlugosc ciagu arytmetycznego w poszczegolnej linii
    int lines = 0;
    int diff = tab[0][1] - tab[0][0];
    int wiersz = 0;
    for(int i=0; i<N; i++)
    {
        diff = tab[i][1] - tab[i][0];
        for(int j=0; j<N; j++)
        {
            cout<<diff<<endl;
            if(tab[i][j+1] == tab[i][j] + diff)
            {
                counter++;
                if(counter == N)
                {
                    lines++;
                }
            }
            else
            {
                counter = 1;
            }
         diff = tab[i][j+1] - tab[i][j]; // roznica w wierszu
        }
    }

    for(int i=0; i<N; i++)
    {
        cout<<"Wiersz: "<<i<<", liczby: \t";
        for(int j=0; j<N; j++)
        {
            cout<<tab[i][j]<<"\t";
        }
        cout<<endl<<endl;
    }
    cout<<"Liczba linii, w ktorych jest ciag arytmetyczny: "<<lines<<endl;
    return lines;
}
int main()
{
    int t[N][N];
    srand(time(NULL));
    t[0][0] = 4;
    t[0][1] = 2;
    t[0][2] = 0;
    t[1][0] = 1;
    t[1][1] = 2;
    t[1][2] = 3;
    t[2][0] = 1;
    t[2][1] = 1;
    t[2][2] = 1;
    number_of_lines(t);

    return 0;
}
