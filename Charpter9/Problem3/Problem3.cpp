#include <iostream>
#include <cstring>

struct chaff{
    char dross[20];
    int slag;
};


int main() {
    static char cach[48];
    chaff * normal_charff = new chaff[2];
    chaff * static_charff = new (cach) chaff[2];
    for(int i=0; i<2; i++) {
        std::strcpy(normal_charff[i].dross, "asdf");
        std::strcpy(static_charff[i].dross, "asdf");
        normal_charff[i].slag = 1;
        static_charff[i].slag = 2;
    }

    for(int i=0; i<2; i++){
        std::cout << "Normal chaff: " << &normal_charff[i] << normal_charff[i].dross << normal_charff[i].slag << std::endl;
        std::cout << "Static chaff: " << &static_charff[i] << static_charff[i].dross << static_charff[i].slag << std::endl;
        std::cout << "Static char: " << static_cast<void*>(&cach[i * sizeof(chaff)]) << std::endl;
    }
    delete [] normal_charff;
    return 0;
}