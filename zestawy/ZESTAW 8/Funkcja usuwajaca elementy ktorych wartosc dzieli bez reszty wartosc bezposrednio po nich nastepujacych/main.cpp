#include <iostream>
/*
Prosz� napisa� funkcj�, otrzymuj�c� jako parametr wska�nik na pierwszy element listy o warto�ciach typu int,
usuwaj�c� wszystkie elementy, kt�rych warto�� dzieli bez reszty warto�� bezpo�rednio nast�puj�cych po nich element�w.
*/
using namespace std;

struct Node{
    int val;
    Node *next;
};

void print_list(Node *first);
void removeElements(Node *&first);
void add(Node*& first, int value);

int main()
{
    Node *first = nullptr;
    for(int i=0; i < 130; i += 10){
        add(first,i);
    }
    print_list(first);
    removeElements(first);
    print_list(first);
    return 0;
}

void print_list(Node *first)
{
    while(first != nullptr) {
        cout << first->val << " ";
        first = first->next;
    }
    cout << endl;
}

void removeElements(Node *&first)
{
    for(Node *p=first; p -> next != nullptr; p = p -> next){
        if((p -> val)%(p -> next ->  val) == 0){
            Node *tmp = p -> next;
            p -> next = tmp -> next;
            delete tmp;
        }
    }
}

void add(Node*& first, int value)
{
    if (first == nullptr) {
        first = new Node;
        first->val = value;
        first->next = nullptr;
    } else {
        Node* new_first = new Node;
        new_first->val = value;
        new_first->next = first;
        first = new_first;
    }
}
