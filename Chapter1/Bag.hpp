
#include <memory>

using std::shared_ptr;
using std::make_shared;

template <typename T>
class BagIterator;

template <typename T>
class Bag
{
    friend class BagIterator<T>;
private:
    /* data */
    class Node
    {
        public:
            T item;
            shared_ptr<Node> next;
    };

    shared_ptr<Node> first = nullptr;
public:
    // add element
    void add(T item) {
        shared_ptr<Node> oldFirst = first;
        first = make_shared<Node>();
        first.item = item;
        first.next = oldFirst;
    }

    BagIterator<T> begin() {
        return  
    }

    ~Bag();
};

template <typename T>
class BagIterator {

public:
    BagIterator() = default;
    BagIterator(const shared_ptr<class shared_ptr<Bag>::Node> &_first) : first(_first){};

    // reload * symbol
    const T& operator*()
    {
        return first->item;
    }
    
    // reload ++ symbol
    BagIterator& operator++()
    {
        first = first->next;
        return *this;
    }
    
    // reload != symbol
    bool operator!=(const BagIterator<T>& rhs) const
    {
        return first != rhs.first;
    }

private:
    shared_ptr<class Bag<T>::Node> first;
};