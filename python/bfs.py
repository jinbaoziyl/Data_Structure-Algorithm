# 从上往下打印二叉树
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def PrintFromTopToBottom(root):
    if root == None:
        return []
    res = []
    queue = []
    queue.append(root)

    while queue:
        node = queue.pop(0)
        if node == None:
            continue
        res.append(node.val)

        if node.left != None and node:
            queue.append(node.left)
        if node.right != None:
            queue.append(node.right)
    return res
