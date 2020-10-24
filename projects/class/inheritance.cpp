#include <iostream>
#include <string>
using namespace std;

class Vehicle{
    public:
        string brand = "ford";
        void honk(){
            cout << "tuut" << "\n";
        }
};

class Car: public Vehicle{
    public:
    string model = "mustang";
};

class Animal{
    public:
        void animalsound(){
            cout << "The animal makes a sound \n";
        }
};

class Pig : public Animal{
    public:
        void animalsound(){
            cout << "wee wee \n";
        }
};

class Cow : public Animal{
    public:
        void animalsound(){
            cout << "moow moow \n";
        } 
};

int main(){
    Car myCar;
    Animal myAnimal;
    Pig myPig;
    Cow myCow;

    myCar.honk();
    cout << myCar.brand+ " " + myCar.model;

    myAnimal.animalsound();
    myPig.animalsound();
    myCow.animalsound();

    return 0;
}