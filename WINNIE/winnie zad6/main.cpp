#include <iostream>

/*Dane s� ci�gi a(n), b(n) i c(n) okre�lone nast�puj�co:
a(n) = 1 dla n=1, 2
a(n) = a(n-1)+a(n-2) dla n>2
b(n) = 1 dla n=1, 2, 3
b(n) = b(n-1)+b(n-2)+b(n-3) dla n>3
Wyrazy ci�gu c(n) s� kolejnymi liczbami naturalnymi nale��cymi do ci�gu a(n) lub b(n). Ci�gi
te przyjmuj� warto�ci:
ci�g a(n) 1 1 2 3 5 8 13 21 ...
ci�g b(n) 1 1 1 3 5 9 17 31 ...
ci�g c(n) 1 2 3 5 8 9 13 17 ...
Prosz� napisa� program kt�ry wczytuje wprowadzon� z klawiatury liczb� naturaln� i wypisuje
kolejne wyrazy ci�gu c(n) mniejsze od wprowadzonej liczby.
using namespace std; */

int main()
{
    int aprev = 1, a = 1;
    int bprevprev = 1, bprev = 1, b = 1;
    int N;
    cin>>N;
    int c = -1;
    for(int i=0; i<N; i++)
    {
        c = min(a,b);
        if(a == c)
        {
            int next = a + aprev;
            aprev = a;
            a = next;
        }
        if(b == c)
        {
            int next = b + bprev + bprevprev;
            bprevprev = bprev;
            bprev = b;
            b = next;
        }
        if(c>=N)
            break;
        cout<<c<<endl;


    }
    return 0;
}
