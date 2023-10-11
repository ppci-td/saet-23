import os

N = int(1e5)

cur_dir = os.path.dirname(__file__)
inout_file = os.path.join(cur_dir, f'../inout/in_12.in')
f = open(inout_file, "w")
f.write(str(N)+'\n')

for i in range(1, N-1):
	f.write(f'{i} {i+1}\n')
	continue

f.close()