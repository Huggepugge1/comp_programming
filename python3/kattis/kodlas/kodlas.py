d = {".": "1", "#": "0"}
n, m = [int(i) for i in input().split()]

disks = []
for j in range(n):
    disks.append([int(''.join(list(map(lambda x: d[x], input()))), 2)])

def rot(n):
    return ((n >> 1) | (n << m - 1)) & ((1 << m) - 1)

def combine(n1, n2):
    memo = {}
    l = []
    for i in n1:
        if i in memo:
            for j in memo[i]:
                l.append(j)
            continue
        mem = []
        for j in range(m):
            i = rot(i)
            if i & n2 != 0:
                mem.append(i & n2)
                l.append(i & n2)
        memo[i] = [*mem]
    return l

for i in range(1, n):
    disks[i] = combine(disks[i-1], disks[i][0])

print(len(disks[-1])*m)
