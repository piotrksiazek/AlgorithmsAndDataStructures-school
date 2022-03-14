#include <iostream>
#include "bitset.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    int result = 15 - 8;
    cout << result << endl;

    BitSet<0,15> *set1 = new BitSet<0,15>();

    set1->insert(1);
    set1->insert(7);
    set1->insert(8);

    set1->insert(1);
    set1->insert(7);
    set1->insert(8);

    set1->insert(10);

    bool contains1 = set1->contains(1);
    bool contains7 = set1->contains(7);
    bool contains10 = set1->contains(10);
    bool contains8 = set1->contains(8);

    cout<<"contains1: "<<contains1<<endl;
    cout<<"contains7: "<<contains7<<endl;
    cout<<"contains10: "<<contains10<<endl;
    cout<<"contains8: "<<contains8<<endl;

    cout<<"size: " << set1->getSize() << endl;
    set1->print();
}
