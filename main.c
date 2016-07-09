#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "multi_cost_h.h"
#include <malloc.h>
int n,m;
double **a;
double* b, *c, *x;


/*

void create_Nb(double **alpha_matrix,int *Nb)
{
	int k = 0;
    int q = -1;
    for (int j = 1; j <= n; j++)
    {
    	k = 0;
        for (int i = 1; i <= m; i++)
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

double delta_func(int j,const double *Cb,const double **alpha_matrix,const double *C) //обчислення дельта-функції
{
	double sum = 0;
    for (int i = 1; i < m + 1; i++)
    {
    	sum += Cb[i] * alpha_matrix[i][j];
    }
    return sum - C[j];
}

int max_delta(const double *delta,int n) //пошук мінімальних значень
{
	double max = 0;
    int num = 0;
    for (int i = 0; i < n + 1; i++)
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
    for (int i = 1; i < m + 1; i++)
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

int symplex_iter(double **alpha_matrix,double *C,double *Cb,double *Teta,double *delta)
{
	double **alpha_matrix_copy;
	alpha_matrix_copy = (double **)malloc(m*sizeof(double *));
	for (int i=0;i<m;i++)
	{
		alpha_matrix_copy[i] = (double *)malloc(n*sizeof(double));
	}
	int col = max_delta();
  //printf("\ncol=%d\n", col);
	for (int i = 1; i < m + 1; i++)
    {
		Teta[i] = alpha_matrix[i][0] / alpha_matrix[i][col];
    }
    int row = min_Teta();
    if (row < 0)
    {
    	printf("task hasn't solution\n");
        //task hasn't solution
        return -1;
    }
    for (int i = 1; i < m + 1; i++)
    {
    	for (int j = 0; j < n + 1; j++)
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
    for (int i = 1; i < m + 1; i++)
    {
    	for (int j = 0; j < n + 1; j++)
        {
    		alpha_matrix[i][j] = alpha_matrix_copy[i][j];
        }
    }
    for (int i=0;i<m;i++)
    	free(alpha_matrix_copy[i]);
    free(alpha_matrix_copy);
    int iter = 0;
    for (int i = 0; i < n + 1; i++)
    {
    	delta[i] = delta_func(i);
        if (delta[i] > 0)
        {
        	iter++;
        }
    }
    if (iter==0)
    {
    	return 1;
    }
    return 0;
}

*/

int main(void)
{
	/*
	scanf("%d",&m);
	scanf("%d",&n);
	FILE* a_file;
	FILE *b_file;
	FILE *c_file;
	*/
	m=4;
	a=(double**)malloc(m*sizeof(double*));
	double **lu_matrix = (double**)malloc(m*sizeof(double*));
	for (int i=0;i<m;i++)
	{
		a[i]=(double*)malloc(m*sizeof(double));
		lu_matrix[i]=(double*)malloc(m*sizeof(double));
	}
	a[0][0] = 4.0;
	a[0][1] = 1.0;
	a[0][2] = 8.0;
	a[0][3] = 2.0;

	a[1][0] = 4.0;
	a[1][1] = 7.0;
	a[1][2] = 2.0;
	a[1][3] = 8.0;

	a[2][0] = 4.0;
	a[2][1] = 9.0;
	a[2][2] = 4.0;
	a[2][3] = 2.0;

	a[3][0] = 5.0;
	a[3][1] = 2.0;
	a[3][2] = 0.0;
	a[3][3] = 4.0;


	for (int i=0;i<m;i++)
		free(a[i]);
	free(a);
	/*
	b=(double*)malloc(n*sizeof(double));
	c=(double*)malloc(n*sizeof(double));
	x=(double*)malloc(n*sizeof(double));
	hx = (double *)malloc(n*sizeof(double));
	hv = (double *)malloc(n*sizeof(double));
	vk = (double *)malloc(m*sizeof(double));
	a_file=fopen("a_file.txt","r");
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++)
		fscanf(a_file,"%lf ",&a[i][j]);
		fscanf(a_file,"\n");
	}
	fclose(a_file);
	c_file = fopen("c_file.txt","r");
	for (int i=0;i<n;i++)
	{
		fscanf(c_file,"%lf\n",&c[i]);
	}
	fclose(c_file);
	b_file = fopen("b_file.txt","r");
	for (int i=0;i<m;i++)
	{
		fscanf(b_file,"%lf\n",&b[i]);
	}
	fclose(b_file);
	*/
	return 0;
}

