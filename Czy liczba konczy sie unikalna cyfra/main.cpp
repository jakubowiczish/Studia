#include <iostream>
/*
Napisz program wczytuj�cy liczb� naturaln� z klawiatury
i odpowiadaj�cy na pytanie, czy liczba zako�czona jest unikaln� cyfr�
*/
using namespace std;
const int DIGITS = 10;

bool is_last_digit_unique(int n)
{
    int tab[DIGITS];

    for(int i=0; i<DIGITS; i++)
    {
        tab[i] = 0;
    }

    int next = n;
    while(next > 0)
    {
        int ost = next%10;
        tab[ost]++;
        next /= 10;
    }

    if(tab[n%10] == 1){
        return true;
    }

    return false;
}
int main()
{
    cout<<is_last_digit_unique(1234);
    return 0;
}
