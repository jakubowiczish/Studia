#include <iostream>
#include <ctime>
#include <cstdlib>
/*
Dwie liczby naturalne s� �kole�ankami� je�eli maj� przynajmniej dwie r�ne wsp�lne cyfry,
np. 123 i 1345 lub 225 i 1235. Dana jest tablica t[N][N] wype�niona liczbami naturalnymi.
Prosz� napisa� funkcj�, kt�ra w tablicy t zeruje wszystkie liczby nie maj�ce �adnej kole�anki.
Do funkcji nale�y przekaza� tablic� t. Funkcja powinna zwr�ci� ilo�� liczb naturalnych jaka
pozostanie w tablicy.
Uwagi:
- czas na rozwi�zanie obu zada� wynosi 45 minut
- za ka�de zadanie mo�na otrzyma� maksymalnie 5 pkt
- oceniane b�d�: czytelno��, poprawno�� i efektywno�� rozwi�za�
*/
using namespace std;
const int N = 5;
bool areFriends(int a, int b);
void setTable(int tab[N][N]);
void zeroTable(bool tab[N][N]);
void printTable(int tab[N][N]);
void zeroThoseWithoutFriends(int tab[N][N]);

int main()
{
    int tab[N][N];
    cout << "Zainicjalizowana tablica: " << endl << endl;
    setTable(tab);
    zeroThoseWithoutFriends(tab);
    cout << "Tablica po zmianach: " << endl << endl;
    printTable(tab);
    return 0;
}

void zeroThoseWithoutFriends(int tab[N][N])
{
    bool shouldBeZero[N][N];
    zeroTable(shouldBeZero);
    bool found = false;
    for(int i=0; i < N; i++)
    {
        for(int j=0; j < N; j++)
        {
            found = false;
            for(int k=0; k < N; k++)
            {
                for(int m=0; m < N; m++)
                {
                    if((i != k || j != m) and areFriends(tab[i][j],tab[k][m]))
                    {
                        found = true;
                        shouldBeZero[k][m] = false;
                    }
                }
            }
            if(found){
                shouldBeZero[i][j] = false;
            }
        }
    }

    for(int i=0; i < N; i++)
    {
        for(int j=0; j < N; j++)
        {
            if(shouldBeZero[i][j])
            tab[i][j] = 0;
        }
    }
}

bool areFriends(int a, int b)
{
    int tab1[10], tab2[10];
    for(int i=0; i < 10; i++){
        tab1[i] = 0;
        tab2[i] = 0;
    }
    int x = a;
    int y = b;
    while(x > 0){
        tab1[x%10]++;
        x /= 10;
    }
    while(y > 0){
        tab2[y%10]++;
        y /= 10;
    }
    int counter = 0;
    for(int i=0; i < 10; i++){
        if(tab1[i] != 0 and tab2[i] != 0){
            counter++;
        }
        if(counter >= 2){
            return true;
        }
    }

    return false;
}

void zeroTable(bool tab[N][N])
{
    for(int i=0; i < N; i++){
        for(int j=0; j < N; j++){
            tab[i][j] = true;
        }
    }
}

void setTable(int tab[N][N])
{
    srand(time(NULL));
    for(int i=0; i < N; i++)
    {
        for(int j=0; j < N; j++)
        {
            tab[i][j] = rand() % 50 + 1;
            cout<<tab[i][j]<<"\t";
        }
        cout<<endl<<endl;
    }
}

void printTable(int tab[N][N])
{
    for(int i=0; i < N; i++)
    {
        for(int j=0; j < N; j++)
        {
            cout<<tab[i][j]<<"\t";
        }
        cout<<endl<<endl;
    }
}
