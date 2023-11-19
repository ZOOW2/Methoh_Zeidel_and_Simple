// iterative_methods.h
#ifndef ITERATIVE_METHODS_H
#define ITERATIVE_METHODS_H

extern "C" {
    void simpleIterationMethod(double* A, double* B, double* X, int n, int maxIterations, double tolerance);
    void gaussSeidelMethod(double* A, double* B, double* X, int n, int maxIterations, double tolerance);
}

#endif
