n = int(input())
p = input()
xs = []

for x in range(n):
    xs.append(list(int(i) for i in input().split()))

for x in xs:
    x.append(sum(x))

m = max([k for i, j, k in (x for x in xs)])

ys = list(map(lambda x: x if x[2] == m else [], xs))

if p == "antal":
    a = 0
    b = 0
    for x in range(len(ys)):
        if len(ys[x]) > 0 and a < ys[x][0]:
            a = ys[x][0]
            b = x + 1

else:
    a = 0
    b = 0
    for x in range(len(ys)):
        if a < ys[x][1]:
            a = ys[x][1]
            b = x + 1

print(b)
