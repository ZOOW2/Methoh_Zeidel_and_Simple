#include <iostream>
#include "Header.h"

using namespace std;

const int maximum = 1000; // Кол-во точек

int main()
{
    // Руссификация
    setlocale(LC_ALL, "Rus");

    // Инициализация переменных
    int n;

    cout << "Введите кол-во значений: " << "\n";
    cin >> n;

    double exp = 1e-6;
    double* solution, * solution_1;

    // Создание двумерного массива
    double** A = new double* [n];
    for (int i = 0; i < n; ++i)
    {
        A[i] = new double[n];
    }

    // Матрица A
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                A[i][j] = 2 * n;
            } else {
                A[i][j] = 1;
            }
        }
    }

    // Матрица B
    double* b = new double[n];
    for (int i = 0; i < n; ++i) {
        b[i] = (n * (n + 1) / 2) + i * (2 * n - 1);
    }

    IterativeMethods iterativeMethods;

    // Выбор начального приближения
    double* initialGuess = new double[n];
    for (int i = 0; i < n; ++i) {
        initialGuess[i] = 0.0;
    }

    solution = iterativeMethods.simpleIteration(A, b, n, maximum, exp, initialGuess);
    cout << "Решение с использованием метода простой итерации:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "x[" << i << "] = " << solution[i] << "\n";
    }

    solution_1 = iterativeMethods.gaussSeidel(A, b, n, maximum, exp);
    cout << "Решение с использованием метода Гаусса-Зейделя:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "x[" << i << "] = " << solution_1[i] << "\n";
    }

    // Удаление матриц
    for (int i = 0; i < n; ++i) {
        delete[] A[i];
    }
    delete[] A;
    delete[] b;
    delete[] solution;
    delete[] solution_1;
    delete[] initialGuess;

    return 0;
}
