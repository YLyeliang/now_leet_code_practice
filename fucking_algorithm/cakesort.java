//记录反转操作序列
LinkedList<Integer> res= new LinkedList<>();

List<Integer> pancakeSort(int[] cakes) {
    sort(cakes, cakes.length);
    return res;
}

void sort(int[] cakes, int n) {
    // base case
    if (n==1) return;

    //寻找最大饼的索引
    int maxCake=0;
    int maxCakeIndex=0;
    for (int i=0;i<n;i++)
        if (cakes[i]>maxCake) {
            maxCake=cakes[i];
            maxCakeIndex=i;
        }

    //第一次翻转，将最大饼翻到最上面
    reverse(cakes,0,maxCakeIndex);
    res.add(maxCakeIndex+1);
    //第二次翻转，将最大饼翻到最下面
    reverse(cakes,0,n-1);
    res.add(n);

    //递归
    sort(cakes,n-1);
}

void reverse(int[] cakes,int i, int j) {
    while (i<j) {
        int tmp=cakes[i];
        cakes[i]=cakes[j];
        cakes[j]=tmp;
        i++;
        j--;
    }
}

