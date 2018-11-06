#include <iostream>
#include <cstdlib>
#include <ctime>
/*
Zad. 1 Dana jest du�a tablica typu tab=array[1..n] of integer. Prosz� napisa� funkcj�, kt�ra
zwraca sum� cyfr element�w tablicy zapisanych w systemie o podstawie 7, kt�rych indeks nie jest
liczb� pierwsz�. Wskaz�wka: rozwa�y� metod� sita.
Uwagi:
� Zawarto�� tablicy wej�ciowej nie mo�e ulec zmianie.
� Czas na rozwi�zanie zadania wynosi 25 minut, za zadanie mo�na otrzyma� 5 punkt�w.
� Oceniane b�d�: przejrzysto�� i czytelno�� kodu oraz efektywno�� rozwi�zania.
*/
using namespace std;

bool isPrime(int n)
{
    if(n < 2)
        return false;

    for(int i=2; i*i <= n; i++)
    {
        if(n % i == 0)
            return false;
    }

    return true;
}

int suma_cyfr_system7(int n)
{
    int next = n;
    int sum = 0;
    while(next > 0)
    {
        sum += next % 7;
        next /= 7;
    }
    return sum;
}

int main()
{
    srand(time(NULL));
    const int N = 100;
    unsigned long long mainSum = 0;
    int tab[N];
    for(int i=0; i<N; i++)
    {
        tab[i] = rand() % 1000 + 1;
        cout<<"Indeks: "<<i<<", liczba: "<<tab[i]<<endl;
    }
    for(int i=0; i<N; i++)
    {
        if(!isPrime(i))
        {
            mainSum += suma_cyfr_system7(tab[i]);
        }
    }
    cout<<"Suma cyfr liczb ktore stoja na indeksach ktore nie sa liczbami pierwszymi: "<<mainSum<<endl;

    return 0;
}
