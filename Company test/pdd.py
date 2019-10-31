N, M = list(map(int, input().split()))
ranges = []
for _ in range(M):
    ranges.append(list(map(int, input().split())))

# trees = [0 for _ in range(N)]
exclude=[]

def count(arr, l, r):
    for i in range(l, r):
        if arr[i] >= 1:
            continue
        else:
            arr[i] += 1

j=0
jump =False
for ran in ranges:
    L=ran[0]
    R=ran[1]
    if j>0:
        for ex in exclude:
            LL=ex[0]
            RR=ex[1]
            if L>=LL and R<=RR:
                L=0
                R=-1
                jump=True
                break
            elif L >=LL and L<=RR and R>RR:
                L=RR+1
            elif L<LL and R<=RR and R >=LL:
                R=LL-1
    j+=1
    exclude.append([L,R])
    num=0
    for ex in exclude:
        ll=ex[0]
        rr=ex[1]
        num+=rr-ll+1
        # count(trees,L-1,R)
    jump=False
    print(num)
