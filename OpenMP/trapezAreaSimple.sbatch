#!/bin/bash
#SBATCH --job-name=trapezAreaSimple
#SBATCH --output=trapezAreaSimple_output.txt
#SBATCH --ntasks=1
#SBATCH --nodes=1
#SBATCH --time=00:05:00
#SBATCH --mem=100
#SBATCH --cpus-per-task=4

module load gcc/9.3.0
export OMP_NUM_THREADS=$SLURM_CPUS_PER_TASK

srun ./omp_trapezAreaSimple
