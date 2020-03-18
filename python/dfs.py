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
