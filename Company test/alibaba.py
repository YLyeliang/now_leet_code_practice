def question1():
    n,m,k=[int(x) for x in input().split()]
    a=[int(x) for x in input().split()]

    num=sum(a)
    for i in range(m):
        max=a[0]
        index=0
        for j in range(len(a)):
            a[j]+=k
            if a[j]>max:
                max=a[j]
                index=j
        num=num+n*k-
    print(sum(a))

def question2():
    n=int(input())
    arr=[int(x) for x in input().split()]



# question1()
question2()
