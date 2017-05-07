from math import sqrt

def main():
    n = int(input())
    assert n >= 1

    D = sqrt(1 + 8 * n)
    x = (-1 + D) / 2

    if int(x) == x:
        x = int(x)
        print(x)
        [print(i, end=" ") if i < x else print(i) for i in range(1, x + 1)]
    else:
        m = int(x) + 1
        m_sum = (m**2 + m) // 2
        diff = m_sum - n
        print(m - 1)
        for i in range(1, m + 1):
            if i != diff:
                if i != m:
                    print(i, end=" ")
                elif i == m:
                    print(i)
            
if __name__ == "__main__": main()
