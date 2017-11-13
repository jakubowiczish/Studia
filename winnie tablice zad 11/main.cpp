#include <iostream>
/*
Dane s� nast�puj�ce definicje:
const
max = 10;
var
tab: array[1..max] of real;
Prosz� napisa� program, kt�ry wczytuje wprowadzony z klawiatury ci�g dodatnich liczb
rzeczywistych zako�czony warto�ci� -1, b�d�c� znacznikiem ko�ca ci�gu i umieszcza max
najwi�kszych element�w w tablicy tab. Mo�na za�o�y�, �e ci�g zawiera co najmniej max liczb.
*/
using namespace std;

int main()
{
    int nowe[10] = {0,0,0,0,0,0,0,0,0,0};
    int liczba;
    cin>>liczba;
    nowe[0] = liczba;
    while(liczba != 0)
    {
        cin>> liczba;
        while(liczba > nowe[0])
        {
            for(int i=9; i>=1; i--)
            {
                nowe[i] = nowe[i-1];
            }

            nowe[0] = liczba;
        }
    }
    for(int i=0; i<10; i++)
        cout<<nowe[i]<<" ";

    return 0;
}
