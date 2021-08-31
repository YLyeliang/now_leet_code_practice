//
// Created by yel on 2021/8/31.
//

// Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.
//
//For example:
//
//A -> 1
//B -> 2
//C -> 3
//...
//Z -> 26
//AA -> 27
//AB -> 28
//...
//
//
//Example 1:
//
//Input: columnNumber = 1
//Output: "A"
//Example 2:
//
//Input: columnNumber = 28
//Output: "AB"
//Example 3:
//
//Input: columnNumber = 701
//Output: "ZY"
//Example 4:
//
//Input: columnNumber = 2147483647
//Output: "FXSHRXW"

// 问题：假设有一个映射关系：26个字母->数字，如上述例子所示。给一个数字，求其对应的字母(excel sheet)

// 方法：递归求解，每次除26取余+'A'得到后面的字符，然后递归调用求解头部字符并合并。

#include "string"

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        if (columnNumber == 0)return "";
        string s = "";
        s = s + (char) (--columnNumber % 26 + 'A');
        return convertToTitle(columnNumber / 26) + s;
    }
};

int main() {
//    char s = 'A';
    string s = "A";
    size_t n = s.size();
//    for (int i = 0; i < 26; i++)
//        s++;
    return 0;
}