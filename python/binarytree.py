class Node():
    def __init__(self, x, left=None, right=None):
        self.value = x
        self.left = left 
        self.right = right

class BinaryTree():
    def __init__(self):
        self.root = None
    
# 前序遍历
def preTraverse(root):
    if root is None:
        return 
    print(root.value)
    preTraverse(root.left)
    preTraverse(root.right)
# 中序遍历
def midTraverse(root):
    if root is None:
        return 
    preTraverse(root.left)
    print(root.value)
    preTraverse(root.right)
# 后序遍历
def afterTraverse(root):
    if root is None:
        return 
    preTraverse(root.left)
    preTraverse(root.right)
    print(root.value)

# 先序遍历-非递归
# 用栈来辅助:
# 1、把二叉树的根节点 root 放进栈。
# 2、如果栈不为空，从栈中取出一个节点，把该节点放入容器的尾部；如果该节点的右子树不为空，则把有节点放入栈；
#    如果该节点的左子树不为空，则把左子树放入栈中。
# 3、一直重复步骤 2 ，直到栈为空，此时遍历结束
def preTraverseNoRec(root):
    results = []   # 用列表保存遍历的结果
    stack = []     # 栈结构辅助算法
    if root is None:
        return results
    stack.append(root)

    while 0 != len(stack):
        tmp = stack.pop()
        results.append(tmp.value)

        if tmp.right != None:
            stack.append(tmp.right)
        if tmp.left != None:
            stack.append(tmp.left)
        
    return results

def midTraverseNoRec(root):
    results = []   # 用列表保存遍历的结果
    stack = []     # 栈结构辅助算法

    while root is not None or 0!=len(stack):
        if root is not None:
            stack.append(root)
            root = root.left
        else:
            root = stack.pop()
            results.append(root.value)
            root = root.right
    return results

def afterTraverseNoRec(root):
    results = []   # 用列表保存遍历的结果
    stack = []     # 栈结构辅助算法
    if root is None:
        return results
    stack.append(root)

    while 0 != len(stack):
        tmp = stack.pop()
        results.insert(0, tmp.value)  #和前序遍历的区别，头插

        if tmp.left != None:
            stack.append(tmp.left)
        if tmp.right != None:
            stack.append(tmp.right)
        
    return results

# 从上往下打印二叉树
# 相当于层序遍历， 采用BFS, 借助辅助队列实现
# 1、把二叉树的根节点 root 放进队列。
# 2、如果队列不为空，取出队列的一个节点，把这个节点的左右孩子放进队列中(为空的话就不用放)，然后打印这个节点。
# 3、一直重复步骤 2 ，直到队列为空，此时遍历结束
def FromTopToBottomTraverse(root):
    queue = []
    results = []
    if root is None:
        return results
    queue.append(root)

    while 0!=len(queue):
        tmp = queue.pop(0)
        results.append(tmp.value)

        if tmp.left is not None:
            queue.append(tmp.left)
        if tmp.right is not None:
            queue.append(tmp.right)
    
    return queue

# 二叉树镜像
def mirror(root):
    if root is None:
        return root
    
    # 递归先处理左右子树的镜像化
    left = mirror(root.left)
    right = mirror(root.right)

    # 对左右字树结果和root进行组合
    root.left = right
    root.right = left

    return root

# 二叉树的子结构
# 对于与二叉树有关的题目，90% 是采取递归的方式来解决比较简单的
def judge(root1, root2):
    if root2 == None:
        return False
    if root1 == None:
        return False
    if root1.value == root2:
        return judge(root1.left,root2.left) or judge(root1.right,root2.right)
    
    return False

def isSubTree(root1, root2):
    if root1 == None or root2 == None:
        return False
    
    # 以root为根节点判断子结构是否成立
    if judge(root1, root2):
        return True
    else:
        return isSubTree(root1.left, root2) or isSubTree(root1.right, root2)

# 重建二叉树
# 输入前序遍历和中序遍历，重建二叉树并返回
# 递归实现:
# 1、通过前序序列第一个元素确定根节点(例如 1)。
# 2、通过根节点把中序序列分成两个序列，一个是左子树序列([4,7,2)]，一个是右子树序列([5,3,8,6)]。
# 3、通过左右子树的中序序列可以求出前序遍历的左右子树序列(左:[2,4,7],右:[3,5,8,6])。
# 4、左右子树的前序序列第一个元素分别是根节点的左右儿子。
# 5、通过递归重复以上步骤
def rebuildTree(pre, preStart, preEnd, mid, midStart, midEnd):
    if preStart > preEnd or midStart > midEnd:
        return None
    # 根节点-前序遍历第一个元素
    root = Node(pre[preStart])
    # 寻找根结点在中序遍历中的位置
    for i in range(midStart, midEnd+1):
        if mid[i] == pre[preStart]:
            # 中序序列的左右子树： 左：midStart~i-1  右: i+1~midEnd
            # 前序序列左右子树:    左: preStart+1~preStart+i-midStart  右子树: preStart+i-midStart+1~preEnd
            root.left = rebuildTree(pre, preStart+1,preStart+i-midStart, mid, midStart, i-1)
            root.right = rebuildTree(pre, preStart+i-midStart+1,preEnd, mid, i+1, midEnd)
    return root

def reConstructBinarytion(pre, mid):
    return rebuildTree(pre, 0, len(pre)-1, mid, 0, len(mid)-1)


if __name__=='__main__':
    root=Node('D',Node('B',Node('A'),Node('C')),Node('E',right=Node('G',Node('F'))))
    print('前序遍历：')
    preTraverse(root)

    print('非递归-前序遍历：')
    res = preTraverseNoRec(root)
    for s in res:
        print(s)
    print('\n')

    print('中序遍历：')
    midTraverse(root)

    print('非递归-中序遍历：')
    res = midTraverseNoRec(root)
    for s in res:
        print(s)
    print('\n')

    print('后序遍历：')
    afterTraverse(root)
    print('\n')

    print('非递归-后序遍历：')
    res = afterTraverseNoRec(root)
    for s in res:
        print(s)
    print('\n')