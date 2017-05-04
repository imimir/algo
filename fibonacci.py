def memo(f):
    cache = {}

    def inner(n):
        if n not in cache:
            cache[n] = f(n)
        return cache[n]

    return inner

def fibonacci(n):
    assert n >= 0
    return n if n < 2 else fibonacci(n - 1) + fibonacci(n - 2)

fibonacci = memo(fibonacci)

for i in range(100):
    print "# ", i, " ", fibonacci(i)
