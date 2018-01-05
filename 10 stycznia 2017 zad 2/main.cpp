#include <iostream>
/*
Dane s� dwie listy cykliczne powsta�e przez zap�tlenie listy jednokierunkowej posortowanej
rosn�co, dla ka�dej listy dany jest wska�nik wskazuj�cy przypadkowy element w takiej li�cie.
Prosz� napisa� funkcj�, kt�ra dla dw�ch list cyklicznych, usuwa z obu list elementy
wyst�puj�ce w obu listach. Do funkcji nale�y przekaza� wska�niki na dwie listy, funkcja
powinna zwr�ci� ��czn� liczb� usuni�tych element�w.
Uwagi:
- czas na rozwi�zanie obu zada� wynosi 45 minut
- za ka�de zadanie mo�na otrzyma� maksymalnie 5 pkt
- oceniane b�d�: czytelno��, poprawno�� i efektywno�� rozwi�za�
*/
using namespace std;
struct Node{
    int value;
    Node* next;
};
struct List{
    Node* first;
};
Node* addToList(List& list, int value){
    if(list.first == NULL){
        list.first = new Node;
        list.first->value=value;
        list.first->next=NULL;
        return list.first;
    }
    Node* tmp;
    tmp = list.first;
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    tmp->next = new Node;
    tmp->next->value=value;
    tmp->next->next=NULL;
    return tmp->next;

}
void showCycle(List& list){
    Node* tmp;
    tmp = list.first;
    if(tmp!=NULL){ //warunek dla pustej listy
        while(tmp->next!=list.first){
            cout << "Element: " << tmp->value << endl;
            tmp=tmp->next;
        }
        cout << "Element: " << tmp->value << endl;
    }
}
void showList(List& list){
    Node* tmp;
    tmp = list.first;
    while(tmp!=NULL){
        cout << "Element: " << tmp->value << endl;
        tmp=tmp->next;
    }
}
void endCycle(List& list){
    Node* tmp;
    tmp = list.first;
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    tmp->next=list.first;
}
void removeValueFromCycle(List& list1, int value){
    Node* tmp1 = list1.first;
    while(tmp1->next!=list1.first){ //por�wnywanie adres�w pami�ci, nw czy przejdzie
        if(tmp1->next->value == value){
            Node* nodeToDelete = tmp1->next;
            tmp1->next = tmp1->next->next;
            delete nodeToDelete;
        }
        else {
            tmp1 = tmp1->next;
        }
    }
    //w tym miejscu kolejny node do ten, kt�ry by� "pierwszy" w li�cie
    if(tmp1->next->value == value){
        if(tmp1->next == tmp1->next->next){
            delete tmp1->next;
            list1.first=NULL;
        }
        else {
            Node* nodeToDelete = tmp1->next;
            tmp1->next = tmp1->next->next;
            delete nodeToDelete;
            list1.first = tmp1->next;
        }
    }
}
bool checkIfValueExistsInCycle(List& list, int value){
    Node* tmp;
    tmp = list.first;
    if(tmp!=NULL){ //warunek dla pustej listy
        while(tmp->next!=list.first){
            if(tmp->value == value) return true;
            tmp=tmp->next;
        }
        if(tmp->value == value) return true;
    }
    return false;
}
void removeDuplicatesFromCycles(List& list1, List& list2){
    Node* tmp;
    tmp = list1.first;
    if(tmp!=NULL){ //warunek dla pustej listy
        while(tmp->next!=list1.first){
            if(checkIfValueExistsInCycle(list2,tmp->value)){
                removeValueFromCycle(list2,tmp->value);
                removeValueFromCycle(list1,tmp->value);
                removeDuplicatesFromCycles(list1,list2);
                return;
            }
            tmp=tmp->next;
        }
        if(checkIfValueExistsInCycle(list2,tmp->value)){
            removeValueFromCycle(list2,tmp->value);
            removeValueFromCycle(list1,tmp->value);
            removeDuplicatesFromCycles(list1,list2);
            return;
        }
    }




}
int main(int argc, char** argv) {
    List list1;
    list1.first=NULL;
    addToList(list1,1);
    addToList(list1,1);
    addToList(list1,1);
    Node* node = addToList(list1,2); //pobieram tego noda zeby go da� jako wska�nik do listy (w zadaniu jest �e mamy wska�nik na losowy element a nie pierwszy
    addToList(list1,3);
    endCycle(list1);
    list1.first = node;

    List list2;
    list2.first=NULL;
    addToList(list2,1);
    addToList(list2,4);
    addToList(list2,6);
    endCycle(list2);

    cout << "CYKLE PRZED USUWANIEM" << endl;
    cout << "CYKL 1" << endl;
    showCycle(list1);
    cout << "CYKL 2" << endl;
    showCycle(list2);

    removeDuplicatesFromCycles(list1,list2);
    cout << "CYKLE PO USUNIECIU" << endl;
    cout << "CYKL 1" << endl;
    showCycle(list1);
    cout << "CYKL 2" << endl;
    showCycle(list2);

    return 0;
}
