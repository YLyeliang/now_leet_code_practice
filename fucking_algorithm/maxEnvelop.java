// 给定一些标记了宽和高的信封，以[w,h]形式出现，当另一个信封的宽和高都比某一个大时，则这个可以放进另一个里。
// 计算一共有多少信封能嵌套在一块
// In:[[5,4],[6,4],[6,7],[2,3]]
// Out: 3 
// 组合为：[2,3]->[5,4]->[6,7]

// 这道题其实就是最长递增子序列（longest increasing subsequence, LIS)
//
// 一、解法
// 先对w升序排序，如W相同，则按照h降序排序。将所有的h作为一个数组，在这个数组上计算LIS即答案。
//
public int maxEnvelopes(int[][] envelopes) {
    int n= envelopes.length;
    //按宽度升序排列，如果宽度一样，则按高度降序排序
    Arrays.sort(envelopes, new Comparator<int[]>()
    {
        public int compare(int[] a, int[] b) {
            return a[0]==b[0]?
                b[1]-a[1]:a[0]-b[0];
        }
    });
    // 对高度数组寻找LIS
    int[] height= new int[n];
    for (int i=0;i<n;i++)
        height[i]=envelopes[i][1];

    return lengthOfLIS(height);
}

// 最长递增子序列
// 动态规划解法
public int lengthOfLIS(int[] nums) {
    int piles=0,n=nums.length;
    int[] top= new int[n];
    for (int i =0;i<n;i++) {
        int poker =nums[i];
        int left= 0,right=piles;

        while (left<right){
            int mid=(left+right)/2;
            if (top[mid]>=poker)
                

