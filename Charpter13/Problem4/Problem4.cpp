#include "port.h"
#include <iostream>

int main() {
    using std::cout;
    using std::endl;

    // Test Port class
    Port port1("Gallo", "tawny", 20);
    Port port2("Taylor", "ruby", 30);
    Port port3 = port1; // Copy constructor
    port2 = port1; // Assignment operator

    cout << "Testing Port class:" << endl;
    cout << "port1: " << port1 << endl;
    cout << "port2: " << port2 << endl;
    cout << "port3: " << port3 << endl;

    port1 += 10;
    port2 -= 5;

    cout << "After modifying port1 and port2:" << endl;
    cout << "port1: " << port1 << endl;
    cout << "port2: " << port2 << endl;

    port1.Show();
    port2.Show();
    port3.Show();

    // Test VintagePort class
    VintagePort vp1("Fonseca", 50, "Old Velvet", 1985);
    VintagePort vp2("Sandeman", 60, "Vintage Reserve", 1990);
    VintagePort vp3 = vp1; // Copy constructor
    vp2 = vp1; // Assignment operator

    cout << "\nTesting VintagePort class:" << endl;
    cout << "vp1: " << vp1 << endl;
    cout << "vp2: " << vp2 << endl;
    cout << "vp3: " << vp3 << endl;

    vp1 += 20;
    vp2 -= 10;

    cout << "After modifying vp1 and vp2:" << endl;
    cout << "vp1: " << vp1 << endl;
    cout << "vp2: " << vp2 << endl;

    vp1.Show();
    vp2.Show();
    vp3.Show();

    return 0;
}