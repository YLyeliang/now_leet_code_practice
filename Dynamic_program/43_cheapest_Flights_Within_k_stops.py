# There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi,
# toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.
#
# You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops.
# If there is no such route, return -1.
#
#
#
# Example 1:
#
#
# Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
# Output: 200
# Explanation: The graph is shown.
# The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.
# Example 2:
#
#
# Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
# Output: 500
# Explanation: The graph is shown.
# The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.
#
#
# Constraints:
#
# 1 <= n <= 100
# 0 <= flights.length <= (n * (n - 1) / 2)
# flights[i].length == 3
# 0 <= fromi, toi < n
# fromi != toi
# 1 <= pricei <= 104
# There will not be any multiple flights between two cities.
# 0 <= src, dst, k < n
# src != dst

# 问题：给定数组flights,flights[i] = [from_i,to_i,price_i]表示从from到to,价格为price.给定三个整数src, dst, k,
# 返回从src到dst with most k stops的最低价格，如果没有返回-1.

# 分析：DP方法，该问题为有向权图问题，采用BFS+DP方法。每个顶点到另一个顶点的的消耗已知，可以建立seen[i]表示从src到i时的最低消耗。
# k为可经停次数。整体思想是：遍历每个顶点的路径，逐步更新seen[i]的值，当seen[i]的值大于经停顶点到该顶点的最小消耗时，更新价格。


import collections


class Solution(object):
    def findCheapestPrice(self, n, flights, src, dst, K):
        if src == dst: return 0
        d, seen = collections.defaultdict(list), collections.defaultdict(lambda: float('inf'))
        for u, v, p in flights:
            d[u] += [(v, p)]

        q = [(src, -1, 0)]

        while q:
            pos, k, cost = q.pop(0)
            if pos == dst or k == K: continue
            for nei, p in d[pos]:
                if cost + p >= seen[nei]:
                    continue
                else:
                    seen[nei] = cost + p
                    q += [(nei, k + 1, cost + p)]

        return seen[dst] if seen[dst] < float('inf') else -1


n = 3
flights = [[0, 1, 100], [1, 2, 100], [0, 2, 500]]
src = 0
dst = 2
k = 1
sol = Solution()
sol.findCheapestPrice(n, flights, src, dst, k)
