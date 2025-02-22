#ifndef QUEUETP_H_
#define QUEUETP_H_

template <class C>
class QueueTp{
    struct Node{
        C * item;
        Node * next;
    };
    private:
        int MAX;
        int size;
        Node * front;
        Node * rear;
    public:
        QueueTp():MAX(20), size(0){ };
        QueueTp(int max):MAX(max), size(0){ };
        bool inQueue(C & c);
        bool deQueue(C * & c);
        int queueDepth() const { return size; }
        bool isfull() const { return size==MAX; }
        bool isempty() const { return size==0; }
        void delQueue();
        ~QueueTp(){ delQueue(); }
};

template <class C>
bool QueueTp<C>::inQueue(C & c){
    if (isfull()) return false;

    Node * newnode = new Node;
    newnode->item = &c;
    newnode->next = nullptr;

    if (isempty()){
        front = newnode;
    } else {
        rear->next = newnode;
    }
    rear = newnode;
    size++;
    return true;
}

template <class C>
bool QueueTp<C>::deQueue(C * & c){
    if (isempty()) return false;

    Node * temp = front;
    front = front->next;
    c = temp->item;
    
    if (queueDepth()==1) rear = rear->next;
    delete temp;
    size--;
    return true;
}

template <class C>
void QueueTp<C>::delQueue(){
    while(!isempty()){
        Node * temp = front;
        front = front->next;
        delete temp;
        size--;
    }
    rear = nullptr;
    return;
}



#endif