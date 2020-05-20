#leetcode 986:
# 给定两个由一些闭区间组成的列表，每个区间列表都是成对不相交的，并且已经排序。
# 返回这俩区间列表的交集。
# e.g In: A=[[0,2],[5,10],[13,23],[24,25]] B=[[1,5,],[8,12],[15,24],[25,26]]
# Out: [[1,2],[5,5],[,8,10],[15,23],[24,24],[25,25]]

# 思路：
# 一般是先排序后进行操作，但是给定的数组已经排序好了。则可以使用两个索引在A和B之间游走，找出交集。

def intervalIntersection(A,B):
    i,j=0,0
    res=[]
    while i<len(A) and j<len(B):
        # ...
        j+=1
        i+=1
    return res

# 什么情况下不存在交集？区间[a1,a2], [b1,b2]
# if b2 < a1 or a2 < b1

# 什么情况下存在交集？对上述取反即可。
# if b2>=a1 and a2>=b1
# 判断条件之后，如何取交集？ 很简单，[c1,c2]为交集，c1=max(a1,b1) c2=min(a2,b2)

# 最终代码
def intervalIntersection(A,B):
    i,j=0,0
    res=[]
    while i<len(A) and j<len(B):
        a1,a2=A[i][0],A[i][1]
        b1,b2=B[i][0],B[i][1]
        if b2>=1a and a2>=b1:
            c1=max(a1,b1)
            c2=max(a2,b2)
            res.append([c1,c2])
        if b2< a2:
            j+=1
        else:
            i+=1
    return res


