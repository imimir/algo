def gcd(a, b):
    assert a >=0 and b >= 0

    if a == 0 or b == 0:
        return max(a, b) 

    return gcd(b % a, a)

a = int(input())
b = int(input())

print(gcd(a, b))
