def gcd(a, b):
    assert a >=0 and b >= 0

    if a == 0:
        return b
    elif b == 0:
        return a

    return gcd(a % b, b) if a > b else gcd(b % a, a)


a = int(input())
b = int(input())

print(gcd(a, b))
