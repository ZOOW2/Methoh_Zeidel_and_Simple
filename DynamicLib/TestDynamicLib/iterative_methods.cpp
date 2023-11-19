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
	    // Создание временного массива для хранения новых значений переменных
	    double* newX = new double[n];

	    for (int k = 0; k < maxIterations; ++k) {
		for (int i = 0; i < n; ++i) {
		    double sum = B[i];

		    // Используем текущие значения переменных X вместо newX
		    for (int j = 0; j < i; ++j) {
		        sum -= A[i * n + j] * X[j];
		    }

		    // Используем newX для j >= i, чтобы использовать новые значения
		    for (int j = i + 1; j < n; ++j) {
		        sum -= A[i * n + j] * newX[j];
		    }

		    newX[i] = sum / A[i * n + i];
		}

		// Перенос новых значений в основной массив
		for (int i = 0; i < n; ++i) {
		    X[i] = newX[i];
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

	    // Освобождение памяти
	    delete[] newX;
	}
}
