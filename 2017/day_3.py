from collections import defaultdict
from itertools import count

def sum_spiral():
    a = defaultdict(int)
    sn = lambda i,j: sum(a[k,l] for k in range(i-1,i+2) for l in range(j-1,j+2))
    a[0, 0], i, j = 1, 0, 0
    for s in count(1, 2):
        for _ in range(s):   i += 1; a[i,j] = sn(i,j); yield a[i,j]
        for _ in range(s):   j -= 1; a[i,j] = sn(i,j); yield a[i,j]
        for _ in range(s+1): i -= 1; a[i,j] = sn(i,j); yield a[i,j]
        for _ in range(s+1): j += 1; a[i,j] = sn(i,j); yield a[i,j]

def part2(n):
    for x in sum_spiral():
        if x>n: return x

def part1(goal):
    x = y = dx = 0
    dy = -1
    step = 0

    while True:
        step += 1
        if goal == step:
            return abs(x) + abs(y)
        if (x == y) or (x < 0 and x == -y) or (x > 0 and x == 1-y):
            dx, dy = -dy, dx
        x, y = x+dx, y+dy

# print(part1(368078))
print(part2(368078))

