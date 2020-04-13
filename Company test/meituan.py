
def minop():
    n,x=[int(i) for i in input().split()]
    arr=[int(i) for i in input().split()]
    dp=[]

    op=0
    while max(arr)-min(arr)>x:
        id1=arr.index(min(arr))
        id2=arr.index(max(arr))
        tmp1=arr[:]
        tmp2=arr[:]
        del tmp1[id1]
        del tmp2[id2]
        if max(tmp1)-min(tmp1) < max(tmp2)-min(tmp2):
            del arr[id1]
        else:
            del arr[id2]
        op+=1
    print(op)

def sumrange(arr,i,j):
    return arr[j]-arr[i]

def circle():
    n,m=[int(i) for i in input().split()]
    cost=[int(i) for i in input().split()]
    dp=[0]
    for i in range(len(cost)):
        dp.append(cost[i]+dp[i])
    num=0
    i = 0
    j = n
    while m>=min(cost):
        if sumrange(dp,i,j)<=m:
            num+=n
            m-=sumrange(dp,i,j)
            i=0
            j=n
        else:
            while not i==n:
                j-=1
                if i==j:
                    i+=1
                    j=n
                if sumrange(dp,i,j)<=m:
                    num+=j-i
                    m-=sumrange(dp,i,j)
                    i=j
                    j=n+1

    print(num)

def maxrange(dp,i,j):
    value=0
    for id in range(i,j):
        value=max(dp[id],value)
    return value
n=int(input())
p=[float(i) for i in input().split()]
a=[int(i) for i in input().split()]
dp=[p[i]*a[i] for i in range(n)]
score=[]
score_p=[]
index=0
while n>0:
    max_sc=maxrange(dp,0,n)
    k=dp.index(max_sc)
    n=n-k-1
    if index==0:
        score.append(max_sc)
        score_p.append(p[k])
    else:
        score.append(max_sc*score_p[-1])
        score_p.append(p[k]*score_p[-1])
    index+=1
print('{:.2f}'.format(sum(score)))
