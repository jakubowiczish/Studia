#include <iostream>

/*
Zad. 2 Dana jest tablica typu tab=array[1..n] of integer. Prosz� napisa� funkcj�, kt�ra znajdzie
najmniejszy (w sensie liczebno�ci) podzbi�r element�w tablicy, dla kt�rego suma element�w jest
r�wna sumie indeks�w tych element�w. Do funkcji nale�y przekaza� tablic�, funkcja powinna
zwr�ci� sum� element�w znalezionego podzbioru. Na przyk�ad dla tablicy: [ 7, 3, 5, 11, 2 ]
rozwi�zaniem jest liczba 10.
Uwagi:
� Zawarto�� tablicy wej�ciowej nie mo�e ulec zmianie.
� Czas na rozwi�zanie zadania wynosi 25 minut, za zadanie mo�na otrzyma� 5 punkt�w.
� Oceniane b�d�: przejrzysto�� i czytelno�� kodu oraz efektywno�� rozwi�zania.
*/

using namespace std;
int W[2];
int get(int T[], int tabSize, int start, int sumIndex, int sumValue, int sumCount)
{
    if(sumCount != 0 && sumValue==sumIndex){
        W[0]=sumCount;
        W[1]=sumValue;
        return sumValue;
    }

    int minCount = -1;
    int minSumValue = 0;
    bool isMinimum=false;
    for(int i = start; i < tabSize; i++){
        get(T,tabSize,i+1,sumIndex+(i+1),sumValue+T[i],sumCount+1);
        if(W[0]!=-1){
            if(isMinimum){
                if(W[0] < minCount){
                    minCount=W[0];
                    minSumValue=W[1];
                }
            }
            else {
                minCount=W[0];
                minSumValue=W[1];
                isMinimum=true;
            }
        }
    }
    W[0]=minCount;
    W[1]=minSumValue;
    return minSumValue;
}
int main(int argc, char** argv) {
    int T[]{7,3,5,11,2};
    cout << "MINIMUM " << get(T,5,0,0,0,0) << endl;
    return 0;
}
