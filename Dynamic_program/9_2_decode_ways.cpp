// A message containing letters from A-Z can be encoded into numbers using the following mapping:
//
//'A' -> "1"
//'B' -> "2"
//...
//'Z' -> "26"
//To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:
//
//"AAJF" with the grouping (1 1 10 6)
//"KJF" with the grouping (11 10 6)
//Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".
//
//Given a string s containing only digits, return the number of ways to decode it.
//
//The test cases are generated so that the answer fits in a 32-bit integer.

// Example 1:
//
//Input: s = "12"
//Output: 2
//Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
//Example 2:
//
//Input: s = "226"
//Output: 3
//Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
//Example 3:
//
//Input: s = "06"
//Output: 0
//Explanation: "06" cannot be mapped to "F" because of the leading zero ("6" is different from "06").
//
//
//Constraints:
//
//1 <= s.length <= 100
//s contains only digits and may contain leading zero(s).

// 问题：A-Z可以被映射为1-26. 给定一个数字字符串，求其被解码的所有种数

// 方法：以i结尾时的个数为dp[i], 226, dp[0] = 1, dp[1] = dp[0] + 1(2加上2仍然为1种,22构成第二种)
// dp[2] = dp[1] + 1(2 2 + 6, 22 +6, 新组成一种26)
// e.g 120;  1 20;  dp[0] = 1, dp[1] = 2, dp[2] = 1(1 2 0, 12 0, 1 20)
// 几种情况：1. s[i]在[1,9],构成独立数字, dp[i] = dp[i-1]; 2. s[i]与s[i-1]构成[10,26], dp[i] = dp[i-2];
//
// 状态转移方程： dp[i] = dp[i-1] + dp[i-2] if s[i] > 0  and s[i-1]s[i] in [10,26], else 满足哪种就取哪种
// 初始状态：dp[0] = 1 if s[0] >0 else 0

#include "string"
#include "iostream"
#include "vector"

using namespace std;

// brute-force
class Solution1 {
public:
    int numDecodings(string s) {
        return s.empty() ? 0 : numDecodings(0, s);
    }

    int numDecodings(int p, string &s) {
        int n = s.size();
        if (p == n) return 1;
        if (s[p] == '0') return 0; // 从0开始的子串不合规
        int res = numDecodings(p + 1, s);
        if (p < n - 1 && (s[p] == '1' || (s[p] == '2' && s[p + 1] < '7'))) res += numDecodings(p + 2, s);
        return res;

    }
};

// memoization
class Solution2 {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> mem(n + 1, -1);
        mem[n] = 1;
        return s.empty() ? 0 : numDecodings(0, s, mem);
    }

    int numDecodings(int p, string &s, vector<int> mem) {
        if (mem[p] > 1) return mem[p];
        if (s[p] == '0') return mem[p] = 0;
        int res = numDecodings(p + 1, s, mem);
        if (p < s.size() - 1 && (s[p] == '1' || (s[p] == '2' && s[p + 1] < '7'))) res = numDecodings(p + 2, s, mem);
        return mem[p] = res;
    }
};

// bottom-up
class Solution3 {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0')dp[i] = 0;
            else {
                dp[i] = dp[i + 1];
                if (i < n - 1 && (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7')))
                    dp[i] += dp[i + 2];
            }
        }
        return s.empty() ? 0 : dp[0];
    }
};