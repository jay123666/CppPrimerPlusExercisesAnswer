#include "move.h"

int main() {
    Move m = Move(0, 0);
    m.showmove();
    Move m1 = Move(1, 2);
    Move m2 = Move(-3.1, 3);
    Move m3 = m.add(m1);
    m3.showmove();
    m.reset(4, 4);
    m.showmove();
    m = m.add(m2);
    m.showmove();
    m.reset();
    m.showmove();
    return 0;
}