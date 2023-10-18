import random

# Número de magias disponíveis
N = 10

# Número de monstros na raid
M = 5

# Gere magias aleatórias (valores de dano)
magias = [random.randint(1, 100) for _ in range(N)]

# Gere HP aleatórios para os monstros
monstros = [random.randint(1, 100) for _ in range(M)]

# Salve as entradas em um arquivo .in
with open("input.in", "w") as f:
    f.write(f"{N} {M}\n")
    f.write(" ".join(map(str, magias)) + "\n")
    f.write(" ".join(map(str, monstros)) + "\n")
