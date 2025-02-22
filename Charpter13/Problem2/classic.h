#ifndef CLASSIC_H_
#define CLASSIC_H_

class Cd{
    private:
        char * performers;
        char * label;
        int selections;
        double playtime;
    public:
        Cd(const char * s1, const char * s2, int n, double x);
        Cd(const Cd & cd);
        Cd();
        
        virtual Cd & operator=(const Cd & cd);
        virtual ~Cd();
        virtual void Report() const;
};

class Classic: public Cd{
    private:
        char * musics;
    public:
        Classic(const char * s1, const char * s2, const char * s3, int n, double x);
        Classic(const Classic & cls);
        Classic();
        ~Classic();

        Classic & operator=(const Classic & cls);
        void Report() const;
};


#endif
