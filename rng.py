import random

def generate():
    numbers = set()
    while len(numbers) < 5:
        numbers.add(random.randint(100, 999))
    return list(numbers)

numbers = generate()
random.shuffle(numbers)
for num in numbers:
    print(num, end=' ')