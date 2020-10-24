# In LeetCode Store, there are some kinds of items to sell. Each item has a price.
#
# However, there are some special offers, and a special offer consists of one or more different kinds of items with a
# sale price.
#
# You are given the each item's price, a set of special offers, and the number we need to buy for each item. The job
# is to output the lowest price you have to pay for exactly certain items as given, where you could make optimal use
# of the special offers.
#
# Each special offer is represented in the form of an array, the last number represents the price you need to pay for
# this special offer, other numbers represents how many specific items you could get if you buy this offer.
#
# You could use any of special offers as many times as you want.
#
# Example 1:
# Input: [2,5], [[3,0,5],[1,2,10]], [3,2]
# Output: 14
# Explanation:
# There are two kinds of items, A and B. Their prices are $2 and $5 respectively.
# In special offer 1, you can pay $5 for 3A and 0B
# In special offer 2, you can pay $10 for 1A and 2B.
# You need to buy 3A and 2B, so you may pay $10 for 1A and 2B (special offer #2), and $4 for 2A.
# Example 2:
# Input: [2,3,4], [[1,1,0,4],[2,2,1,9]], [1,2,1]
# Output: 11
# Explanation:
# The price of A is $2, and $3 for B, $4 for C.
# You may pay $4 for 1A and 1B, and $9 for 2A ,2B and 1C.
# You need to buy 1A ,2B and 1C, so you may pay $4 for 1A and 1B (special offer #1), and $3 for 1B, $4 for 1C.
# You cannot add more items, though only $9 for 2A ,2B and 1C.
# Note:
# There are at most 6 kinds of items, 100 special offers.
# For each item, you need to buy at most 6 of them.
# You are not allowed to buy more items than you want, even if that would lower the overall price.


# 问题：给定三个输入price, special, needs. 其中Price为数字list，表示索引为i的物品的价格，special为一个list(list),
# 其中每个List为打包价格，list中最后一个数字表示花多少钱能买多少物品。needs为我们的需求。
# 求怎样花最少的钱达到needs. 不能买超过需求的数量。

# 分析：考虑首先使用单价的方式进行购买。购买完毕之后，利用DFS方法，使用special中的打包价进行替换，来对比价格。同时，将数量：价格存入memo，
# 减少重复计算，
#
from typing import List


class Solution:
    def shoppingOffers(self, price: List[int], special: List[List[int]], needs: List[int]) -> int:
        d = {}

        def dfs(cur):
            val = sum(cur[i] * price[i] for i in range(len(needs)))  # cost without special
            for spec in special:
                tmp = [cur[j] - spec[j] for j in range(len(needs))]
                if min(tmp) >= 0:  # skip deals that exceed needs
                    val = min(val, d.get(tuple(tmp), dfs(tmp)) + spec[
                        -1])  # .get check the dictionary first for result, otherwise perform dfs.
            d[tuple(cur)] = val
            return val

        return dfs(needs)
