inputs=input().replace(' ','')[1:-1]
arr = list(map(int, input().split()))

max_num = arr[0]
temp = 0
for i in range(len(arr)):
    if temp >= 0:
        temp += arr[i]
        max_num = max(temp, max_num)
    else:
        temp = arr[i]

print(max_num)