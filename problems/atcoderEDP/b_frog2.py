import sys

n, jL = map(int, input().split())
values = list(map(int, input().split()))

dp = [sys.maxsize]*n
dp[0] = 0

for i in range(n):
    for j in range(i + 1, i + jL + 1):
        if j < n:
            dp[j] = min(dp[j], dp[i]+abs(values[i]-values[j]))

print(dp[n-1])