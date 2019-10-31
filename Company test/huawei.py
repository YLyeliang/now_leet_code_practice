# 1
# 200以内的数字n，用4和9的加法去得到n，求组成n的最少组合。
# e.g 13  return 2, cause 9 + 4.
n=int(input())
count=0
dp=[0 for i in range(n+1)]
for i in range(1,n+1):
    if i-4>=0 and dp[i-4] >=0 and i-9>=0 and dp[i-9]>=0:
        dp[i] = min(dp[i-4],dp[i-9])+1
    elif i-4>=0 and dp[i-4] >=0:
        dp[i] =dp[i-4]+1
    elif i-9>=0 and dp[i-9]>=0:
        dp[i]=dp[i-9]+1
    else:
        dp[i]=-1

print(dp[-1])

# 2
# 编写一个简单的编译器，包括变量、加号、等于、数字

n=int(input())
cols=[]
# left=[]
# right=[]
NA=False
val={}
for i in range(n):
    cols.append(input().replace(' ',''))

def get_number(char):
    try:
        char=int(char)
    except ValueError:
        pass
    return char

for i,num in enumerate(cols):
    if NA:break
    left,right = num.split('=') # string
    if '+' in right:
        sum=0
        variables=right.split('+')
        for var in variables:
            var_tmp=get_number(var)
            if isinstance(var_tmp,int):
                sum+=var_tmp
            else:
                try:
                    sum+=val[var]
                except KeyError:
                    NA=True
        val[left]=sum
    else:
        val_right=get_number(right)
        if isinstance(val_right,int):
            val[left]=val_right
        else:
            try:
                val[left]=val[val_right]
            except KeyError:
                NA=True

if NA:
    print('NA')
else:
    print(val[left])