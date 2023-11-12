// iterative_methods.cpp
#include <cmath>

extern "C" {
    // Метод простой итерации
    void simpleIterationMethod(double* A, double* B, double* X, int n, int maxIterations, double tolerance) {
        for (int k = 0; k < maxIterations; ++k) {
            for (int i = 0; i < n; ++i) {
                double sum = B[i];
                for (int j = 0; j < n; ++j) {
                    if (i != j) {
                        sum -= A[i * n + j] * X[j];
                    }
                }
                X[i] = sum / A[i * n + i];
            }

            // Проверка на сходимость
            double error = 0.0;
            for (int i = 0; i < n; ++i) {
                double sum = B[i];
                for (int j = 0; j < n; ++j) {
                    sum -= A[i * n + j] * X[j];
                }
                error += std::abs(sum);
            }

            if (error < tolerance) {
                // Достигнута сходимость
                break;
            }
        }
    }

    // Метод Зейделя
    void gaussSeidelMethod(double* A, double* B, double* X, int n, int maxIterations, double tolerance) {
        for (int k = 0; k < maxIterations; ++k) {
            for (int i = 0; i < n; ++i) {
                double sum = B[i];
                for (int j = 0; j < n; ++j) {
                    if (i != j) {
                        sum -= A[i * n + j] * X[j];
                    }
                }
                X[i] = sum / A[i * n + i];
            }

            // Проверка на сходимость
            double error = 0.0;
            for (int i = 0; i < n; ++i) {
                double sum = B[i];
                for (int j = 0; j < n; ++j) {
                    sum -= A[i * n + j] * X[j];
                }
                error += std::abs(sum);
            }

            if (error < tolerance) {
                // Достигнута сходимость
                break;
            }
        }
    }
}
