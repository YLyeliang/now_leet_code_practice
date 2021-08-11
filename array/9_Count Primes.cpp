//
// Created by yel on 2021/8/11.
//

// Count the number of prime numbers less than a non-negative number, n.
//
//
//
//Example 1:
//
//Input: n = 10
//Output: 4
//Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
//Example 2:
//
//Input: n = 0
//Output: 0
//Example 3:
//
//Input: n = 1
//Output: 0

// 问题：给定整数n，求小于它的所有质数/素数的个数。 质数：只能被1和其自身整除的数字.

// 分析：Sieve_of_Eratosthenes: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
// 根据质数的特性，可以建立一个bool型表格，将所有为非质数的数置False。该表格的规则为：从2开始，计算其不大于n的所有倍数，将其置为True(非质数)

#include "vector"

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> notPrime(n, false);
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (!notPrime[i]) {
                count++;
                for (int j = 2 ; i * j < n; j++)
                    notPrime[i * j] = true;
            }
        }
        return count;
    }
};
