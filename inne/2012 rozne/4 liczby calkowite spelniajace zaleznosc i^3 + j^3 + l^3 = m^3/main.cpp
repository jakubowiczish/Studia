#include <iostream>
/*
Prosz� napisa� program, kt�ry odnajdzie wszystkie liczby ca�kowite mniejsze od 20 spe�niaj�ce
zale�no�� i^3+j^3+k^3=l^3
*/
using namespace std;

int main()
{
    const int N = 100;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            for(int k=0; k<N; k++)
            {
                for(int m=0; m<N; m++)
                {
                    if(i*i*i + j*j*j + k*k*k == m*m*m)
                        cout<<i<<" "<<j<<" "<<k<<" "<<m<<endl;
                }
            }
        }
    }

    return 0;
}
