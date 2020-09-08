# We are playing the Guess Game. The game is as follows:
#
# I pick a number from 1 to n. You have to guess which number I picked.
#
# Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.
#
# However, when you guess a particular number x, and you guess wrong, you pay $x.
# You win the game when you guess the number I picked.
#
# Example:
#
# n = 10, I pick 8.
#
# First round:  You guess 5, I tell you that it's higher. You pay $5.
# Second round: You guess 7, I tell you that it's higher. You pay $7.
# Third round:  You guess 9, I tell you that it's lower. You pay $9.
#
# Game over. 8 is the number I picked.
#
# You end up paying $5 + $7 + $9 = $21.
# Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.

# 问题：玩一个游戏：我从1-n中选择一个数，你来猜我选中了哪个数字。每次猜错，我告诉你我选择的数是大了还是小了。但是你当你猜一个数字x时，如果错了就需要支付x元，直到猜对。
# 给定n>=1,找到保证能赢需要支付的金钱。
# 分析：如果选择x belong to [i,j],则result_x = x+ max(DP[i,x-1],DP[x+1,j])
# TODO: waiting for complete.

class Solution:
    def getMoneyAmount(self, n: int) -> int:


