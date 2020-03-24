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

    def genLoopList(self):
        tmp = self.head
        while tmp.next != None:
            tmp = tmp.next
        tmp.next = self.head.next

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

# arr = [1,2,3,4]
# linkedlist = LinkedList()
# for s in arr:
#     linkedlist.addNode(s)
# linkedlist.printList()
# newNode = ReverseList(linkedlist.head.next)
# # 翻转后设置头结点的后继结点
# linkedlist.head.next = newNode
# print('========== result: ============')
# linkedlist.printList()

# 删除单链表中的第K个节点
def delKNode(head, k):
    if k < 0 or head == None:
        raise Exception('Parameter invalid')
    delNode = head
    k -= 1
    while k:
        if delNode.next is not None:
            delNode = delNode.next
        else:
            raise IndexError('k index invalid')
        k -= 1
    
    # 删除delNode指向k结点的前驱
    delNode.next = delNode.next.next
    
# arr = [1,2,3,4,5,6]
# linkedlist = LinkedList()
# for s in arr:
#     linkedlist.addNode(s)
# linkedlist.printList()
# delKNode(linkedlist.head.next, 2)
# print('========== result: ============')
# linkedlist.printList()   

# 删除单链表的中间节点
def delMidNode(head):
    if head.next is None:
        head = None
    fast, slow = head.next.next, head # 为了停止时，slow指向前驱，fast=head.next.next

    # 快慢指针一起走，直到快指针到结尾
    while fast.next is not None and fast.next.next is not None:
        fast = fast.next.next
        slow = slow.next
    
    # slow指向中间结点的前驱
    slow.next = slow.next.next

    
# arr = [1,2,3]
# linkedlist = LinkedList()
# for s in arr:
#     linkedlist.addNode(s)
# linkedlist.printList()
# delMidNode(linkedlist.head.next)
# # 翻转后设置头结点的后继结点
# # linkedlist.head.next = newNode
# print('========== result: ============')
# linkedlist.printList()

# 环形单链表约瑟夫问题
def JosephKill(head, m):
    if m < 1 or head.next is None: 
        return None
    tmp = head
    while tmp.next != tmp:
        # 删除第m个结点
        count = m - 2 #为了指向待删除的前驱
        while count:
            tmp = tmp.next
            count -= 1
        node = tmp.next.next
        print("del val: %d" %tmp.next.value)
        tmp.next = tmp.next.next
        
        tmp = node # 更新报数结点
    return head

# 递归方式找出最后一个位置
#  f(n) 表示当环形链表的长度为n时，生存下来的人的编号为 f(n)，显然当 n = 1 时，f(n) = 1。
#  假如我们能够找出 f(n) 和 f(n-1) 之间的关系的话，我们我们就可以用递归的方式来解决了
# 删除前     ---     删除后
# …          ---      …
# m - 2     ---     n - 2
# m - 1    ---      n - 1
# m         ----    无(因为编号被删除了)
# m + 1     ---     1(因为下次就从这里报数了)
# m + 2     ----    2
# …         ----    …

# 假设 old 为删除之前的节点编号， new 为删除了一个节点之后的编号，
# 则 old 与 new 之间的关系为 old = (new + m - 1) % n + 1

def f(n, m):
    if n == 1:
        return 1
    return (f(n-1,m) + m -1) % n + 1

def JosephKillRecursive(head, m):
    if m < 1 or head.next is None: 
        return None
    # 统计共有多少个结点
    n = 1
    tmp = head
    while tmp.next != head:
        tmp = tmp.next
        n += 1
    des = f(n, m)  
    des -= 1
    while(des):
        head = head.next
        des -= 1
    head.next = head
    return head

# arr = [1,2,3,4,5,6]
# # arr = [1,2,3]
# linkedlist = LinkedList()
# for s in arr:
#     linkedlist.addNode(s)
# linkedlist.printList()
# linkedlist.genLoopList()

# # node = JosephKill(linkedlist.head.next, 2)
# node = JosephKillRecursive(linkedlist.head.next, 2)
# print(node.next.value)
# if node.next.next == node.next:
#     print("Loop")
        
# 三种方法带你优雅判断回文链表
# 方法1: 我们可以利用栈来做辅助，把链表的节点全部入栈，在一个一个出栈与链表进行对比
# 方法2: 其实我们也可以让链表的后半部分入栈就可以了，然后把栈中的元素与链表的前半部分对比
# 方法3: 我们可以把链表的后半部分进行反转，然后再用后半部分与前半部分进行比较就可以了。
#        这种做法额外空间复杂度只需要 O(1), 时间复杂度为 O(n)
def palindromeList(head):
    if head is None or head.next is None:
        return True
    fast, slow = head.next.next, head # 为了停止时，slow指向前驱，fast=head.next.next

    # 快慢指针一起走，直到快指针到结尾
    while fast.next is not None and fast.next.next is not None:
        fast = fast.next.next
        slow = slow.next

    # slow现在指向中间结点的前驱
    # 将链表后半部分，放入堆栈中
    stack = []
    stknode = slow
    while stknode.next is not None:
        stknode = stknode.next
        stack.append(stknode.value) 
    
    # print(stack)
    # 比较链表前半部分和堆栈顶部弹出的元素
    tmp = head
    while(0 != len(stack)):
        val = stack.pop()
        if val != tmp.value:
            return False
        else:
            tmp = tmp.next
    
    return True

arr = [1,2,2,1]
linkedlist = LinkedList()
for s in arr:
    linkedlist.addNode(s)
linkedlist.printList()

if palindromeList(linkedlist.head.next):
    print("Linked list is palindrome")
else: 
    print("Linked list is not palindrome")

# 将单向链表按某值划分成左边小，中间相等，右边大的形式
# 思路: 使用3个指针，把原链表依次划分成三个部分的链表，然后再把他们合并起来，
# 这种做法不但空间复杂度为 O(1), 而且内部节点的顺序也是和原链表一样的
def partitionList(head, pivot):
    if head is None or head.next is None:
        return head
    list1 =  LinkedList()   
    list2 =  LinkedList()   
    list3 =  LinkedList()   
    tmp = head
    while tmp is not None:
        if tmp.value < pivot:
            list1.addNode(tmp.value)
        elif tmp.value == pivot:
            list2.addNode(tmp.value)
        else:   
            list3.addNode(tmp.value)
        tmp = tmp.next    
    #合并3个链表
    headNode = list1.head
    while  headNode.next is not None:
        headNode = headNode.next
    headNode.next = list2.head.next

    headNode2 = list2.head
    while headNode2.next is not None:
        headNode2 = headNode2.next
    headNode2.next = list3.head.next

    return list1




arr = [9,0,4,3,3,5,1]
linkedlist = LinkedList()
for s in arr:
    linkedlist.addNode(s)
# linkedlist.printList()

reslist = partitionList(linkedlist.head.next, 3)
reslist.printList()





