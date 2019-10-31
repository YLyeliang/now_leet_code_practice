x=int(input())
y=int(input())
z=int(input())
A=[]
B=[]
for _ in range(x):
    A.append(list(map(int,input().split())))
for _ in range(y):
    B.append(list(map(int,input().split())))


C=[['']*z for _ in range(x)]
for i in range(x):
    for j in range(z):
        C[i][j]=str(sum([A[i][k]*B[k][j] for k in range(y)]))

for l in range(x):
    print(" ".join(C[l]))