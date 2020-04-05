# 二叉树中和为某一值的路径
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def FindPath(root, expectNumber):
    if root == None:
        return []
    results = []
    stack = []
    ls = []
    stack.append(root)

    while(0 != len(stack)):
        node = stack.pop()
        if node.val != -1:
            ls.append(node.val)
        node.val = -1
        if (node.left == None and node.right == None) or (node.left.val == -1 and node.right.val == -1):
            ls.pop()

        if node.left == None and node.right == None and sum(ls[:])+node.val == expectNumber:
            ls_cp = ls.copy()
            ls_cp.append(node.val)
            results.append(ls_cp)
        
        if node.left != None and node.left.val != -1:
            stack.append(node.left)
        if node.right != None and node.right.val != -1:
            stack.append(node.right)
    return results
        
class Solution:
    # 返回二维列表，内部每个列表表示找到的路径
    def FindPath(self, root, expectNumber):
        # write code here
        if root == None:
            return []
        result = []
        stack = []
        stack.append((root, [root.val]))
        while stack:
            node, path = stack.pop()
            if node.left == None and node.right == None and sum(path) == expectNumber:
                result.append(path)
            if node.right != None:
                stack.append((node.right, path + [node.right.val]))
            if node.left != None:
                stack.append((node.left, path + [node.left.val]))
        return result       

def bitSum(pos):
    list = []
    for s in pos:
        b = str(s)
        for c in b:
            list.append(int(c))

    return sum(list)

# 机器人的运动范围
def movingCount(self, threshold, rows, cols):
    if threshold <= 0:
        return 0

    i, j = 0, 0
    stack = []
    stack.append([[i, j], 1])
    
    while stack:
        pos, num = stack.pop()
        cur_x = pos[0]
        cur_y = pos[1]
        if bitSum(pos) > threshold:
            return (num - 1)
        
        for i in range(4):
            if i == 0 and cur_y - 1 >= 0:
                stack.append([[cur_x, cur_y-1], num + 1])
            elif i == 1 and cur_y+1 <= cols:
                stack.append([[cur_x, cur_y+1], num + 1])
            elif i == 2 and cur_x - 1 >= 0:
                stack.append([[cur_x - 1, cur_y], num + 1])
            else:
                stack.append([[cur_x + 1, cur_y], num + 1])


# 迷宫问题(华为机考)
import sys
# @x,y  终点坐标
def maze_dfs(matrix, x, y):
    stack = []                  # stack数据结构作用
    dir = [[1,0], [0,1]]        # 定义两个方向横着或者竖着走
    visited = [[0]*(y+1) for _ in range(x+1)] #标记是否访问过

    #将起始点放入栈中
    stack.append((0,0))
    visited[0][0] = 1

    while stack:
        flag = False    #标记是否找到方向
        pek = stack[-1] #获得栈顶元素

        if pek[0] == x and pek[1] == y:
            break
        else:
            for i in range(2): # 两个方向搜索
                tmp_x = pek[0] + dir[i][0]
                tmp_y = pek[1] + dir[i][1]
                # 找到邻居位置, 判断合不合法
                if tmp_x>=0 and tmp_x<=x and tmp_y>=0 and tmp_y<=y and matrix[tmp_x][tmp_y]==0 and visited[tmp_x][tmp_y]==0:
                    stack.append((tmp_x,tmp_y))
                    visited[tmp_x][tmp_y] = 1
                    flag = True  #找到下一个方向
                    break
            if flag:
                continue
            # 如果两个方向都找不到， 那么出栈
            stack.pop()
    for ele in stack:
        print("(%d,%d)" %(ele[0], ele[1]))
         

def main():
    while True:
        matrix_info = sys.stdin.readline().strip()
        if matrix_info == '':
            break
        row, col = matrix_info.split()

        matrix = []
        for i in range(int(row)):
            matrix.append(list(map(int, sys.stdin.readline().strip().split())))

        maze_dfs(matrix, int(row)-1, int(col)-1)

# if __name__ == '__main__':
#     main()
    
