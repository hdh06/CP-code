s = input().lower().split()
for x in s:
    print(x[: 1].upper() + x[1: ], end = " ")
