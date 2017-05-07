from operator import itemgetter

segments = []

class Segment(object):
    def __init__(self, left, right):
        self.left = left
        self.right = right

    def __getitem__(self, key):
        return self.left if key == "left" else None

    def intersection(self, segment):
        if segment.left <= self.right:
            if segment.right > self.right:
                return Segment(segment.left, self.right)
            else:
                return segment
        else:
            return None
        
def main():
    n = int(input())

    for i in range(n):
        a, b = map(int, input().split())
        segments.append(Segment(a, b))

    segments.sort(key=itemgetter("left"))

    result = []
    
    while segments:
        current_segment = segments.pop(0)
        
        while segments:
            temp_segment = current_segment.intersection(segments[0])
            if temp_segment:
                current_segment = temp_segment
                segments.pop(0)
            else:
                result.append(current_segment.right)
                break
        else:
            result.append(current_segment.right)

    print(len(result))
    for dot in result:
        print(dot, end=' ')
    else:
        print()

if __name__ == "__main__": main()
