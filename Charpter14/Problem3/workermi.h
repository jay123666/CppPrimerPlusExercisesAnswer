#ifndef WORKER_H_
#define WORKER_H_
#include <string>

class Worker{
    private:
        std::string fullname;
    protected:
        virtual void Get();
        virtual void Data() const;
    public:
        Worker():fullname("Nobody"){ }
        Worker(const std::string & name):fullname(name){ }
        virtual ~Worker() = 0;
        virtual void Set() = 0;
        virtual void Show() const = 0;
};

class Waiter: virtual public Worker{
    private:
        int panache;
    protected:
        void Get();
        void Data() const;
    public:
        Waiter():Worker(),panache(0) { }
        Waiter(const std::string & name, int p):Worker(name),panache(p){ }
        Waiter(Worker & wk, int p):Worker(wk),panache(p) { }
        void Set();
        void Show() const;
};

class Fucker: virtual public Worker{
    private:
        int fuck_lvl;
    protected:
        void Get();
        void Data() const;
    public:
        Fucker():Worker(),fuck_lvl(0){ }
        Fucker(const std::string & name, int f):Worker(name),fuck_lvl(f){ }
        Fucker(Worker & wk, int f):Worker(wk),fuck_lvl(f){ }
        void Set();
        void Show() const;
};

class WaiterFucker: public Waiter, public Fucker{
    private:
        int exp;
    protected:
        void Get();
        void Data() const;
    public:
        WaiterFucker():Waiter(),Fucker(){ }
        WaiterFucker(const std::string & name, int p, int fuck_lvl, int exp):Worker(name),Fucker(name, fuck_lvl),Waiter(name, exp){ }
        WaiterFucker(Worker & wk, int p, int f):Worker(wk),Waiter(wk, p),Fucker(wk, f){ }
        void Set();
        void Show() const;
};

#endif