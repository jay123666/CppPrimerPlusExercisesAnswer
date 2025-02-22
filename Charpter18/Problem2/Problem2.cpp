#include <string>
#include <utility>
#include "cpmv.h"

int main() {
    Cpmv mv1;
    Cpmv mv2 = Cpmv("Guochen", "Wang");
    Cpmv mv3 = std::move(mv1+mv2);
    mv1 = mv2;
    Cpmv mv4 = Cpmv(mv2);
    mv4 = mv2 + mv2;
    return 0;
}
