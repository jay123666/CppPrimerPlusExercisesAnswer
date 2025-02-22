
template <typename T>
struct Item{
    T data;
    Item * next;
    Item(const T&d, Item *n = nullptr) : data(d), next(n){}
};

template<typename T>
class List{
    private:
        Item<T> * head;
        Item<T> * tail;
        int size;
        enum {MAX=10};
    public:
        List();
        ~List();
        void add(const T &data);
        bool isEmpty() const;
        bool isFull() const;
        void visit(void (*pf)(Item<T> &item));
};

#include "List.tpp"