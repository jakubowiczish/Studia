#include <iostream>

using namespace std;
/*
Dana jest 2-wymiarowa kwadratowa tablica int tab[N][N] wype�niona liczbami.
Napisz funkcj� rekurencyjn�, kt�ra znajdzie d�ugo�� najkr�tszej drogi z punktu (0,0) do (N-1,N-1)
przy poruszaniu si� jedynie w d� i w prawo.
Za d�ugo�� drogi uznajemy sum� warto�ci p�l przez kt�re przechodzi.
Przyk�ad

 1  3  6
 2 -5  9      1 -> 2 -> -5 -> 3 -> -7   =  -6
 8  3 -7
 */
const int N = 3;

int path(int tab[N][N],int x, int y)
{
    if(x == N-1 && y == N-1)
        return tab[x][y];
    if(x == N-1)
        return tab[x][y] + path(tab,x,y+1);
    if(y == N-1)
        return tab[x][y] + path(tab,x+1,y);
    return tab[x][y] + min(path(tab,x+1,y),path(tab,x,y+1));
}
int main()
{
    int tab[N][N] =
    {
        {1,2,3},
        {4,5,6},
        {7,8,9},
    };

    cout<<path(tab,0,0);
    return 0;
}
