#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include "mpi.h"


int main(int argc, char **argv)
{
  MPI_Init(&argc, &argv);
  MPI_Barrier(MPI_COMM_WORLD);
  MPI_Finalize();
  return 0;
}
