#include <iostream>
#include <cmath>

using namespace std;

class IterativeMethods {
public:
    static double* simpleIteration(double** A, double* b, int n, int maxIter, double tol, double* initialGuess);
    static double* gaussSeidel(double** A, double* b, int n, int maxIter, double tol);
private:
    static double calculateResidual(double* x, double* xPrev, int n);
};

double IterativeMethods::calculateResidual(double* x, double* xPrev, int n) {
    // Рассчет нормы разности между текущими и предыдущими векторами
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        sum += pow(x[i] - xPrev[i], 2);
    }
    return sqrt(sum);
}

double* IterativeMethods::simpleIteration(double** A, double* b, int n, int maxIter, double tol, double* initialGuess) {
    double* x = new double[n];

    // Используем начальное приближение, если оно предоставлено
    if (initialGuess != nullptr) {
        for (int i = 0; i < n; ++i) {
            x[i] = initialGuess[i];
        }
    } else {
        // Или инициализируем нулями
        for (int i = 0; i < n; ++i) {
            x[i] = 0.0;
        }
    }

    for (int iter = 0; iter < maxIter; ++iter) {
        double* xPrev = new double[n];

        // Сохраняем текущее значение x
        for (int i = 0; i < n; ++i) {
            xPrev[i] = x[i];
        }

        // Реализация метода простой итерации
        for (int i = 0; i < n; ++i) {
            x[i] = b[i];
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    x[i] -= A[i][j] * xPrev[j];
                }
            }
            x[i] /= A[i][i];
        }

        // Проверка на сходимость
        if (calculateResidual(x, xPrev, n) < tol) {
            cout << "Преобразование после " << iter + 1 << " итераций\n";
            delete[] xPrev;
            return x;
        }

        delete[] xPrev;
    }

    cerr << "Не сходится за максимальное кол-во итераций\n";
    return x;
}

// Реализация метода Гаусса-Зейделя осталась без изменений
double* IterativeMethods::gaussSeidel(double** A, double* b, int n, int maxIter, double tol) {
    double* x = new double[n];

    // Начальное приближение
    for (int i = 0; i < n; ++i) {
        x[i] = 0.0;
    }

    for (int iter = 0; iter < maxIter; ++iter) {
        double* xPrev = new double[n];

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
            delete[] xPrev;
            return x;
        }

        delete[] xPrev;
    }

    cerr << "Не сходится за максимальное кол-во итераций\n";
    return x;
}
