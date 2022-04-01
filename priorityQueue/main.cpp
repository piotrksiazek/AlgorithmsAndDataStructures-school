#include <iostream>
#include "pqueue.hpp"

int main(int argc, char const *argv[])
{
    PQueue <std::string> quque;
    quque.enqueue("jeden", 4);
    quque.enqueue("dwa", 6);
    quque.enqueue("trzy", 2);    

    std::cout<<quque<<std::endl;
    
    return 0;
}
