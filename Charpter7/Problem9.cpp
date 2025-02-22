#include <iostream>

const int SLEN = 30;
struct student {
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};

int getinfo(student pa[], int n);
void display1(student st);
void display2(const student * ps);
void display3(const student pa[], int n);

int main() {
    std::cout << "Enter class size: ";
    int class_size;
    std::cin >> class_size;
    while (std::cin.get()!='\n') continue;
    student * ptr_stu = new student[class_size];
    int entered = getinfo(ptr_stu, class_size);
    for (int i=0; i < entered; i++){
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu, entered);
    delete [] ptr_stu;
    std::cout << "Done\n";
    return 0;
}

int getinfo(student pa[], int n){
    int count = 0;
    while(count < n){
        std::cout << "Enter fullname: ";
        std::cin.getline(pa[count].fullname, SLEN);
        if(pa[count].fullname == NULL) break;
        std::cout << "Enter hobby: ";
        std::cin.getline(pa[count].hobby, SLEN);
        std::cout << "Enter ooplevel: ";
        std::cin >> pa[count].ooplevel;
        while(std::cin.get()!='\n') continue;
        ++count;
    }
    return count;
} 

void display1(student st){
    std::cout << "Fullname: " << st.fullname << " hobby: " << st.hobby << " ooplevel: " << st.ooplevel << std::endl;
}

void display2(const student * ps){
    std::cout << "Fullname: " << ps->fullname << " hobby: " << ps->hobby << " ooplevel: " << ps->ooplevel << std::endl;
}

void display3(const student pa[], int n){
    for(int i=0; i<n; i++) {
        std::cout << "Fullname: " << pa[i].fullname << " hobby: " << pa[i].hobby << " ooplevel: " << pa[i].ooplevel << std::endl;
    }
}