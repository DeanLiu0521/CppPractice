#ifndef MATH_UTILS
#define MATH_UTILS
struct Rectangle{
    int length;
    int width;
};

namespace utilz{
    
    double area(int length, int width);
    double area(int length);

    double area(Rectangle rectangle);

    double pow(double base, int pow = 2); 
}

#endif