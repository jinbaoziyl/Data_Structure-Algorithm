# 无重复字符的最长子串
def MaxSubStr(str):
    if str == None:
        return 0
    nums = []
    for i in range(len(str)):
        arr = [0]*256
        icount = 0
        for j in range(i, len(str)):
            if arr[ord(str[j])] == 1:
                break
            else:
                arr[ord(str[j])] += 1
                icount += 1
        nums.append(icount)
    
    return max(nums)

# str = 'abcabcabc'
# str = 'bbbbbbbbbbbb'
# str = 'pwwkew'
# val = MaxSubStr(str)
# print('val: %d' %val)

# 寻找两个有序数组中的中位数
def Median(arr1, arr2):
    if arr1 == None and arr2 == None:
        return -1
    size = len(arr1)+len(arr2)
    res = [0]*size
    idx1, idx2 = 0, 0
    for i in range(size):
        if idx1 > len(arr1)-1:
            res[i] = arr2[idx2]
            idx2 += 1
        elif idx2 > len(arr2)-1:
            res[i] = arr1[idx1]
            idx1 += 1
        elif arr1[idx1] < arr2[idx2]:
            res[i] = arr1[idx1]
            idx1 += 1
        else:
            res[i] = arr2[idx2]
            idx2 += 1

    if size % 2 == 1:
        return res[size//2]
    else:
        return (res[size//2] + res[size//2+1])//2

# arr1 = [1,2]
# arr2 = [3,4]
# val = Median(arr1, arr2)
# print('val: %d' %val)


# 第k小的数
import random
def partition(arr, lo, hi): 
    # pivot = random.randrange(lo, hi+1)
    pivot = hi
    arr[pivot], arr[hi] = arr[hi], arr[pivot] 

    i = lo
    # j变量遍历每个元素
    for j in range(lo, hi+1):
        if arr[j] < arr[hi]:
            # i变量是小于pivot的索引，离j最近的数
            arr[i], arr[j] = arr[j], arr[i] 
            i += 1
    arr[i], arr[j] = arr[j], arr[i] 
    return i

def findK(nums, lo, hi, k):
    if nums == None or k < 0:
        return -1 
    
    if lo > hi:
        return -1 

    q = partition(nums, lo, hi)
    if q == k - 1:
        return nums[k]
    if q <= k - 1:
        return findK(nums, q+1, hi, k)
    else:
        return findK(nums, lo, q-1, k)
        
        
# nums = [32, 68, 98, 51, 88, 1]
# val = findK(nums, 0, len(nums)-1, 3)
# print('val: %d' %val)

# 合并k个排序链表
# 解法1： 暴力法
# 解法2： 最小堆
# 解法3： 分治法

# 合并区间
# 贪婪算法:
# 定义两个变量previous和current，分别表示前一个区间和当前区间
#  如果没有发生融合 当前区间变成previous，下一个区间变成current
#  如果发生融合，更新前一个区间的结束时间

def takeFirst(elem): # 获取列表的第一个个元素
    return elem[0]
def MergeInterval(vlist):
    vlist.sort(key=takeFirst)
    # print(vlist)

    previous = []
    results = []
    for current in vlist:
        if(len(previous)==0 or current[0] > previous[1]):
            previous = current
            results.append(previous)
        else:
            previous[1] = max(previous[1], current[1])
    return results

# vlist = [[1,3], [2,4], [8,10], [15,18]]
# results = MergeInterval(vlist)
# print(results)


# 无重叠区间
# 贪婪算法:
# 解题思路: 
# 先求出最大不重叠子区间个数, 再用「区间总数-最大不重叠子区间个数」即为最小要移除的重叠区间数
# 用贪心算法求最大不重大子区间个数步骤如下
# 1. 选择终点最小的区间，设置为当前区间 cur 。
# 2. 按区间终点从小到大寻找下一个与区间 cur 不重叠的区间，
#    然后将此区间设置为当前区间 cur（注意此时最大不重叠子区间个数要加1），
#    不断重复步骤 2， 直到遍历所有的区间。
def takeSecond(elem): # 获取列表的第一个个元素
    return elem[-1]
def MergeIntervalMinDel(vlist):
    vlist.sort(key=takeSecond)
    
    count = 1
    cur = 0
    for i in range(1,len(vlist)):
        if(vlist[cur][1] <= vlist[i][0]):
            cur = i
            count += 1

    return len(vlist) - count

# vlist = [[1,2], [2,3], [3,4], [1,3]]
# # vlist = [[1,2], [2,3]]
# results = MergeIntervalMinDel(vlist)
# print(results)

# 火星字典
# 核心思想: 对有向图进行拓扑排序
# 步骤:
# 1. 根据输入构建有向图
# 2. 对该有向图图进行拓扑排序
def topologicalSort(adList, u, visited, loop, stack): 
    visited.append(u)
    loop.append(u)
    if u in adList:
        for v in adList[u]:
            if v in loop:
                return False
            if v not in visited:
                val = topologicalSort(adList,v,visited,loop,stack)
                if not val:
                    return False
    loop.remove(u)
    stack.append(u)
    return True

def alienOrder(words):
    # 基本处理
    if words == None or len(words) == 0:
        return None
    if len(words) == 1:
        return words[0]
    adList  = {}  # 有向图， 定义邻接链表adList； 也可以用邻接矩阵  
    # 两两比较字符串
    # 一旦发现两字母不同，就链接这两个顶点
    for i in range(len(words)-1):
        word1 = words[i]
        word2 = words[i+1]
        len1= len(word1)
        len2= len(word2)
        found = False
        for j in range(max(len1, len2)):
            char1 = word1[j] if j<len1 else None
            char2 = word2[j] if j<len2 else None
            
            # 对每个出现的字母都创建一个图里的顶点
            if char1 != None:
                if char1 not in adList:
                    adList[char1] = []
            if char2 != None:
                if char2 not in adList:
                    adList[char2] = []
            
            if char1 != None and char2 != None and char1 != char2 and (not found):
                found = True
                adList[char1].append(char2)
    # print(adList)
    # 有向图拓扑排序：dfs、bfs均可； dfs复杂些 这里练习一下
    visited = []
    loop = []
    stack = []

    for key in adList:
        if key not in visited:
            val = topologicalSort(adList, key, visited, loop, stack)
            if not val:
                return ''

    res = ''
    for i in range(len(stack)-1, -1, -1):
        res += stack[i]

    return res

# words = ['wrt', 'wrf', 'er','ett','rftt']
# res = alienOrder(words)
# print(res)

# 基本计算器
def calculate(s: str) -> int: 
    def helper(s: list) -> int:
        stack = []
        sign = '+'
        num = 0

        while len(s) > 0:
            c = s.pop(0)
            if c.isdigit():
                num = 10 * num + int(c)
            # 遇到左括号开始递归
            if c == '(':
                num = helper(s)

            if (not c.isdigit() and c != ' ') or len(s) == 0:
                if sign == '+':
                    stack.append(num)
                elif sign == '-':
                    stack.append(-num)
                elif sign == '*':
                    stack[-1] = stack[-1] * num
                elif sign == '/':
                    # python 除法向 0 取整的写法
                    stack[-1] = int(stack[-1] / float(num))                    
                num = 0
                sign = c
            # 遇到右括号结束递归
            if c == ')':
                break
        return sum(stack)
    # 需要把字符串转成列表方便操作
    return helper(list(s))

# res = calculate('6-4/2')
# print(res)

# LRU缓存
# 双向链表和字典组合解题:
# 双向链表的作用是: 从头到尾 访问的次数越低， 满的时候直接删除头结点
# 字典: 查看是否存在key
class Node:

    def __init__(self, k, v):
        self.key = k
        self.val = v
        self._prev = None
        self._next = None

class LRUCache:

    def __init__(self, capacity: int):
        self.store = {}
        # 预设一个头尾节点，后续插入时不要判空的情况
        self.head = Node('h', -1)
        self.tail = Node('t', -1)
        self.head._next = self.tail
        self.tail._prev = self.head
        self.cap = capacity

    def insert_after(self, target, node):
        # 将一个新节点插入到某节点的后面
        node._next = target._next
        node._prev = target

        target._next._prev = node
        target._next = node

    def move_to_head(self, node):
        # 将已存在的节点插入到头结点后面
        node._prev._next = node._next
        node._next._prev = node._prev

        node._next = self.head._next
        node._prev = self.head

        self.head._next = node
        node._next._prev = node
        
    def pop(self):
        # 待删除的节点
        res = self.tail._prev
        res._prev._next = self.tail
        self.tail._prev = res._prev

        res._prev = None
        res._next = None

        return res

    def get(self, key: int) -> int:
        item = self.store.get(key, -1)
        if item != -1:
            self.move_to_head(item)
            return item.val
        else:
            return -1

    def put(self, key: int, value: int) -> None:
        if key in self.store:
            item = self.store[key]
            item.val = value
            self.move_to_head(item)
            return
        if len(self.store) == self.cap:
            poped = self.pop()
            del self.store[poped.key]
        # 插入新节点
        node = Node(key, value)
        self.insert_after(self.head, node)
        self.store[key] = node


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)


