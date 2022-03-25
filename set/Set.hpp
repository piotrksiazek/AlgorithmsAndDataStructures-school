#include "LinkedList.hpp"
#include "Node.hpp"
using namespace std;

template<typename T>
class Set
{
    public:
        Set()
        {
            this->list = new LinkedList<T>();
        }

        ~Set()
        {
            delete this->list;
        }
        
        void insert(T value)
        {
            if(!this->contains(value))
                this->list->add(value);
        }

        void remove(T value)
        {
            this->list->removeElement(value);
        }

        bool contains(T value) const
        {
            return this->list->contains(value);
        }

        int size()
        {
            return this->list->getSize();
        }

        void Union(const Set &other)
        {
            Node<T> *currentNode;

            while((currentNode = other.list->nextNode()) != nullptr)
            {
                this->insert(currentNode->value);
            }
        }

        void intersection(const Set &other)
        {
            Node<T> *currentNode;
            LinkedList<T> *toRemove = new LinkedList<T>();
            while((currentNode = this->list->nextNode()) != nullptr)
            {
                T value = currentNode->value;
                if(!other.contains(value))
                {
                    toRemove->add(value);
                }
            }
            while((currentNode = toRemove->nextNode()) != nullptr)
            {
                T value = currentNode->value;
                this->remove(value);
            }
        }

        void difference(const Set &other)
        {
            Node<T> *currentNode;
            while((currentNode = other.list->nextNode()) != nullptr)
            {
                T value = currentNode->value;
                if(this->contains(value))
                {

                    this->remove(value);
                }
            }
                        // toRemove->print();
        }

        bool operator==(Set& l2)
        {
            return *this->list == *l2.list;
        }

        void print()
        {
            this->list->print();
        }
    private:
        LinkedList<T> *list;
};