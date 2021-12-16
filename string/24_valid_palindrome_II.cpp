//
// Created by 叶亮 on 2021/12/12.
//

// Given a string s, return true if the s can be palindrome after deleting at most one character from it.
//
//
//
//Example 1:
//
//Input: s = "aba"
//Output: true
//Example 2:
//
//Input: s = "abca"
//Output: true
//Explanation: You could delete the character 'c'.
//Example 3:
//
//Input: s = "abc"
//Output: false

// 问题： 在至多删除一个字符后，判断字符串s是否为回文

// 方法：使用双指针方法，由于至多删除一个字符，在向中间遍历时，遇到不相等的字符时，可以略过当前字符，判断剩下的字符是否为回文
// 这时会遇到两种情况：略过左边 or 略过右边，分别判断其是否为回文，有一个满足即可。
#include "iostream"
#include "string"
#include "map"
#include "vector"

using namespace std;


class Solution {
public:
    bool validPalindrome(string s) {
        int l=0,r = s.length()-1;
        for(;l<r;l++,r--){
            if (s[l]!=s[r]) {
                int i1=l,j1=r-1,i2=l+1,j2=r;
                while(i1<j1 && s[i1]==s[j1]){i1++;j1--;}
                while (i2<j2&& s[i2]==s[j2]){i2++;j2--;}
                return i1>=j1 || i2>=j2;
            }
        }
        return true;
    }
};