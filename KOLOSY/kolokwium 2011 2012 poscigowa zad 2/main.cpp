#include <iostream>
#include <ctime>
#include <cstdlib>
/*
Dana jest tablica typu tab = array [1..100] of integer wype�niona liczbami naturalnymi.
Stoj�c na polu tablicy o indeksie n mo�emy przesun�� si� w prawo o liczb� b�d�c�
czynnikiem pierwszym liczby t[n]. Na przyk�ad:
- warto�� w polu tablicy wynosi 12, mo�emy przeskoczy� o 2 lub 3 pola,
- warto�� w polu tablicy wynosi 14, mo�emy przeskoczy� o 2 lub 7 p�l,
- warto�� w polu tablicy wynosi 17, mo�emy przeskoczy� o 17 p�l.
Prosz� napisa� program, kt�ry tablic� typu tab wype�nia liczbami pseudolosowymi z zakresu
[2..100], nast�pnie odpowiada na pytanie: czy jest mo�liwe przej�cie z pola 1 do 100?
*/
using namespace std;
const int N = 30;
bool isPossible(int tab[N], int i);

int main()
{
    srand(time(NULL));
    int tab[N];
    for(int i=0; i < N; i++){
        tab[i] = rand()% 5000 + 2;
        cout << tab[i] << " ";
    }
    cout << endl << isPossible(tab,0) << endl;
    return 0;
}

bool isPossible(int tab[N], int i)
{
    if(i == N-1)
        return true;
    int a = tab[i];
    for(int p=2; p < a; p++){
        if(a%p == 0){
            while(a%p == 0){
                a /= p;
            }
            if(i+p < N){
                if(isPossible(tab,i+p)) return true;
            }
        }
    }
    return false;
}
