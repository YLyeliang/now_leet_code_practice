//
// Created by yel on 2021/8/31.
//

// Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
//
//
//
//Example 1:
//
//Input: s = "A man, a plan, a canal: Panama"
//Output: true
//Explanation: "amanaplanacanalpanama" is a palindrome.
//Example 2:
//
//Input: s = "race a car"
//Output: false
//Explanation: "raceacar" is not a palindrome.

// 问题：判断字符串是否为回文，只考虑字母字符

// 方法：使用双指针方法，判断头指针和尾指针的值，向中间遍历

#include "string"

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {

        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            while (isalnum(s[i]) == false && i < j) i++;
            while (isalnum(s[j]) == false && i < j) j--;
            if (tolower(s[i]) != tolower(s[j])) return false;
        }
        return true;
    }
};

int main() {
    string s = "A man, a plan, a canal: Panama";
    Solution sol;
    sol.isPalindrome(s);
}