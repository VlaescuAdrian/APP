#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define N 100

int main (int argc, char *argv[]) 
{
int	tid, nthreads, i, j, k, chunk;
double	a[N][N],
	b[N],
	c[N];        

double t1, t2;
t1 = omp_get_wtime();
#pragma omp parallel sections
  {
    #pragma omp section
    {
        tid = omp_get_thread_num();
        if (tid == 0)
            {
            nthreads = omp_get_num_threads();
            printf("Starting matrix multiple example with %d threads\n",nthreads);
            printf("Initializing matrices...\n");
            }
    }
	#pragma omp section
    {
        for (i=0; i<N; i++)
            for (j=0; j<N; j++)
            a[i][j]= i+j;
    }
    #pragma omp section
    {
        for (i=0; i<N; i++)
            b[i]= i*j;
    }

	#pragma omp section
    {
        for (i=0; i<N; i++)
            c[i]= 0;
    }
    #pragma omp section
    {
        for (i=0; i<N; i++)    
		{
			printf("Thread=%d did row=%d\n",tid,i);
            for(j=0; j<N; j++)       
                c[i] += a[i][j] * b[j];
            }   
    }
  }
	//for (i=0; i<N; i++)
        //printf("%lf   ",c[i]);
   t2 = omp_get_wtime();
  printf("Execution time %g",t2-t1);

}
