n = int(input())
m = int(input())

l = [int(i) for i in input().split()]

p1, p2 = 0, len(l) - 1
ans = 0

while p1 != p2:
    if l[p1] * l[p2] < n:
        p1 += 1
    else:
        p2 -= 1
        ans += 1
        
print(ans)
