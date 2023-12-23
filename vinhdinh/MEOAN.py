s = list(map(int, input().split()))

maxx = max(s)
ans = 0
for x in s:
    ans += maxx - x
print(ans)
