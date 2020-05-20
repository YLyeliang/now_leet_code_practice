// 求子集、排列、组合
//
// 一、子集
// 输入一个不包含重复数字的数组，要求算法输出这些数字的所有子集。
#include<vector>
#include<stack>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums);
// e.g [1,2,3] 输出8个子集
// out:[[],[1],[2],[3],[1,2],[1,3],[2,3],[1,2,3]]
//
//解法一：数学归纳法
//　考虑一下，知道［1,2]的子集，能否推断出[1,2,3]的子集，
//[1,2]:[[],[1],[2],[1,2]]
//再考虑[1,2,3]，多出如下子集：[1,3],[2,3],[1,2,3],[3]
//即对[1,2]的子集均加上了3。
//即，令A=subset[1,2]
//则subset[1,2,3]= A+A[i].add(3) i = 1...len(A)
//为典型的递归结构。base case显然是当输入为空集时，子集为空集。
//代码
vector<vector<int>> subsets(vector<int>& nums) {
    // base case 返回空集
    if (nums.empty()) return {{}};
    // 取出最后一个元素
    int n =nums.back();
    nums.pop_back();
    // 递归算出前面元素的所有子集
    vector<vector<int>> res=subsets(nums);
    
    int size =res.size();
    for (int i=0;i<size;i++) {
        //然后在之前的结果之上追加
        res.push_back(res[i]);
        res.back().push_back(n);
    }
    return res;
}

//复杂度：递归的时间复杂度计算：找到递归深度，乘以每次递归中迭代的次数。
//递归深度明显为N，每次for循环的迭代次数取决于size大小，每次迭代均翻倍，为2^N。
//在for循环里面，res的push包括两次，第一次是push一个数组，该操作需要O(N),第二个
//为单个数字，为O(1)。则总时间为O(N*2^N).
//
//解法二:回溯算法
// 算法模板(pytho)
result = []
def backtrack(路径, 选择列表):
        if 满足结束条件:
            result.add(路径)
            return
        for 选择 in 选择列表:
            做选择
            backtrack(路径, 选择列表)
            撤销选择

//修改一下模板即可.
vector<vector<int>> res;
vector<vector<int>> subsets(vector<int>& nums) {
    //记录走过的路径
    vector<int> track;
    backtrack(nums,0,track);
    return res;
}
void backtrack(vector<int>& nums, int start, vector<int>& track) {
    res.push_back(track);
    for (int i =start;i<nums.size();i++) {
        //做选择
        track.push_back(nums[i]);
        // 回溯
        backtrack(nums,i+1,track);
        //撤销选择
        track.pop_back();
    }
}
// 可知，对res更新的位置处在前序遍历，也就是说，res就是树上的所有节点。


// 二、组合
// 输入两个数字 n, k，算法输出 [1..n] 中 k 个数字的所有组合
vector<vector<int>> combine(int n, int k);
// 比如输入 n = 4, k = 2，输出如下结果，顺序无所谓，但是不能包含重复（按照组合的定义，[1,2] 和 [2,1] 也算重复）：
//
// [ [1,2], [1,3], [1,4], [2,3], [2,4], [3,4] ]
// 这也是典型的回溯算法，k 限制了树的高度，n 限制了树的宽度，继续套我们以前讲过的回溯算法模板框架就行了：
vector<vector<int>>res;
vector<vector<int>> combine(int n, int k) {
    //记录走过的路径
    vector<int> track;
    backtrack(n,k,1,track);
    return res;
}
void backtrack(int n, int k, int start, vector<int>& track) {
    // 得到长度为k的数组/到达树的底部。
    if (track.size()==k) {
        res.push_back(track);
        return;
    }
    for (int i=start;i<=n;i++) {
        //做选择
        track.push_back(i);
        //回溯
        backtrack(n,k,i+1,track);
        //撤销选择
        track.pop_back();
    }
}

//三、排列
//输入一个不包含重复数字的数组 nums，返回这些数字的全部排列。
//比如说输入数组 [1,2,3]，输出结果应该如下，顺序无所谓，不能有重复：
//
//[ [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1] ]
//还是按照模板来解：
vector<vector<in>> res;
vector<vector<int>> permute(vector<int>& nums) {
    //记录路径
    vector<int> track;
    backtrack(nums,track);
    return res;
}

void backtrack(vector<int>& nums, vector<int>& track) {
    if (track.size()==nums.size()) {
        res.push_back(track);
        return;
    }
    for (int i=0; i<nums.size();i++) {
        // remove repeated numbers.
        if (find(track.begin(),track.end(),nums[i])!=res.end()) continue;
        //Make a choice
        track.push_back(nums[i]);
        //backtrack
        backtrack(nums,i+1,track);
        //Undo the choice
        track.pop_back();
    }
}

