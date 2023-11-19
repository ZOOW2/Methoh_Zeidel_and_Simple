// main.cpp
#include <iostream>
#include <dlfcn.h>
#include "iterative_methods.h"

using namespace std;

const int maxIterations = 1000;
const double tolerance = 1e-6;

int main() {
    // Загрузка библиотеки
    void* libraryHandle = dlopen("./iterative_methods.so", RTLD_LAZY);

    if (!libraryHandle) {
        cerr << "Ошибка при загрузке библиотеки: " << dlerror() << "\n";
        return 1;
    }

    // Получение указателей на функции из библиотеки
    typedef void (*SimpleIterationMethod)(double*, double*, double*, int, int, double);
    typedef void (*GaussSeidelMethod)(double*, double*, double*, int, int, double);

    SimpleIterationMethod simpleIteration = reinterpret_cast<SimpleIterationMethod>(dlsym(libraryHandle, "simpleIterationMethod"));
    GaussSeidelMethod gaussSeidel = reinterpret_cast<GaussSeidelMethod>(dlsym(libraryHandle, "gaussSeidelMethod"));

    if (!simpleIteration || !gaussSeidel) {
        cerr << "Ошибка при получении указателей на функции: " << dlerror() << "\n";
        dlclose(libraryHandle);
        return 1;
    }

    // Пример использования метода простой итерации
    int n;
    cout << "Введите ваше n: " << "\n";
    cin >> n;
    
    double A[n][n];
    double B[n];
    double X[n];

    // Заполнение матрицы A и вектора B согласно вашим условиям
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                A[i][j] = 2 * n;
            } else {
                A[i][j] = 1;
            }
        }
        B[i] = (n * (n + 1) / 2) + i * (2 * n - 1);
        X[i] = 0; // Инициализация начального приближения
    }

    simpleIteration(&A[0][0], B, X, n, maxIterations, tolerance);

    // Вывод результата
    cout << "Метод простой итерации:" << "\n";
    for (int i = 0; i < n; ++i) {
        cout << "X[" << i << "] = " << X[i] << "\n";
    }

    // Пример использования метода Зейделя
    double X_seidel[] = {0, 0, 0};

    gaussSeidel(&A[0][0], B, X_seidel, n, maxIterations, tolerance);

    // Вывод результата
    cout << "\nМетод Зейделя:" << "\n";
    for (int i = 0; i < n; ++i) {
        cout << "X[" << i << "] = " << X_seidel[i] << "\n";
    }


    // Программа ждет ввода пользователя перед завершением
    cout << "Нажмите Enter, чтобы закрыть программу." << "\n";
    cin.get();

    // Выгрузка библиотеки
    dlclose(libraryHandle);

    return 0;
}
