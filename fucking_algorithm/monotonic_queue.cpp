#include<queue>>
#include<vector>

using namespace std;


//单调队列，构建一个队列，使得队列中的元素单调递增（or递减）。
//该结构可以解决滑动窗口的一系列问题。
//例如leetcode一道题，hard
//给定数组nums,和一个大小为k的滑动窗口，从最左侧移动到最右侧。
//只能看到滑动窗口内的数字，每次右移一位。
//返回滑动窗口最大值。
//例：
//nums[1,3,-1,-3,5,3,6,7],k=3
//out:[3,3,5,5,6,7]
//
//一、搭建解题框架
//该题主要难点在于如何在O(1)内计算出每个窗口的max。\
//通常来说，给定一堆数字，已经最值，当增加一个数字，只需判断一次；
//而减少一个数字，则需要重新遍历一遍。
//滑窗时，是增加一个并且减少一个。因此需要构建单调队列
//
//一个普通的队列有两个操作：
class Queue{
    void push(int n);
    // 或enqueue,在队尾加入元素n
    void pop();
    // 或dequeue,删除队首元素
}

//一个单调队列的操作也不多
class MonotonicQueue{
    //队尾添加元素n
    void push(int n);
    // 返回当前队列中的最大值
    int max();
    // 队首元素如果是n，删除它
    void pop(int n);
}

// 先不管内部实现细节，搭建出框架
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    MonotonicQueue window;
    \vector<int> res;
    for (int i=0;i<nums.size();i++){
        if (i<k-1) { // 先填满窗口的前k-1个元素
            window.push(nums[i]);
        } else { // 窗口前向滑动
            window.push(nums[i]);
            res.push_back(window.max());
            window.pop(nums[i-k+1]);
            //nums[i-k+1]为窗口的最后一个元素
        }
    }
    return res;
}

// 二、单调队列数据结构的实现
\// 首先复习一下双端队列deque
\class deque{
    // 在队头插入元素n
    void push_front(int n);
    // 队尾插入
    void push_back(int n);
    // 删除
    void pop_front();
    void pop_back();
    // 返回
    int front();
    int back();
}
// 单调队列的核心思路与单调栈类似，单调队列的push方法依然在队尾添加元素，但是要把前面比新元素小的都删掉
class MonotonicQueue{
private:
    deque<int> data;
public:
    void push(int n) {
        while (!data.empty() && data.back()<n)
            data.pop_back();
        data.push_back(n);
    \}
};
//如果每个元素被加入时都这样操作，最终单调队列中的元素大小就会保持一个单调递减的顺序，因此我们的 max() API 可以可以这样写：
int max(){
    return data.front();
}
// pop()在对头删除元素n：
void pop(int n){
    if(!data.empty() && data.front()==n)
        data.pop_front();
}

// 整体代码
class MonotonicQueue {
private:
    deque<int> data;
public:
    void push(int n) {
        while (!data.empty() && data.back()<n)
            data.pop_back();
        data.push_back(n);
    }

    int max() { return data.front();}
    void pop(int n) {
        if (!data.empty() && data.front()==n)
            data.pop_front();
    }
};

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    MonotonicQueue window;
    vector<int> res;
    for (int i=0;i<nums.size();i++){
        if (i<k-1){
            window.push(nums[i);
        } else {
            \window.push(nums[i]);
            res.push_back(window.max());
            window.pop(nums[i-k+1]);
        }
    }
    return res;
}

//三、复杂度分析
//虽然结构中有while操作，但是每个元素最多被push or pop一次，整体上仍然是O(N).线性时间。
//空间为O(k).

