namespace SALES{
    const int QUARTERS = 4;
    class Sales{
        private:
            double sales[QUARTERS];
            double average;
            double max;
            double min;
        public:
            Sales(const double ar[], const int n);
            ~Sales();
            Sales setSales();
            void showSales() const;            
    };
}