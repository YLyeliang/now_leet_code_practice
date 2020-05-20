#include <cstddef>
#include <sched.h>
#include<unordered_map>

// 滑动窗口的问题,可以使用高级双指针技巧的算法框架来进行解决，比如子字符串匹配问题。
// 以Leetcode上的三道题为例。
// 需要用到哈希表，unordered_map(哈希表，dictionary)，方法count(key)可以判断key是否存在
// 使用方括号访问键对应的值map[key]。若不存在要访问的key，会自动创建一个值为0的key。
//
// 一、最小覆盖子串
// 给定字符串S、T，在S里找出包含T所有字母的最小字串。
// 例：S='ADOBECODEBANC', T="ABC"
// out "BANC"
// 若不存在，返回空
// 暴力解法：直接两个for循环，从0开始判断字串。时间复杂度O(N^2)
for (int i =0;i<s.size();i++)
    for (int j=i+1;j<s.size();j++)
        if s[i:j] 包含t所有字幕： 更新

//滑动窗口方法
//1、使用双指针技巧，left=right=0,将索引闭区间[left,right]视为一个窗口
//2、先不断增加right扩大窗口[left,right],直到窗口中的字符串满足需求（包含T中所有字符)
//3、停止增加right,改而增加left[left,right],直到窗口中的字符串不满足需求（不包含所有字符）。每次增加left,更新一次结果。
//4、重复2和3，直到right到达字符串S的尽头。
//伪代码如下：
string s,t;
// 在s中寻找t的最小覆盖子串
int left=0,right=0;
string res=s;

while (right<s.size()) {
    window.add(s[right]);
    right++;
    //若符合要求，移动left缩小窗口
    while (window符合) {
        //若该窗口子串更短，更新res
        res=minLen(res,window);
        window.remove(s[left]);
        left++;
    }
}
return res;

//现在的问题转变成了，如何判断window符合需求。
//可以使用两个哈希表当作计数器进行解决。用一个哈希表needs记录t中包含的字符及出现次数，用另一个哈希表window记录当前窗口中包含的字符及出现次数，
//若window包含needs所有的键，且大于等于needs中的值，则符合要求，移动left.
string s,t;
// 在s中寻找t的最小覆盖子串
int left=0,right=0;
string res=s;

//两个计数器
unordered_map<char,int> window;
unordered_map<char,int> needs;
for (char c: t) needs[c]++;

// 记录window中有多少符合需求了
int match=0;

while (right<s.size()) {
    char c1=s[right];
    if (needs.count(c1)) {
        window[c1]++; //加入window
        if (window[c1] == needs[c1])
            //字符c1的出现次数符合要求了
            match++;
    }
    right++;

    // window中的字符串已经符合needs的要求了
    while (match==needs.size()) {
        //更新结果 res
        res=minLen(res,window);
        char c2=s[left];
        if (needs.count(c2)) {
            window[c2]--; // 移出window
            if(window[c2]<needs[c2])
                //字符c2不再符合要求
                match--;
        }
        left++;
    }
}
return res;
//最后解决更新res的地方。
string minWindow(string s,string t) {
    //记录最短字串的开始位置和长度
    int start=0,minLen=INT_MAX;
    int left=0,right=0;

    unordered_map<char,int> window;
    unordered_map<char,int> needs;
    for (char c:t) needs[c]++;

    int match=0;

    while (right<s.size()) {
        char c1=s[right];
        if (needs.count[c1]) {
            window[c1]++;
            if (window[c1]==needs[c1]) 
                match++;
        }
        right++;

        while (match== needs.size()) {
            if (right-left<minLen){
                //update 
                start=left;
                minLen=right-left;
            }
            char c2=s[right];
            if (needs.count(c2)){
                window[c2]--;
                if (window[c2]<needs[c2])
                    match--;
            }
            left++;
        }
    }
    return minLen==INT_MAX? "":s.substr(start,minLen);
}

//二、找到字符串中所有字母异位词
//给定string s & 非空字符串p,找到s中所有是p的字母异位词的子串，返回这些子串的起始索引
//只包含小写
//字母异位词：字母相同，但排列不同的字符串
//In: s:"cbaebabacd" p:"abc"
//out: [0,6]
//解法:使用双指针技巧进行解决，仍然使用一中提到的框架
#include<vector>
using namespace std;
vector<int> findAnagrams(string s, string p) {
    //用数组记录答案
    vector<int> res;
    int left=0;right=0;
    unordered_map(char,int) needs;
    unordered_map(char,int) window;
    int match=0;
    for (char c:p) needs[c]++;
    
    while (right<s.size()) {
        char c1=s[right];
        if (needs.count(c1)){
            window[c1]++;
            if (window[c1]==needs[c1])
                match++;
        }
        right++;

        while(match==p.size()){
            //如果window的大小合适，将left加入结果
            if (right-left==p.size()){
                res.push_back(left);
            }
            char c2=s[left];
            if (needs.count(c2)){
                window[c2]--;
                if(window[c2]<needs[c2])
                    match--;
            }
            left++;
        }
    }
    return res;
}

//三、无重复字符的最长子串
//给定一个字符串，找出不含有重复字符的最长子串的长度
//In: "abcabcbb"
//Out: 3    最长为"abc"
// 当遇到子串问题，首先想到滑动窗口技巧。
// 与之前类似，使用window作为计数记录窗口中的字符出现次数，然后先向右移动right,当window中出现重复字符时，开始移动left缩小窗口，直到遍历完：
int lengthOfLongestSubstring(string s) {
    int left=0;right=0;
    unordered_map<char,int> window;
    int res=0;

    while (right<s.size()){
        char c1=s[right];
        window[c1]++;
        right++;

        // 进行判断:当window出现重复字符，移动left缩小窗口
        while (window[c1]>1) {
            char c2=s[left];
            window[c2]--;
            left++;
        }
        res=max(res,right-left);
    }
    return res;
}
// 总结：
// 通过三道题，总结出滑动窗口的抽象思维：
int left=0;right=0;
while (right<s.size()) {
    window.add(s[right]);
    right++;

    while (valid) {
        window.remove(s[left]);
        left++;
    }
}
