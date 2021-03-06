# 3. DFS and BFS
## 3.1 DFS 深度优先搜索算法

DFS解决什么问题？
DFS解决的是连通性的问题，即给定两个点，一个起点(或者某种状态)和一个终点(或者某种最终状态),
判读是否存在一条路径从起点连接到终点
很多情况，连通路径有多条，只需要找到一条即可， DFS只关心路径是否存在，不在乎长短

算法的思想:
从起点出发，选择一个可选方向不断前进，直到无法继续为止
然后尝试另外一种方向，直到最后走到终点

DFS的递归实现:
递归的时候需要将当前程序的变量以及状态压入到系统的栈里面
压入和弹出需要较多时间，如果栈的深度大 会造成效率底下

DFS的非递归实现
栈的数据结构也支持压入和弹出
利用栈来提高效率

图的遍历总体框架
```
boolean dfs(int maze[][], int x, int y)
{
    Stack<Integer[]> stack = new stack<>(); // step1: 创建Stack数据结构
    stack.push(new Integer[] {x, y});       // step2: 将起始点压入Stack，并标记它被访问过
    maze[x][y] = -1;

    while(!stack.isEmpty())                 // step3: 只要Stack不为空，就不断循环处理
    {
        Integer[] pos = stack.pop();        // step4: 从堆栈中取出当前要处理的点
        x = pos[0] , y = pos[1];

        if(x == B[0] && y == B[1])          // step5: 判断是否到达目的地
            return true;

        for(int d = 0; d < 4; d++)              // step6: 不是目的地就从可能的方向尝试
        {
            int i = x + dx[d], j = y + dy[d];
            if(isSafe(maze,i,j))
            {
                stack.push(new Integer[]{i,j});    // step7: 将各个方向的点压入堆栈，并标记为访问过
                maze[i][j] = -1;
            }
        }
    }

    return false;
}

```


如何利用DFS寻找最短的路径？
通过DFS+枝剪方法

经典案例:
1. 剑指offer: 二叉树中和为某一值的路径
题目描述:
输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径
2. 剑指offer 66-机器人的运动范围

## 3.2 BFS 广度优先搜索算法
广度优先搜索一般用来解决最短路径的问题
广度优先搜索一般从起始点出发，一层一层地进行
每层中的点距离起始点的步数是相同的

双端BFS
同时从起始点和终点开始进行的广度优先搜索称为双端BFS
双端BFS可以大大地提高搜索的效率
可以利用队列的数据结构实现BFS算法

BFS算法总体框架
```
void bfs(int [][]maze, int x, int y)
{
    Queue<Integer[]> queue = new LinkedList<>();    // step1: 创建队列，加入起始点
    queue.add(new Integer[] {x, y});

    while(!queue.isEmpty())                         // step2: 队列不为空，一直循环下去
    {
        Integer[] pos = queue.poll();               // step3: 取出当前处理的点
        x = pos[0]; y = pos[1];

        for(int d = 0; d < 4; d++ )                 // step4: 在可能的方向上进行BFS搜索
        {
            int i = x + dx(d), j = y + dy(d);

            if(isSafe(maze, i, j))                   // step5: 判断一下该方向的点是否已经被访问过
            {
                maze[i][j] = maze[x][y] + 1;          // step6: 被访问过，则纪录步数，并加入队列
                queue.add(new Integer[] {i,j});

                if(i == B[0] && j == B[1])  return; // step7: 找到目的地立即返回
            }
        }
    }
}
```

经典案例:
1.剑指offer 从上往下打印二叉树
2.剑指offer 65.矩阵中的路径
3.迷宫问题(华为机考)
