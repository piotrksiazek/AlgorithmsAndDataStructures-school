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
            
            if(numberOfElements % 8 != 0)
            {
                this->numberOfBytes++;
            }
            
            cout<<"elements: "<<numberOfElements << " bytes: " <<numberOfBytes<<endl;
        }

        ~BitSet()
        {
            delete[] this->tab;
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

        void Union(const BitSet &other)
        {
           for(int i = 0; i < this->numberOfBytes; i++)
            {
                this->tab[i] |= other.tab[i];
            }
        }

        void intersection(const BitSet &other)
        {
            for(int i = 0; i < this->numberOfBytes; i++)
            {
                this->tab[i] &= other.tab[i];
            }
        }

        void difference(const BitSet &other)
        {
            for(int i = 0; i < this->numberOfBytes; i++)
            {
                this->tab[i] &= ~(this->tab[i] & other.tab[i]);
            }
        }

        bool operator==(BitSet &other)
        {
            if(this->numberOfBytes != other.numberOfBytes)
            {
                return false;
            }
            for(int i = 0; i < this->numberOfBytes; i++)
            {
                if(this->tab[i] != other.tab[i])
                {
                    return false;
                }
            }
            return true;
        }

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
};