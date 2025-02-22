#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <memory>
#include <random>
#include <ctime>
#include <chrono>

using namespace std;

struct Review{
    string title;
    int rating;
    double price;
};

bool worseThan(const shared_ptr<Review> & pr1, const shared_ptr<Review> & pr2);
bool expenThan(const shared_ptr<Review> & pr1, const shared_ptr<Review> & pr2);
bool operator<(const shared_ptr<Review> & pr1, const shared_ptr<Review> & pr2);
void showReview(const shared_ptr<Review> & pr);
void showMenu();
bool fillReview(Review & rr);

int main(){
    vector<shared_ptr<Review>> books;
    while (true){
        shared_ptr<Review> p(new Review());
        if (!fillReview(*p)) break;
        books.push_back(p);
    }
    while (true){
        showMenu();
        char choice;
        if(cin>>choice && choice != 'q'){
            switch(choice){
                case 'o':
                    break;
                case 'a':
                    sort(books.begin(), books.end());
                    break;
                case 'r':
                    sort(books.begin(), books.end(), worseThan);
                    break;
                case 's':
                    sort(books.rbegin(), books.rend(), worseThan);
                    break;
                case 'p':
                    sort(books.begin(), books.end(), expenThan);
                    break;
                case 'd':
                    sort(books.rbegin(), books.rend(), expenThan);
                    break;
            }
            cout << "Rating\tTitle\t\tPrice\n";
            for_each(books.begin(), books.end(), showReview);
        } else {
            cout << "No entries. ";
            break;
        }
    }
    cout << "Bye.\n";
    return 0;
}

bool fillReview(Review & rr){
    cout << "Enter book title (quit to quit): ";
    getline(cin, rr.title);
    if (rr.title == "quit") return false;
    cout << "Enter book rating: ";
    cin >> rr.rating;
    if (!cin) return false;
    while(cin.get()!='\n') continue;
    cout << "Enter book price: ";
    cin >> rr.price;
    if (!cin) return false;
    while(cin.get()!='\n') continue;
    return true;
}


void showReview(const shared_ptr<Review> & rr){
    cout << rr->rating << "\t" << rr->title << "\t" << rr->price << endl;
} 

bool operator<(const shared_ptr<Review> & pr1, const shared_ptr<Review> & pr2){
    if (pr1->title < pr2->title) {
        return true;
    } else if (pr1->title == pr2->title && pr1->rating < pr2->rating) {
        return true;
    } else if (pr1->title == pr2->title && pr1->rating == pr2->rating && pr1->price < pr2->price) {
        return true;
    } else {
        return false;
    }
}

bool worseThan(const shared_ptr<Review> & pr1, const shared_ptr<Review> & pr2){
    if(pr1->rating > pr2->rating){
        return true;
    } else {
        return false;
    }
}

bool expenThan(const shared_ptr<Review> & pr1, const shared_ptr<Review> & pr2){
    if(pr1->price > pr2->price){
        return true;
    } else {
        return false;
    }
}

void showMenu(){
    cout << "Please choose a way to sort.\n";
    cout << "o: original, a: alphabet\n";
    cout << "r: rate, s: rate revserse\n";
    cout << "p: price, d: price reverse\n";
    cout << "q: quit\n";
}