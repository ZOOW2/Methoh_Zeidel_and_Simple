#include <iostream>
#include "Header.h"

using namespace std;

const int maximum = 1000; // ���-�� �����

int main()
{
    // ������������
    setlocale(LC_ALL, "Rus");

    // ������������� ����������
    int n;

    cout << "�������� ���-�� ����������: " << "\n";
    cin >> n;

    double exp = 1e-6;
    double* solution, * solution_1;

    // �������� ���������� �������
    double** A = new double* [n];
    for (int i = 0; i < n; ++i)
    {
        A[i] = new double[n];
    }

    // ������� A
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                A[i][j] = 2 * n;
            } else {
                A[i][j] = 1;
            }
        }
    }

    // ������� B
    double* b = new double[n];
    for (int i = 0; i < n; ++i) {
        b[i] = (n * (n + 1) / 2) + i * (2 * n - 1);
    }

    IterativeMethods iterativeMethods;

    solution = iterativeMethods.simpleIteration(A, b, n, maximum, exp);
    cout << "������� � �������������� ������ ������� ��������:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "x[" << i << "] = " << solution[i] << "\n";
    }

    solution_1 = iterativeMethods.gaussSeidel(A, b, n, maximum, exp);
    cout << "������� � �������������� ������ ������-�������:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "x[" << i << "] = " << solution_1[i] << "\n";
    }

    // �������� �������
    for (int i = 0; i < n; ++i) {
        delete[] A[i];
    }
    delete[] A;
    delete[] b;
    delete[] solution;
    delete[] solution_1;

    system("PAUSE");

    return 0;
}
