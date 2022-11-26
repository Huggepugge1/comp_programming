n, m, k = [int(i) for i in input().split()]

memo = {}

def prob(n, m, curr, goal):
    global memo
    if n == 0:
        if curr == goal:
            return 1
        return 0
    if curr in memo and n in memo[curr]:
        return memo[curr][n]
    if curr not in memo:
        memo[curr] = {}
    ans = 0
    for i in range(1, m + 1):
        ans += prob(n - 1, m, curr + i, goal)
    memo[curr][n] = ans
    return ans

ans = [0 for i in range(k)]
for i in range(0, n * m + 1):
    memo = {}
    curr = prob(n, m, 0, i) / m ** n
    if curr > min(ans):
        ans[ans.index(min(ans))] = curr


print(sum(ans))