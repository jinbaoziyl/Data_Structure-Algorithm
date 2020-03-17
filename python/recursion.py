# 汉诺塔
def hano(A,B,C,n):
    if n > 0:
        hano(A,C,B, n-1)
        print(A + '->' + C + " n: %d" %n)
        hano(B,A,C, n-1)

def decode(chars, index):
    if index <= 0: 
        return 1
    count = 0
    curr = chars[index]
    prev = chars[index-1]

    if curr > '0':
        count = decode(chars, index-1)
    
    # 本质上也是斐波那契函数，结尾字符分两种情况
    # 只是f(n-2)这项存在条件
    if prev == '1' or (prev == '2' and curr <= '6'):
        count += decode(chars, index-2)

    return  count

# Leetcode 91.解码方法
def numDecodings(s:str) ->int:
    chars = list(s)
    return decode(chars, len(chars)-1)

# Leetcode 247.中心对称数II
def helper(n, m):
    # 判断输入或者状态是否合法
    if n < 0 or m < 0 or n > m:
        raise Exception("invalid input")
    
    if n == 0:
        return []
    if n == 1:
        return ['0','1','8']
    if n == 2:
        return ['11', '69', '88', '96']

    list = helper(n-2, m)
    res = []
    for s in list:
        if n != m: res.append('0' + s + '0') #形参m的作用，最外面一层不需要加0
        res.append('1' + s + '1')
        res.append('6' + s + '9')
        res.append('8' + s + '8')
        res.append('9' + s + '6')
    return res

# hano('A','B','C',5)
# count = numDecodings("2226")
# print("method nums: %d" %count)

list = helper(2, 2)
for s in list:
    print(s)