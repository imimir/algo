def fibonacci(n):
    assert n >= 0

    if n < 2:
        return n
    else:
        return fibonacci(n - 1) + fibonacci(n - 2)
fibonacci(-1)
for i in range(100):
    print "# ", i, " ", fibonacci(i)
