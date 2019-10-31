import math
n = int(input())
array = []
for _ in range(n):
    array.append(list(map(int,input().split())))

def factorial(t):
    for i in range(1,t):
        t*=i
    return t

def power(a,t):
    return a**t

def log_add(a,t):
    tmp=0
    for i in range(1,t+1):
        tmp+=math.log(i,a)
    return tmp

for arr in array:
    # log=log_add(arr[0],arr[1])
    # if log> arr[1]:
    #     print(math.factorial(arr[1])%9999991)
    # else:
    #     print(pow(arr[0],arr[1])%9999991)
    fac = int(math.sqrt(2*math.pi*arr[1])*pow(arr[1]/math.e,arr[1])*(1+1/12/arr[1]+1/288/arr[1]**2))
    maximum=max(fac,pow(arr[0],arr[1]))
    print(maximum%9999991)