#include <iostream>
#include <ctime>
#include <cstdlib>
/*
Dana jest du�a tablica typu tab=array [1..max, 1..max] of integer wype�niona liczbami
naturalnymi. Prosz� napisa� funkcj�, kt�ra sprawdza czy w tablicy istniej� dwa elementy odleg�e o
jeden ruch skoczka szachowego, kt�rych warto�ci s� liczbami wzgl�dnie pierwszymi.
Uwagi:
� Zawarto�� tablicy wej�ciowej nie mo�e ulec zmianie.
� Czas na rozwi�zanie zadania wynosi 25 minut, za zadanie mo�na otrzyma� 5 punkt�w.
� Oceniane b�d�: przejrzysto�� i czytelno�� kodu oraz efektywno�� rozwi�zania.
*/
using namespace std;
const int N = 3;
bool isIndexValid(int w, int k);
void set_table(int tab[N][N]);
bool checkIfRelativelyPrime(int tab[N][N]);

int main()
{
    int tab[N][N];
    set_table(tab);
    cout << checkIfRelativelyPrime(tab);
    return 0;
}

int NWD(int a, int b)
{
    while(b != 0){
        int c = a%b;
        a = b;
        b = c;
    }
    return a;
}

bool isIndexValid(int w, int k)
{
    if(w >= 0 and k >= 0 and w < N and k < N)
        return true;
    return false;
}

bool checkIfRelativelyPrime(int tab[N][N])
{
    int d_x[] = {-2,-1,1,2,2,1,-1,-2};
    int d_y[] = {-1,-2,-2,-1,1,2,2,1};

    for(int w=0; w < N; w++)
    {
        for(int k=0; k < N; k++)
        {
            for(int n_id=0; n_id < 8; n_id++)
            {
                if(isIndexValid(w + d_y[n_id],k + d_x[n_id]))
                {
                    if(NWD(tab[w][k],tab[w + d_y[n_id]][k + d_x[n_id]]) == 1)
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
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
