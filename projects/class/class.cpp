#include <iostream>
#include <string>
using namespace std;


class Myclass {
    public:
        int myNum;
        string mystring;
        Myclass(int a, string b);

};

Myclass::Myclass(int a, string b){
    myNum = a;
    mystring = b;
};

int main(){
    Myclass food(10, "abc");
    cout << food.myNum << "\n";
    cout << food.mystring << "\n";
    return 0;
}

