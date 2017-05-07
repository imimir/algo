from operator import itemgetter

class Bar(object):
    def __init__(self, c, w):
        self.cost = c
        self.w = w

    def profit(self):
        return self.cost / self.w if self.w != 0 else 0.0

    def __getitem__(self, key):
        return self.profit() if key == "profit" else None

def main():
    current_w = 0
    current_c = 0
    Bars = []

    n, W = map(int, input().split())
    assert n >=1 and W >= 0

    i = 0
    while i < n:
        c, w = map(int, input().split())
        assert c >= 0 and w >= 0

        Bars.append(Bar(c, w))
        i += 1

    Bars.sort(key=itemgetter("profit"))

    while Bars and current_w < W:
        empty_w = W - current_w

        bar = Bars.pop()
        add_w = bar.w if empty_w > bar.w else empty_w

        current_w += add_w
        current_c += add_w * bar.profit()
        
    print(current_c)

if __name__ == "__main__": main()
