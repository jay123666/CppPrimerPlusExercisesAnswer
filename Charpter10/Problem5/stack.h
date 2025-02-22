#include <string>

struct customer{
    std::string fullname;
    double payment;
};

typedef customer Item;

class Stack{
    private:
        enum {MAX=10};
        Item items[MAX];
        int top;
    public:
        Stack(){
            this->top = 0;
        };
        bool push(Item & item);
        Item pop();
        Item * peek();
        bool isEmpty();
        bool isFull();
        void show() const;
};