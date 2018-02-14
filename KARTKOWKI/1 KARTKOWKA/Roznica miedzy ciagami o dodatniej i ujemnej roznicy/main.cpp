#include <iostream>
using namespace std;

// skr�towo, to idea programu jest taka - najpierw szukamy najd�u�szego ci�gu rosn�cego, a potem malej�cego, a dzi�ki odpowiednio napisanym warunkom robimy to w jednym przej�ciu p�tli. Dok�adny opis zawarty jest w komentarzach w p�tli
int main() {
    int N = 10; // oczywi�cie tu mo�e by� cokolwiek
    int tab[N];
    for(int i=0; i<N; i++) cin >> tab[i];

    int increasing_max_length = 1, decreasing_max_length = 1;
    int current_length = 1; // d�ugo�� aktualnie rozpatrywanego ci�gu, b�dziemy jej u�ywa� w p�tli
    int current_difference; // r�nica aktualnie rozpatrywanego ci�gu arytmetycznego
    // oczywi�cie obie p�tle mo�na zrealizowa� w jednej (trzeba tylko u�y� paru dodatkowych zmiennych), ale dla czytelno�ci kodu zapisa�em to w osobnych
    // znajd�my najd�u�szy ci�g rosn�cy
    current_difference = -1; // jakakolwiek warto�� ujemna, odr�niamy w ten spos�b ci�g ujemny
    for(int i=1; i<N; i++) {
        if(tab[i] > tab[i-1] and current_length == 1) { // rozpoczynamy analizowanie nowego podci�gu, bo poprzedni si� zako�czy� z powodu wyst�pienia ciagu malej�cego / dopiero rozpocz�li�my program
            current_difference = tab[i] - tab[i-1];
            current_length = 2; // ustawiamy na 2, bo mamy dwa elementy tworz�ce nowy ci�g
        }
        else if(tab[i] - tab[i-1] == current_difference and current_difference > 0){ // je�li podci�g dalej ro�nie o r�nic� arytmetyczn� oraz r�nica ta jest dodatnia
            current_length++;
        }
        else if(tab[i] - tab[i-1] != current_difference and tab[i] > tab[i-1]) { // je�eli kolejny element ma inn� r�nic�, ale jest wi�kszy od poprzedniego, to rozpoczynamy nowy ci�g rosn�cy
            current_length = 2; // ustawiamy na 2, bo mamy dwa elementy tworz�ce nowy podci�g
            current_difference = tab[i] - tab[i-1];
        }
        else { // w przeciwnym wypadku mamy ci�g malej�cy. Jako nast�pnego wywo�amy pierwszego if'a (albo zn�w tego elsa, je�eli nast�pny element dalej b�dzie mniejszy)
            current_length = 1; // ustawiamy na 1, bo dopiero szukamy podci�gu
            current_difference = -1;
        }

        if(current_length > increasing_max_length) increasing_max_length = current_length; // je�eli aktualna d�ugo�� jest wi�ksza od dotychczasowej maksymalnej, to update'ujemy maksymaln�
        // poni�ej cout wypisuje nam krok po kroku co si� dzieje ze zmiennymi w tej p�tli, mo�esz go sobie odkomentowa� aby to prze�ledzi�. Zwr�� uwag� na to, �e wypisuje on aktualne warto�ci po zako�czeniu danego obiegu p�tli
        // cout << tab[i] << " current_length: " << current_length << ", current_difference: " << current_difference << ", increasing_max_length: " << increasing_max_length << endl;
    }

    // znajd�my najd�u�szy ci�g rosn�cy
    current_difference = 1; // jakakolwiek warto�� dodatnia
    current_length = 1;
    for(int i=1; i<N; i++) {
        if(tab[i] < tab[i-1] and current_length == 1) { // rozpoczynamy analizowanie nowego podci�gu, bo poprzedni si� zako�czy� z powodu wyst�pienia ciagu malej�cego / dopiero rozpocz�li�my program
            current_difference = tab[i] - tab[i-1];
            current_length = 2; // ustawiamy na 2, bo mamy dwa elementy tworz�ce nowy ci�g
        }
        else if(tab[i] - tab[i-1] == current_difference and current_difference < 0){ // je�li podci�g dalej maleje o r�nic� arytmetyczn� (m�wi�c �ci�lej - malej� o jej warto�� bezwgl�dn� jej r�nicy) oraz r�nica ta jest ujemna
            current_length++;
        }
        else if(tab[i] - tab[i-1] != current_difference and tab[i] < tab[i-1]) { // je�eli kolejny element ma inn� r�nic�, ale jest mniejszy od poprzedniego, to rozpoczynamy nowy ci�g malej�cy
            current_length = 2; // ustawiamy na 2, bo mamy dwa elementy tworz�ce nowy podci�g
            current_difference = tab[i] - tab[i-1];
        }
        else { // w przeciwnym wypadku mamy ci�g malej�cy. Jako nast�pnego wywo�amy pierwszego if'a (albo zn�w tego elsa, je�eli nast�pny element dalej b�dzie mniejszy)
            current_length = 1; // ustawiamy na 1, bo dopiero szukamy podci�gu
            current_difference = 1;
        }

        if(current_length > decreasing_max_length) decreasing_max_length = current_length; // je�eli aktualna d�ugo�� jest wi�ksza od dotychczasowej maksymalnej, to update'ujemy maksymaln�
        // poni�ej cout wypisuje nam krok po kroku co si� dzieje ze zmiennymi w tej p�tli, mo�esz go sobie odkomentowa� aby to prze�ledzi�. Zwr�� uwag� na to, �e wypisuje on aktualne warto�ci po zako�czeniu danego obiegu p�tli
        // cout << tab[i] << " current_length: " << current_length << ", current_difference: " << current_difference << ", increasing_max_length: " << decreasing_max_length << endl;
    }

    cout << "increasing_max_length = " << increasing_max_length << ", decreasing_max_length = " << decreasing_max_length << endl;
    cout << increasing_max_length - decreasing_max_length << endl;

    return 0;
}
