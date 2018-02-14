#include <iostream>
/* Dana jest tablica int t[N][N] zawieraj�ca liczby naturalne. Dok�adnie w jednym z wierszy
tablicy znajduje si� fragment ci�gu Fibonacciego o d�ugo�ciwi�kszej ni�2,a mniejszej ni� N. Prosz�
napisa� funkcj�, kt�ra odszuka ten fragment ci�gu i zwr�ci numer wiersza w kt�rym on si� znajduje.
Uwagi:
o Czas na rozwi�zanie zadania wynosi 25 minut, za zadanie mo�na otrzyma� 5 punkt�w.
o oceniane b�d�: przejrzysto�� iczytelno�� kodu oraz efektywno�� rozwi�zania'
*/
using namespace std;

bool isFibonacci(int i)
{
    int Fibonacci1 = 0;
    int Fibonacci2 = 1;
    while(Fibonacci2 <= i)
    {
        int Fibonacci3 = Fibonacci1 + Fibonacci2;
        Fibonacci1 = Fibonacci2;
        Fibonacci2 = Fibonacci3;
        if(Fibonacci2 == i) return true;
    }
    return false;
}

int nextFibonacci(int i)
{
    int Fibonacci1 = 0;
    int Fibonacci2 = 1;
    while(Fibonacci2 <= i)
    {
        int Fibonacci3 = Fibonacci1 + Fibonacci2;
        Fibonacci1 = Fibonacci2;
        Fibonacci2 = Fibonacci3;
        if(Fibonacci2 == i)
            return Fibonacci1 + Fibonacci2;
    }
    return -1;
}
int main()
{
    const int N = 10;
    int t[N][N];
    // testy przykladowe
    t[0][0] = 2;
    t[0][1] = 3;
    t[0][2] = 5;
    t[1][0] = 2;
    t[1][1] = 3;
    t[1][2] = 5;
    for(int i=0; i<N; i++)
    {
        int licznik = 0;
        int licznikMAX = 0;
        for(int j=0; j<N; j++)
        {
            if(isFibonacci(t[i][j]))
            {
                licznik++;
                if(licznik > licznikMAX)
                    licznikMAX = licznik;
            }
            else
                licznik = 0;
        }
    cout<<"ilosc liczb ciagu w wierszu " << i << " to "<< licznikMAX <<endl;
    }
return 0;
}
