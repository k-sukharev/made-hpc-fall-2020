import random

from mpi4py import MPI

N = 4

comm = MPI.COMM_WORLD
rank = comm.Get_rank()
size = comm.Get_size()

ranks = list(range(0, size))

if rank == 0:
    ranks.remove(rank)
    dest = random.choice(ranks)
    data = [rank]
    comm.send(data, dest=dest)
    print(f"Process {rank}:", "Game started")
else:
    ranks.remove(rank)
    data = comm.recv()
    print(f"Process {rank}:", data)

    for other_rank in data:
        ranks.remove(other_rank)

    if ranks and len(data) < N - 1:
        dest = random.choice(ranks)
        data.append(rank)
        comm.send(data, dest=dest)
    else:
        print(f"Process {rank}:", "Game finished")
