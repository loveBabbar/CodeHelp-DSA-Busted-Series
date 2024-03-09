#include<iostream>
using namespace std;


class Animal {

    public:
    int age;
    int weight;


    public:
    void speak() {
        cout << "Speaking " << endl;
    }
};

class Dog: public Animal {

};


int main() {

    Dog d;
    d.speak();
    cout << d.age << endl;


    return 0;
}