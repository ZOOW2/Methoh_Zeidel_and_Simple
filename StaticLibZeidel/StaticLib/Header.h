#ifndef ITERATIVE_METHODS_H
#define ITERATIVE_METHODS_H

class IterativeMethods {
public:
    static double* simpleIteration(double** A, double* b, int n, int maxIter, double tol);
    static double* gaussSeidel(double** A, double* b, int n, int maxIter, double tol);
};

#endif // ITERATIVE_METHODS_H
