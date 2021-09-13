//
// Created by yel on 2021/9/12.
//

// Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
//Letters are case sensitive, for example, "Aa" is not considered a palindrome here.
//Example 1:
//Input: s = "abccccdd"
//Output: 7
//Explanation:
//One longest palindrome that can be built is "dccaccd", whose length is 7.

//Example 2:
//Input: s = "a"
//Output: 1
//Example 3:
//
//Input: s = "bb"
//Output: 2
//
//Constraints:
//
//1 <= s.length <= 2000
//s consists of lowercase and/or uppercase English letters only.

// 问题：给定字符串s，包含大小写，求这些字符能够组成的回文字符的最大长度。

// 方法：根据回文串的特性，正序和逆序表示是相同的。则：1.当字符串长度为奇数的时候，字符串中间的数出现频次应为奇数；2.当为偶数的时，字符串所有字符出现频次均为偶数。
// 则，只需要统计字符串中字符的出现频次即可。即，统计所有字符出现次数，所有偶数求和，加上所有(奇数-1),如果奇数字符不为0，则+1(偶数字符串在中间添加一个字符)
// 简化：统计所有字符是否为奇数，如果该字符为奇数，则odds+=1,最后返回结果 s.size() - odds + (odds>0)


#include "string"

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int odds = 0;
        for (char c='A'; c<='z'; c++)
            odds += count(s.begin(), s.end(), c) & 1;
        return s.size() - odds + (odds > 0);
    }
};

int main() {
    char a = 'A';
    return 0;
}