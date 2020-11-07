#include <stdio.h>
#include <omp.h>
#define N 10000000
int a[N];
int main(void) {

    int i;
    for (i=0;i<N;i++)
        a[i] = 1;

    double t1, t2;
    int sum = 0;
    int from, to;

    t1 = omp_get_wtime();
    #pragma omp parallel default(shared) private(i)
    {
        
        int psum = 0;
        #pragma omp for
        for(i = 0; i < N; i++)
            psum += a[i];


        #pragma omp critical
            sum += psum;
    }
    t2 = omp_get_wtime();
    
    printf("Sum=%ld, duration=%g\n",sum,t2-t1);
    return 0;
}
