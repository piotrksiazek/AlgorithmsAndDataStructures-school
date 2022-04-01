#include <vector>
#include <algorithm>

template<typename T>
class PQueue
{
    public:
        void enqueue(T value, int priority)
        {
            Element element(value, priority);
            data.push_back(element);
            size++;
            int currentIndex = size - 1;
            while(currentIndex != 0)
            {
                int parentIndex = getParentIndex(currentIndex);
                int parentPriority = data[parentIndex].priority;
                int childPriority = data[currentIndex].priority;
                if(childPriority > parentPriority)
                {
                    std::iter_swap(data.begin() + currentIndex, data.begin()+parentIndex);
                }
                else
                {
                    break;
                }
                currentIndex = parentIndex;
            }
            
        }

        T front()
        {
            return data[0].value;
        }

        T dequeue()
        {

        }
    // private:
        
        struct Element
        {
            T value;
            int priority;

            Element(T value, int priority)
            {
                this->value = value;
                this->priority = priority;
            }
        };
        std::vector<Element> data;

        int size=0;
        
        int getParentIndex(int index)
        {
            return ((index+1) / 2) - 1;
        }

        int getLeftChildIndex(int index) //popraw
        {
            return (index+1) * 2 - 1;
        }

        int getRightChildIndex(int index) //popraw
        {
            return (index+1) * 2 - 1;
        }
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const PQueue<T>& dt)
{
    int index = 0;
    for(const auto& element: dt.data) 
    {
        os<< "i: " << index++  <<" v: " << element.value << " p: " << element.priority << std::endl;
    }
    
    return os;
}