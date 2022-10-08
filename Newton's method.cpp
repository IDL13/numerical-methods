#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;
double find(double x, double eps)
{
	double f, df; int iter = 0;
	cout << "x0 = " << x << endl;
	do {
		f = (x*x*x)+12*x-12;
		df = 3*x*x+12;
		x = x - f / df;
		cout << "x = " << x << endl;
		iter++;
	} while (fabs(f) > eps && iter < 1000);
	cout  << "Количество итераций = " << iter << endl;
	return x;
}
int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Получаемый корень = " << find(1, 0.001) << endl;
	cin.get(); 
	return 0;
}