import random
import os

cur_dir = os.path.dirname(__file__)

def gen_random(k, gen): 
    # random N
	N = random.randint(2, k)
	inout_dir = os.path.join(cur_dir, f'../inout/in_{gen}.in')
	# print(inout_dir)
	f = open(inout_dir, "w")
	f.write(f'{N}\n')

	used = []
	not_used = list(range(1, N+1))

	not_used.remove(1)
	used.append(1)

	# print(not_used)
	# random pairs
	for i in range(1, N):
		a = random.choice(used)
		b = random.choice(not_used)
		f.write(f'{a} {b}\n')
		not_used.remove(b)
		used.append(b)
	f.close()
 
# Short

for i in range(2):
	gen_random(10, i)
# Medium
for i in range(2, 7):
	gen_random(20, i)
# Large
for i in range(7, 9):
	gen_random(100, i)
# Extra large
for i in range(9, 12):
	gen_random(1000, i)