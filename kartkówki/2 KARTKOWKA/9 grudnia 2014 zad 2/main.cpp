#include <iostream>
/*
. Wyrazy budowane s� z liter a..z. Dwa wyrazy �wa��� tyle samo je�eli: maj� t� sam� liczb�
samog�osek oraz sumy kod�w ascii liter z kt�rych s� zbudowane s� identyczne, na przyk�ad �ula� ->
117 108 97 oraz �exe� 101 120 101. Prosz� napisa� funkcj� bool wyraz( string s1, string s2), kt�ra
sprawdza czy jest mo�liwe zbudowanie wyrazu z podzbioru liter zawartych w s2 wa��cego tyle co
wyraz s1. Dodatkowo funkcja powinna wypisa� znaleziony wyraz.
*/
using namespace std;

bool samogloska(char ch){
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y') return true;
    if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'Y') return true;
    return false;
}

bool wyraz2(int samogloskiW1, int sumaW1, string zbior, string aktualny, int samogloski, int suma){
    if(samogloski == samogloskiW1 && suma == sumaW1){
        cout << aktualny;
        return true;
    }
    if(samogloski > samogloskiW1) return false;
    if(suma > sumaW1) return false;

    for(int i = 0; i < zbior.length(); i++){
        bool isSamogloska = samogloska(zbior[i]);
        if(isSamogloska){
            if(wyraz2(samogloskiW1,sumaW1,zbior,aktualny+zbior[i], samogloski+1, suma+zbior[i])) return true;
        }
        else {
            if(wyraz2(samogloskiW1,sumaW1,zbior,aktualny+zbior[i], samogloski, suma+zbior[i])) return true;
        }
    }
}
int sumaASCII(string w){
    int suma = 0;
    for(int i = 0; i < w.length(); i++){
        suma += w[i];
    }
    return suma;
}

bool wyraz(string s1, string s2){
    int samogloskiW1 = 0;
    for(int i = 0; i < s1.length(); i++){
        if(samogloska(s1[i])) samogloskiW1++;
    }
    int sumaW1 = sumaASCII(s1);

    return wyraz2(samogloskiW1, sumaW1, s2, "", 0,0);
}

int main() {
    int test = (int)'A';
    cout << wyraz("ula", "xe");
    return 0;
}
