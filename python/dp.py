# 斐波那契数列， 一步一步走向dp的解法
# 1. 判断是否可用递归解法
def fabonacci(n):
    if n == 1: return 1
    if n == 2: return 2
    return fabonacci(n-1) + fabonacci(n-2)

# val = fabonacci(6)
# print("val: %d" %val)

# 2.分析在递归的过程中是否存在大量的重复子问题
# 3.采用备忘录的方式来存子问题的解以避免大量的重复计算 
#  既然以上中间子问题中存在着大量的重复计算，那么我们可以把这些中间结果给缓存住（可以用哈希表缓存）
map = {}
def fabonacci_map(n):
    if n == 1: return 1
    if n == 2: return 2
    if n in map:
        return map[n]
    result = fabonacci(n-1) + fabonacci(n-2)
    map[n] = result
    return result

# val = fabonacci_map(10)
# print("val: %d" %val)

# 4. 改用自底向上的方式来递推，即动态规划 我们注意到如下规律:
# f(1) = 1
# f(2) = 2
# f(3) = f(1) + f(2) = 3
# f(4) = f(3) + f(2) = 5
# ....
# f(n) = f(n-1) + f(n-2)
def fabonacci_dp(n):
    if n == 1: return 1
    if n == 2: return 2
    dp = [1,2]
    result = 0

    for i in range(3, n+1):
        result = dp[0] + dp[1]
        dp[0] = dp[1]
        dp[1] = result

    return result

# val = fabonacci_dp(10)
# print("val: %d" %val)

#  LeetCode 198 打家劫舍
# 考虑能否用递归; 然后分析重叠子结构
# 推导递归公式: dp[i] 表示到数组i项 得到的最高金额
# dp[i] = max{ dp[i-2]+num[i] , dp[i-1]}
def rob(nums):
    if nums:
        dp = [nums[0], max(nums[1], nums[0])] #注意index 2, 需要是最优解-最大的金额
        for i in range(2, len(nums)):
            dp.insert(i, max([dp[i-2]+nums[i], dp[i-1]]))
        return dp[-1]
    else:
        return 0
# nums = [1,2,3,1]
# val = rob(nums)  
# print("val: %d" %val)  

# 三角形的最小路径和 https://mp.weixin.qq.com/s/15HSidWyGg5eN--ICNNjFg
# 此题和dfs的‘二叉树中和为某一值的路径’对比一下，观察异同
import numpy as np
list = [2, 0, 0, 0,
        3, 4, 0, 0,
        6, 5, 7, 0,
        4, 1, 8, 3]
triangle = np.array(list).reshape(4,4)

# 分析递归
def traverse(i, j):
    if i >= triangle.shape[0] - 1:
        return triangle[i][j]
    
    leftSum = traverse(i+1, j)
    rightSum = traverse(i+1, j+1)

    return min(leftSum,rightSum)+triangle[i][j]

# val = traverse(0,0)
# print("val: %d" %val) 

# 2. 分析递归的过程中是否存在大量的重复子问题
# 3. 采用备忘录的方式来存子问题的解以避免大量的重复计算（剪枝）
map = {}
def traverse_map(i, j):
    n = str(i)+str(j)
    for n in map:
        return map[n]
    if i >= triangle.shape[0] - 1:
        return triangle[i][j]
    
    leftSum = traverse(i+1, j)
    rightSum = traverse(i+1, j+1)

    result = min(leftSum,rightSum)+triangle[i][j]
    map[n] = result
    return result

# val = traverse_map(0,0)
# print("val: %d" %val) 

# DP状态转移方程定义:  DP 状态 DP[i,j] 定义为 i,j 的节点到底部的最小值
# DP[i,j] = min(DP[i+1, j], D[i+1, j+1]) + triangle[i,j]
def traverse_dp(i, j):
    dp = triangle[-1,:]   # 自底而上， 底部的dp值全部确认

    for i in range(triangle.shape[0]-2, -1, -1):
        for j in range(0, i):
            dp[j] = triangle[i][j] + min(dp[j], dp[j+1])
    return dp[0]

# val = traverse_dp(0,0) + triangle[0][0]
# print("val: %d" %val) 

# 凑零钱
# 给定不同面额的硬币 coins 和一个总金额 amount。
# 编写一个函数来计算可以凑成总金额所需的最少的硬币个数。
# 如果没有任何一种硬币组合能组成总金额，返回 -1。 
# 输入: coins = [1, 2, 5], amount = 11，输出: 3  
# 解释: 11 = 5 + 5 + 1 输入: coins = [2], amount = 3，输出: -1

# 递归分析
import sys
def exchange(amount, coins):
    if amount == 0:
        return 0
    if amount < 0:
        return -1
    
    result = sys.maxsize
    for i in range(len(coins)):
        subMin = exchange(amount-coins[i], coins)
        if subMin < 0:
            continue
        if (subMin + 1) < result:
            result = subMin + 1
    
    if result == sys.maxsize:  #没有符合的解法
        return -1

    return result

# coins = [1,2,5]
# amount = 11
# val = exchange(amount, coins)
# print("val: %d" %val) 
maps = {}
def exchange_map(amount, coins):
    if amount in maps:
        return maps[amount]
    if amount == 0:
        return 0
    if amount < 0:
        return -1
    
    result = sys.maxsize
    for i in range(len(coins)):
        subMin = exchange(amount-coins[i], coins)
        if subMin < 0:
            continue
        if (subMin + 1) < result:
            result = subMin + 1
    
    if result == sys.maxsize:  #没有符合的解法
        return -1

    maps[amount] = result
    return result

# coins = [1,2,5]
# amount = 11
# val = exchange_map(amount, coins)
# print("val: %d" %val) 

# 改用自底向上的方式来递推，即动态规划
# DP[i] =  min{ DP[ i - coins[j] ] + 1 } = min{ DP[ i - coins[j] ]} + 1,  
# 其中 j 的取值为 0 到 coins 的大小，DP(i) 为凑够零钱 i 需要的最小值
def exchange_dp(amount, coins):
    dp = []
    for i in range(amount+1):
        dp.append(sys.maxsize)

    dp[0] = 0
    # 从凑钱数0开始，直到凑到amount
    for i in range(amount+1):
        for j in range(len(coins)):
            if i >= coins[j]:
                dp[i] = min(dp[i-coins[j]], dp[i]) + 1

    if dp[amount] == sys.maxsize: #没有凑齐
        return -1

    return dp[amount]

# coins = [1,2,5]
# amount = 11
# val = exchange_dp(amount, coins)
# print("val: %d" %val) 

# 0-1背包问题
def bag(vlist,wlist,totalWeight,totalLength):
    resArr = np.zeros((totalLength+1,totalWeight+1),dtype=np.int32)
    for i in range(1,totalLength+1):
        for j in range(1,totalWeight+1):
            if wlist[i] <= j:
                resArr[i,j] = max(resArr[i-1,j-wlist[i]]+vlist[i],resArr[i-1,j])
            else:
                resArr[i,j] = resArr[i-1,j]
    return resArr[-1,-1]

v = [0,60,100,120]
w = [0,10,20,30]
weight = 50
n = 3
val = bag(v,w,weight,n)
print("val: %d" %val) 
