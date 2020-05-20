# leetcode 56题：给出一个区间的集合，请合并所有重叠的区间。
# In: [[1,3],[2,6],[8,10],[15,18]]
# Out: [[1,6],[8,10],[15,18]]
# ps: [1,3] [2,6]重叠
# In: [[1,4],[4,5]]
# Out: [[1,5]]

# 思路:先排序，后检查规律
# 一个区间可以表示为[start,end]，可以对start排序，然后确定重叠区间中最大的end。
def merge(intervals):
    if not intervals: return []
    # 按区间的start升序
    intervals.sort(key=lambda elem: elem[0])
    res=[]
    res.append(intervals[0])

    for i in range(1,len(intervals)):
        curr=intervals[i]
        # res中最后一个元素的调用
        last = res[-1]
        if curr[0]<= last[1]:
            # 找到最大的end
            last[1]=max(last[1],curr[1])
        else:
            #继续处理下一个区间
            res.append(curr)
    return res

inter=[[1,3],[2,6],[8,10],[15,18]]
print(merge(inter))



