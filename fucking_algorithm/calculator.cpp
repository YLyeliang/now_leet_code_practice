//实现计算器
//1、输入一个字符串，可以包含+ - * /、数字、括号以及空格，你的算法返回运算结构。
//
//2、要符合运算法则，括号的优先级最高，先乘除后加减。
//
//3、除号是整数除法，无论正负都向 0 取整（5/2=2，-5/2=-2）。
//
//4、可以假定输入的算式一定合法，且计算过程不会出现整型溢出，不会出现除数为 0 的意外情况。
//
//e.g 3 * (2-6/(3-7)) =  9  (注意条件3)
//
//难点：括号的处理、运算优先级处理、空格的处理
//将问题进行拆解，从最简单的一个开始。
//一、字符串转整数
#include <cctype>
#include <cstddef>
#include <pthread.h>
#include<string>
#include<stack>
#include<cstdio>
#include<iostream>
using namespace std;
string s="458";

int n=0;
for (int i=0;i<s.size();i++) {
    char c= s[i];
    n=10*n+ (c-'0');
}
// n=458
// (c-'0')用于防止整形溢出
// 因为变量c是一个 ASCII 码，如果不加括号就会先加后减，想象一下s如果接近 INT_MAX，就会溢出。所以用括号保证先减后加才行。

//二、处理加减法
// 如果只包含加减法，且不存在空格，怎么计算？以 1-12+3为例，包含三个步骤：
// 1、给第一个数字默认+号，+1-12+3
// 2、把一个运算符和数字组合成一对儿，也就是三对：+1,-12,+3,然后将其转化为数字，放入栈中。
// 3、将栈中所有数字求和，即为结果。
int calculate(string s) {
    stack<int> stk;
    //记录数字
    int num=0;
    //记录符号，初始化为+
    char sign='+';
    for (int i=0;i<s.size();i++) {
        char c=s[i];
        //如果是数字，连续读取到num
        if (isdigit(c))
            num=10*num+(c-'0');
        //如果不是数字，或者读到了最后一位，则需要压入栈中，并重置状态
        if (!isdigit(c)|| i==s.size()-1){
            switch(sign){
                case '+':
                    stk.push(num);break;
                case '-':
                    stk.push(-num);break;
            }
            //更新符号和数字状态
            sign=c;
            num=0;
        }
    }
    //将栈中元素求和
    int res=0;
    while(!stk.empty()){
        res+=stk.top();
        stk.pop();
    }
    return res;
}

//三、处理乘除法
//在计算乘除时，需要考虑到乘除相较于加减的优先级。
//因此，在读取到* /符号时，可以选择将当前的数字与当前的栈顶元素进行对应的计算，再压入栈中。
//这样，就可以保证是优先计算* /，并在最后对栈中元素进行求和。
for (int i=0;i<s.size();i++) {
    char c=s[i];
    if (isdigit(c))
        num=10*num+(c-'0');
    //处理空格符
    if (!isdigit(c)&& c!=' '||i==s.size()-1) {
        switch(sign){
            int pre;
            case '+':
                stk.push(num);break;
            case '-':
                stk.push(-num);break;
            case '*': //拿出当前栈顶元素计算并压入栈
                pre= stk.top();
                stk.pop();
                stk.push(pre*num);
                break;
            case '/':
                pre=stk.top();
                stk.pop();
                stk.push(pre/num);
                break;
        }
        sign=c;
        num=0;
    }
}

//四、处理括号
//这里将之前的c++代码翻译成python（为了方便）
def calculate(s: str) -> int:

    def helper(s: List) -> int:
        stack=[]
        sign='+'
        num=0

        while len(s)>0:
            c=s.pop()
            if c.isdigit():
                num=10*num+int(c)
            if (not c.isdigit() and c!=' ') or len(s)==0:
                if sign='+':
                    stack.append(num)
                elif sign='-':
                    stack.append(-num)
                elif sign='*':
                    stack[-1]=stack[-1]*num
                elif sign="/":
                    stack[-1]=int(stack[-1]/float(num))
                num=9
                sign=c

            return sum(stack)

    return helper(list(s))

// 括号由于具有递归性质，所以处理起来没有那么难，以3*(4-5/2)+6为例
// calculate(3*(4-5/2)+6 = 3* calculate(4-5/2)+6
// 现在的问题变成了，如果确定递归的开始条件和结束条件
def calculate(s):
    def helper(s):
        stack=[]
        sign='+'
        num=0
        while len(s)>0:
            c=s.pop()
            if c.isdigit():
                num=10*num+int(c)
            # 遇到左括号开始递归
            if c=='(':
                num=helper(s)
            
            if (not c.isdigit() and c!=' ') or len(s)==0:
                ...

            if c==')': break
        return sum(stack)
    return helper(lsit(s))






                    



