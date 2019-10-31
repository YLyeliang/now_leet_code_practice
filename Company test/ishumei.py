
# question 1:

string=[]
with open("keyword.conf","r") as f:
    while True:
        line=f.readline()
        if not line:
            break
        line=line.rstrip()
        string.append(line)

file=open("input.txt","r")
while True:
    line=file.readline()
    if not line:
        break
    word,text=line.split(" ")
    for i in string:
        if i in word:
            print("{} {}".format(word,text))
debug=1




# question 2: There are 1 million numbers in input.txt, one per row, need to
# statistic [0,99], ....[99900,99999], the frequency .
# freq = [0 for i in range(1000)]
# with open("input.txt","r") as f:
#     while True:
#         line = f.readline()
#         if not line:
#             break
#         num = int(line)
#         index= num//100
#         freq[index]+=1
# f.close()
# for id,parent in enumerate(freq):
#     print("{}-{} {}".format(id*100,id * 100 + 99,parent))

# question 4:

# import math
# dic={}
# nums=0
# with open("input.txt","r") as f:
#     while True:
#         line=f.readline()
#         if not line:
#             break
#         deviceid, mac, t = line.split(" ")
#         if mac not in dic:
#             dic[mac]=1
#         else:
#             dic[mac]+=1
#         nums+=1
#
# prob_list=[0 for i in range(len(dic))]
# entropy=0
# for i,wifimac in enumerate(dic):
#     num=dic[wifimac]
#     prob=num/nums
#     log2=math.log(prob,2)
#     entropy-=prob*log2
# print("{} {}".format(deviceid,entropy))






