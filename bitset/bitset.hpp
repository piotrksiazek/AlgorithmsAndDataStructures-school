#include "../set/LinkedList.hpp"
#include "../set/Node.hpp"
#include <bitset>
using namespace std;

template<int min, int max>
class BitSet
{
    public:
        BitSet()
        {
            this->size = 0;
            int numberOfElements = max - min + 1;
            this->numberOfBytes = numberOfElements / 8;
            this->tab = new unsigned char[this->numberOfBytes];
        }

        ~BitSet()
        {
            delete[] this->tab;
        }

        int getTabIndex(int value) const
        {
            return value / 8;
        }

        int getBitShift(int value, int tabIndex) const
        {
            return (value - tabIndex * 8);
        }

        void changeSizeCount(unsigned char oldByte, unsigned char newByte)
        {
            if(oldByte != newByte)
            {
                this->size++;
            }
        }
        
        void insert(int value)
        {
            int tabIndex = this->getTabIndex(value);
            unsigned char oldByte = this->tab[tabIndex];

            tab[tabIndex] |= (1 << getBitShift(value, tabIndex));

            changeSizeCount(oldByte, this->tab[tabIndex]);
        }

        void remove(int value)
        {
            int tabIndex = this->getTabIndex(value);
            unsigned char oldByte = this->tab[tabIndex];

            tab[tabIndex] &= ~(1 << getBitShift(value, tabIndex));

            changeSizeCount(oldByte, this->tab[tabIndex]);
        }

        bool contains(int value) const
        {
            int tabIndex = this->getTabIndex(value);
            unsigned char byte = tab[tabIndex];
            return (byte & (1 << this->getBitShift(value, tabIndex))) > 0;
        }

        int getSize()
        {
            return this->size;
        }

        // void Union(const set &other)
        // {
           
        // }

        // void intersection(const set &other)
        // {
            
        // }

        // void difference(const set &other)
        // {
            
        // }

        // bool operator==(set& l2)
        // {
            
        // }

        void print()
        {
            for(int i = 0; i < this->numberOfBytes; i++)
            {
                cout << bitset<8>(this->tab[i]) << " ";
            }
            cout<<endl;
        }
    private:
        unsigned char *tab;
        int numberOfBytes;
        int size;
};