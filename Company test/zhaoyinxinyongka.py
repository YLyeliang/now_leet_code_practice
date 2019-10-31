# 题目：给定字符串，只包含R和L，第一个和最后一个必定是R，L
# 所有的位置上都有一个机器人，R表示右移，L表示左移
# 问移动10^100次后，每个位置上有多少机器人

s = input()
length = len(s)
# 因为是移动偶数次，如果是连续相同的字符，则前面N个字符不存在机器人，
# 最后只会在LR交叉的地方存在机器人
out = [0 for _ in range(length)]

R_count = 0
L_count = 0
L_first = True
R_first = True
for i in range(length - 1):
    if s[i] == 'R' and s[i + 1] == 'R':
        if R_first:
            R_first = False
        R_count += 1
    elif s[i] == 'R' and s[i + 1] == 'L':
        if not R_first:
            R_first = True
            R = R_count // 2
            L = R_count - R
            out[i] += R + 1  # 将连续的RRRR左边的R最后归为到R的统计到该位置上
            out[i + 1] += L  # 将连续的RRR左边的R最后归位到L的统计到该位置上
            R_count = 0
        else:
            out[i] += 1
            if i == length - 2: out[i + 1] += 1
    elif s[i] == 'L' and s[i + 1] == 'L':
        if L_first:  # 连续的LLL中第一个L的地址
            id_l = i
            L_first = False
        L_count += 1
        if i==length - 2:
            L = L_count // 2
            R = L_count - L
            out[id_l] += L + 1
            out[id_l - 1] += R
    elif s[i] == 'L' and s[i + 1] == 'R':
        if not L_first:  # 如果是连续的LLL中的最后一个L
            L_first = True
            L = L_count // 2
            R = L_count - L
            out[id_l] += L + 1
            out[id_l - 1] += R
            L_count=0
        else:
            out[i] += 1

out = map(str, out)
output = " ".join(out)
print(output)
#
# debug = 1

# 题目：给定字符串由0-9 ？组成，
# ?可由0-9填上，问模13余5的数有多少种情况， 有前导0的情况存在
s=input()
