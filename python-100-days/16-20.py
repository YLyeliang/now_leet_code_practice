import sys
import time


# Exhaustive method(穷举法）
class Exhaustive(object):
    # 公鸡5元一只 母鸡3元一只 小鸡1元三只
    # 用100元买100只鸡 问公鸡/母鸡/小鸡各多少只
    # ps. x,y,z 5x=100 =>x=20 ...y=33 z =100-x-y
    @staticmethod
    def chicken():
        for x in range(20):
            for y in range(33):
                z = 100-x-y
                if 5*x+3*y+z/3==100:
                    print(x,y,z)

    # A、B、C、D、E五人在某天夜里合伙捕鱼 最后疲惫不堪各自睡觉
    # 第二天A第一个醒来 他将鱼分为5份 扔掉多余的1条 拿走自己的一份
    # B第二个醒来 也将鱼分为5份 扔掉多余的1条 拿走自己的一份
    # 然后C、D、E依次醒来也按同样的方式分鱼 问他们至少捕了多少条鱼
    @staticmethod
    def fish():
        fish = 6
        while True:
            total = fish
            enough = True
            for _ in range(5):
                if (total - 1) % 5 == 0:
                    total = (total - 1) // 5 * 4
                else:
                    enough = False
                    break
            if enough:
                print(fish)
                break
            fish += 5

# Greedy method
class Greedy(object):
    #贪婪法例子：假设小偷有一个背包，最多能装20公斤赃物，他闯入一户人家，发现如下表所示的物品。
    # 很显然，他不能把所有物品都装进背包，所以必须确定拿走哪些物品，留下哪些物品。
    """
    贪婪法：在对问题求解时，总是做出在当前看来是最好的选择，不追求最优解，快速找到满意解。
    输入：
    20 6
    名称  价格 重量
    电脑 200 20
    收音机 20 4
    钟 175 10
    花瓶 50 2
    书 10 1
    油画 90 9
    """
    class Thing(object):
        def __init__(self,name,price,weight):
            self.name=name
            self.price=price
            self.weight=weight

        @property
        def value(self):
            """价格重量比"""
            return self.price / self.weight

        @staticmethod
        def input_thing():
            """输入物品信息"""
            name_str, price_str, weight_str = input().split()
            return name_str, int(price_str), int(weight_str)

    def run(self):
        """主函数"""
        max_weight, num_of_things = map(int, input().split())
        all_things = []
        for _ in range(num_of_things):
            all_things.append(self.Thing(*self.Thing.input_thing()))
        all_things.sort(key=lambda x: x.value, reverse=True)
        total_weight=0
        total_price=0
        for thing in all_things:
            if total_weight + thing.weight <=max_weight:
                print(f'小偷拿走了{thing.name}')
                total_weight += thing.weight
                total_price+=thing.price
        print(f'总价值:{total_price}美元')

"""
快速排序 - 选择枢轴对元素进行划分，左边都比枢轴小右边都比枢轴大
"""
class quicksort(object):
    def sort(self,original_items,comp=lambda x,y: x<=y ):
        items=original_items[:]
        self._quick_sort(items,0,len(items)-1,comp)
        return items

    def _quick_sort(self,items,start,end,comp):
        if start < end:
            pos = self._partition(items,start,end,comp)
            self._quick_sort(items,start,pos-1,comp)
            self._quick_sort(items,pos+1,end,comp)

    def _partition(self,items,start,end,comp):
        pivot=items[end]
        i=start-1
        for j in range(start,end):
            if comp(items[j],pivot):
                i+=1
                items[i],items[j]=items[j],items[i]
        items[i+1],items[end]=items[end],items[i+1]
        return i+1

"""
递归回溯法：叫称为试探法，按选优条件向前搜索，当搜索到某一步，发现原先选择并不优或达不到目标时，
就退回一步重新选择，比较经典的问题包括骑士巡逻、八皇后和迷宫寻路等。
"""


# q=quicksort()
# b=q.sort([5,1,9,3,7,2,8,6,4])
# print(b)
items1 = list(map(lambda x: x ** 2, filter(lambda x: x % 2, range(1, 10))))
print(items1)
# greedy=Greedy()
# greedy.run()

# Exhaustive.fish()




