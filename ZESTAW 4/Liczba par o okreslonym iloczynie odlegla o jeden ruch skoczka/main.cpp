#include <iostream>
#include <ctime>
#include <cstdlib>
/*
Dana jest tablica wype�niona liczbami naturalnymi int t[MAX][MAX];
Prosz� napisad funkcj�, kt�ra zwraca liczb� par element�w, o okre�lonym iloczynie,
takich �e elementy s� odleg�e o jeden ruch skoczka szachowego.
*/
using namespace std;
const int N = 5;
void set_table(int tab[N][N]);
int howManyPairs(int tab[N][N], int result);
int main()
{
    int tab[N][N];
    set_table(tab);
    int k;
    cin >> k;
    cout << howManyPairs(tab,k) << endl;
    return 0;
}

bool isIndexValid(int w, int k)
{
    if(w >=0 and k >=0 and w < N and k < N)
        return true;
    return false;
}
int howManyPairs(int tab[N][N], int result)
{
    int d_x[] = {-2,-1,1,2,2,1,-1,-2};
    int d_y[] = {-1,-2,-2,-1,1,2,2,1};
    int counter = 0;
    for(int w=0; w < N; w++)
    {
        for(int k=0; k < N; k++)
        {
            for(int n_id=0; n_id < 8; n_id++)
            {
                if(isIndexValid(w + d_y[n_id],k + d_x[n_id]))
                {
                    int a = tab[w][k];
                    int b = tab[w + d_y[n_id]][k + d_x[n_id]];
                    if(a * b == result)
                        counter++;
                }
            }
        }
    }
    return counter / 2;
}

void set_table(int tab[N][N])
{
    srand(time(NULL));
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            tab[i][j] = rand() % 50 + 1;
            cout<<tab[i][j]<<"\t";
        }
        cout<<endl<<endl;
    }
}
