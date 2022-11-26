a = int(input())
b = 111111111111111
c = 0
while a > 0:
    if a - b >= 0:
        c += 1
        a -= b
    else:
        b //= 10
print(c)
