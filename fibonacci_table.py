def fibonacci(n):
    assert n >= 0

    fp = 0
    fn = 1

    if n < 2:
        return n

    for i in range(n - 1):
            fn, fp = fn + fp, fn

    return fn


for i in range(101):
    print "#", i, " ", fibonacci(i)
