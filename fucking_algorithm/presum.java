//前缀和技巧
//一个简单问题：给定一个整数数组和一个整数k，需要找到数组中和为k的连续子数组的个数
//e.g nums=[1,1,1] k=2
//out: 2     ps:[1,1] & [1,1]
//
//
//在解决这个问题之前，需要考虑到对子数组求和的问题。
//在限制了一定时间复杂度的情况下，不能每次对子数组求和都以遍历的方式进行
//比如实现sum(i,j)，有没有一种O(1)的方法来实现呢，这就需要用到前缀和的技巧
//
//一、前缀和
//给定一个nums,开辟一个新数组储存到当前索引时的数组之和。
int n=nums.length;
//前缀和数组
int[] preSum=new int[n+1];
preSum[0]=0;
for (int i=0;i<n;i++)
    preSum[i+1]=nums[i]+preSum[i];

//这样的话，要求子数组nums[i..j]的和，就只需要计算preSum[j+1]-preSum[i]即可。
//因此，可以得到下列解法
int subarraySum(int[] nums,int k) {
    int n=nums.length;
    //构造前缀和
    int[] preSum=new int[n+1];
    preSum[0]=0;
    for (int i=0;i<n;i++)
        preSum[i+1]=preSum[i]+nums[i];

    int ans=0;
    //穷举所有子数组
    for (int i=0;i<n;i++)
        for (int j=0;j<i;j++)
            //判断和是否满足
            if (preSum[i]-preSum[j]==k)
                ans++;
    return ans;
}

//上述解法需要时间复杂度O(N^2)，因为有两个for循环，如何进一步进行优化呢？
//二、优化解法
//在两个for循环中，第二个嵌套的for循环用于遍历当前索引之前的所有子数组是否满足
//这里可以对判断做个变化
//if (preSum[j]==preSum[i]-k)
//这样，可以使用哈希表记录前缀和出现的次数，当判断到preSum[j]与preSum[i]-k相等时，结果直接加上前缀和出现的次数即可。
import java.utils.HashMaph
int subarraySum(int[] nums,int k) {
    int n=nums.length;

    //构造哈希表:前缀和->出现次数
    HashMap<Integer,Integer> preSum= new HashMap<>();
    preSum.put(0,1);

    int ans=0;sum0_i=0;
    for (int i=0;i<n;i++) {
        sum0_i+=nums[i];
        //前缀和和nums[i..j]
        int sum0_j=sum0_i-k;
        //若存在，则更新
        if (preSum.containsKey(sum0_j)
                ans++preSum.gut(sum0_j);
        //将前缀和nums[i..j]加入并记录次数
        preSum.put(sum0_j,preSum.getOrDefault(sum0_j,0)+1);
    }
    return ans;
}
