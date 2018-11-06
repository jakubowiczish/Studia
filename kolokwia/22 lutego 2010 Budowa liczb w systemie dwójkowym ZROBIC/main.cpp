#include <iostream>
using namespace std;
/*
Zad. 2 Do budowy liczby naturalnej reprezentowanej w systemie dw�jkowym mo�emy u�y� A cyfr
1 oraz B cyfr 0, gdzie A,B>0. Prosz� napisa� funkcj�, kt�ra dla zadanych parametr�w A i B zwraca
ilo�� wszystkich mo�liwych do zbudowania liczb, takich �e pierwsza cyfra w systemie dw�jkowym
(najstarszy bit) jest r�wna 1, a zbudowana liczba jest z�o�ona.
Na przyk�ad dla A=2, B=3 ilo�� liczb wynosi 3, s� to 10010(2) 10100(2) 11000(2)
Uwagi:
� Czas na rozwi�zanie zadania wynosi 25 minut, za zadanie mo�na otrzyma� 5 punkt�w.
� Oceniane b�d�: przejrzysto�� i czytelno�� kodu oraz efektywno�� rozwi�zania.
*/
void buduj(int a, int b, int &ilosc);
int zadanie(int a, int b);

int main()
{
    int a,b;
    cin >> a >> b;
    cout << zadanie(a,b);
    return 0;
}

void buduj(int a, int b, int &ilosc)
{
    if(a == 0 && b == 0){
        ilosc++;
        return;
    }

    if(a > 0) buduj(a-1,b,ilosc);
    if(b > 0) buduj(a,b-1,ilosc);
}

int zadanie(int a, int b)
{
    int ilosc = 0;
    buduj(a-1,b,ilosc); // a-1 bo zaczynamy kazda liczbe od jedynki
    return ilosc;
}

