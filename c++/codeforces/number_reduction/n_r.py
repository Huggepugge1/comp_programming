def s(n, k):
    if k == 0: return n
    sn = str(n)
    l = 0
    m = 10000000000
    if sn[1] == "0":
        l = 1
        if len(sn) == 2:
            return int(sn[0])
    for i in range(l, len(sn)):
        if i == len(sn) - 1:
            if sn[i] >= sn[i - 1]:
                m = min(s(int(sn[:i-1] + sn[i]), k - 1), m)
        elif sn[i] >= sn[i + 1] and len(sn) > 2:
            m = min(s(int(sn[:i] + sn[i + 1:]), k - 1), m)
        elif len(sn) == 2:
            return int(min(sn[0], sn[1]))
    if m == 10000000000: return n
    return m

n = int(input())
for i in range(n):
    print(s(int(input()), int(input())))