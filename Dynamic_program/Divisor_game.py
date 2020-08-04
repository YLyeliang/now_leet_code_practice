# Alice and Bob take turns playing a game, with Alice starting first.
#
# Initially, there is a number N on the chalkboard.  On each player's turn, that player makes a move consisting of:
#
# Choosing any x with 0 < x < N and N % x == 0.
# Replacing the number N on the chalkboard with N - x.
# Also, if a player cannot make a move, they lose the game.
#
# Return True if and only if Alice wins the game, assuming both players play optimally.
#
#
#
# Example 1:
#
# Input: 2
# Output: true
# Explanation: Alice chooses 1, and Bob has no more moves.
# Example 2:
#
# Input: 3
# Output: false
# Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more moves.
#
#
# Note:
#
# 1 <= N <= 1000

# A & B轮流玩游戏，A先手。刚开始时桌上有一个数字N，每个玩家做的动作是：选择一个x满足 0 < x < N且 N % x ==0. 然后剩下 N-x.
# 当一个玩家做不到这一步时，则输了游戏。 A 赢时返回True，每个人都是最优玩法。

# 分析：由于每次选择的数都是需要能够整除，
# 贴一个大佬的解释：prove it by two steps:
#
# if Alice will lose for N, then Alice will must win for N+1, since Alice can first just make N decrease 1.
# for any odd number N, it only has odd factor, so after the first move, it will be an even number
# let's check the inference
# fisrt N = 1, Alice lose. then Alice will must win for 2.
# if N = 3, since all even number(2) smaller than 3 will leads Alice win, so Alice will lose for 3
# 3 lose -> 4 win
# all even number(2,4) smaller than 5 will leads Alice win, so Alice will lose for 5
# ...
#
# Therefore, Alice will always win for even number, lose for odd number.


class Solution:
    def divisorGame(self, N: int) -> bool:
        return N%2==0


