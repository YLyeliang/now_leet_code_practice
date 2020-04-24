# 最强的不一定是最后的赢家。
#
# 某赛事有n名选手参加，但是不同于其他的比赛，本比赛采取的是擂台赛的形式，n名选手排成一排，每次队伍的第一位和第二位选手进行比赛，输的一方会排到队尾。
#
# 当某位选手取得m连胜时，他将成为最后的赢家，且游戏结束，请问截止到游戏结束，共会进行多少次比赛。
#
# 两位选手的比赛结果由他们的战斗力决定，n位选手的战斗力是一个1~n的排列，也就是说他们的战斗力两两不同，不会有平局的情况。
# 输入第一行包含两个正整数n，m，分别代表参赛选手数量和取得连胜的要求。(1<=n<=100000，1<=m<=10^9)
#
# 输入第二行包含n个正整数，中间用空格隔开，第i个数表示队伍的第i位选手的战斗力，整体是一个1~n的排列。
# 4 2
# 1 3 2 4
# out: 2

n,m=[int(i) for i in input().split()]
arr=[int(i) for i in input().split()]

def comp(arr):
    """
    whether the first greater than the second.
    """
    return arr[0]>arr[1]

def solve():
    continuity = 0
    count = 0

    while not continuity==m:
        if count==0:
            if comp(arr):
                arr.append(arr[1])
                arr.pop(1)
            else:
                arr.append(arr[0])
                arr.pop(0)
            count += 1
            continuity+=1
            continue

        if comp(arr):
            continuity+=1
            arr.append(arr[1])
            arr.pop(1)
        else:
            continuity=1
            arr.append(arr[0])
            arr.pop(0)
        count+=1

    return count