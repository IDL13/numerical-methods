#include <math.h>
#include <iostream>
const double eps = 0.01; /// точность 

/// N - размерность матрицы; A[N][N] - матрица коэффициентов, F[N] - столбец свободных членов,
/// X[N] - начальное приближение, ответ записывается также в X[N];
void Jacobi(int N, double** A, double* F, double* X)
{
    double* TempX = new double[N];
    double norm; // норма, определяемая как наибольшая разность компонент столбца иксов соседних итераций.

    do {
        for (int i = 0; i < N; i++) {
            TempX[i] = F[i];
            for (int g = 0; g < N; g++) {
                if (i != g)
                    TempX[i] -= A[i][g] * X[g];
            }
            TempX[i] /= A[i][i];
        }
        norm = fabs(X[0] - TempX[0]);
        std::cout << norm << std::endl;
        for (int h = 0; h < N; h++) {
            if (fabs(X[h] - TempX[h]) > norm)
                norm = fabs(X[h] - TempX[h]);
            X[h] = TempX[h];
        }
    } while (norm > eps);
    delete[] TempX;
}

int main()
{
    const int N = 4;
    double B[N][N] = { { 3, 1, -1, 1 }, { 1, -4, 1, -1}, { -1, 1, 4, 1 },{1, 2, 1, -5} };
    double F[N] = { 30, 4, 5, 12 };
    double X[N] = { 0.5 };
    double** A = new double* [N];
    for (int i = 0; i < N; ++i) {
        A[i] = new double[N];
        for (int j = 0; j < N; ++j)
            A[i][j] = B[i][j];
    }
    Jacobi(N, A, F, X);
    system("pause");
    system("cls");
    return 0;
}