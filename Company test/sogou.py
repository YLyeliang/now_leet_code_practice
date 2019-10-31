k, rows = list(map(int, input().split()))
tree = {}
for i in range(rows):
    row = list(map(int, input().split()))
    if i == 0:
        tree['0'] = row[2:]
    else:
        tree[str(row[1])] = row[2:]

activation = list(range(rows + 1))

while True:
    temp=[]

