#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

double f(double x) {
    return (x*x*x+12*x-12);
}

double root_serch(double a, double b, double eps) {
    double c;
    int i = 0;
    do {
        i++;
        c = (a + b) / 2.0;
        if (f(a) * f(c) < 0) {
            b = c;
            std::cout << "Точка a =" << a << std::endl;
            std::cout << "Точка b = " << b << std::endl;
            std::cout << "delta x" << ":" << " " << fabs(b - a) << std::endl;
            std::cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << std::endl;
        }
 
        else if (f(b) * f(c) < 0) {
            a = c;
            std::cout << "Точка a =" << a << std::endl;
            std::cout << "Точка b = " << b << std::endl;
            std::cout << "delta x" << ":" << " " << fabs(b - a) << std::endl;
            std::cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << std::endl;
        }
        else {
            std::cout << " Корень не найден " << std::endl;
            std::cout << "Точка a =" << a << std::endl;
            std::cout << "Точка b = " << b << std::endl;
            std::cout << "delta x" << ":" << " " << fabs(b - a) << std::endl;
            std::cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << std::endl;
                return 0;
        }
        
    } while (fabs(b - a) > eps);
    std::cout << "Число итераций = " << i << std::endl;
    std::cout << "Корень будет равен = " << floor(c*100)/100 << std::endl;
}


int main()
{
    setlocale(LC_ALL, "Rus");
    double a = 0.0;
    double b = 2.0;
    double eps = 0.01;
    root_serch(a, b, eps);
    system("PAUSE");
}
