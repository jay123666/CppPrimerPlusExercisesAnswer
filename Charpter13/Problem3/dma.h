#ifndef DMA_H_
#define DMA_H_
#include <iostream>

class DMA{
    public:
        DMA(const DMA & dma) { };
        DMA() { };
        virtual ~DMA() { };
        virtual DMA & operator=(const DMA & dma) { return *this; }
        virtual void view() const = 0;
        friend std::ostream & operator<<(std::ostream & os, const DMA & dma) { os << "This is base.\n"; return os; }
};

class baseDMA: public DMA{
    private:
        char * label;
        int rating;
    public:
        baseDMA(const char * l="null", int r=0);
        baseDMA(const baseDMA & rs);
        ~baseDMA();
        baseDMA & operator=(const baseDMA & rs);
        virtual void view() const;
        friend std::ostream & operator<<(std::ostream & os, const baseDMA & rs);
};

class lacksDMA: public DMA{
    private: 
        enum{ COL_LEN = 40 };
        char color[COL_LEN];
    public:
        lacksDMA(const char * c="blank");
        virtual void view() const;
        friend std::ostream & operator<<(std::ostream & os, const lacksDMA & rs);
};

class hasDMA: public DMA{
    private:
        char * style;
    public:
        hasDMA(const char * s="none");
        hasDMA(const hasDMA & rs);
        ~hasDMA();
        hasDMA & operator=(const hasDMA & rs);
        virtual void view() const;
        friend std::ostream & operator<<(std::ostream & os, const hasDMA & rs);

};


#endif