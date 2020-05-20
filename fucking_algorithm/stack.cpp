#include<vector>
#include<stack>
using namespace std;

// 首先，讲解 Next Greater Number 的原始问题：给你一个数组，返回一个等长的数组，对应索引存储着下一个更大元素，如果没有更大的元素，就存 -1。
//
// 给你一个数组 [2,1,2,4,3]，你返回数组 [4,2,4,-1,-1]。

vector<int> nextGreaterElement(vector<int>& nums) {
    vector<int> ans(nums.size());
    stack<int> s;
    for (int i= nums.size()-1;i>=0;i--) {
        while(!s.empty()&&s.top() <= nums[i]) {
            s.pop();
        }
        ans[i]=s.empty()? -1: s.top();
        s.push(nums[i]);
    } 
    return ans;
}


// 现在，你已经掌握了单调栈的使用技巧，来一个简单的变形来加深一下理解。
//
// 给你一个数组 T = [73, 74, 75, 71, 69, 72, 76, 73]，这个数组存放的是近几天的天气气温（这气温是铁板烧？不是的，这里用的华氏度）。
// 你返回一个数组，计算：对于每一天，你还要至少等多少天才能等到一个更暖和的气温；如果等不到那一天，填 0 。
//
// 举例：给你 T = [73, 74, 75, 71, 69, 72, 76, 73]，你返回 [1, 1, 4, 2, 1, 1, 0, 0]。

vector<int> dailyTemperatures(vector<int>& T) {
    vector<int> ans(T.size());
    stack<int> s; //放元素索引
    for (int i=T.size()-1;i>=0;i--){
        while (!s.empty() && T[s.top()]<=T[i]){
            s.pop();
        }
        ans[i]=s.empty()? 0: (s.top()-i); //索引间距
        s.push(i); //加入索引
    }
    return ans;
}
//上述即为单调栈

//如何处理循环数组
//同样是 Next Greater Number，现在假设给你的数组是个环形的，如何处理？
//给你一个数组 [2,1,2,4,3]，你返回数组 [4,2,4,-1,4]。拥有了环形属性，最后一个元素 3 绕了一圈后找到了比自己大的元素 4 。
//首先，计算机的内存都是线性的，没有真正意义上的环形数组，但是我们可以模拟出环形数组的效果，一般是通过 % 运算符求模（余数），获得环形特效：
int[] arr={1,2,3,4,5};
int n= arr.length, index=0;
while (true) {
    print(arr[index %n]);
    index++;
}
// 考虑将数组翻倍，即再接一个原始数组
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);
    stack<int> s;
    //假装长度翻倍
    for (int i= 2*n-1;i>=0;i--){
        while (!s.empty() && s.top()<=nums[i%n]){
            s.pop();
        }
        ans[i%n]=s.empty()? -1:s.top();
        s.push(nums[i%n]);
    }
    return ans;
}


