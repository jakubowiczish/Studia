#include <iostream>
using namespace std;
/*
2. Dane s� dwie liczby naturalne z kt�rych budujemy trzeci� liczb�. W budowanej liczbie musz�
wyst�pi� wszystkie cyfry wyst�puj�ce w liczbach wej�ciowych. Wzajemna kolejno�� cyfr ka�dej z liczb
wej�ciowych musi by� zachowana. Na przyk�ad maj�c liczby 123 i 75 mo�emy zbudowa� liczby 12375,
17523, 75123, 17253, itd. Prosz� napisa� funkcj� kt�ra wyznaczy ile liczb pierwszych mo�na
zbudowa� z dw�ch zadanych liczb.
*/
void wygeneruj(int a, int b, int c, int n, int &ilosc);
int zadanie(int a, int b);
bool isPrime(int n);

int main()
{
    int a,b;
    cin >> a >> b;
    cout << zadanie(a,b);
    return 0;
}

// a - liczba nr 1
// b - liczba nr 2
// c = generowana liczba
// n = czynnik, mnozymy go razy 10 zeby dodawac cyfry do generowanej liczby
// ilosc = ilosc liczb
void wygeneruj(int a, int b, int c, int n, int &ilosc)
{
    if(a == 0 && b == 0){
        cout << c << endl;
        if(isPrime(c)){
            ilosc++;
        }
        return;
    }

    if(a > 0) wygeneruj(a/10,b,c + n*(a%10),n*10,ilosc);
    if(b > 0 && b%10 != a%10) wygeneruj(a,b/10,c + n*(b%10),n*10,ilosc);
}

int zadanie(int a, int b)
{
    int ilosc = 0;
    cout << "Wygenerowane liczby: " << endl;
    wygeneruj(a,b,0,1,ilosc);
    return ilosc;
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
