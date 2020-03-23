class Node:
    def __init__(self, x):
        self.value = x
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = Node(-1)  # 头节点哨兵

    def addNode(self, val): # 哨兵头结点好处，头结点和其他节点统一
        tmp = self.head
        while tmp.next != None:
            tmp = tmp.next
        tmp.next = Node(val)

    def headInsert(self, val):
        newNode = Node(val)
        newNode.next = self.head.next
        self.head.next = newNode
    
    def printList(self):
        tmp = self.head
        while tmp.next != None:
            tmp = tmp.next
            print('%d ' %tmp.value)

# arr = [1,2,3,4]
# linkedlist = LinkedList()
# for s in arr:
#     linkedlist.addNode(s)
# linkedlist.printList()

# Google 面试题：给定单向链表的头指针和一个节点指针，定义一个函数在 O(1) 内删除这个节点
def delNode(linkedlist, node):
    # 如果待删除结点是最后一个，依然需要遍历
    if node.next == None:
        tmp = linkedlist.head
        while(tmp.next != node):
            tmp = tmp.next
        tmp.next = None
    else:
        nextNode = node.next
        node.value = nextNode.value
        node.next = nextNode.next
        nextNode.next = None

# arr = [1,2,3,4]
# linkedlist = LinkedList()
# for s in arr:
#     linkedlist.addNode(s)
# linkedlist.printList()

# node = linkedlist.head.next.next
# # print(node.value)
# delNode(linkedlist, node)
# linkedlist.printList()

# 翻转链表
def ReverseList(node):
    if node.next == None or node == None:
        return node
    newNode = ReverseList(node.next)

    # 处理第一个结点和子问题的关系
    node.next.next = node
    node.next = None

    return newNode

arr = [1,2,3,4]
linkedlist = LinkedList()
for s in arr:
    linkedlist.addNode(s)
linkedlist.printList()
newNode = ReverseList(linkedlist.head.next)
# 翻转后设置头结点的后继结点
linkedlist.head.next = newNode
print('========== result: ============')
linkedlist.printList()

