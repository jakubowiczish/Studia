#include <iostream>
/*
Napisz program wczytuj�cy liczb� naturaln� z klawiatury i odpowiadaj�cy na pytanie,
czy liczba ta jest iloczynem dowolnych dw�ch wyraz�w ci�gu Fibonacciego
*/
using namespace std;

int main()
{
    const int max = 1000;

    int tab[max];
    int n, i, j=0, k;
    bool flag=false;
    cin>>n;

    tab[0]=1;
    tab[1]=1;

    for (i=2; tab[i-1]<n ;i++)
        tab[i] = tab[i-1] + tab[i-2];

    while ( j<i )
    {
       k = j+1;
       while (k < i)
       {
            if (tab[j] * tab[k] == n)
            flag = true;
            k++;
       }
       j++;
    }

    cout<<flag<<endl;


    return 0;
}
