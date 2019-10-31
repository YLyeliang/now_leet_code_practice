x,y,n=list(map(int,input().split()))
obstacle=[]
for _ in range(n):
    obstacle.append(list(map(int,input().split())))

# xmin=0
# xmax=0
# ymin=0
# ymax=0
# for i in obstacle:
#     xmin=min(i[0],xmin)
#     ymin=min(i[1],ymin)
#     xmax=max(i[0],xmax)
#     ymax=max(i[1],ymax)


# width =xmax - xmin+2
# height=ymax-ymin+2


arr=[[0]*1000 for _ in range(1000)]
for i in obstacle:
    x_i,y_i=i
    x_i+=500
    y_i+=500
    arr[x_i][y_i]=1

x+=500
y+=500

def passObstacle(x,y):
    x0=499
    y0=499


