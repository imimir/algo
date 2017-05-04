from functools import lru_cache

def fibonacci(n):
    assert n >= 0
    return n if n < 2 else fibonacci(n - 1) + fibonacci(n - 2)

fibonacci = lru_cache(maxsize = None)(fibonacci)

for i in range(100):
    print("# ", i, " ", fibonacci(i))
