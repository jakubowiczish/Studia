#include <iostream>
#include <cstdlib>
#include <ctime>
/*
Dane s� definicje:
const
max1 = 100;
max2 = 200;
type
wiersz = array[1..max1] of integer;
tablica = array[1..max2] of wiersz;
Zak�adamy, �e zmienna typu tablica jest wype�niona przypadkowymi warto�ciami. Prosz�
napisa� funkcj�, kt�ra dla zmiennej typu tablica zwraca numer wiersza w kt�rym wyst�puje
najd�u�szy sp�jny fragment z�o�ony z liczb o tej samej warto�ci. W przypadku kilku
fragment�w o tej samej d�ugo�ci nale�y zwr�ci� pozycj� pierwszego z nich
*/
using namespace std;
const int max1 = 10, max2 = 20;
int line_number(int tab[max1][max2]) // funkcja ktora sprawdza kazdy wiersz po kolei, powtarzajace sie elementy
{                                    // zlicza ilosc powtorzen cyfr z rzedu i podaje w ktorym wierszu wystapily
    int counter = 1;
    int counterMAX[max1];
    for(int i=0; i<max1; i++)
    {
        counterMAX[i] = 0;
    }
    for(int i=0; i<max1; i++)
    {
        counter = 1;
        for(int j=0; j<max2-1; j++)
        {
            if(tab[i][j] == tab[i][j+1])
            {
                counter++;
                counterMAX[i] = counter;
            }
            else
            {
                counter = 1;
            }
        }
    }
    int maximum = 0;
    int line = 0;
    for(int i=0; i<max1; i++)
    {
        if(counterMAX[i] > maximum)
        {
            maximum = counterMAX[i];
            line = i;
        }
    }
    cout<<maximum<<endl;
return line;
}
int main()
{
    int t[max1][max2];
    int result = 0;
    srand(time(NULL));
    for(int i=0; i<max1; i++)
    {
        for(int j=0; j<max2; j++)
        {
            t[i][j] = rand() % 2 + 1;
            cout<<t[i][j]<<" ";
        }
    cout<<endl;
    }
    int line = line_number(t);
      cout<<"W wierszu "<<line;

    return 0;
}
