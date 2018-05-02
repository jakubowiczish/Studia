#include <iostream>
/*
Napisz program wczytuj�cy liczb� naturaln� z klawiatury i odpowiadaj�cy na pytanie,
czy liczba ta jest wielokrotno�ci� dowolnego wyrazu ci�gu danego wzorem A(n)=3*A(n-1)+1,
 a pierwszy wyraz jest r�wny 2
*/

using namespace std;

int main()
{
    int k;
    cin >> k;
    int n = 2;

    bool out = false;
    bool result = false;

    while(!result && !out)
    {
        if(3*n + 1 > k)
            out = true;
        if(k%(3*n+1) == 0)
            result = true;
        else
            n = 3*n + 1;
    }
    if(result)
        cout<<"Tak, ta liczba jest wielokrotnoscia jakiegos wyrazu ciagu A(n) = 3A(n-1)+1"<<endl;
    else
        cout<<"Nie, ta liczba NIE jest wielokrotnoscia jakiegos wyrazu ciagu A(n) = 3A(n-1)+1"<<endl;
    return 0;
}
