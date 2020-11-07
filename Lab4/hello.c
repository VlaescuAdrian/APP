#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
   int np,pid,proc_name_len;

    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &pid); 
    MPI_Comm_size(MPI_COMM_WORLD, &np); 

    char processor_name[MPI_MAX_PROCESSOR_NAME];

    MPI_Get_processor_name(processor_name, &proc_name_len);

    printf("Hello world from processor %s, pid %d out of %d processors\n", processor_name, pid, np);
    MPI_Finalize();
}