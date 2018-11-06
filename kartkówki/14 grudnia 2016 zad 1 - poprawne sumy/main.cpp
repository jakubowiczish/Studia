#include <iostream>
using namespace std;
/*
1. Dane s� dwie tablice t1[N] i t2[N] zawieraj�ce liczby naturalne. Z warto�ci w obu tablicach
mo�emy tworzy� sumy. �Poprawna� suma to taka, kt�ra zawiera co najmniej jeden element
(z tablicy t1 lub t2) o ka�dym indeksie. Na przyk�ad dla tablic: t1 = [1,3,2,4] i t2 = [9,7,4,8]
poprawnymi sumami s� na przyk�ad 1+3+2+4, 9+7+4+8, 1+7+3+8, 1+9+7+2+4+8.
Prosz� napisa� funkcj� generuj�c� i wypisuj�c� wszystkie poprawne sumy, kt�re s� liczbami
pierwszymi. Do funkcji nale�y przekaza� dwie tablice, funkcja powinna zwr�ci� liczb�
znalezionych i wypisanych sum.
Uwagi:
- warunek pierwszo�ci mo�na pomin�� kosztem 1 pkt
- do funkcji mo�na przekaza� dodatkowe parametry
- czas na rozwi�zanie obu zada� wynosi 45 minut
- za ka�de zadanie mo�na otrzyma� maksymalnie 5 pkt
- oceniane b�d�: czytelno��, poprawno�� i efektywno�� rozwi�za�
*/const int N = 4;
int valid_sum(int tab1[],int tab2[],int i, int sum);
bool isPrime(int n);

int main()
{
    int tab1[N] = {1,2,3,4};
    int tab2[N] = {9,7,4,8};
    cout << "Ilosc" << valid_sum(tab1,tab2,0,0) << endl;
    return 0;
}

// tab1, tab2 - tablice
// sum - generowana suma
// i - indeks
// ilosc - ilosc wygenerowanych poprawnych sum
int valid_sum(int tab1[],int tab2[],int i, int sum)
{
    if(i == N)
    {
        if(isPrime(sum))
        {
            cout << sum << endl;
            return 1;
        }
        return 0;
    }
    else
    {
        return valid_sum(tab1,tab2,i+1,sum + tab1[i]) +
                   valid_sum(tab1,tab2,i+1,sum + tab2[i]) +
                   valid_sum(tab1,tab2,i+1,sum + tab1[i] + tab2[i]);
    }
}

bool isPrime(int n)
{
    if(n < 2)
        return false;
    for(int i=2; i*i <= n; i++)
    {
        if(n%i == 0)
            return false;
    }
    return true;
}
