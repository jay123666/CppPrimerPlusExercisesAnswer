#include <string>
#include <stdexcept>
#include <sstream>
class bad_hmean: public std::logic_error{
    private:
        double v1;
        double v2;
    public:
        bad_hmean(double v1=0, double v2=0):logic_error(""),v1(v1),v2(v2){ }
        const char * what();
};

class bad_gmean: public std::logic_error{
    private:
        double v1;
        double v2;
    public:
        bad_gmean(double v1=0, double v2=0):logic_error(""),v1(v1),v2(v2){ }
        const char * what();
};

inline const char * bad_hmean::what(){
    std::ostringstream oss;
    oss << "bad arguments to hmean(): " << v1 << ", " << v2;
    static std::string static_msg = oss.str();
    return static_msg.c_str();
}

inline const char * bad_gmean::what(){
    std::ostringstream oss;
    oss << "bad arguments to gmean(): " << v1 << ", " << v2;
    static std::string static_msg = oss.str();
    return static_msg.c_str();

}