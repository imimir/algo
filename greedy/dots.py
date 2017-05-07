from random import randint

dots = [randint(0, 100) for i in range(20)]

print(sorted(dots))

def solve(dots):
    result = []
    sorted_dots = sorted(dots)
    
    counter = 0
    while counter < len(dots):
        segment = [dots[counter], dots[counter] + 5]
        print("Segment: ", segment)
        result.append(segment)

        counter += 1
        while counter < len(dots):
            if segment[0] <= dots[counter] <= segment[1]:
                counter += 1
            else:
                break

    return result

print(solve(sorted(dots)))
