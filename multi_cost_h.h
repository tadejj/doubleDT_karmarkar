#ifndef MULTI_COST_H_H_INCLUDED
#define MULTI_COST_H_H_INCLUDED
#include <malloc.h>
double* matrxvec(double **,double *,int,int);
double ** LU_inverse_matrix(double**,int);
double** matrxmatr(double**,double**,int,int,int,int);
double **transpon_matrix(double **,int,int);
double **diagonalization(const double *,int);
double min_val_hv(const double *,const double *,int);
int karmarkar_iteration(double **,double *,double *,double *,int,int,double);
void create_Nb(double **,int *,int,int);
double delta_func(int,double *,double **,double *,int); //обчислення дельта-функції
int max_delta(double *,int);
int min_Teta(int ,double *);
double * symplex_iter(double **,double *,double *,int,int);

#endif // MULTI_COST_H_H_INCLUDED
