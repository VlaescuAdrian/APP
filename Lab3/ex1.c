#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100000000
float a[N], b[N],c[N],d[N];

int main (int argc, char *argv[]) 
{
    int i;
    double t1,t2;
	t1 = omp_get_wtime();
	
	#pragma omp parallel
	{
		#pragma omp sections
			{
				#pragma omp section
				{
					for (i=0; i<N; i++) {
						a[i] = log(i)/log(2);
					}
				}
				#pragma omp section
				{
					for (i=0; i<N; i++) {
						b[i] = log(N - i)/log(2);
					}
				}
				#pragma omp section
				{
					for (i=0; i<N; i++) {
						c[i] = a[i] * b[i];
					}
				}
				#pragma omp section
				{
					for (i=0; i<N; i++) {
						d[i] = a[i]/b[i];
					}
				}
		}
    }
    t2 = omp_get_wtime();

    printf("Duration %g\n",t2-t1);

    return 0;
}
