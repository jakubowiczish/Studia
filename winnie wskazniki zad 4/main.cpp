#include <iostream>
/*
Dane s� definicje opisuj�ce list� jednokierunkow�:
type
pwezel = ^wezel;
wezel = record
nr: integer;
next: pwezel
end;
Pojedyncza, niepusta lista zako�czona jest cyklem. Prosz� napisa� funkcj�, kt�ra zwraca dla
danej listy ilo�� element�w w cyklu. Do funkcji nale�y przekaza� wska�nik na pocz�tek listy.
Mo�na za�o�y�, �e ilo�� element�w w li�cie nie przekracza 100 [Mo�na rozwa�y� tak�e
przypadek, kiedy nie znamy a priori ograniczenia ilo�ci element�w w li�cie].
*/
struct Node{
    int val;
    Node *next;
};
using namespace std;
int CycleLength(Node *&first);
Node *add_at_beginning_v2(Node *first, Node *new_node);
Node *create_node(int value);
void print_list(Node *first);

int main()
{
    Node *first = new Node;
    first -> val = 5;
    first -> next = nullptr;
    for(int i=0; i<20; i++){
        first = add_at_beginning_v2(first,create_node(i));
    }
    print_list(first);
    cout << CycleLength(first);
    return 0;
}

int CycleLength(Node *&first)
{
    Node *p = first;
    //Node *q = first;
    int counter = 0;
    while(p -> next != nullptr)
    {
        p = p -> next;
        counter++;
    }
    return counter;
}

Node *create_node(int value) {
    Node *new_node = new Node;
    new_node->val = value;
    new_node->next = nullptr;
    return new_node;
}

void print_list(Node *first) {
    while(first != nullptr) {
        cout << first->val << " ";
        first = first->next;
    }
    cout << endl;
}

Node *add_at_beginning_v2(Node *first, Node *new_node) {
    if(first == nullptr) return new_node;

    new_node->next = first;
    return new_node;
}
