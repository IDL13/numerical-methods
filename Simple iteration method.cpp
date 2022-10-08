#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;
double find(double x, double eps)
{
	double rez; int iter = 0;
	cout << "x0 = " << x << endl;
	do {
		rez = x;
		x = (12 - (x * x * x)) / 12; 
		cout << "x = " << x << endl;
		iter ++;
	} while (fabs(rez - x) > eps && iter < 1000);
	cout << "Количество итераций = " << iter << endl;
	return x;
}
int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Получаемый твет = " << " " << find(1, 0.001) << endl;
	cin.get();
	return 0;
}