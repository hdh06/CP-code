n = int(input())

n -= (n % 2 == 0)
n = (n + 1)//2;

print(n*n)