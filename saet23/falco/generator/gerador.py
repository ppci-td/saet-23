import random
import string

def generate_random_string(length):
    characters = string.ascii_lowercase  # Only lowercase ASCII letters
    random_string = ''.join(random.choice(characters) for _ in range(length))
    return random_string



def generate_random_integer(min_value, max_value):
    if min_value > max_value:
        min_value, max_value = max_value, min_value  # Swap values if min_value is greater than max_value
    return random.randint(min_value, max_value)


def create_file(filename, number1, number2, some_string):
    with open(filename, 'w') as file:
        file.write(f"{number1} {number2}\n{some_string}\n")

# Example usage: Create 5 files with different content
for i in range(5):
    filename = f'in_{i + 1}.in'
    k = generate_random_integer(1, 999999)
    l = generate_random_integer(1, 99)
    some_string = generate_random_string(l)
    create_file(filename, k, l, some_string)


