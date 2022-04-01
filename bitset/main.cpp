#include <iostream>
#include "bitset.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    BitSet<0,7> *set1 = new BitSet<0,7>();
    BitSet<0,8> *set2 = new BitSet<0,8>();

    BitSet<0,22> *set3 = new BitSet<0,22>();
    BitSet<0,31> *set4 = new BitSet<0,31>();

    set1->print();
    set2->print();
    set3->print();
    set4->print();
}
