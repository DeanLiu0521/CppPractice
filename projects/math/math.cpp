#include <iostream>
#include "math_utils.h"

using namespace std;

int main(){
    Rectangle rectangle;
    rectangle.length = 10;
    rectangle.width = 5;

    cout << "The area of the rectangle is: " << utilz::area(rectangle) << endl;
    cout << "The power of 5 is: " << utilz::pow(5);
    return 0;
}
