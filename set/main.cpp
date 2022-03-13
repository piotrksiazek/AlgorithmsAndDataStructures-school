#include <iostream>
#include "LinkedList.hpp"
#include "Node.hpp"
#include "Set.hpp"

using namespace std;

int main(int argc, char const *argv[])
{

    //1 diff
    Set<int> *set = new Set<int>();
    Set<int> *set2 = new Set<int>();
    Set<int> *expected = new Set<int>();

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

    expected->insert(16);

    set->print();
    cout<<"difference test 1: "<< (*set == *expected) << endl;


    //2 diff
    set = new Set<int>();
    set2 = new Set<int>();
    expected = new Set<int>();

    set->insert(1);
    set->insert(2);

    set2->insert(1);
    set2->insert(2);

    set->difference(*set2);


    set->print();
    cout<<"difference test 2: "<< (*set == *expected) << endl;

    //1 union
    set = new Set<int>();
    set2 = new Set<int>();
    expected = new Set<int>();

    set->insert(1);
    set->insert(2);

    set2->insert(1);
    set2->insert(2);

    set->Union(*set2);

    expected->insert(1);
    expected->insert(2);

    set->print();
    cout<<"union test 1: "<< (*set == *expected) << endl;

    //2 union
    set = new Set<int>();
    set2 = new Set<int>();
    expected = new Set<int>();

    set->insert(1);
    set->insert(2);
    set->insert(2);
    set->insert(2);
    set->insert(2);
    set->insert(3);

    set2->insert(3);

    set->Union(*set2);

    expected->insert(1);
    expected->insert(2);
    expected->insert(3);
    set->print();
    cout<<"union test 2: "<< (*set == *expected) << endl;

    //1 intersection
    set = new Set<int>();
    set2 = new Set<int>();
    expected = new Set<int>();

    set->insert(4);
    set->insert(5);
    set->insert(6);

    set2->insert(4);

    set->intersection(*set2);

    expected->insert(3);

    set->print();
    cout<<"intersection test 1: "<< (*set == *expected) << endl;

    //2 intersection
    set = new Set<int>();
    set2 = new Set<int>();
    expected = new Set<int>();

    set->insert(4);
    set->insert(5);
    set->insert(6);

    set2->insert(1);

    set->intersection(*set2);

    set->print();
    cout<<"intersection test 2: "<< (*set == *expected) << endl;

    //3 intersection
    set = new Set<int>();
    set2 = new Set<int>();
    expected = new Set<int>();

    set->insert(4);
    set->insert(6);

    set2->insert(4);
    set2->insert(5);
    set2->insert(6);
    set2->insert(7);
    set2->insert(8);
    set2->insert(9);

    expected->insert(4);
    expected->insert(6);

    set->intersection(*set2);

    set->print();
    cout<<"intersection test 3: "<< (*set == *expected) << endl;

    
    return 0;
}

void listTest()
{
    LinkedList<int> *list = new LinkedList<int>();
    LinkedList<int> *list2 = new LinkedList<int>();
    
    list->add(1);
    list->add(2);
    list->add(3);

    list2->add(1);
    list2->add(2);
    list2->add(3);

    bool equal = (*list == *list2);
    cout<<"should be 1: " << equal << endl;

    list = new LinkedList<int>();
    list2 = new LinkedList<int>();

    list->add(1);
    list->add(2);
    list->add(3);

    list2->add(3);
    list2->add(2);
    list2->add(1);

    equal = (*list == *list2);
    cout<<"should be 1: " << equal << endl;

    list = new LinkedList<int>();
    list2 = new LinkedList<int>();

    list->add(1);
    list->add(2);
    list->add(4);

    list2->add(3);
    list2->add(2);
    list2->add(1);

    equal = (*list == *list2);
    cout<<"should be 0: " << equal << endl;

    list = new LinkedList<int>();
    list2 = new LinkedList<int>();

    list->add(1);
    list->add(2);
    list->add(4);

    list2->add(4);
    list2->add(1);
    list2->add(2);

    equal = (*list == *list2);
    cout<<"should be 1: " << equal << endl;
}
