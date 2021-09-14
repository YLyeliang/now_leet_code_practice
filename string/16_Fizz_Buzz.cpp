//
// Created by yel on 2021/9/14.
//

// Given an integer n, return a string array answer (1-indexed) where:
//
//answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
//answer[i] == "Fizz" if i is divisible by 3.
//answer[i] == "Buzz" if i is divisible by 5.
//answer[i] == i if non of the above conditions are true.
//
//
//Example 1:
//
//Input: n = 3
//Output: ["1","2","Fizz"]
//Example 2:
//
//Input: n = 5
//Output: ["1","2","Fizz","4","Buzz"]
//Example 3:
//
//Input: n = 15
//Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]

// 问题：给定一个整数n，返回一个字符串数组（从1索引）。第i个数，如果被3和5整除，则为"FizzBuzz",被3整除则为"Fizz" ...

// 方法；1.基本的条件判断语句即可。if-else
// 2. 优化：根据每个字符串的特性，被3、5和15整除的情况，遍历时i+3 i+5, i+15来进行遍历。可以减少求余操作。
#include "string"
#include "vector"

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res(n);
        for (int i = 1; i <= n; i++) {
            res[i - 1] = to_string(i);
        }
        for (int i = 2; i < n; i += 3) {
            res[i] = "Fizz";
        }
        for (int i = 4; i < n; i += 5) {
            res[i] = "Buzz";
        }
        for (int i = 14; i < n; i += 15) {
            res[i] = "FizzBuzz";
        }
        return res;
    }
};