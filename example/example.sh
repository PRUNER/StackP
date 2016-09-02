LD_PRELOAD=./libpmpi123.so srun -n 2 ./mpi-main
LD_PRELOAD=./libpmpi12.so srun -n 2 ./mpi-main
LD_PRELOAD=./libpmpi13.so srun -n 2 ./mpi-main
LD_PRELOAD=./libpmpi23.so srun -n 2 ./mpi-main
