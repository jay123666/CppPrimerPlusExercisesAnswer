#include <string>
#include <stdexcept>
#include <sstream>

class bad_mean: public std::logic_error{
    protected:
        double v1;
        double v2;
    public:
        bad_mean(double v1=0, double v2=0):logic_error(""),v1(v1),v2(v2) { }
        virtual ~bad_mean() { }
        virtual const char * what() const noexcept override = 0;
};


class bad_hmean: public bad_mean{
    public:
        bad_hmean(double v1=0, double v2=0):bad_mean(v1, v2){ }
        virtual ~bad_hmean() { }
        const char * what() const noexcept;
};

class bad_gmean: public bad_mean{
    public:
        bad_gmean(double v1=0, double v2=0):bad_mean(v1, v2){ }
        const char * what() const noexcept;
};

inline const char * bad_hmean::what() const noexcept{
    std::ostringstream oss;
    oss << "bad arguments to hmean(): " << bad_mean::v1 << ", " << bad_mean::v2;
    static std::string static_msg = oss.str();
    return static_msg.c_str();
}

inline const char * bad_gmean::what() const noexcept{
    std::ostringstream oss;
    oss << "bad arguments to gmean(): " << bad_mean::v1 << ", " << bad_mean::v2;
    static std::string static_msg = oss.str();
    return static_msg.c_str();

}