class Golf{
    private:
        static const int Len = 40;
        char fullname[Len];
        int handicap;
    public:
        Golf(const char * name, int hc);
        ~Golf();
        Golf setgolf();
        void sethandicap(int hc);
        void showgolf() const;
};