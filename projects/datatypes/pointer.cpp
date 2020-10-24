#include <iostream>
#include <string>
using namespace std;

int main(){
    string drink = "coke";
    string* ptr = &drink;
    cout << ptr << "\n";
    cout << &drink << "\n";
    cout << *ptr << "\n";
    *ptr = "pepsi";
    cout << drink << "\n";
}

