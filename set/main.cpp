#include <iostream>
#include "LinkedList.hpp"
#include "Node.hpp"
#include "Set.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    Set<int> *set = new Set<int>();
    Set<int> *set2 = new Set<int>();

    set->insert(1);
    set->insert(2);
    set->insert(3);
    set->insert(16);

    set2->insert(1);
    set2->insert(2);
    set2->insert(3);
    set2->insert(5);
    set2->insert(4);
    set2->insert(6);
    set2->insert(7);

    set->difference(*set2);

    set->print();
    // LinkedList<int> *list = new LinkedList<int>();

    // list->add(1);
    // list->add(2);
    // list->add(3);
    // list->add(4);

    // list->contains(1);
    // list->contains(5);
    // list->contains(3);

    // Node<int> *currentNode;
    // while((currentNode = list->nextNode()) != nullptr)
    // {
    //     cout << currentNode->value << endl;
    // }


    // list->print(); 
    
    return 0;
}
