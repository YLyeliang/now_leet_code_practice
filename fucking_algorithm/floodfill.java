//FloodFill算法，其最直接的一个应用就是【颜色填充】。比如画图中的填充区域；扫雷中的点击方格，展开一片区域；以及消消乐中的方块累计到一定程度进行消除。

//一、构建框架
//想象一个二维矩阵，从某一点开始向四周扩展，直到无法再扩展。将矩阵抽象成图，这就是一个图的遍历问题，也类似一个N叉树遍历问题。
//框架：

//(x,y)为坐标，第x行第y列
void fill(int x,int y) {
    fill(x-1,y); //上
    fill(x+1,y); //下
    fill(x,y-1); //左
    fill(x,y+1); //右
}

//该框架可以解决所有二位矩阵的遍历问题，往高了说，这就是深度优先搜索（DFS）；简单点说，这是一个四叉树的遍历问题，(x,y)为root,四个方向为root的四个子节点。
//看一道leetcode:
//有一幅以二维整数数组表示的图画，每个整数表示图画的像素大小，数值再0~65535之间。给定坐标(sr,sc)表示渲染开始的行列和一个新的颜色值newColor.
//对这幅图重新上色，并返回上色后的图像。
//e.g
//In: Image = [[1,1,1],
//             [1,1,0],
//             [1,0,1]]
//sr=1,sc=1,newColor=2
//Out: [[2,2,2],
//      [2,2,0],
//      [2,0,1]]
//PS:从中间开始，对周围的图像重新上色（上下左右）。
//根据树的框架，可以写出如下代码:
int[][] floodFill(int[][] image, int sr, int sc, int newColor){
    int origColor= image[sr][sc];
    fill(image,sr,sc,origColor,newColor);
    return image;
}

void fill(int[][] image, int sr, int sc, int origColor,int newColor) {
    //出界，超出索引边界
    if (!inArea(image,x,y)) return;
    //碰壁：遇到其它颜色，超出origColor区域
    if (image[x][y]!=origColor) return ;
    image[x][y]=newColor;

    fill(image,x-1,y,origColor,newColor);
    fill(image,x+1,y,origColor,newColor);
    fill(image,x,y-1,origColor,newColor);
    fill(image,x,y+1,origColor,newColor);
}

boolean inArea(int[][] image, int x, int y) {
    return x>=0 && x<=image.length
        && y>=0 && y<=image[0].length;
}

// 上述代码能够解决99%的问题，但是，当origcolor=newColor时，会陷入无限递归中，  
// 二、细节
// 为什么会陷入无限递归，考虑到递归时是往四个方向进行搜索，当往左递归时，递归反过来又回重复往右进行搜索（因为是四个方向），如果origcolor=newcolor时，就会反复横跳，导致死循环。
// 如何避免重复搜索呢，可以引入一个二位矩阵记录走过的路径，重复时返回。
...
if (visited[x][y]) return;
visited[x][y]=True;
image[x][y]=newColor;

//另一个方法，就是回溯算法。
//根据回溯算法框架，可以得到：
void fill(int[][] image, int x, int y, int origColor,int newColor){
    //出界
    if(!inArea(image,x,y)) return;
    //碰壁
    if(image[x][y]!=origColor) return;
    // 已访问过
    if (image[x][y]==-1)return;

    //回溯过程
    //choose:对走过路径标记
    image[x][y]=-1;
    fill(image,x-1,y,origColor,newColor);
    fill(image,x+1,y,origColor,newColor);
    fill(image,x,y-1,origColor,newColor);
    fill(image,x,y+1,origColor,newColor);
    
    //unchoose:将标记替换为newColor
    image[x][y]=newColor;
}

//三、拓展延伸
//像PS等软件中一般都有【魔棒】工具，用于自动选择颜色相近的区域。
//该工具一般是基于FloodFill算法， 但有些不同：一、同样是一种颜色，由于拍摄等问题会导致略微有些偏差，但是再选择时需要将其一块选中。二、Floodfill是区域填充，而魔棒工具更类似于边界填充。
//第一个问题，可以使用阈值的方法，在一定范围内的进行选择即可。
if (Math.abs(image[x][y]-origColor)>threshold)
    return;
//第二个问题，首先需要明确的是，不是将区域内所有origColor都染色，因为魔棒工具的范围有大有小，而是只给区域最外边染色。即最外围坐标。
//如何判断外围坐标也很简单，至少有一个方向不是origColor即是。保持框架不变，使用visited记录已搜索坐标，代码如下：
int fill(int[][] image, int x, int y, int origColor, int newColor) {
    //出界
    if (!inArea(image,x,y) return 0;
    //已搜索过
    if(visited[x][y]) return 1;
    //碰壁
    if (image[x][y] != origColor) return 0;

    visited[x][y] = true;

    int surround = 
            fill(image,x-1,y,origColor,newColor)
          + fill(image,x+1,y,origColor,newColor)
          + fill(image,x,y-1,origColor,newColor)
          + fill(image,x,y+1,origColor,newColor);
    if (surround<4)
        image[x][y]=newColor;

    return 1;
}


