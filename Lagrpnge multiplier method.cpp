#include <iostream>
#include <conio.h>
#include <locale.h>

using namespace std;

void Create_Array(double* x, int n, double* y) {
    for (int i = 0; i < n; i++) {
        cout << "Введите элеимент масива" << " " << i << endl;
        cin >> x[i];
    }
    for (int j = 0; j < n; j++) {
        cout << "Введите элеимент масива" << " " << j << endl;
        cin >> y[j];
    }
}

void Show_Array(double* x, int n, double* y) {
    cout << "Масив x" << endl;

    for (int i = 0; i < n; i++) {
        cout << x[i] << " " << endl;;
    }
    cout << "Масив y" << endl;

    for (int j = 0; j < n; j++) {
        cout << y[j] << " " << endl;
    }

}

void Lagrange(double* x, double* y, int S, int n) {
    double z = 0.0;
    cout << "Введите значение точки z: ";
    cin >> z;


    for (int i = 0; i < n; ++i)
    {
        double  P = 1.0;
        for (int j = 0; j < n; ++j)
        {
            if (i != j)
            {
                P *= (z - x[j]) / (x[i] - x[j]);
            }
        }
        S = S + y[i] * P;
    }
    cout << S << endl;
}

int main()
{
    setlocale(LC_ALL, "Ru");
    int n;
    int S;
    cout << "Введите размер матрицы" << endl;
    cin >> n;


   //Выделение памяти под массив//
     double* x = new double [n];
     double* y = new double[n];
    
     Create_Array(x, n, y);
     Show_Array( x, n, y);
     Lagrange(x, y, 0.0,n);

    //double x[] = { 1, 2, 2.0000001, 4 };
    //double y[] = { 1, 2, 5,         4 };


    //Очистка памяти//
    delete x;
    delete y;

    system("pause");
    system("cls");
    return 0;
}