#include <iostream>

struct box {
    char maker[40];
    float height;
    float width;
    float length;
    float volume = 0;
};

void getBox(box b);
void setBoxVolume(box * b);

int main() {
    box boxes[4] = {
        {"Jay Wang", 12, 12, 12},
        {"Silong Hu", 1, 1, 1},
        {"Foo", 12, 34, 56},
        {"Bar", 32, 32, 32},
    };
    for (box & b: boxes) {
        setBoxVolume(&b);
        getBox(b);
    }
    return 0;
}

void getBox(const box b){
    std::cout << "This is the detail of box: " << b.maker << std::endl;
    std::cout << "Height: " << b.height << std::endl;
    std::cout << "Width: " << b.width << std::endl;
    std::cout << "Length: " << b.length << std::endl;
    std::cout << "Volume: " << b.volume << std::endl;
}

void setBoxVolume(box * b){
    b->volume = b->height * b->length * b->width;
}