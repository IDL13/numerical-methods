#include <iostream>

double InFunction(double x)
{
    return ((2 * x * x) + 1 - sqrt(x));
}

void CalcIntegral(double a, double b, int n)
{
    double result = 0;
    double h = (b - a) / n;

    for (int i = 0; i < n; i++)
    {
        const double x1 = a + i * h;
        const double x2 = a + (i + 1) * h;

        result += (x2 - x1) / 6 * (InFunction(x1) + 4 * InFunction(0.5 * (x1 + x2)) + InFunction(x2));
    }
    std::cout << result << std::endl;

}

int main()
{
    setlocale(LC_ALL, "Rus");
    system("cls");
    std::cout << "Приблизительное значение интегралла" << std::endl;
    CalcIntegral(0, 4, 8);
    system("pause");
}