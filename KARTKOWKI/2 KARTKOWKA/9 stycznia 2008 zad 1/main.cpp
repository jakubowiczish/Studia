#include <iostream>

using namespace std;
/*
Dany jest typ tablicowy mapa = array [ 1..max,1..max ] of Boolean;
reprezentuj�cy map�. Warto�� true oznacza l�d, a warto�� false ocean. Na
oceanie znajduj� si� wyspy utworzone przez s�siaduj�ce pola (rysunek). Prosz�
napisa� w Pascalu funkcj� do kt�rej przekazujemy map� i wsp�rz�dne x,y
punktu na mapie. Je�eli wsp�rz�dne oznaczaj� punkt na wyspie, funkcja
powinna zatopi� wysp�. Funkcja powinna zwr�ci� rozmiar zatopionego obszaru.
Mo�na za�o�y�, �e �adna wyspa na mapie nie styka si� z jej kraw�dzi�.
*/
const int N = 5;

int plunge(bool tab[N][N],int x, int y)
{
    if(!tab[x][y])
        return 0;
    tab[x][y] = false;

    return 1 + plunge(tab,x+1,y) + plunge(tab,x-1,y) + plunge(tab,x,y-1) + plunge(tab,x,y+1);
}

int main()
{
    bool tab[N][N] =
    {
        {false,false,false,false,false},
        {false,true,true,false,false},
        {false,false,true,true,false},
        {false,true,true,false,false},
        {false,false,false,false,false},
    };
    int a,b;
    cin >> a >> b;
    cout<<plunge(tab,a,b);

return 0;
}
