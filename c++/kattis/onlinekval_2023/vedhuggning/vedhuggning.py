n, m = [int(i) for i in input().split()]
k = []
for i in range(n):
    k.append([int(i) for i in input().split()])

def s(k, i):
    return sum(map(lambda x: x[0] + x[1] * min(x[2], i), k))

if s(k, 0) >= m:
    print(0)
    exit(0)

l = 0
h = 1000000000000
while l + 1 < h:
    mid = int((h + l) / 2)
    if s(k, mid) < m:
        l = mid
    else:
        h = mid
print(h)