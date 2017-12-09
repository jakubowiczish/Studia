#include <iostream>
using namespace std;
/*
Zadanie 2.
Tablica t[N] jest wype�niona liczbami naturalnymi. Skok z pola i-tego mo�na
wykona� na pola o indeksach i+k, gdzie k jest czynnikiem pierwszym liczby
t[i] (mniejszym od niej samej). Napisz funkcj�, kt�ra sprawdza, czy da si�
przej�� z pola 0 do N-1 � je�li si� da, zwraca ilo�� skok�w, je�li si� nie da,
zwraca -1
*/
const int N = 8;

int jump(int tab[N], int p, int krok){
	if(p==N-1) return krok;
	if(p>=N) return -1;

	int element = tab[p];

	int k = 2;

	while(element > 1 && k < tab[p]){
		bool found = false;
		while(element%k == 0){
			element /= k;
			found = true;
		}
		if(found){
			//cout << "FOUND DZI " << k << " " << tab[p] << endl;
			int kroki = jump(tab,p+k,krok+1);
			if(kroki != -1) return kroki;

			//k jest czynnikiem pierwszym
		}
		k++;
	}
	return -1;
}

int main()
{
	int tab[N]={6,3,4,4,4,4,1,1};
	cout << jump(tab,0,0) << endl;

	return 0;
}
