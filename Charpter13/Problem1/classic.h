#ifndef CLASSIC_H_
#define CLASSIC_H_

class Cd{
    private:
        char performers[50];
        char label[20];
        int selections;
        double playtime;
    public:
        Cd(const char * s1, const char * s2, int n, double x);
        Cd();
        virtual ~Cd();
        virtual void Report() const;
};

class Classic: public Cd{
    private:
        char musics[20];
    public:
        Classic(const char * s1, const char * s2, const char * s3, int n, double x);
        Classic();
        ~Classic();
        void Report() const;
};


#endif
