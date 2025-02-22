#ifndef _CUSTOM_H_
#define _CUSTOM_H_
class Customer{
    private:
        long arrive;
        int processtime;
    public:
        Customer();
        void set(long when);
        long when() const { return arrive; }
        int ptime() const { return processtime; }
};

Customer::Customer():arrive(0), processtime(0){
}

void Customer::set(long when){
    processtime = std::rand() % 3 + 1;
    arrive = when;
}
#endif