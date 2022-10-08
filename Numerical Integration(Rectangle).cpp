#include <iostream>

double InFunction(double x) { //Подынтегральная функция
    return (2*x*x + 1 - sqrt(x));
}

void CalcIntegral(double a, double b, int n) {
    double result = 0;
    double h = (b - a) / n;

    for (int i = 0; i < n; i++) {
        result = result + InFunction(a + h * (i + 0.5));
    }

    result = result * h;
    std::cout << result << std::endl;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    system("cls");
    std::cout << "Приблизительное значение интеграла:" << std::endl;
    CalcIntegral(0, 4, 8);
    system("pause");
    return 0;
}