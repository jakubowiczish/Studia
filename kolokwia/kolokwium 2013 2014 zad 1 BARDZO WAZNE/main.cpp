#include <iostream>
/*
Tablica t[N][N] jest wype�niona liczbami naturalnymi. W dok�adnie jednym
wierszu istnieje dok�adnie jeden fragment ci�gu Fibonacciego o d�ugo�ci
wi�kszej ni� 2, mniejszej ni� N. Napisz funkcj�, kt�ra znajdzie ten fragment i
zwr�ci numer wiersza, w kt�rym si� znajduje.
*/
using namespace std;
const int N = 3;
int row_of_Fibonacci(int tab[N][N]);
bool isFibonacci(int n);

int main()
{
    int tab[N][N] =
    {
        {5,13,34},
        {5,8,13},
        {1,3377,1}
    };
    cout << row_of_Fibonacci(tab);
    return 0;
}

int row_of_Fibonacci(int tab[N][N])
{
    for(int i=0; i < N; i++)
    {
        for(int j=0; j < N - 2; j++)
        {
            if(isFibonacci(tab[i][j]) and isFibonacci(tab[i][j+1]) and isFibonacci(tab[i][j+2]) and tab[i][j] + tab[i][j+1] == tab[i][j+2])
            {
                return i;
            }

        }
    }
    return -1;
}

bool isFibonacci(int n)
{
    int Fib1 = 0;
    int Fib2 = 1;
    while(Fib2 <= n)
    {
        int Fib3 = Fib1 + Fib2;
        Fib1 = Fib2;
        Fib2 = Fib3;
        if(Fib2 == n)
            return true;
    }
    return false;
}
