class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

results = []
def FindPath(root, expectNumber):
    if root == None:
        return []
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
