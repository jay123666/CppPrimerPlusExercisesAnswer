class Plorg{
    private:
        enum {MAX=20};
        char fullname[MAX];
        int CI;
    public:
        Plorg(const char * fullname="Plorga", int CI=50);
        void moidfyCI(int CI);
        void showPlorg() const;
};