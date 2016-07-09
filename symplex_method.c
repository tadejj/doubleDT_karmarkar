#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "multi_cost_h.h"
#include <malloc.h>
void create_Nb(double **alpha_matrix,int *Nb,int m,int n)
{
	int k = 0;
    int q = -1;
    for (int j = 0; j < n; j++)
    {
    	k = 0;
        for (int i = 0; i < m; i++)
        {
        	if (k > 2)
        		j++;
            if (alpha_matrix[i][j] == 0)
                i++;
            if ((i<=m)&&(alpha_matrix[i][j] == 1))
            {
            	k++;
                q = i;
            }
        }
        if (q!=-1)
        	Nb[q] = j;
    }
}

double delta_func(int j,double *Cb,double **alpha_matrix,double *C,int m) //обчислення дельта-функції
{
	double sum = 0;
    for (int i = 0; i < m; i++)
    {
    	sum += Cb[i] * alpha_matrix[i][j];
    }
    return sum - C[j];
}

int max_delta(double *delta,int n) //пошук мінімальних значень
{
	double max = 0;
    int num = 0;
    for (int i = 0; i < n; i++)
    {
    	if (delta[i] > max)
        {
    		max = delta[i];
            num = i;
        }
    }
    return num;
}

int min_Teta(int m,double *Teta)
{
	double min = 1000000;
    int num = 0;
    int counter = 0;
    for (int i = 0; i < m; i++)
    {
    	if (Teta[i] < 0)
        {
    		continue;
            counter++;
        }
        if (Teta[i] < min)
        {
        	min = Teta[i];
            num = i;
        }
     }
     if (counter == m)
     {
    	 return -1;
     }
     return num;
}

double * symplex_iter(double **alpha_matrix,double *C,double *b,int n,int m)
{
	double **alpha_matrix_copy;
	double *b_copy,*Cb,*delta,*Teta,*x0;
	int *Nb;
	int flag = 0;
	alpha_matrix_copy = (double **)malloc(m*sizeof(double *));
	b_copy = (double *)malloc(m*sizeof(double));
	Cb = (double *)malloc(m*sizeof(double));
	delta = (double *)malloc(n*sizeof(double));
	Teta = (double *)malloc(n*sizeof(double));
	Nb = (int *)malloc(m*sizeof(int));
	for (int i=0;i<m;i++)
	{
		alpha_matrix_copy[i] = (double *)malloc(n*sizeof(double));
        b_copy[i] = b[i];
	}
	for (int i=0;i<n;i++)
    {
        delta[i]=delta_func(i,Cb,alpha_matrix,C,m);
        printf("%lf \n",delta[i]);
    }
	create_Nb(alpha_matrix,Nb,m,n);
	for (int i=0;i<m;i++)
	{
		Cb[i] = C[Nb[i]];
	}
	while (1)
	{
        int col = max_delta(delta,n);
        for (int i = 0; i < m; i++)
        {
            Teta[i] = b[i] / alpha_matrix[i][col];
        }
        int row = min_Teta();
        if (row < 0)
        {
            printf("task hasn't solution\n");
            return x0;
        }
        for (int i = 0; i < m; i++)
        {
            if (i == row)
            {
                b_copy[i]/=alpha_matrix[row][col];
            }
            else
            {
                b_copy[i] = (b_copy[i] * alpha_matrix[row][col] - alpha_matrix[i][col] * b_copy[row]) / alpha_matrix[row][col];
            }
            for (int j = 0; j < n; j++)
            {
                if (i == row)
                {
                    alpha_matrix_copy[i][j] = alpha_matrix[i][j] / alpha_matrix[row][col];
                }
                else
                {
                    alpha_matrix_copy[i][j] = (alpha_matrix[row][col] * alpha_matrix[i][j] - alpha_matrix[i][col] * alpha_matrix[row][j]) / alpha_matrix[row][col];
                }
            }
        }
        Cb[row] = C[col];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                alpha_matrix[i][j] = alpha_matrix_copy[i][j];
            }
        }
        for (int i=0;i<m;i++)
            free(alpha_matrix_copy[i]);
        free(alpha_matrix_copy);
        int iter = 0;
        for (int i = 0; i < n; i++)
        {
            delta[i] = delta_func(i);
            if (delta[i] > 0)
            {
                iter++;
            }
        }
        if (iter==0)
        {
            return x0;
        }
    }
    return 0;
}
