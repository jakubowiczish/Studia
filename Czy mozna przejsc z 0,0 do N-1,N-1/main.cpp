#include <iostream>
#include <ctime>
#include <cstdlib>
/*
Dana jest tablica int t[N][N] wype�niona liczbami naturalnymi. Z danego pola mo�emy
wykonywa� ruch w prawo lub w d�, pod warunkiem, �e przechodzimy na pole o wi�kszej
warto�ci.
(a) Napisa� funkcj�, kt�ra sprawdzi czy mo�na przej�� z pola [0,0] na pole [N-1,N-1]
(b) wypisa� drog� przej�cia
*/
using namespace std;
const int N = 6;

bool droga(int tab[N][N], int w, int k);
void set_table(int tab[N][N]);
void print_table(int tab[N][N]);

int main()
{
    int tab[N][N]=
    {
        {1,1,1,1,1,1 },
        {2,3,4,5,6,1 },
        {1,1,1,1,7,1 },
        {1,1,6,7,8,1 },
        {1,1,1,8,9,1 },
        {1,1,1,1,10,11}
    };
    print_table(tab);
    cout << droga(tab,0,0);
    return 0;
}

bool droga(int tab[N][N], int w, int k)
{
    if(w == N-1 && k == N-1)
        return true;
    if(w < N-1 && tab[w+1][k] > tab[w][k])
        if(droga(tab,w+1,k)) return true;
    if(k < N-1 && tab[w][k+1] > tab[w][k])
        if(droga(tab,w,k+1)) return true;

    return false;
}

void print_table(int tab[N][N])
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout<<tab[i][j]<<"\t";
        }
        cout<<endl<<endl;
    }
}
void set_table(int tab[N][N])
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            tab[i][j] = i + j;
            cout<<tab[i][j]<<"\t";
        }
        cout<<endl<<endl;
    }
}
