# 很多数列都是递推形成的，现给出前四项，a[n]=a[n-1]+a[n-3]+a[n-4]
# 求第n项
temp = list(map(int, input().split()))
a = temp[:4]
n = temp[4]


def jump(a, n):
    for i in range(4, n):
        a += [a[i - 3] + a[i - 3] + a[i - 4]]
    return a[-1] % (10 ** 9 + 7)


print(10 ** 9 + 7)
print(jump(a, n))
