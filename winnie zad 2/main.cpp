#include <iostream>
/*
Prosz� napisa� program kt�ry wczytuje wprowadzon� z klawiatury liczb� naturaln� i
odpowiada na pytanie, czy liczba ta jest wielokrotno�ci� kwadratu dowolnej liczby naturalnej
wi�kszej od 1 i nie jest r�wnocze�nie wielokrotno�ci� sze�cianu dowolnej liczby naturalnej
wi�kszej od 1.
*/
using namespace std;

int main()
{
    int number;
    cin>>number;
    bool kwadrat = false,szescian = false,out1 = false,out2 = false;
    int i = 2;
    while(out1 == false && kwadrat == false) // dla czytelnosci dla mnie
    {
        if(i*i > number)
            out1 = true;
        if(number%(i*i) == 0)
            kwadrat = true;
        else i++;
    }
    i = 2;
    while(out2 == false && szescian == false) // dla czytelnosci dla mnie
    {
        if(i*i*i> number)
            out2 = true;
        if(number%(i*i*i) == 0)
            szescian = true;
        else i++;
    }

    if(kwadrat == true && szescian == false)
        cout<<"tak"<<endl;
    else cout<<"nie"<<endl;
    return 0;
}
