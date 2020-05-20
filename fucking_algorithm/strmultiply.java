//字符串乘法：
//给定两个字符串形式的非负整数num1和num2,返回他们的乘积，以字符串表示。
//注意，这两个数字可能会非常长，导致直接转换成Int型时会溢出，因此需要使用其它的方法。
//考虑到手算时的乘法方式。
//123*4=
// 1 2 3
//     4
//------
//   1 2
// 0 8
//04  
//-----
// 4 9 2
//可以写出如下代码
string multiply(string num1, string num2) {
    int n = num1.size(), n =num2.size();
    //结果最多为m+n位数
    vector<int> res(m+n,0);
    //从个位数开始逐位相乘
    for (int i=m-1;i>=0;i--) 
        for (int j=n-1;j>=0;j--) {
            int mul=(num1[j]-'0')*(num[j]-'0');
            //乘积在res对应的索引
            int p1=i+j,p2=i+j+1;
            //叠加到res上面
            int sum = mul + res[p2];
            res[p2]=sum%10;
            res[p1]=sum/10;
        }
    // 结果前缀可能存的0（未使用的位）
    int i=0;
    while (i<res.size() && res[i]==0)
        i++;
    //将结果转化位字符串
    string str;
    for (;i<res.size();i++)
        str.push_back('0'+res[i]);

    return str.size() ==0 ? '0' : str;
}

        
