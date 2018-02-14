#include <iostream>

using namespace std;
/*
Dana jest liczba naturalna N niezawieraj�ca cyfry 0, kt�r� rozbijamy na dwie liczby naturalne
A i B, przenosz�c kolejne cyfry z liczby N do liczby A albo B. Na przyk�ad liczb� 21523
mo�emy rozbi� na wiele sposob�w, np. (215,23),(2,1523),(223,15),(152,23),(22,153),(1,2523)...
Uwaga: wzgl�dna kolejno�� cyfr w liczbie N oraz liczbach A i B musi by� zachowana. Prosz�
napisa� funkcj� generuj�c� i wypisuj�c� wszystkie rozbicia, w kt�rych powsta�e liczby A i B
s� wzgl�dnie pierwsze. Do funkcji nale�y przekaza� warto�� N, funkcja powinna zwr�ci� liczb�
znalezionych par.
Uwagi:
- warunek wzgl�dnej pierwszo�ci mo�na pomin�� kosztem 1 pkt
- do funkcji mo�na przekaza� dodatkowe parametry
- czas na rozwi�zanie obu zada� wynosi 45 minut
- za ka�de zadanie mo�na otrzyma� maksymalnie 5 pkt
- oceniane b�d�: czytelno��, poprawno�� i efektywno�� rozwi�za�
*/
int gcd(int a, int b)
{
    while(b != 0)
    {
        int c = a%b;
        a = b;
        b = c;
    }
    return a;
}

int reversed(int n)
{
    int r = 0;
    while(n > 0)
    {
        r = (10*r) + (n%10);
        n/=10;
    }
    return r;

}

int generate_recursive(int src, int a, int b, int last_added_to_a)
{
    if(src == 0)
    {
        if(a != 0 && b != 0 && gcd(a,b) == 1)
        {
            cout << a << ',' << b <<endl;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int digit = src%10;
    int new_src = src/10;

    int new_a = (10*a) + digit;
    int new_b = (10*b) + digit;

    int result = 0;
    result += generate_recursive(new_src,new_a,b,digit);

    if(digit != last_added_to_a)
    {
        result += generate_recursive(new_src,a,new_b,digit);
    }

    return result;
}

int generate(int n)
{
    n = reversed(n);
    return generate_recursive(n,0,0,-1);
}
int main()
{
    int n;
    cin >> n;
    cout<<generate(n);
    return 0;
}
