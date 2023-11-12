#include <iostream>
#include <cmath>

using namespace std;

class IterativeMethods {
public:
    static double* simpleIteration(double** A, double* b, int n, int maxIter, double tol);
    static double* gaussSeidel(double** A, double* b, int n, int maxIter, double tol);
private:
    static double calculateResidual(double* x, double* xPrev, int n);
};

double IterativeMethods::calculateResidual(double* x, double* xPrev, int n)
{

    // Рассчет нормы разности между текущими и предыдущими векторами
    double sum = 0.0;
    for (int i = 0; i < n; ++i)
    {
        sum += pow(x[i] - xPrev[i], 2);
    }
    return sqrt(sum);
}

double* IterativeMethods::simpleIteration(double** A, double* b, int n, int maxIter, double tol)
{
    double* x = new double[n];
    double* xPrev = new double[n];

    // Начальное приближение
    for (int i = 0; i < n; ++i) {
        x[i] = 0.0;
    }

    for (int iter = 0; iter < maxIter; ++iter)
    {
        // Сохраняем текущее значение x
        for (int i = 0; i < n; ++i)
        {
            xPrev[i] = x[i];
        }

        // Реализация метода простой итерации
        for (int i = 0; i < n; ++i)
        {
            x[i] = b[i];
            for (int j = 0; j < n; ++j)
            {
                if (i != j)
                {
                    x[i] -= A[i][j] * xPrev[j];
                }
            }
            x[i] /= A[i][i];
        }

        // Проверка на сходимость
        if (calculateResidual(x, xPrev, n) < tol)
        {
            cout << "Преобразование после " << iter + 1 << " итераций\n";
            return x;
        }
    }

    cerr << "Не сходится за максимальное кол-во итераций\n";
    return x;
}

double* IterativeMethods::gaussSeidel(double** A, double* b, int n, int maxIter, double tol) {
    double* x = new double[n];
    double* xPrev = new double[n];

    // Начальное приближение
    for (int i = 0; i < n; ++i) {
        x[i] = 0.0;
    }

    for (int iter = 0; iter < maxIter; ++iter) {
        // Сохраняем текущее значение x
        for (int i = 0; i < n; ++i) {
            xPrev[i] = x[i];
        }

        // Реализация метода Зейделя
        for (int i = 0; i < n; ++i) {
            x[i] = b[i];
            for (int j = 0; j < i; ++j) {
                x[i] -= A[i][j] * x[j];
            }
            for (int j = i + 1; j < n; ++j) {
                x[i] -= A[i][j] * xPrev[j];
            }
            x[i] /= A[i][i];
        }

        // Проверка на сходимость
        if (calculateResidual(x, xPrev, n) < tol) {
            cout << "Преобразование после " << iter + 1 << " итераций\n";
            return x;
        }
    }

    std::cerr << "Íå ñõîäèòñÿ çà ìàêñèìàëüíîå êîëè÷åñòâî èòåðàöèé\n";
    return x;
}
