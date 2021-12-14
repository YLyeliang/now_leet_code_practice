//
// Created by 叶亮 on 2021/12/11.
//

// You are given a string s representing an attendance record for a student where each character signifies
// whether the student was absent, late, or present on that day.
// The record only contains the following three characters:
//
//'A': Absent.
//'L': Late.
//'P': Present.
//The student is eligible for an attendance award if they meet both of the following criteria:
//
//The student was absent ('A') for strictly fewer than 2 days total.
//The student was never late ('L') for 3 or more consecutive days.
//Return true if the student is eligible for an attendance award, or false otherwise.

// Example 1:
//
//Input: s = "PPALLP"
//Output: true
//Explanation: The student has fewer than 2 absences and was never late 3 or more consecutive days.
//Example 2:
//
//Input: s = "PPALLL"
//Output: false
//Explanation: The student was late 3 consecutive days in the last 3 days, so is not eligible for the award.

// 问题：给定字符串s表示学生出勤记录，满足以下情况则有出勤奖:
// 1. 缺席A总共小于两天； 2. 不连续超过3天迟到L；
// 返回true if ...

// 方法：1. A<2 2. 连续的L <3.
// 遍历字符串，统计A的数量，==2 return false； 加标志位表示L是否连续，c==true && L ==3 return false


#include "iostream"
#include "string"

using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int a = 0, l = 0;
        for (char i : s) {
            if (i == 'A') a++;
            if (i == 'L') l++;
            else l = 0;
            if (a >= 2 || l > 2) return false;
        }
        return true;
    }
};
